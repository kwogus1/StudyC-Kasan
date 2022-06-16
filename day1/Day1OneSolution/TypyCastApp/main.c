#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void) {
	printf("%lf\n", (10 + 10.5));
	printf("%lf\n", (double)10);
	printf("%d\n", (int)10.5); // 주의 요망

	int a = 10;
	float fa = 3.4f;
	double da = 3.14;

	printf("int형 변수 크기 : %d\n", sizeof(a));
	printf("float형 변수 크기 : %d\n", sizeof(fa));
	printf("double형 변수 크기 : %d\n", sizeof(da));


	printf("char형 변수 크기 : %d\n", sizeof(char));
	printf("short형 변수 크기 : %d\n", sizeof(short));
	printf("int형 변수 크기 : %d\n", sizeof(int));
	printf("long형 변수 크기 : %d\n", sizeof(long));
	printf("long long형 변수 크기 : %d\n", sizeof(long long));
	printf("float형 변수 크기 : %d\n", sizeof(float));
	printf("double형 변수 크기 : %d\n", sizeof(double));
	printf("long double형 변수 크기 : %d\n", sizeof(long double));

	int b = 20, res;

	res = (a > b) ? a : b;
	printf("큰 값 : %d\n", res);

	// 비트 연산자
	int c = 10; // 00000000 00000000 00000000 00001010
	int d = 12; // 00000000 00000000 00000000 00001100

	printf("c & d : %d\n", c & d); // 8, 모두 1인 경우에만 1
	printf("c ^ d : %d\n", c ^ d); // 14, 서로 다른 경우에만 1
	printf("c | d : %d\n", c | d); // 6, 하나라도 참이면 1
	printf("~c : %d\n", ~c); // 0은 1로 1은 0으로
	printf("c << 1 : %d\n", c << 1); // shift 연산 16 + 4
	printf("c >> 2 : %d\n", c >> 2); // 32 + 8 = 40


}
