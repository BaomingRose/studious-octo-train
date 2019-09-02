//��һ������a,��д����,��������ǰK����С������

#include<stdio.h>
//ʹ�ÿ��ŵĻ��� ��Ȼ������ʹ�öѽ������
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
	int index = Partion(arr,start,end);//ʹ����һ����Ŀ��Partion����
	if(arr == NULL || len < 1) {
		return ;
	}
	if(arr == NULL || len < 0) {
		return ;//�������鵱�в��������0
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
