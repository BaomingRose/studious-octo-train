/*��һ����ά������,ÿһ�ж����մ����ҵ�����˳������,ÿһ�ж����մ��ϵ��µ�����˳������.�����һ��
����,���������һ����ά�����һ������,�ж��������Ƿ��и�����.ʱ�临�Ӷ�O(row+col)
//����������
int arr[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13, 
		6, 8, 11, 15
		}; */

//�������Ͻǿ�ʼ��,����������,С�������� 

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
