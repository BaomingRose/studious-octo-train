#include<stdio.h>
//一个数组中均有两个相同的数，只有一个没有成对，找出这个没有成对的（找单身狗）
int findSingle(int *a, int len) {
	int find = 0;
	for (int i = 0; i < len; ++i) {
		find ^= a[i];
	}
	return find;
}

int main3() {
	int a[] = { 3,4,5,7,8,8,6,5,7,4,3 };
	printf("%d\n", findSingle(a, 11));
	//拓展；找到两个单身狗
	int b[10] = { 1,5,2,3,4,1,6,3,4,2 };
	int i;
	int sum = 0;
	for(i = 0; i < 9; i ++)
	{
		sum ^=a[i];
	}
	int pos;
	for(i = 0; i < 32; i ++)
	{
		if(sum&1 <<i)
		{
			pos = i;
			break;
		}
	}

	int num1 = 0,num2 = 0;
	for(i = 0; i < 10; i ++)
	{
		if(a[i]&1 << pos)
		{
			num1 ^= a[i];
		}
		else
		{
			num2 ^= a[i];
		}
	}
	printf("%d %d\n",num1,num2);
	system("pause");
	return 0;
}