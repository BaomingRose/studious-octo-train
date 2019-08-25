#include<stdio.h>

int main() {
	
	#if 0 
	int x = 1, y = 1;
	if(x = y) 	//是将y值赋给了x，然后检查该值是否为0 应该写作:if((x = y) != 0) 
		break;
	#endif
		
	#if 0
	char c, f;
	while(c = ' ' || c == '\t' || c == '\n')	// =的优先级低于||，是将' '||c=='\t'||c=='\n'赋给了c 
		c = getc(f);							//' '值为32,无论c此前为何值,上述表达式都为1 
											//在文件指针到达文件结尾如果还允许继续读取字符,将是死循环 
	#endif
	
	/*编译器将程序分解成符号的方法是从左到右一个字符一个字符读入,如果该字符可能组成一个符号,
	那么再读入下一个字符,判断已经读入的两个字符组成的字符串是否可能是一个符号的组成部分;如果可能
	继续读入下一个字符,重复上述判断,直到读入的字符组成的字符串已不再可能组成一个有意义的符号.
	这个处理策略有时被称为“贪心法”或“大嘴法”*/
	#if 0
	int a = 10, b = 5;
	printf("a---b = %d\n", a---b);		//相当于a-- - b	等于5 
	printf("a = %d, b = %d\n", a, b);	//a = 9, b = 5 
	#endif
	
	#if 0
	int x = 10, y = 1, n = 2;
	int *p = &n;
	//printf("%d", y = x/*p);	//	'/*'被编译器理解为一段注释的开始, 将不断读入字符直到'*/'的出现 
	y = x / *p;			//这样写就可以了 更清楚的写作 y = x / (*p); 
	printf("%d\n", y);	//5
	#endif
	
	#if 0
	int a = 1;
	//a >> = 1;	//老版本编译器可以处理 a >> = 1,一个严格的ANSI C编译器会报错 
	printf("%d\n", a);
	#endif
	
	#if 0 
	int a = 0195;	//第一个字符0表示八进制,此数含义为141(十进制) 0215(八进制),ANSI C标准禁止这种用法 
	printf("%d", a);
	#endif
	
	#if 0 
	printf("Hello world\n");
	
	char hello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\n', 0};
	printf(hello);
	//打印结果相同
	#endif
	
	#if 0
	int a = 'yes';		//没有准确的定义 
	int b = "yes";		//依次包含'y''e''s''\0'四个连续内存单元的首地址
	printf("a = %x\n", a);
	printf("b = %x\n", b); 
	#endif
	
	return 0;
} 
