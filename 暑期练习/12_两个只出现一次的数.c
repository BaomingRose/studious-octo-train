//һ�����������������������֮��,���������ֶ�����������.���ҵ�������ֻ����һ�ε�����.
//{1, 3, 5, 7, 1, 3, 5, 9},�ҵ�7��9��

#include<stdio.h>

int findNumberBits(int number);
int isBit(int num, int index);

void findNumberAppearOnce(int* arr, int len, int *num1, int *num2) {
	int resultOR = 0;
	int i = 0;
	int indexOf1 = 0;
	int j = 0;
	if(arr == NULL || len < 2) {
		return;
	}
	*num1 = 0;
	*num2 = 0;
	//�����鵱��ÿ�����ֽ������,���Ϊ��������ͬ�����������
	for (i = 0;i < len;i++) {
		resultOR ^= arr[i];
	}
	//�ҳ�resultOR���еĵ�һ��������1�ǵڼ�λ����===����
	indexOf1 = findNumberBits(resultOR);
	//�������飬��indexOf1Ϊ1�Ľ������ ��Ϊ1�Ľ������
	for(j = 0;j < len;j++) {
		if(isBit(arr[j],indexOf1)) {
			*num1 = *num1^arr[j];
		} else {
		*num2 = *num2^arr[j];
		}
	}
}

//�������ĵ�bitΪ1
int findNumberBits(int number) {
	int indexBit = 0;
	while((number & 1) == 0 && indexBit < 8 *sizeof(int)) {
		number = number >> 1;
		++indexBit;
	}
	return indexBit;
}

int isBit(int num, int index) {
	num = num >> index;
	if((num & 1) == 1) {
		return 1;
	}
	return 0;
}

int main() {
	int a[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int b, c;
	findNumberAppearOnce(a, 8, &b, &c);
	printf("%d %d\n", b, c);
	return 0;
}
