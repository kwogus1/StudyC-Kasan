#include <stdio.h>

int main(void) {
	// escape charater 사용법
	printf("be Happy!!\n");
	printf("12345678901234567890\n");
	printf("My\tFriend\n");
	printf("Goot\bd\tchance\n");
	printf("be Happy!!\n");
	printf("Cow\r\W\a\n");


	// 정수와 실수 출력
	printf("%d\n", 10);
	printf("%lf\n", 3.141592);
	printf("%d\n", 3.141592); // -5599XX 이상한 값 출력
	printf("%.1lf\n", 3.141592); // 소수점 첫째자리만 출력
	printf("%.10lf\n", 3.1);
	printf("%.10lf\n", 3);
	printf("%d와 %d의 합은 %d입니다.\n", 10, 10, 20);
	printf("%.1lf - %.1lf = % 1lf\n", 3.4, 1.2, 3.4 - 1.2);

	// 진수 표현
	printf("%d\t", 12); // 10진수 12
	printf("%d\t", 0x14); // 8진수 12
	printf("%d\n", 0xC); // 16진수 12, c C와 동일

	// 지수 표현
	printf("%.2lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le.2lf\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	// 문자와 문자열 표현
	printf("%c\n", 'A'); // 문자 character
	printf("%s\n", "A"); // 문자열 string
	printf("%c는 %s 입니다.\n", '1', "first");

	return 0;
}