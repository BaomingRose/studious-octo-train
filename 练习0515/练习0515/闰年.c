#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100)) {
		return 1;
	}
	return 0;
}
int main() {
	int year = 0;
	printf("������һ������ж��Ƿ�Ϊ����\n");
	scanf("%d", &year);
	if (isLeapYear(year)) {
		printf("%d������\n", year);
	}
	else {
		printf("%d��ƽ��\n", year);
	}
	system("pause");
	return 0;
}