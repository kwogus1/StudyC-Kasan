# define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <wtypes.h>	
#include <sqlext.h>
#include <sql.h>


SQLHENV henv = NULL; // DB환경 구조체
SQLHDBC hdbc = NULL; // DB 접속 구조체

// ODBC db접속
int ODBCConnect(SQLCHAR* dsn, SQLCHAR* userId, SQLCHAR* pwd) {
	SQLRETURN res;
	henv = NULL;
	hdbc = NULL; // 관련된 정보 초기화

	// SQL 환경 henv 값을 할당
	res = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
	if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
		// OCBC 버전에 따른 환경 속성 설정
		res = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
		if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
			// 커넥션 핸들 설정
			res = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
			if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
				// 접속하기 위한 설정 먼저
				SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)30, 0);
				// 실제 접속(중요!!)
				res = SQLConnect(hdbc, dsn, SQL_NTS, userId, SQL_NTS, pwd, SQL_NTS);
				if (res == SQL_SUCCESS || res == SQL_SUCCESS_WITH_INFO) {
					return 1; // 접속 성공 true
				}

				SQLDisconnect(hdbc);
				
			}
			SQLFreeHandle(SQL_HANDLE_DBC, hdbc);

			hdbc = henv = NULL;

			return 0; // 접속 실패 false
		}
	}
}

// DB 접속해제
int ODBCDisconnect() {
	if (hdbc) {
		SQLDisconnect(hdbc); // 접속 종료
		SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
	}
	if (henv) SQLFreeHandle(SQL_HANDLE_ENV, henv);
	hdbc = henv = NULL;
	return 1;

}

// 데이터 가져오기
int db_fetch() {
	SQLRETURN rt;
	SQLHSTMT hstmt;
	SQLCHAR sql[256]; 
	SQLLEN n; // 쿼리를 위한 변수

	SQLINTEGER id;
	SQLCHAR title[100];
	SQLCHAR writer[100];
	SQLCHAR genre[45];
	SQLDATE release_date;
	SQLSMALLINT pages;
	SQLCHAR company[50];
	SQLDECIMAL price; // 데이터를 담기 위한 변수

	if (hdbc == NULL || henv == NULL) return 0;

	rt = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
	if (!(rt = SQL_SUCCESS || rt == SQL_SUCCESS_WITH_INFO)) return 0;

	strcpy(sql, "SELECT id, title, writer, genre, release_date, pages, price FROM books_info ");
	rt = SQLExecDirect(hstmt, sql, SQL_NTS);
	if (rt != SQL_SUCCESS) {
		printf("cannot access query\n");
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
		return 0;
	}

	while (1) {
		rt = SQLFetch(hstmt);
		if (rt = SQL_SUCCESS || rt == SQL_SUCCESS_WITH_INFO) {
			rt = SQLGetData(hstmt, 1, SQL_C_ULONG, &id, 0, &n);
			rt = SQLGetData(hstmt, 2, SQL_C_WCHAR, title, 100, &n);

			printf("%d, %s\n", id, title);
		}
		else if (rt == SQL_NO_DATA) {
			printf("No Data!\n");
			break;
		}
		else {
			printf("Fail to fetch data!");
			break;
		}
	}
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	return 0;
}

int main(void) {
	int ret = 0;
	printf("MSSQL 접속 시작\n");
	ret = ODBCConnect("BMS", "sa", "1234");
	if (ret == 1)
		printf("접속 성공!\n");

	ret = db_fetch();
	if (ret == 1)
		printf("\n");

	ret = ODBCDisconnect();
	if(ret == 1)
	printf("접속 종료!\n");
	return 0;
}