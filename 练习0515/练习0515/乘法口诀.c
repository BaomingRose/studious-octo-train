#include<stdio.h> 
int main2() {
	int i, j;
	for (i = 1; i <= 9; ++i) {
		for (j = 1; j <= i; ++j) {
			printf("%d*%d=%d\t", j, i, j*i);
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}