#include <stdio.h>

// �ռ�����
int sum(int, int); // int x, int y���� x, y �������� // �Լ� ���� ���� �� sum ���� ���� �ʾҴٰ� ��

// �����Լ�
int main(void) {
	printf("�ջ��ϱ�\n");

	int total = sum(100, 34);
	printf("�հ�, %d\n", total);

}

// �Լ�����
int sum(int x, int y) {
	int res;

	res = x = y;
	return res;

}