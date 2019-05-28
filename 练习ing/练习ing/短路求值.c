#include<stdio.h>
//360面试题
//短路求值
//对于逻辑与操作，如果左侧的表达式为 0，那么右侧不在计算
//对于逻辑或操作，如果左侧的表达式为 1，那么右侧不在计算
int main1() {
	//后置++等价代码
	/*int i;
	int tmp = i;
	i += 1;
	return tmp;*/
	//前置++等价代码
	/*int i;
	i += 1;
	return i;*/
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && c++ && d++;
	i = a++ || ++b || c++ || d++;
	printf("a = %d\nb = %d\nc = %d\nd = %d\ni = %d\n", a, b, c, d, i);
	system("pause");
	return 0;
}