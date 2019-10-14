#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//number--->No
#include<errno.h>

/**Χ���ļ�����ز���
*1.���ļ�
*2.�ر��ļ�
*3.���ļ�
*4.д�ļ�
*/

int main() {
#if 0
	int i = 0;
	for (i = 0; i < 10; ++i) {
		printf("%s\n", strerror(i));
	}
	/*error:
	0:	No error
	1:	Operation not permitted
	2:	No such file or directory
	3:	No such process
	4:	Interrupted function call
	5:	Input / output error
	6:	No such device or address
	7:	Arg list too long
	8:	Exec format error
	9:	Bad file descriptor
	���滹��*/
#endif
	//Դ�ļ���exe�ļ�����ͬһ·������Ҫ����ִ�з�ʽ���ܴ��ļ����԰��ļ�������һ��Ŀ¼
	//Ҳ����ʹ�þ���·��
	//һ�����������Դ�512(����׼ȷ����,��������)���ļ�
	//���л�Ĭ�ϴ�����
	//stdin:��׼����
	//stdout:��׼���
	//stderr:��׼���� 

	//���ļ�	fopen��һ���������ļ���,���������·��Ҳ�����Ǿ���·��,�ڶ���������׷�ӷ�ʽ
	//FILE��һ���ṹ��
	//���(ң����)

	//"w"���ļ���ʱ�򣬻�����ļ���ԭ������
	//"a"׷��д�룬�������ԭ������
	//"w+"��"r+"����:�����Զ���д�������������������ļ�r+�ᱨ��w+�ᴴ�����ļ�
	//"w+"���ԭ��������� "r+"׷��д��
	FILE* fp = fopen("../test.txt", "w+");
	//�����ڸ��ļ�
	if (fp == NULL) {
		printf("%d\n", errno);		//errno = 2
		printf("%s\n", strerror(errno));	//����errno����������ԭ��	"No such file or directory"
		perror("fopen");	//������ĺ�����ͬ���� "fopen"��ǰ�����ʾ��Ϣ
		return 1;
	}
	
	//���ļ��ǰѴ����е����ݶ����ڴ���
	//д�ļ��ǰ��ڴ��ϵ�����д��������
	char buf[1024] = { 0 };
	//size_t fread(void * ptr, size_t size, size_t count, FILE * stream);
	//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
	//����ֵΪʵ�ʶ�ȡ�ɹ��ĸ���������countֻ��Ԥ��Ԫ�ظ���
	size_t n = fread(buf, sizeof(char), sizeof(buf), fp);
	printf(buf);
	putchar('\n');
	printf("n = %d\n", n);

	char buf1[] = "hehe";
	fwrite(buf1, sizeof(char), strlen(buf1), fp);

	//������ر��ļ����ᵼ����Դй©
	fclose(fp);
	return 0;
}
#endif
