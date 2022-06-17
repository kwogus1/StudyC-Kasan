#include <stdio.h>

// 합수정의
int sum(int, int); // int x, int y에서 x, y 생략가능 // 함수 정의 생략 시 sum 정희 되지 않았다고 뜸

// 메인함수
int main(void) {
	printf("합산하기\n");

	int total = sum(100, 34);
	printf("합계, %d\n", total);

}

// 함수선언
int sum(int x, int y) {
	int res;

	res = x = y;
	return res;

}