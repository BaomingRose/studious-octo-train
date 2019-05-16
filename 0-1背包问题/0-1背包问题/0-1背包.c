#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main() {
	int data[1001] = { 0 };
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("请输入背包容量及物品个数：\n");
	scanf("%d%d", &size, &n);
	printf("请输入每个物品的重量及对应的价值：\n");
	for (i = 1; i <= n; i++) {
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++) {
		//完全背包只需要改这一句代码
		//for (j = weight[i]; j <= size; j++)
		for (j = size; j >= weight[i] ; j--) {
			data[j] = MAX(data[j], data[j - weight[i]] + value[i]);
		}
	}
	printf("背包最大价值为：%d\n", data[size]);
	system("pause");
	return 0;
}

int maintt() {
	int data[101][1001] = { 0 };
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("请输入背包容量及物品个数：\n");
	scanf("%d%d", &size, &n);
	printf("请输入每个物品的重量及对应的价值：\n");
	for (i = 1; i <= n; i++) {
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= size; j++) {
			if (j < weight[i]) {
				data[i][j] = data[i - 1][j];
			}
			else {
				data[i][j] = MAX(data[i - 1][j], data[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	printf("背包最大价值为：%d\n", data[n][size]);
	system("pause");
	return 0;
}