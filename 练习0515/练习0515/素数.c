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
	printf("������һ�������ж��Ƿ�Ϊ����\n");
	scanf("%d", &num);
	if (isPrime(num)) {
		printf("%d��������\n", num);
	}
	else {
		printf("%d����������\n", num);
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