#include <stdio.h>

int main(void) {
	// escape charater ����
	printf("be Happy!!\n");
	printf("12345678901234567890\n");
	printf("My\tFriend\n");
	printf("Goot\bd\tchance\n");
	printf("be Happy!!\n");
	printf("Cow\r\W\a\n");


	// ������ �Ǽ� ���
	printf("%d\n", 10);
	printf("%lf\n", 3.141592);
	printf("%d\n", 3.141592); // -5599XX �̻��� �� ���
	printf("%.1lf\n", 3.141592); // �Ҽ��� ù°�ڸ��� ���
	printf("%.10lf\n", 3.1);
	printf("%.10lf\n", 3);
	printf("%d�� %d�� ���� %d�Դϴ�.\n", 10, 10, 20);
	printf("%.1lf - %.1lf = % 1lf\n", 3.4, 1.2, 3.4 - 1.2);

	// ���� ǥ��
	printf("%d\t", 12); // 10���� 12
	printf("%d\t", 0x14); // 8���� 12
	printf("%d\n", 0xC); // 16���� 12, c C�� ����

	// ���� ǥ��
	printf("%.2lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le.2lf\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	// ���ڿ� ���ڿ� ǥ��
	printf("%c\n", 'A'); // ���� character
	printf("%s\n", "A"); // ���ڿ� string
	printf("%c�� %s �Դϴ�.\n", '1', "first");

	return 0;
}