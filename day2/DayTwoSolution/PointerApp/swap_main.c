// �����͸� �ϴ� ����
#include <stdio.h>

void swap(int*, int*);

int main(void) {
	int a = 33, b = 98;

	printf("������ a = %d, b = %d\n", a, b);
	swap(&a, &b); // a�� b�� �ּҸ� �Ѱ��༭ 
	printf("������ a = %d, b = %d\n", a, b);

}

void swap(int *x, int *y) {
	int temp; // ���� 0

	temp = *y; // 98
	*y = *x;  // 33
	*x = temp;

}