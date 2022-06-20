// int main(void)게 진짜가 아니다
#include <stdio.h>
#include < string.h>

// 콘솔에서 C프로그램할때 실제적 쓰는 메인 엔트리포인트
int main(int argc, char** argv) {
	int i;

	for (i = 0; i < argc; i++) {
		// printf("%d번째 인수 %s\n", i, argv[i]);
		if (i == 1) {
			if (argv[i] == "--version") {
				printf("DynamicAllocApp version 3.4\n");
			}
		}
	}
	system("pause");
}