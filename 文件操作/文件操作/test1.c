#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//number--->No
#include<errno.h>

/**围绕文件的相关操作
*1.打开文件
*2.关闭文件
*3.读文件
*4.写文件
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
	后面还有*/
#endif
	//源文件和exe文件不再同一路径，想要两个执行方式都能打开文件可以把文件放在上一级目录
	//也可以使用绝对路径
	//一个程序最多可以打开512(不是准确数字,可以配置)个文件
	//其中会默认打开三个
	//stdin:标准输入
	//stdout:标准输出
	//stderr:标准错误 

	//打开文件	fopen第一个参数是文件名,可以是相对路径也可以是绝对路径,第二个参数是追加方式
	//FILE是一个结构体
	//句柄(遥控器)

	//"w"打开文件的时候，会清空文件的原有内容
	//"a"追加写入，不会清空原有内容
	//"w+"和"r+"区别:都可以读和写，但是如果不存在这个文件r+会报错，w+会创建该文件
	//"w+"会把原有内容清空 "r+"追加写入
	FILE* fp = fopen("../test.txt", "w+");
	//不存在该文件
	if (fp == NULL) {
		printf("%d\n", errno);		//errno = 2
		printf("%s\n", strerror(errno));	//翻译errno，描述错误原因	"No such file or directory"
		perror("fopen");	//和上面的函数相同作用 "fopen"是前面的提示信息
		return 1;
	}
	
	//读文件是把磁盘中的数据读到内存中
	//写文件是把内存上的数据写到磁盘中
	char buf[1024] = { 0 };
	//size_t fread(void * ptr, size_t size, size_t count, FILE * stream);
	//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
	//返回值为实际读取成功的个数，参数count只是预期元素个数
	size_t n = fread(buf, sizeof(char), sizeof(buf), fp);
	printf(buf);
	putchar('\n');
	printf("n = %d\n", n);

	char buf1[] = "hehe";
	fwrite(buf1, sizeof(char), strlen(buf1), fp);

	//如果不关闭文件，会导致资源泄漏
	fclose(fp);
	return 0;
}
#endif
