#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//ð������
void bubble(int* data, int num) {
	int i, j, tmp;
	for (i = 0; i < num; ++i) {
		for (j = 0; j < num - 1 - i; ++j) {
			if (data[j] > data[j + 1]) {
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
int main() {
	int size, num;
	int weight[20] = { 0 };
	int i, j, sum = 0, count = 0;
	printf("����������num ��������size:\n");
	scanf("%d %d", &num, &size);
	printf("��ֱ�����ÿ���˵�����:\n");
	for (i = 0; i < num; ++i) {
		scanf("%d", weight + 1);
	}
	bubble(weight, num);
	//����ָ��ֱ�ָ�����غ�����,���ص�ָ����ǰɨ��
	//����ǰ�����,���С����������+1,��������������ֱ��+1,ָ�������ǰ
	for (i = 0, j = num - 1; i <= j; j--) {
		if (weight[i] + weight[j] <= size) {
			++i;
		}
		++count;
	}
	printf("����Ҫ%d����\n", count);
	system("pause");
	return 0;
}

