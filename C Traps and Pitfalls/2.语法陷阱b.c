#include<stdio.h>
#include<stdlib.h>
//如下宏定义可以避免"悬挂"else的问题 
#define IF 		if(
#define THEN  	) {
#define ELSE	else{
#define FI		}

int f() {
	printf("1\n");
}

int main() {
	
	#if 0
	//三目运算符优先级较低,赋值运算符比三目运算符低,逗号运算符最低 
	int home_score, vistor_score;
	home_score = vistor_score = 0;
	//相当于
	vistor_score = 0;
	home_score = vistor_score;
	
	//复制一个文件到另一个文件 
	while(c = getc(in) != EOF)	//相当于while(c = (getc(int) != EOF)) 
		putc(c, out); 
	//实际应该写成：
	while((c = getc(in)) != EOF)
		putc(c, out); 
	#endif
	
	#if 0
	int color;
	scanf("%d", &color);
	switch(color) {
	case 1: printf("red\n");
			break;
	case 2: printf("yellow\n");
			break;
	case 3: printf("blue\n");
	
			break;
	}
	
	switch(color) {
	case 1: printf("red\n");
	case 2: printf("yellow\n");
	case 3: printf("blue\n");
	}
	//如果color值为2,将打印yellowblue
	//有的时候会有意不写break,这是switch语句 
	#endif
	
	#if 0
	f();	//f()是调用函数
	f;		//f什么也不做的语句,是计算函数f的地址,却不调用该函数
	printf("%x", f); 
	#endif
	
	#if 1 
	//函数指针是一个假指针,指向函数的代码地址,函数没有调用,不存在空间地址
	int (* fptr)() = f;
	fptr();
	(*fptr)();
	(*****fptr)();
	//以上函数都可以调用,都是调用一样的函数 
	#endif
	
	#if 1
	int i = 1;
	IF i == 0
	THEN f();
	FI
	ELSE i += 10;
		printf("%d\n", i);
	FI
	#endif
}
