#include <stdio.h>
#include < string.h>

int main(void) {
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(double));
	if (pd == NULL) {
		printf("# �޸𸮰� �����մϴ�. \n");
		exit(1); // ������������ ����

		pi = (int*)malloc(sizeof(double));
		if (pd == NULL) {
			printf("# �޸𸮰� �����մϴ�. \n");
			exit(1); // ������������ ����
		}

		*pi = 10;
		*pd = 3.141592;
		printf("%d\n", *pi);
		printf("%lf\n", *pd);
	}
}
