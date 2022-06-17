#include <stdio.h>
#include < string.h>

int main(void) {
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(double));
	if (pd == NULL) {
		printf("# 메모리가 부족합니다. \n");
		exit(1); // 비정상적으로 종료

		pi = (int*)malloc(sizeof(double));
		if (pd == NULL) {
			printf("# 메모리가 부족합니다. \n");
			exit(1); // 비정상적으로 종료
		}

		*pi = 10;
		*pd = 3.141592;
		printf("%d\n", *pi);
		printf("%lf\n", *pd);
	}
}
