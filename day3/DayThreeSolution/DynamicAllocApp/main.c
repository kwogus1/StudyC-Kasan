#define _CRT_SECURE_NO_WARNINGS
// �迭 �����Ҵ�
#include <stdio.h>
#include <stdlib.h>	

int main(void) {
	int* pi;
	int i = 0, sum = 0;

	// �ٽ�! �����Ҵ�
	pi = malloc(3 * sizeof(int)); // 20����Ʈ 
	if (pi == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1); // 1�� ������ ����, 
	}
	
	//printf("�ټ� ���� ���̸� �Է��ϼ��� > ");
	//for (i = 0; i < 3; i++) {
	//	scanf("%d", &pi[i]); // �迭���·� �Է�
	//	sum += pi[i]; // *(pi + i) �ε� ����

	for (i = 0 ; i <3; i++){
		printf("%d\t", pi[i]); // �迭���·� �Է�
	}
	printf("\n");

	printf("������ ���̸� �Է��ϼ��� > ");
	��(i 0; i <3)

	printf("�ټ� ���� ��ճ��� : %.1lf\n", sum / 5.0);
	free(pi); // �����޸� ����, �ʼ�!

	return 0;


	// exit(0); // 0�� ���������� ���α׷� ����, �Ϲ����̹Ƿ� ��������
}