#include <stdio.h>
#include <string.h>

int main(void) {
//	char str[80] = "applejam";
//
//	printf("���ʹ��ڿ� : %s\n", str);
//	printf("���ڿ� �Է� > ");
//	scanf("%s", str); // ���ڿ��迭 & ����
//	printf("�Է¹��ڿ� : %s\n", str);

	char str1[80] = "cat";
	char str2[80];
	char* str3 = "Hello Wolrd";

	printf("%s\n", str3);

	// printf("%s %s\n", str1, str2);
	strpy(str2, str1); // string copy  ���ڿ����� �Լ�
	printf("% s : % s\n", str1, str2);

	printf("���ڿ� �Է� > ");
	gets(str2);
	puts("�Է� ���ڿ� :");
	puts(str2);
	printf("�Է� ���ڿ� : %s\n", str2);


}