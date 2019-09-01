//编写函数,求第n个斐波那契数列的值(非递归)

#include<stdio.h>

long long Fab(int num) {
	if(num <= 2) {
		return 1;
	}
	int i;
	long long last1 = 1, last2 = 1, cur;
	for(i = 3; i <= num; ++i) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}

int main() {
	int n;
	while(scanf("%d", &n)) {
		printf("%lld\n", Fab(n));
	}
	return 0;
}
