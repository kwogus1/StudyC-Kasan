#include <stdio.h>
#include <string.h>

int main(void) {
//	char str[80] = "applejam";
//
//	printf("최초문자열 : %s\n", str);
//	printf("문자열 입력 > ");
//	scanf("%s", str); // 문자열배열 & 생략
//	printf("입력문자열 : %s\n", str);

	char str1[80] = "cat";
	char str2[80];
	char* str3 = "Hello Wolrd";

	printf("%s\n", str3);

	// printf("%s %s\n", str1, str2);
	strpy(str2, str1); // string copy  문자열복사 함수
	printf("% s : % s\n", str1, str2);

	printf("문자열 입력 > ");
	gets(str2);
	puts("입력 문자열 :");
	puts(str2);
	printf("입력 문자열 : %s\n", str2);


}