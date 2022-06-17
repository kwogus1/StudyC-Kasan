#include <stdio.h>
#include < string.h>

int main(void) {
	char str[80];

	// str = "apple";
	strcpy(str, "apple");
	printf("%s\n", str);

	// str = "안녕하세요~";
	strcpy(str, "안녕하세요~");
	printf("%s\n", str);

	//printf("이름을 입력하세요 > ");
	//gets(str);
	//printf("이름은 %s\n", str);

	// 문자열을 원하는 길이만큼 잘라서 복사가능
	// substring은 따로 구현 필요
	char str2[20] = "mango tree";
	strncpy(str2, "apple-pie", 5); // 5를 6으로 테스트
	strncpy(str2, "apple-pie", 6);
	printf("%s\n", str2);

	// 문자열 결합 함수
	char str3[80] = "straw"; // 빨대
	strcat(str3, "berry");
	printf("%s\n", str3);
	strncat(str3, "piece", 3);
	printf("%s\n", str3);

	// 문자열 길이리턴 함수
	printf("%d\n", strlen(str3));

	// 문자열 비교 함수
	char str5[80] = "pear"; // 112, 101, 97, 114
	char str6[80] = "peach"; // 112, 101, 97, 99, 104

	printf("사전에 나중에 나오는 과일이름 > ");
	if (strcmp(str5, str6) > 0)
		printf("%s\n", str5);
	else
		printf("%s\n", str6);

	// printf("%d\n", 'h')

	if (strncmp(str5, str6,3) > 0)
		printf("%s\n", str5);
	else
		printf("%s\n", str6);


}