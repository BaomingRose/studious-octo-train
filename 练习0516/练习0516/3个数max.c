#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//冒泡排序
void bubble(int* data, int n) {
	int i, j, tmp;
	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
int main4() {
	printf("输入三个整数\n");
	int i,data[3];
	for (i = 0; i < 3; ++i) {
		scanf("%d", &data[i]);
	}
	bubble(data, 3);
	for (i = 2; i >= 0; --i) {
		printf("%d ", data[i]);
	}
	system("pause");
	return 0;
}