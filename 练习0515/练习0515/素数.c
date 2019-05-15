#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int isPrime(int num) {
	int i = 0;
	for (i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main1() {
	/*int num;
	printf("请输入一个整数判断是否为素数\n");
	scanf("%d", &num);
	if (isPrime(num)) {
		printf("%d是素数！\n", num);
	}
	else {
		printf("%d不是素数！\n", num);
	}*/
	int i;
	for (i = 0; i <= 10000; ++i) {
		if (isPrime(i)) {
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}