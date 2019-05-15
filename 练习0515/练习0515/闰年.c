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
	printf("请输入一个年份判断是否为闰年\n");
	scanf("%d", &year);
	if (isLeapYear(year)) {
		printf("%d是闰年\n", year);
	}
	else {
		printf("%d是平年\n", year);
	}
	system("pause");
	return 0;
}