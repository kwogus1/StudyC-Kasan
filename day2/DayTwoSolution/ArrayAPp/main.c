#include <stdio.h>

int main(void) {
	int arr[5] = { 0, }; // �迭 �ʱ�ȭ

	arr[0] = 90;
	arr[1] = 95;
	arr[2] = 80;
	printf("�׹�° �л� ���� �Է� > ");
	scanf("%d", arr[3]);

	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);
	printf("%d\n", arr[3]);
	printf("%d\n", arr[4]);

	int sum = 0;
	float average;

	for (int i = 0; i < 4; i++) {
		sum += arr[i];

	}
	average = sum / 5;

	printf("��� �л��� ���� ���� : %d\n", sum);
	printf("��� �л��� ������� : %.1lf\n", average);
}