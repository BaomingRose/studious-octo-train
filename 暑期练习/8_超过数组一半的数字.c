//��д����:��������Ԫ�س��ִ����������鳤��һ�������.��:{1,2,3,2,2,2,5,4,2}.����2Ϊ�������鳤��һ������� 

#include<stdio.h>

int Partion(int *arr,int left,int right)
{
	int tmp = arr[left];
	if(arr == NULL) {
		return -1;
	}
	while(left < right) {
		while(left < right && arr[right] >= tmp) {
			right--;
		}
		if(left >= right) {
			break;
		} else {
			arr[left] = arr[right];
		}
		while(left < right && arr[left] <= tmp) {
			left++;
		}
		if(left >= right) {
			break;
		} else {
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}

int arrayLenHalfNum(int* arr,int len) {
	int mid = len >> 1;
	int start = 0;
	int end = len - 1;
	int result = 0;
	int index = Partion(arr, start, end);	//ʹ����һ����Ŀ��Partion����
	if(arr == NULL || len < 0) {
		return 0;	//�������鵱�в��������0
	}
	while(index != mid) {
		if(index > mid) {	//˵���������
			end = index - 1;
			index = Partion(arr, start, end);
		} else {
			start = index + 1;
			index = Partion(arr,start,end);
		}
	}
	result = arr[mid];
	//�������ݵ��� ����һֱ��Ϊ �������λ������������Ҫ�ҵ�����
	//���� ����һ�����鵱��Ƶ����ߵ����� ������λ�� ���Եõ����result
	//֮�� ���ǻ���Ҫ�ж�һ��������ֳ��ֵ�Ƶ���Ƿ�Ϊ�������ȵ�һ��
	if(!checkIsMoreThanHalf(arr, result)) {
		result = 0;
	}
	return result;
}

int checkIsMoreThanHalf(int *arr, int n, int num) {
	int count = 0;
	int i = 0;
	for(i = 0; i < n; i++) {
		if(arr[i] == num) {
			count++;
		}
	}
	if(count*2 <= n) {
		return 0;
	}
	return 1;
}

