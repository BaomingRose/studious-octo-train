#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//malloc的内存在堆上
//堆比较大,栈比较小
//堆的大小和物理内存差不多
//栈的大小是可配置的
//linux内存访问越界会提示"段错误" linux 默认栈空间8M Windowd默认1M
//Linux ulimit -a命令可以查看stack空间	ulimit -s 10240 改变占空间为10240
//堆上申请空间效率较低
//栈上申请空间效率非常高

#if 0
/**这段代码的错误：※※※
*没有判断malloc是否成功
*malloc后没有free
*str作为GetMemory的参数,并没有真正改变str
*/
/**更改:
*第一个函数传入二级指针
*判断str申请空间成功没有
if (str == NULL) {
	return;
}
*最后free(str)
*/
void GetMemory(char * p) {
	p = (char*)malloc(sizeof(char) * 10);
}
void test() {
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}
#endif

#if 0
//以下的p是局部变量，执行完被释放，所以str访问了非法内存，打印"烫烫烫烫烫"
//将p[] 改成指针，就可以正常打印了
char* GetMemory() {
	char p[] = "hello world";
	return p;
}
void test() {
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
#endif

#if 0
void GetMemory(char** p, int num) {
	*p = (char*)malloc(num);
}
void test() {
	char* str = NULL;
	GetMemory(&str, 100);
	//判断malloc申请成功？
	if (str == NULL) {
		return;
	strcpy(str, "hello");
	printf(str);
	//要释放
	free(str);
}
#endif

#if 0
void test(void) {
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL) {
		strcpy(str, "world");	//str被释放之后虽然还可以用，但是这块内存仍被分配出去
		printf(str);	//依然会打印world 但是这样写并不正确
	}
}
#endif

void a() {

}

int b = 0;

int main() {
#if 0
	//malloc有可能会失败的
	int *p = (int*)malloc(INT_MAX);	//约2G
	*p = 20;
	printf("%d ", *p);
	free(p);
#endif

#if 0
	int i = 0;
	int *p = (int*)malloc(10 * sizeof(int));
	if (NULL == p) {
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; ++i) {
		*(p + i) = i;	//当i为10的时候越界
	}
	free(p);
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	free(p);
	p = NULL;
	//C语言标准规定，对一个 空指针 进行free，没有任何副作用
	free(p);
	//并不会出错
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	free(p);
	*p = 10;
	printf("%d\n", *p);	//这样的代码是不正确的，但是扔会打印10
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	p = p + 1;
	free(p);	//	free传入的地址必须是malloc返回的起始地址
#endif

	//test();
	int *c = (int*)malloc(sizeof(int));
	int d = 0;
	printf("代码段：%p\n", a);
	printf("数据段：%p\n", &b);
	printf("堆：%p\n", c);
	printf("栈：%p\n", &d);
	//Linux的内存分布从高地址到低地址依次为：栈->堆->数据段->代码段
	return 0;
}