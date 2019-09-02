//一个整形数组里除了两个数字之外,其他的数字都出现了两次.请找到这两个只出现一次的数字.
//{1, 3, 5, 7, 1, 3, 5, 9},找到7和9、

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
	//对数组当中每个数字进行异或,结果为两个不相同的数字异或结果
	for (i = 0;i < len;i++) {
		resultOR ^= arr[i];
	}
	//找出resultOR当中的第一个二进制1是第几位（右===》左）
	indexOf1 = findNumberBits(resultOR);
	//遍历数组，第indexOf1为1的进行异或 不为1的进行异或
	for(j = 0;j < len;j++) {
		if(isBit(arr[j],indexOf1)) {
			*num1 = *num1^arr[j];
		} else {
		*num2 = *num2^arr[j];
		}
	}
}

//从右数的第bit为1
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
