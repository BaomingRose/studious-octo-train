/*在一个二维数组中,每一行都按照从左到右递增的顺序排序,每一行都按照从上到下递增的顺序排序.请完成一个
函数,输出这样的一个二维数组和一个整数,判断数组中是否含有该整数.时间复杂度O(row+col)
//数组样例：
int arr[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13, 
		6, 8, 11, 15
		}; */

//从最右上角开始找,大了向左移,小了向右移 

#include<stdio.h>

void Fnid_val(int *arr,int row,int col,int num) {
	if(NULL != arr && row > 0 && col > 0) {
		int tmpRow = 0;
		int tmpCol = col-1;
		while(tmpRow < row && col >= 0) {
			if(arr[tmpRow * col + tmpCol] == num) {
				printf("%d,intdex == %d\n",arr[tmpRow * col + tmpCol],tmpRow * col + tmpCol);
				break;
			} else if(arr[tmpRow * col + tmpCol] > num) {
				--tmpCol;
			} else {
				++tmpRow;
			}
		}
	}
}

int main() {
	int arr[4][4] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15};
	Fnid_val((int*)arr,4,4,15);
	
	/*int i, j;
	for(i = 0; i < 4; ++i) {
		for(j = 0; j < 4; ++j) {
			printf("%d ", arr[i][j]);
		}
		putchar('\n');
	}*/
	return 0;
}
