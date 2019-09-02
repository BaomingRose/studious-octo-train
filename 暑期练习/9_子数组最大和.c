/*输入一个整形数组,数组里有正数也有负数.数组中一个或连续的多个整数组成一个子数组.求所有子数组的和的
最大值.要求时间复杂度为O(n).例如输入的数组为{1,-2,3,10,-4,7,2,-5},和最大的子数组为{3,10,-4,7,2},
因此输出为该子数组的和18*/
#include<stdio.h>

int MAX_Arry(int* arr, int sz) {
	int MAX = arr[0];
	int sum = arr[0];
	int i = 1;
	if (arr == NULL || sz <= 1)
		return 0;
	for ( i = 1; i < sz; i++) {
		if (sum < 0)
			sum = arr[i];
		else {
			sum += arr[i];
		}
		if (sum > MAX)
			MAX = sum;
	}
	return MAX;
}
int main() {
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5};
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", MAX_Arry(arr,len));
	return 0;
}
