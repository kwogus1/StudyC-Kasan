#include <stdio.h>

int main(void) {
	//int a;
	//double b;
	//char c;

	//printf("int�� ���� �ּ� > % u\n", &a);
	//printf("double�� ���� �ּ� > % u\n", &b);
	//printf("char�� ���� �ּ� > % u\n", &c);

	int a;
	int* pa;

	pa = &a; // ���� a�� �ּҸ� �����ͺ����� �Ҵ�
	*pa = 10;

	printf("�����ͷ� a�� ��� > %d\n", *pa);
	printf("������� a�� ��� > %d\n", a);

}