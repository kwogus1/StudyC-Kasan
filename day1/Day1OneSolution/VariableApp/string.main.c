// 문자열 학습 main.c
#define _CRT_SECURE_NO_WARNINGS // strcpy, scanf등 사용할 때 전처리기

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

void main(void) {
	const double tax_rate = 0.12; //세율 초기화
	char fruit[7] = "햇사과"; // "apple"는 6자리 필요
	// char main[8] = "test"// 함수명이나 키워드는 변수명으로 X
	int ia = 0;

	printf("%d\n", ia);

	printf("%d\n", main);


	printf("%s\n", fruit); // 변수

	// float = "apple"; // 파이썬에서만 가능, C에서는 변경 불가능

	strcpy(fruit, "apple"); // C에서 문자열 변경
	printf("%s\n", fruit);

	// tax_rate = 0.15; // error 상수값은 변경불가
	




}