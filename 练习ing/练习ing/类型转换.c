#include<stdio.h>

int main2() {
	int n = 1 / 2.0;
	printf("%d\n", n);
	char a = 0xff;
	a = (a << 1) >> 1;
	printf("%x\n", a);  //%x无符号十六进制整型
	//整型提升：short char运算先将其转换为整型再运算
	unsigned char b = 0xff;
	b = (a << 1) >> 1;
	printf("%x\n", b);
	//char运算先将其转换为整型运算，然后再转回字符型
	char x = 2, y = 3, z = 4;
	x = y + z;
	printf("%d\n", x);
	system("pause");
	return 0;
}