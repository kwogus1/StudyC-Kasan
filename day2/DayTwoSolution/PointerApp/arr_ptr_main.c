#include <stdio.h>

void print_ary(int*, int);

int main(void) {
	int ary1[5] = { 10, 20, 30, 40, 50 }; // ũ��5 �迭
	int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 }; // ũ��7 �迭

	// printf("%d", sizeof(ary1));
	// printf("%d", sizeof(ary1[0])); // int 4
	int size = sizeof(ary1) / sizeof(ary1[0]); // ary1 �迭ũ��
	print_ary(ary1, size);
	size = sizeof(ary2) / sizeof(ary2[0]);
	print_ary(ary2, size);
}

void print_ary(int* pa, int size) { // �����͹޾Ƽ�
	for (int i = 0; i < size; i++) {
		printf("%d\t", pa[i]); // �迭 ���
	}
	printf("\n");
}