//有一个数组a,编写函数,求数组中前K个最小的数字

#include<stdio.h>
//使用快排的划分 当然还可以使用堆进行求解
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

void Little_K(int *arr,int len,int k)
{
	int par = 0;
	int start = 0;
	int end = len-1;
	int mid = (end + start) / 2;
	int i;
	int index = Partion(arr,start,end);//使用上一个题目的Partion函数
	if(arr == NULL || len < 1) {
		return ;
	}
	if(arr == NULL || len < 0) {
		return ;//假设数组当中不存放数字0
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
	for(i = 0; i < k;i++) {
		printf("%d ",arr[i]);
	}
}

int main() {
	int arr[] = {12,21,1,4,2,65,33,5,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	Little_K(arr,len,9);
	return 0;
} 
