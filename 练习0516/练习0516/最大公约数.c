#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int maxCommonDivisor(int a, int b) {
	int i, min, max;
	min = a < b ? a : b;
	for (i = 1; i <= min; ++i) {
		if (a % i == 0 && b % i == 0) {
			max = i;
		}
	}
	return max;
}
//շת�����
int maxCommonDivisor2(int a, int b) {
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main() {
	printf("��������������\n");
	int a, b, max1, max2;
	scanf("%d%d", &a, &b);
	max1 = maxCommonDivisor(a, b);
	printf("���Լ��Ϊ��%d\n", max1);
	max2 = maxCommonDivisor2(a, b);
	printf("���Լ��Ϊ��%d\n", max2);
	system("pause");
	return 0;
}