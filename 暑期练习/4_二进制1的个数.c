//дһ������,��unsigned int�ͱ���x���ڴ��ж�����1�ĸ���

#include<stdio.h>

int Numberof1(int n) {
	int count = 0;
	while(n) {
		++count;
		n = (n-1) & n;
	}
	return count;
}

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		printf("%d\n",Numberof1(n));
	}
	return 0;
}
