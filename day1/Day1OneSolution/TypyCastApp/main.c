#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main(void) {
	printf("%lf\n", (10 + 10.5));
	printf("%lf\n", (double)10);
	printf("%d\n", (int)10.5); // ���� ���

	int a = 10;
	float fa = 3.4f;
	double da = 3.14;

	printf("int�� ���� ũ�� : %d\n", sizeof(a));
	printf("float�� ���� ũ�� : %d\n", sizeof(fa));
	printf("double�� ���� ũ�� : %d\n", sizeof(da));


	printf("char�� ���� ũ�� : %d\n", sizeof(char));
	printf("short�� ���� ũ�� : %d\n", sizeof(short));
	printf("int�� ���� ũ�� : %d\n", sizeof(int));
	printf("long�� ���� ũ�� : %d\n", sizeof(long));
	printf("long long�� ���� ũ�� : %d\n", sizeof(long long));
	printf("float�� ���� ũ�� : %d\n", sizeof(float));
	printf("double�� ���� ũ�� : %d\n", sizeof(double));
	printf("long double�� ���� ũ�� : %d\n", sizeof(long double));

	int b = 20, res;

	res = (a > b) ? a : b;
	printf("ū �� : %d\n", res);

	// ��Ʈ ������
	int c = 10; // 00000000 00000000 00000000 00001010
	int d = 12; // 00000000 00000000 00000000 00001100

	printf("c & d : %d\n", c & d); // 8, ��� 1�� ��쿡�� 1
	printf("c ^ d : %d\n", c ^ d); // 14, ���� �ٸ� ��쿡�� 1
	printf("c | d : %d\n", c | d); // 6, �ϳ��� ���̸� 1
	printf("~c : %d\n", ~c); // 0�� 1�� 1�� 0����
	printf("c << 1 : %d\n", c << 1); // shift ���� 16 + 4
	printf("c >> 2 : %d\n", c >> 2); // 32 + 8 = 40


}
