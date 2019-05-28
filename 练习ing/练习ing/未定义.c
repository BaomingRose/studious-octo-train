#include<stdio.h>

int main3() {
	int i = 1;
	//12 = 4 + 4 + 4
	//先++ ++ ++ 再 + +
	//求值顺序不同操作系统不同
	//这是未定义行为
	//同一个表达式中，对同一个变量的修改顺序不能确定
	//表达式的求值顺序是和编译器实现相关的
	int ret = ++i + ++i + ++i;
	printf("%d\n", ret);
	system("pause");
	return 0;
}