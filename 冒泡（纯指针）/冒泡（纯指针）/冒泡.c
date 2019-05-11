#include<stdio.h> 
int main() {
	int a[] = { 4,2,6,7,8,1,0 };
	int n = sizeof(a) / sizeof(a[0]);
	int *p = a, *q = a + 1, *end = a + n - 1;
	int tmp;
	for (p = a; p < a + n - 1; ++p) {
		for (q = a; q < end; ++q) {
			if (*q < *(q + 1)) {
				tmp = *q;
				*q = *(q + 1);
				*(q + 1) = tmp;
			}
		}
		end--;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}