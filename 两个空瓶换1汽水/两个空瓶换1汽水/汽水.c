#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define P 1 //��ˮ�ĵ���
#define N 2 //��һƿ��ˮ����Ŀ�ƿ����
	//SodaConvert���������ÿ�ƿ��������ˮ����
int sodaConvert(int x) {

	int ret = x / N;//��ƿ�һ�����ˮ����
	int empty = x / N + x % N;//�һ�����ˮ��ʣ�µĿ�ƿ����֮��
	if (empty > 1)
		return ret + sodaConvert(empty);
	else
		return ret;
	}
int main() {
	int price = 0;
	int n = 0;
	printf("�������");
	scanf("%d", &price);
	n = price / P;
	int bottle = n + sodaConvert(n);//���պȵ�����ˮ����
	printf("�����Ժȵ�%dƿ\n", bottle);
	system("pause");
	return 0;
}