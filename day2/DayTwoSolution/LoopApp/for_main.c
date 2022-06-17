/*
* for main.c
* 작성일 : 2022-06-22* 
*/


#include <stdio.h>

int main(void) {
	int a = 1;

	for (int i = 0; i < 3; i++) { // 초기값; 반복조건; 증감연산
		a = a * 2;
	}
	printf("a = %d\n", a);

}