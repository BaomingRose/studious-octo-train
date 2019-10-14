#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//number--->No
#include<errno.h>

int main() {
	FILE* fp = fopen("../test.txt", "r");
	if (fp == NULL) {
		printf("%s\n", strerror(errno));
	}

	//以下几个函数所说的文件指针更应该理解为光标位置

	//int fseek ( FILE * stream, long int offset, int origin );
	//offset 偏移量，单位为字节
	//origin 的参数可以是	SEEK_SET SEEK_CUR SEEK_END 相对偏移的原点位置

	//long int ftell ( FILE * stream );
	//返回文件指针相对起始位置的偏移量

	//void rewind(FILE * stream);
	//让文件指针的位置回到文件的起始位置

	fclose(fp);
	return 0;
}
