#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//number--->No
#include<errno.h>

int main() {
	FILE* fp = fopen("../test.txt", "w");
	if (fp == NULL) {
		perror("fopen");
	}
	int x = 10;
	//���ļ�����һ����ʽ���ַ���
	fprintf(fp, "x = %d", x);
	//����ʾ������,��printfһ��
	fprintf(stdout, "x = %d", x);
	putchar('\n');

	char buf[1024] = { 0 };
	//���ַ���������һ����ʽ���ַ���
	//������
	//C������ʵ������תΪ�ַ���������ʹ��sprintfʵ��
	// atoi & itoa Ҳ����ʵ��
	sprintf(buf, "x = %d", x);
	printf(buf);
	putchar('\n');

	//������
	//sscanf ����ʵ�ֽ��ַ���תΪ����
	char ch[] = "100";
	int y = 0;
	sscanf(ch, "%d", &y);
	printf("y = %d\n", y);


	fclose(fp);
	return 0;
}
#endif
