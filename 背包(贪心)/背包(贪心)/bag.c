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
	int weight, num;
	int data[20] = { 0 };
	int i, sum = 0;
	printf("��������Ʒ����num ��������weight:\n");
	scanf("%d %d", &num, &weight);
	printf("��ֱ�������Ʒ����:\n");
	for (i = 0; i < num; ++i) {
		scanf("%d", data + i);
	}
	bubble(data, num);
	//����С������װ����֪��װ����Ϊֹ
	//Ԥ����һ����Ʒ�᲻��װ��
	//���ǵ�������Ʒȫ��װ�����пռ�
	for (i = 0; sum + data[i] < weight && i < num; ++i) {
		sum += data[i];
	}
	printf("�ñ�������װ%d����Ʒ\n", i);
	system("pause");
	return 0;
}