#include <stdio.h>

int main(void) {
	//int a;
	//int* pa; // a�� ����ų �����ͺ��� pa

	//pa = &a;// �߿�!!

	//printf("������ �Է��ϼ��� > ");
	//scanf("%d", pa); // ��! scanf("%d", &a)

	//printf("�Էµ� ������ %d �Դϴ�.\n", a);

	// �������� ������ ���
	int a = 10, b = 15, total;
	double avg;
	int* pa, * pb;
	// int* pt = &total; 
	int* pt;
	pt = &total;


	double* pg;
	pg = &avg;

	pa = &a; pb = &b;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("�� ������ �� : %d, %d\n", *pa, *pb);
	printf("�� ������ �� : %d\n", *pt);
	printf("�� ������ ��� : %.2lf\n", *pg);

}