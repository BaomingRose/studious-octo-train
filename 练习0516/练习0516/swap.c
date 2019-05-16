#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int* a, int * b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main1() {
	int a, b;
	printf("a:\n");
	scanf("%d", &a);
	printf("b:\n");
	scanf("%d", &b);
	swap(&a, &b);
	printf("swap:a:%d,b:%d\n", a, b);
	system("pause");
	return 0;
}