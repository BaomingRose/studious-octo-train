//在字符串中找出第一个只出现一次的字符.如输出"abaccdeff",则输出'b'.要求时间复杂度为O(n) 

#include<stdio.h>

char firstNotRepeate(char* str) {
	const int size = 256;	//表示
	int hashTable[size];
	int i;
	if(str == NULL) {
		return '\0';
	}
	for(i = 0; i < size; i++) {
		hashTable[i] = 0;
	}
	char *pHashKey = str;
	while(*(pHashKey) != '\0') {
		hashTable[*(pHashKey++)]++;
	}
	pHashKey = str;
	while(*(pHashKey) != '\0') {
		if(hashTable[*(pHashKey)] == 1) {
			return *(pHashKey);
		}
		pHashKey++;
	}
	return '\0';
}

int main() {
	putchar(firstNotRepeate("abaccdeff"));
	putchar('\n');
	return 0;
}
