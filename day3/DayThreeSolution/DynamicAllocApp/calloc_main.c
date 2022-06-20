#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* pi;
	int size = 5, count = 0, num, i;

	//calloc
	pi = calloc(size, sizeof(int)); // 20바이트, 5의 int형 배열 0으로 초기화

	/*for (i = 0; i < size; i++)
	{
		printf("%d\t", *(pi + i));
	}*/

	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;

		// 5보다 입력할 갯수가 늘어나면 사이즈를 늘려주는
		// realloc
		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, sizeof(int) * size); // +5 증가
		}
	
		pi[count] = num;
		count++
	}

	for (i = 0; i < size; i++) {
		printf("5d", pi[i]);
	}
	free(pi);
}