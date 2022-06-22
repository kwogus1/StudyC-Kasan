#define _CRT_SECURE_NO_WARNINGS
#pragma comment (lib, "libmysql.lib")

#include <winsock.h>
#include <windows.h>
#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

// MySQL ���� ����(���� �ʿ�!)
#define mysqlip "127.0.0.1"
#define port 3306
#define loginusername "bms"
#define loginpassword "1234"
#define mysqlname "bms"

#define TITLE_LENGTH 100
#define GENRE_LENGTH 50

// å���� ���� ����ü bookInfo
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

// �Լ� ��������
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
	int input = 0; // �޴� �Է°�

	conn = mysql_init(NULL);
	connect_db(conn);

	// ���ѷ���
	while (1) {
		system("cls"); // ȭ�� Ŭ����
		printf("�������� ���α׷�(v2)\n");
		printf("1. ������ȸ\n");
		printf("2. �����Է�\n");
		printf("3. ��������\n");
		printf("4. �����˻�\n");
		printf("5. ��������\n");
		printf("6. ���α׷� ����\n");
		printf("�Է� > ");
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
				printf("���α׷� ����");
				exit(0);
	
		}
	}
	return;
}
void connect_db(MYSQL* conn) {
	
	mysql_real_connect(conn, mysqlip, loginusername, loginpassword, mysqlname, port, NULL, 0);

	if (conn == NULL) {
		fprintf(stderr, "�������! : %s\n", mysql_error(conn));
		return;
	}

	printf("���Ἲ��!\n");
	printf("�������� %s\n", conn->server_version);
}
void close_db(MYSQL* conn) {
	mysql_close(conn);
	printf("��������\n");
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
		fprintf(stderr, "��������! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("����� �����Ͱ� �����ϴ�.\n");
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
	//book insBook = { 0, }; // ����ü ����/�ʱ�ȭ
	int i, y = 0;
	char query[500] = { 0, };
	book tmpBook = { 0, };

	printf("å�̸� �Է� > ");
	scanf("%[^\n]s", tmpBook.title);
	rewind(stdin); // ǥ���Է� ���÷���

	printf("���ڸ� �Է� > ");
	scanf("%[^\n]s", tmpBook.writer);
	rewind(stdin);

	printf("�帣 �Է� > ");
	scanf("%[^\n]s", tmpBook.genre);
	rewind(stdin); 

	printf("������ �Է�(ex. 2022-06-01) > ");
	scanf("%s", tmpBook.release_date);
	rewind(stdin);

	printf("�������� �Է�(ex. 300) > ");
	scanf("%d", &tmpBook.pages);
	rewind(stdin);

	printf("���ǻ� �Է� > ");
	scanf("%[^\n]s", tmpBook.company);
	rewind(stdin);

	printf("���� �Է�(ex. 15000) > ");
	scanf("%d", &tmpBook.price);
	rewind(stdin);

	sprintf(query, " INSERT INTO books_info "
		           " (title, writer, genre, release_date, pages, company, price) "
		           " VALUES "
		           " ('%s', '%s', '%s', '%s', '%d', '%s', '%d') ",
		tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.release_date,
		tmpBook.pages, tmpBook.company, tmpBook.price);
	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "�Է¿��� : %s\n", mysql_error(conn));
		return;
	}
	printf("å������ �ԷµǾ����ϴ�.\n");
}

// å���� �����Լ�
void update_book(MYSQL* conn) {
	int i = 0;
	MYSQL_RES* result;
	MYSQL_ROW row;
	int query_stat;
	unsigned int num_fields;
	unsigned long* lengths;
	char query[500] = { 0, };

	book tmpBook = { 0, };

	printf("������ å ��ȣ �Է� > ");
	scanf("%d", &tmpBook.id); rewind(stdin);

	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "��������! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("������ �����Ͱ� �����ϴ�.\n");
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

	printf("����å�̸� �Է� > ");
	scanf("%[^\n]s", tmpBook.title); rewind(stdin); // ǥ���Է� ���÷���

	printf("�������ڸ� �Է� > ");
	scanf("%[^\n]s", tmpBook.writer); rewind(stdin);

	printf("�����帣 �Է� > ");
	scanf("%[^\n]s", tmpBook.genre); rewind(stdin);

	sprintf(query,
		" UPDATE books_info SET "
		"        title = '%s'  "
		"	   , writer = '%s' "
		"	   , genre = '%s'  "
		"  WHERE id = %d ",
		tmpBook.title, tmpBook.writer, tmpBook.genre, tmpBook.id);

	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "������������! : %s\n", mysql_error(conn));
		return;
	}
	printf("å������ �����Ǿ����ϴ�.\n");
}

// å���� ���� �Լ�
void delete_book(MYSQL* conn) {
	MYSQL_RES* result;
	int query_stat;
	char query[500] = { 0, };

	book tmpBook = { 0, };

	printf("������ å ��ȣ �Է� > ");
	scanf("%d", &tmpBook.id); rewind(stdin);

	sprintf(query, "SELECT * FROM books_info WHERE id = %d", tmpBook.id);
	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "��������! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}
	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("������ �����Ͱ� �����ϴ�.\n");
		return;
	}

	sprintf(query, 
		"DELETE FROM books_info WHERE id = %d", tmpBook.id);

	if (mysql_query(conn, query) != 0) {
		fprintf(stderr, "������������! : %s\n", mysql_error(conn));
		return;
	}
	printf("å������ �����Ǿ����ϴ�.\n");
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

	printf("�˻� å�̸� �Է� > ");
	scanf("%[^\n]s", tmpBook.title); rewind(stdin);
	
	sprintf(query,
		"SELECT * FROM books_info WHERE title LIKE '%%%s%%' ", tmpBook.title);

	query_stat = mysql_query(conn, query);
	if (query_stat != 0) {
		fprintf(stderr, "��������! : %s\n", mysql_error(conn));
		mysql_close(conn);
		return;
	}

	result = mysql_store_result(conn);
	if (result->row_count == 0) {
		printf("����� �����Ͱ� �����ϴ�.\n");
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
	printf("[��ȣ]  [å����]  [����]  [�帣]  [������]  [��������]  [���ǻ�]  [����]\n");
	printf("=========================================================================\n");
}