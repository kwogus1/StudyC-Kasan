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

	printf("일반변수의 크기  --- \n");
	printf("sizeof char var %d\n", sizeof(ch));
	printf("sizeof int bar %d\n", sizeof(in));
	printf("sizeof double var %d\n", sizeof(db));

	printf("포인트변수의 크기  --- \n");
	printf("sizeof char pointer var %d\n", sizeof(ch)); // &, * 로 변경 테스트요
	printf("sizeof int pointer var %d\n", sizeof(pi)); 
	printf("sizeof double pointer var %d\n", sizeof(pd));
}
