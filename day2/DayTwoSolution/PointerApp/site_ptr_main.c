#include <stdio.h>

int main(void) {
	char ch;
	int in;
	double db;
	char* pc;
	pc = &ch;
	int* pi;
	pi = &in;
	double* pd;
	pd = &db;

	printf("�Ϲݺ����� ũ��  --- \n");
	printf("sizeof char var %d\n", sizeof(ch));
	printf("sizeof int bar %d\n", sizeof(in));
	printf("sizeof double var %d\n", sizeof(db));

	printf("����Ʈ������ ũ��  --- \n");
	printf("sizeof char pointer var %d\n", sizeof(ch)); // &, * �� ���� �׽�Ʈ��
	printf("sizeof int pointer var %d\n", sizeof(pi)); 
	printf("sizeof double pointer var %d\n", sizeof(pd));
}
