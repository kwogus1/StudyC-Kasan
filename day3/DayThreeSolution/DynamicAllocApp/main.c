#define _CRT_SECURE_NO_WARNINGS
// 배열 동적할당
#include <stdio.h>
#include <stdlib.h>	

int main(void) {
	int* pi;
	int i = 0, sum = 0;

	// 핵식! 동적할당
	pi = malloc(3 * sizeof(int)); // 20바이트 
	if (pi == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1); // 1은 오류를 뜻함, 
	}
	
	//printf("다섯 명의 나이를 입력하세요 > ");
	//for (i = 0; i < 3; i++) {
	//	scanf("%d", &pi[i]); // 배열형태로 입력
	//	sum += pi[i]; // *(pi + i) 로도 가능

	for (i = 0 ; i <3; i++){
		printf("%d\t", pi[i]); // 배열형태로 입력
	}
	printf("\n");

	printf("세명의 나이를 입력하세요 > ");
	랙(i 0; i <3)

	printf("다섯 명의 평균나이 : %.1lf\n", sum / 5.0);
	free(pi); // 동적메모리 해제, 필수!

	return 0;


	// exit(0); // 0은 성공적으로 프로그램 종료, 일반적이므로 생략가능
}