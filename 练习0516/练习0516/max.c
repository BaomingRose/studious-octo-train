#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int max(int* data, int num) {
	int i;
	for (i = 0; i < num - 1; ++i) {
		//不创建临时变量交换
		if (data[i] > data[i + 1]) {
			data[i] ^= data[i + 1];
			data[i + 1] ^= data[i];
			data[i] ^= data[i + 1];
		}
	}
	return data[num - 1];
}
int main3() {
	int a[] = { 0 };
	int i,Max;
	printf("输入10个整数\n");
	for (i = 0; i < 10; ++i) {
		scanf("%d", &a[i]);
	}
	Max = max(a, 10);
	printf("最大的整数为%d\n", Max);
	system("pause");
	return 0;
}