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
	//向文件输入一个格式化字符串
	fprintf(fp, "x = %d", x);
	//向显示器输入,和printf一样
	fprintf(stdout, "x = %d", x);
	putchar('\n');

	char buf[1024] = { 0 };
	//向字符数组输入一个格式化字符串
	//※※※
	//C语言中实现整数转为字符串，可以使用sprintf实现
	// atoi & itoa 也可以实现
	sprintf(buf, "x = %d", x);
	printf(buf);
	putchar('\n');

	//※※※
	//sscanf 可以实现将字符串转为整数
	char ch[] = "100";
	int y = 0;
	sscanf(ch, "%d", &y);
	printf("y = %d\n", y);


	fclose(fp);
	return 0;
}
#endif
