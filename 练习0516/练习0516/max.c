#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int max(int* data, int num) {
	int i;
	for (i = 0; i < num - 1; ++i) {
		//��������ʱ��������
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
	printf("����10������\n");
	for (i = 0; i < 10; ++i) {
		scanf("%d", &a[i]);
	}
	Max = max(a, 10);
	printf("��������Ϊ%d\n", Max);
	system("pause");
	return 0;
}