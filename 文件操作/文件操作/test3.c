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

	//���¼���������˵���ļ�ָ���Ӧ�����Ϊ���λ��

	//int fseek ( FILE * stream, long int offset, int origin );
	//offset ƫ��������λΪ�ֽ�
	//origin �Ĳ���������	SEEK_SET SEEK_CUR SEEK_END ���ƫ�Ƶ�ԭ��λ��

	//long int ftell ( FILE * stream );
	//�����ļ�ָ�������ʼλ�õ�ƫ����

	//void rewind(FILE * stream);
	//���ļ�ָ���λ�ûص��ļ�����ʼλ��

	fclose(fp);
	return 0;
}
