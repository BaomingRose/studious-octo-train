#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[10][10] = { 0 };
	int row, col;
	printf("������B������\n");
	scanf("%d%d", &row, &col);
	int i, j;
	for (i = 1; i <= row; ++i) {
		for (j = 1; j <= col; ++j) {
			if (i == 1 && j == 1) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i][j - 1];
			}
		}
	}
	printf("A��B��·����Ϊ:%d\n", a[row][col]);
	system("pause");
	return 0;
}