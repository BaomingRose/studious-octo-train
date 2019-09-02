//编写函数:求数组中元素出现次数超过数组长度一半的数字.如:{1,2,3,2,2,2,5,4,2}.数字2为超过数组长度一半的数字 

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
	int index = Partion(arr, start, end);	//使用上一个题目的Partion函数
	if(arr == NULL || len < 0) {
		return 0;	//假设数组当中不存放数字0
	}
	while(index != mid) {
		if(index > mid) {	//说明在左边找
			end = index - 1;
			index = Partion(arr, start, end);
		} else {
			start = index + 1;
			index = Partion(arr,start,end);
		}
	}
	result = arr[mid];
	//以上数据当中 我们一直认为 数组的中位数就是我们需要找的数字
	//但是 并不一定数组当中频率最高的数字 就是中位数 所以得到这个result
	//之后 我们还需要判断一下这个数字出现的频率是否为整个长度的一半
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

