//����һ���ַ���,�����һ����Ч�㷨.�ҵ���һ���ظ����ֵ��ַ�.��������:"qywyer23tdd",����:y 

#define SIZE 256
#include<stdio.h>
char firstNotRepeate(char* str) {
	char *pHashKey = str;
	int hashTable[SIZE];
	int i;
	for(i = 0; i < SIZE; i++) {
		hashTable[i] = 0;
	}
	while(*(pHashKey) != '\0') {
		hashTable[*(pHashKey++)]++;
	}
	pHashKey = str;
	while(*(pHashKey) != '\0') {
		if(hashTable[*(pHashKey)] == 2) {
			return *(pHashKey);
		}
		pHashKey++;
	}
	return '\0';
}

int main() {
	char ch = firstNotRepeate("qywyer23tdd");
	printf("%c\n",ch);
	return 0;
}
