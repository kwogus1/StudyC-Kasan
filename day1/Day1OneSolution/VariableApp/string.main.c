// ���ڿ� �н� main.c
#define _CRT_SECURE_NO_WARNINGS // strcpy, scanf�� ����� �� ��ó����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

void main(void) {
	const double tax_rate = 0.12; //���� �ʱ�ȭ
	char fruit[7] = "�޻��"; // "apple"�� 6�ڸ� �ʿ�
	// char main[8] = "test"// �Լ����̳� Ű����� ���������� X
	int ia = 0;

	printf("%d\n", ia);

	printf("%d\n", main);


	printf("%s\n", fruit); // ����

	// float = "apple"; // ���̽㿡���� ����, C������ ���� �Ұ���

	strcpy(fruit, "apple"); // C���� ���ڿ� ����
	printf("%s\n", fruit);

	// tax_rate = 0.15; // error ������� ����Ұ�
	




}