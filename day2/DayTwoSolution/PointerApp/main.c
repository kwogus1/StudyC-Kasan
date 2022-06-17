#include <stdio.h>

int main(void) {
	//int a;
	//double b;
	//char c;

	//printf("int형 변수 주소 > % u\n", &a);
	//printf("double형 변수 주소 > % u\n", &b);
	//printf("char형 변수 주소 > % u\n", &c);

	int a;
	int* pa;

	pa = &a; // 변수 a의 주소를 포인터변수에 할당
	*pa = 10;

	printf("포인터로 a값 출력 > %d\n", *pa);
	printf("변수명로 a값 출력 > %d\n", a);

}