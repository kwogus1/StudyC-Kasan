#define _CRT_SECURE_NO_WARNINGS
// ���� �б�
#include <stdio.h>

int main(void) {
	FILE* fp; // ����ü(Ŭ�������� ������ �ִ� �Ͱ� ����)
	int ch;

	fp = fopen("C:\\temp\\a.txt", "r"); // a.txt������ �б��� ����
	if (fp = NULL) {
		printf("������ ���� ���߽��ϴ�.\n");
		return 1; // == exit(1);
	}
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) { // End Of File�� ����
			break;
		}
		putchar(ch); // printf("%c", ch);
	}
	fclose(fp); // ���� �ݾ�����Ѵ�! �ݵ��!
}