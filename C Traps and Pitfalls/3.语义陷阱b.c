#include<stdio.h>
#include<string.h>
#include<limits.h>

#if 0
//边界计算与不对称边界
//编程技巧:用第一个入界点和第一个出界点表示一个数值范围
//x>=16 && x<=37,就是满足边界条件x>=16 && x<38;
//取值范围的大小为上界与下界之差，即38-16=22;
//如果取值范围为空,上界等于下界 


/*函数功能将长度无规律的输入数据送到缓冲区(一块能够容纳N个字符的内存)中,每当这块内存被填满时
就将缓冲区的内容写出*/ 
#define N 1024
static char buffer[N];
static char *bufptr = &buffer[0];	//或者bufptr = buffer; 
//按照"不对称边界"惯例, bufptr指向第一个未占用的字符,任何时候已存放的字符数都为bufptr-buffer ※
//通过将这个表达式与N比较,可以推断未占用的字符数N-(bufptr-buffer) 
void flushbuffer() {
	int i = 0;
	for(i = 0; i < N; i++) {
		putchar(buffer[i]);
	}
	bufptr = buffer;
} 

void bufwrite(char *p, int n) {
	while(--n >= 0) {	//循环几次可以考虑最简单的特例:n=1※,循环执行n次
		//在大多数C语言实现中,--n>=0至少与等效的n-->0一样快,甚至更快	后者是不对称边界:从n到1 
		//某些编译器如果"智能"足够高,可发现后一个有可能按照比写出来的更有效率的方式执行 
		if(bufptr == &buffer[N])	//buffer[N]不存在,代替了if(burptr>&buffer[N-1]),坚持不对称边界原则※ 
			flushbuffer();
		*bufptr++ = *p++;
	}
}

//优化:一次移动k个字符 有库函数memcpy
void my_memcpy(char *dest, const char *source, int k) {
	while(--k >= 0)
		*dest++ = *source++;
} 

void bufwrite2(char *p, int n) {
	while(n > 0) {
		int k, rem;
		if(bufptr == &buffer[N])
			flushbuffer();
		rem = N - (bufptr - buffer);
		k = n > rem ? rem : n;
		my_memcpy(bufptr, p, k);
		bufptr += k;
		p += k;
		n -= k;
	}
}

int main() {
	//数组基本的"不对称边界" 
	int a[10], i;
	for(i = 0; i < 10; i++) {
		a[i] = i;
	}
	for(i = 0; i < 10; i++) {
		printf("%d ", *(a + i));
	}
	
	char c[10];
	gets(c);
	for(i = 0; i < 10; i++) {
		*bufptr++ = c;
	}
	
	puts(c);
	return 0;
}
#endif

#if 0
//四个运算符(&& || ?: ,)存在规定的求值顺序
//&& || 首先对左侧操作数求值,只在需要时才对右操作数求值
//a?b:c	首先a被求值,根据a的值在求b或c的值
//,	首先对左侧操作数求值,然后该值被丢弃,再对右侧求值
//C语言中其他所有运算符对其操作数求值的顺序都是未定义的 
int main() {
	int y[10], x[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = 10;
	int i = 0;
	#if 0
	while(i < n) {
		y[i] = x[i++];
	}
	for(i = 0; i < n; ++i) {
		printf("%d ", y[i]);	//{1,0,1,2,3,4,5,6,7} 
	}
	//上面代码假设y[i]的地址将在i的自增操作执行前被求值,这一点并没有任何保证
	//某些实现上,有可能在i自增之前被求值,也可能与此相反 
	#endif
	
	//正确写法
	while(i < n) {
		y[i] = x[i];
		i++;
	} 
	for(i = 0; i < n; i++) {
		printf("%d ", y[i]);
	}
	
	exit(0);
}
#endif

//整数溢出
//C语言存在两类整数算术运算,有符号运算和无符号,无符号没有溢出
//如果算术运算符的一个操作数是有符号,一个无符号,那么有符号会被强转为无符号※,也不会溢出
//但是两个都是有符号整数时,溢出就可能发生,而且溢出的结果是未定义的
void complain() {
	printf("溢出\n");
} 

int main() {
	int a = 1000000000, b = 10000000000;
	if(a + b < 0) {
		complain();
	}
	//在某些机器上,加法将设置一个内部寄存器为四种状态之一:正、负、零、溢出
	//这种机器上,C编译器完全有理由这样来实现上面的例子,即a与b相加,然后检查该内部寄存器的标志是否为负
	//当加法操作发生溢出是,这个你不寄存器的状态是溢出而不是负,那么if语句检查就会失败
	if((unsigned)a + (unsigned)b > INT_MAX)	//INT_MAX在头文件<limits.h>  代表的可能最大整数值 
		complain();
	 if(a > INT_MAX - b)
	 	complain();
}

#if 0 
main() {
	
}
//这个程序并没有声明返回类型,会默认是整形
//一个返回值为整形的函数如果返回失败,实际上是隐含的返回了某个"垃圾"整数,只要数值不被用到,就无关紧要 
#endif

#if 0
main() {
	printf("Hello world\n");
	exit(0);
}
#endif

