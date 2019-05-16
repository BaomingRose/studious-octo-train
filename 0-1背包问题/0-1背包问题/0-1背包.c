#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main() {
	int data[1001] = { 0 };
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("�����뱳����������Ʒ������\n");
	scanf("%d%d", &size, &n);
	printf("������ÿ����Ʒ����������Ӧ�ļ�ֵ��\n");
	for (i = 1; i <= n; i++) {
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++) {
		//��ȫ����ֻ��Ҫ����һ�����
		//for (j = weight[i]; j <= size; j++)
		for (j = size; j >= weight[i] ; j--) {
			data[j] = MAX(data[j], data[j - weight[i]] + value[i]);
		}
	}
	printf("��������ֵΪ��%d\n", data[size]);
	system("pause");
	return 0;
}

int maintt() {
	int data[101][1001] = { 0 };
	int size, n;
	int weight[101] = { 0 };
	int value[101] = { 0 };
	int i, j;
	printf("�����뱳����������Ʒ������\n");
	scanf("%d%d", &size, &n);
	printf("������ÿ����Ʒ����������Ӧ�ļ�ֵ��\n");
	for (i = 1; i <= n; i++) {
		scanf("%d%d", weight + i, value + i);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= size; j++) {
			if (j < weight[i]) {
				data[i][j] = data[i - 1][j];
			}
			else {
				data[i][j] = MAX(data[i - 1][j], data[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	printf("��������ֵΪ��%d\n", data[n][size]);
	system("pause");
	return 0;
}