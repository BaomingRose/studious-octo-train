#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap2(int* a, int* b) {
	*a = *a ^*b;
	*b = *a ^*b;
	*a = *a ^*b;
}
int main2() {
	int a, b;
	printf("a:\n");
	scanf("%d", &a);
	printf("b:\n");
	scanf("%d", &b);
	swap(&a, &b);
	printf("swap:a:%d,b:%d\n", a, b);
	//另一种补创建临时变量交换
	a = a + b;
	b = a - b;
	a = a - b;
	printf("swap:a:%d,b:%d\n", a, b);
	system("pause");
	return 0;
}