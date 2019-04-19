#include<stdio.h>
//不使用（a + b） / 2这种方式，求两个数的平均值

int main() {
	int a = 6, b = 8, ave;
	ave = (a + b) >> 1;
	printf("%d \n", ave);
	system("pause");
	return 0;
}