//���ַ������ҳ���һ��ֻ����һ�ε��ַ�.�����"abaccdeff",�����'b'.Ҫ��ʱ�临�Ӷ�ΪO(n) 

#include<stdio.h>

char firstNotRepeate(char* str) {
	const int size = 256;	//��ʾ
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
