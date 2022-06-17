#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	// printf("Hello World");
	int res = 1;
	int i = 1;
	while (i < 10) {
		res = res * i;
		i++;
	}

	int a = 1;

	while (a < 10){
		a = a * 2;


	}
	int res = 1;
	int i = 1;
	while (i < 10) {
		if (i == 5) break;

		res = res * i;
		i++;

	printf("%d\n", a);
	printf("%d\n", i);

}

}