// int main(void)�� ��¥�� �ƴϴ�
#include <stdio.h>
#include < string.h>

// �ֿܼ��� C���α׷��Ҷ� ������ ���� ���� ��Ʈ������Ʈ
int main(int argc, char** argv) {
	int i;

	for (i = 0; i < argc; i++) {
		// printf("%d��° �μ� %s\n", i, argv[i]);
		if (i == 1) {
			if (argv[i] == "--version") {
				printf("DynamicAllocApp version 3.4\n");
			}
		}
	}
	system("pause");
}