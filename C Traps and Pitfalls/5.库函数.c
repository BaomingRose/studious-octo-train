#include<stdio.h>
#include<signal.h> 

int main() {
	#if 0
	char c;
	//getchar()返回类型为int  

	while((c = getchar()) != EOF) {	//结果两种可能:一是合法的输入字符在被截断后是的c的取值与EOF相同
									//二是不可能取到EOF这个值 
									//还有三就似乎正常运行,但因为巧合,尽管返回值截断,
									//尽管比较运算操作数不是getchar的返回值
		putchar(c);
	}
	#endif
	
	/*FILE *fp;
	fp = fopen(file, "r+");
	//上面打开了文件名由变量file指定的文件
	//为了保持与获取不能同时进行读写操作的程序的向下兼容性,一个输入操作不能随后直接紧跟一个输出操作
	//如果要同时进行输入和输出操作,必须在其中插入fseek函数的调用欧冠 
	*/
	
	#if 0
	FILE *fp;
	struct record rec;
	
	while(fread((char *)&rec, sizeof(rec), 1, fp) == 1) {
		/*对rec执行某些操作*/
		if(/*rec必须被重新写入*/) {
			fseek(fp, -(long)sizeof(rec), 1);
			fwrite((char *)&rec, sizeof(rec), 1, fp);
		} 
	}
	//&rec在传入fread和fwrite函数时被小心翼翼转换为字符指针类型,sizeof(rec)被转换为长整型
	//fseek函数要求第二个参数是long型,因为int类型的整数可能无法包含一个文件的大小;sizeof返回时unsigned值
	//因此首先必须将其转换为有符号类型才有可能将其反号
	//可改写:
	while(fread((char *)&rec, sizeof(rec), 1, fp) == 1) {
		/*对rec执行某些操作*/
		if(/*rec必须被重新写入*/) {
			fseek(fp, -(long)sizeof(rec), 1);
			fwrite((char *)&rec, sizeof(rec), 1, fp);
			fseek(fp, 0L, 1);	//它改变了文件的状态,使文件现在可以正常进行读取了 
		} 
	} 
	#endif
	
	#if 0
	//程序输出有两种方式:一种是即是时处理方式,另一种是先暂存起来,然后在大块写入的方式
	//前者往往造成较高的系统负担,因此,C语言实现通常允许程序员进行实际的写操作之前控制产生的输出数据量
	int c; 
	char buf[BUFSIZ];
	setbuf(stdout, buf); 
	/*语句将通知输入/输出库,所有写入到stdout的输出都应该使用buf作为输出缓冲区,直到buf缓冲区被填满或者程序员直接调用
	fflush(对于由写操作打开的文件,调用fflush将导致输出缓冲区的内容被实际写入该文件),buf缓冲区的内容才实际写入到
	stdout中.缓冲区的大小有系统头文件<stdio.h>中的BUFSIZ */
	
	while((c = getchar()) != EOF)
		putchar(c);
	//main函数结束之后,buf已经被释放
	//改进：static char buf[BUFSIZ] ,也可以放主函数外
	//第二种方法:
	char *malloc();
	setbuf(stdout, malloc(BUFSIZ));
	#endif
	
	#if 0
	//调用库函数时,应该首先检测作为错误指示的返回值,确定程序执行已经失败,然后在检查errno,来搞清楚出错原因
	
	/*调用库函数*/
	if(返回的错误值) 
		检查errno 
	#endif
	
	#if 0
	//捕获异步事件的一种方式 
	signal(signal type, handler function);
	//signal type代表系统头文件signal中定义的某些常量用来标识signal函数将要捕获的信号类型
	//handler function是当指定的事件发生时,将要加以调用的事件处理函数
	//信号甚至可能出现在某些复杂库函数(如malloc)的执行过程中,因此从安全的角度考虑,信号的处理函数不应该调用上述类型的库函数 
	#endif
	
	
	return 0;
}
