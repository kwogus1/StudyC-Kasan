#define _CRT_SECURE_NO_WARNINGS
// 파일 읽기
#include <stdio.h>

int main(void) {
	FILE* fp; // 구조체(클래스에서 변수만 있는 것과 동일)
	int ch;

	fp = fopen("C:\\temp\\a.txt", "r"); // a.txt파일을 읽기모드 오픈
	if (fp = NULL) {
		printf("파일을 열지 못했습니다.\n");
		return 1; // == exit(1);
	}
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) { // End Of File의 약자
			break;
		}
		putchar(ch); // printf("%c", ch);
	}
	fclose(fp); // 파일 닫아줘야한다! 반드시!
}