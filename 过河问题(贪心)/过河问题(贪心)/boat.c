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
	int size, num;
	int weight[20] = { 0 };
	int i, j, sum = 0, count = 0;
	printf("请输入人数num 船的容量size:\n");
	scanf("%d %d", &num, &size);
	printf("请分别输入每个人的重量:\n");
	for (i = 0; i < num; ++i) {
		scanf("%d", weight + 1);
	}
	bubble(weight, num);
	//两个指针分别指向最重和最轻,最重的指针向前扫描
	//与最前的相加,如果小于容量则船数+1,大于容量则容量直接+1,指针继续向前
	for (i = 0, j = num - 1; i <= j; j--) {
		if (weight[i] + weight[j] <= size) {
			++i;
		}
		++count;
	}
	printf("共需要%d条船\n", count);
	system("pause");
	return 0;
}

