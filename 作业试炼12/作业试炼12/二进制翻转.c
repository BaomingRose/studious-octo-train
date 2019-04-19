#include<stdio.h>
//unsigned int reverse_bit(unsigned int value)
//这个函数的返回值value的二进制位模式从左到右翻转后的值
unsigned int round(unsigned n)
{
	int i;
	unsigned int tmp, sum = 0;

	for (i = 0; i < 32; i++, n /= 2)
	{
		tmp = n % 2;
		sum = sum * 2 + tmp;
	}
	return sum;
}

int main1()
{
	printf("%u\n", round(25));
	/*
	int n = 15;
	int i, tmp, sum = 0, sn = 2;
	for (i = n; i; i /= sn)
	{
		tmp = i % sn;
		sum = sum * sn + tmp;
	}
	*/
	system("pause");
	return 0;
}