#pragma comment (lib, "libmysql.lib") // MySQL 라이브러리 사용

#include <stdio.h>
#include <stdint.h> // 기본

#include <WinSock2.h> // DB용, 네트워크 통신
#include <my_global.h>
#include <mysql.h>

int main() {
	// printf("Hello MySQL!");
	printf("MySQL info = %s\n", mysql_get_client_info());

	system("pause");
	return EXIT_SUCCESS;
}