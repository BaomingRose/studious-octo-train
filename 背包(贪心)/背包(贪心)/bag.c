#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//冒泡排序
void bubble(int* data, int num) {
	int i, j, tmp;
	for (i = 0; i < num; ++i) {
		for (j = 0; j < num - 1 - i; ++j) {
			if (data[j] > data[j + 1]) {
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
int main() {
	int weight, num;
	int data[20] = { 0 };
	int i, sum = 0;
	printf("请输入物品总数num 背包容量weight:\n");
	scanf("%d %d", &num, &weight);
	printf("请分别输入物品重量:\n");
	for (i = 0; i < num; ++i) {
		scanf("%d", data + i);
	}
	bubble(data, num);
	//从最小的依次装背包知道装不下为止
	//预测下一个物品会不会装下
	//考虑到所有物品全部装满还有空间
	for (i = 0; sum + data[i] < weight && i < num; ++i) {
		sum += data[i];
	}
	printf("该背包最多可装%d个物品\n", i);
	system("pause");
	return 0;
}