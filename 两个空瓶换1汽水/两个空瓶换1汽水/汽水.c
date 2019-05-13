#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define P 1 //汽水的单价
#define N 2 //换一瓶汽水所需的空瓶个数
	//SodaConvert函数返回用空瓶换来的汽水个数
int sodaConvert(int x) {

	int ret = x / N;//空瓶兑换的汽水个数
	int empty = x / N + x % N;//兑换的汽水和剩下的空瓶个数之和
	if (empty > 1)
		return ret + sodaConvert(empty);
	else
		return ret;
	}
int main() {
	int price = 0;
	int n = 0;
	printf("请输入金额：");
	scanf("%d", &price);
	n = price / P;
	int bottle = n + sodaConvert(n);//最终喝到的汽水个数
	printf("共可以喝到%d瓶\n", bottle);
	system("pause");
	return 0;
}