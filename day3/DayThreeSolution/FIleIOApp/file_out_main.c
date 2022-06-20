#include<stdio.h>
int main(void) {
	FILE* fp;
	char str[] = "banana";
	int i = 0;

	fp = fopen("C:\\Temp\\b.txt", "w");
	if (fp == NULL) {
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}
	qhile(str[i] != '\0') {
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);
}