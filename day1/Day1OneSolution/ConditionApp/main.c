#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void) {
	//int a = 10;

	////int a;
	////scanf("%d", &a);
	//// if�� ����! 
	//
	//if (a > 10) {
	//	printf("a�� 10���� ŭ");
	//}
	//else if (a == 10) {
	//	printf("a �� 10");
	//}
	//else {
	//	printf("a �� 10���� ����");
	
	//}

	char grade;

	printf("������ �Է��ϼ��� > ");
	scanf("%c", &grade);

	switch (grade)
	{
	case 'A':
		printf("����ϳ׿�!");
		break; // break ���� A ���� B ���� �Ѵ� ���
	case 'B':
		printf("���� ���ϼ̽��ϴ�!");
		break;
	case 'C':
		printf("���߽��ϴ�.");
		break;
	case 'D':
		printf("�ܿ� ����߱���.");
		break;
	case 'F':
		printf("���� �б⿡ �� ����~");
		break;
	default: // �ټ����� case�� �ƴ� ���
		printf("������ ����� �Է��ϼ���!");
		break;

	}

	/*if (grade == 'A') {
		printf("����ϳ׿�!");
	}
	else if (grade == 'B') {
		printf("���� ���ϼ̽��ϴ�!");
	}
	else if (grade == 'C') {
		printf("���߽��ϴ�.");
	}
	else if (grade == 'D') {
		printf("�ܿ� ����߱���.");
	}
	else if (grade == 'F') {
		printf("���� �б⿡ �� ����~");
	}
	else if {
		printf("������ ����� �Է��ϼ���!");
	}
	*/
	
}