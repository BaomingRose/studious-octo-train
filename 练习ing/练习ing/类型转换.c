#include<stdio.h>

int main2() {
	int n = 1 / 2.0;
	printf("%d\n", n);
	char a = 0xff;
	a = (a << 1) >> 1;
	printf("%x\n", a);  //%x�޷���ʮ����������
	//����������short char�����Ƚ���ת��Ϊ����������
	unsigned char b = 0xff;
	b = (a << 1) >> 1;
	printf("%x\n", b);
	//char�����Ƚ���ת��Ϊ�������㣬Ȼ����ת���ַ���
	char x = 2, y = 3, z = 4;
	x = y + z;
	printf("%d\n", x);
	system("pause");
	return 0;
}