#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

// MySQL 접속 설정(변경 필요!)
#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

#define TITLE_LENGTH 100
#define GENRE_LENGTH 50

// 책정보 담을 구조체 bookInfo
typedef struct bookInfo {
	int id;
	char title[TITLE_LENGTH];  // NOT NULL
	char writer[TITLE_LENGTH]; // NOT NULL
	char genre[GENRE_LENGTH];
	char release_date[15]; // "2020-06-22\0" // 11
	short pages;
	char company[50];
	int price;
} book;

// 함수 원형선언
void connect_db(MYSQL*);
void close_db();
void insert_book(MYSQL*);
void display_books(MYSQL*);
void update_book(MYSQL*);
void delete_book(MYSQL*);
void search_book(MYSQL*);
void print_header(void);


int main(void) {
	setlocale(LC_ALL, "Korean");

	MYSQL* conn;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	int input = 0; // 메뉴 입력값

	conn = mysql_init(NULL);
	connect_db(conn);

	// 무한루프
	while (1) {
		system("cls"); // 화면 클리어
		printf("도서관리 프로그램(v2)\n");
		printf("1. 도서조회\n");
		printf("2. 도서입력\n");
		printf("3. 도서수정\n");
		printf("4. 도서검색\n");
		printf("5. 도서삭제\n");
		printf("6. 프로그램 종료\n");
		printf("입력 > ");
		scanf("%d", &input); rewind(stdin);

		switch(input) {
			case 1:
				display_books(conn);
				system("pause");
				break;
			case 2:
				insert_book(conn);
				system("pause");
				break;
			case 3:
				update_book(conn);
				system("pause");
				break;
			case 4:
				search_book(conn);
				system("pause");
				break;
			case 5:
				delete_book(conn);
				system("pause");
				break;
			case 6:
			default:
				close_db(conn);
				printf("프로그램 종료");
				exit(0);
	
		}
	}
	return;
}
void connect_db(MYSQL* conn) {
	
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "연결오류! : %s\n", mysql_error(conn));
		return;
	}

	printf("연결성공!\n");
	printf("서버버전 %s\n", conn->server_version);
}
void close_db(MYSQL* conn) {
	mysql_close(conn);
	printf("연결종료\n");
}
void display_books(MYSQL* conn) {
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	int i = 0;

	query_stat = mysql_query(conn, "SELECT * FROM books_info");
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return;
	}

	print_header();

	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

}

void insert_book(MYSQL* conn) {
	//book insBook = { 0, }; // 구조체 선언/초기화
	int i, y = 0;
	char query[500] = { 0, };
	book tmpBook = { 0, };

	printf("책이름 입력 > ");
	scanf("%[^\n]s", tmpBook.title);
	rewind(stdin); // 표준입력 리플레쉬

	printf("저자명 입력 > ");
	scanf("%[^\n]s", tmpBook.writer);
	rewind(stdin);

	printf("장르 입력 > ");
	scanf("%[^\n]s", tmpBook.genre);
	rewind(stdin); 

	printf("출판일 입력(ex. 2022-06-01) > ");
	scanf("%s", tmpBook.release_date);
	rewind(stdin);

	printf("페이지수 입력(ex. 300) > ");
	scanf("%d", &tmpBook.pages);
	rewind(stdin);

	printf("출판사 입력 > ");
	scanf("%[^\n]s", tmpBook.company);
	rewind(stdin);

	printf("가격 입력(ex. 15000) > ");
	scanf("%d", &tmpBook.price);
	rewind(stdin);

	sprintf(query, " INSERT INTO books_info "
		           " (title, writer, genre, release_date, pages, company, price) "
		           " VALUES "
		           " ('%s', '%s', '%s', '%s', '%d', '%s', '%d') ",
		tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date,
		tmpBook.pages, tmpBook.company, tmpBook.price);
	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "입력오류 : %s\n", mysql_error(conn));
		return;
	}
	printf("책정보가 입력되었습니다.\n");
}

// 책정보 수정함수
void update_book(MYSQL* conn) {
	int i = 0;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	char query[500] = { 0, };

	book tmpBook = { 0, };

	printf("수정할 책 번호 입력 > ");
	scanf("%d", &tmpBook.id); rewind(stdin);

	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("수정할 데이터가 없습니다.\n");
		return;
	}

	print_header();

	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	printf("변경책이름 입력 > ");
	scanf("%[^\n]s", tmpBook.title); rewind(stdin); // 표준입력 리플레쉬

	printf("변경저자명 입력 > ");
	scanf("%[^\n]s", tmpBook.writer); rewind(stdin);

	printf("변경장르 입력 > ");
	scanf("%[^\n]s", tmpBook.genre); rewind(stdin);

	sprintf(query,
		" UPDATE books_info SET "
		"        title = '%s'  "
		"	   , writer = '%s' "
		"	   , genre = '%s'  "
		"  WHERE id = %d ",
		tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.id);

	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "수정쿼리오류! : %s\n", mysql_error(conn));
		return;
	}
	printf("책정보가 수정되었습니다.\n");
}

// 책정보 삭제 함수
void delete_book(MYSQL* conn) {
	MYSQL_RES* result;
	int query_stat;
	char query[500] = { 0, };

	book tmpBook = { 0, };

	printf("삭제할 책 번호 입력 > ");
	scanf("%d", &tmpBook.id); rewind(stdin);

	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("삭제할 데이터가 없습니다.\n");
		return;
	}

	sprintf(query, 
		"DELETE FROM books_info WHERE id = %d", tmpBook.id);

	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "삭제쿼리오류! : %s\n", mysql_error(conn));
		return;
	}
	printf("책정보가 삭제되었습니다.\n");
}

void search_book(MYSQL* conn) {
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	book tmpBook = { 0, };
	char query[500] = { 0, };

	int i = 0;

	printf("검색 책이름 입력 > ");
	scanf("%[^\n]s", tmpBook.title); rewind(stdin);
	
	sprintf(query,
		"SELECT * FROM books_info WHERE title LIKE '%%%s%%' ", tmpBook.title);

	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "쿼리오류! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("출력할 데이터가 없습니다.\n");
		return;
	}

	print_header();
	num_fields = mysql_num_fields(result);
	while (row = mysql_fetch_row(result)) {
		lengths = mysql_fetch_lengths(result);
		for (i = 0; i < num_fields; i++)
		{
			printf("[%.*s] ", (int)lengths[i], row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

void print_header(void) {
	printf("[번호]  [책제목]  [저자]  [장르]  [출판일]  [페이지수]  [출판사]  [가격]\n");
	printf("=========================================================================\n");
}