#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi;
	int size = 5, count = 0, num, i;

	//calloc
	pi = calloc(size, sizeof(int)); // 20����Ʈ, 5�� int�� �迭 0���� �ʱ�ȭ

	/*for (i = 0; i < size; i++)
	{
		printf("%d\t", *(pi + i));
	}*/

	while (1)
	{
		printf("����� �Է��ϼ��� => ");
		scanf("%d", &num);
		if (num <= 0) break;

		// 5���� �Է��� ������ �þ�� ����� �÷��ִ�
		// realloc
		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, sizeof(int) * size); // +5 ����
		}
	
		pi[count] = num;
		count++
	}

	for (i = 0; i < size; i++) {
		printf("5d", pi[i]);
	}
	free(pi);
}