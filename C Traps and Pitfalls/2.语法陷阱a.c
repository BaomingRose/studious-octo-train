#include<stdio.h>

#if 0 
void sigfunc(int);
void sigfunc(int n) {
	
}
//设sfp是一个指向sigfunc函数的指针,因此*sfp可以被调用,所以可以如下声明sfp
void (*sfp)(int);

//signal函数的返回值类型与sfp的返回类型一样 
/*传递适当的参数以调用signal函数,对signal函数返回值(为函数指针类型)解除引用,然后传递一个
 整形参数调用解除引用后所得函数,最后返回值为void类型*/
//signal返回值是一个指向返回值为void类型的函数的指针 
void (*signal(int, void(*)(int)))(int);

//简化上面的声明 
typedef void (*HANDLER)(int);
HANDLER signal(int, HANDLER);
#endif

int main() {
	
	#if 0
	//模拟开机启动，硬件调用首地址为0位置的子例程
	//void(*)()0 表示将常数0转换为指向返回值为空类型的函数的指针类型
	(*(void (*)())0)();
	
	//这样表述更加清晰
	typedef void (*funcptr)();
	(*(funcptr)0)();
	
	return 0;
	#endif
	
	#if 0
	int flag = 8,  FLAG = 12;
	//判断flag为1的那一位,FLAG那一位是否同样为1
	//这种写法不正确 
	if(flag & FLAG != 0)	//将被解释为 if(flag & (FLAG != 0)), !=的优先级高于& 
		printf("YES\n"); 
	//以下两种为正确写法 
	if(flag & FLAG)		
		printf("YES\n"); 
	if((flag & FLAG) != 0)
		printf("YES\n"); 
	return 0; 
	#endif
	
	#if 0
	int hi = 7, low = 5;	//hi,low在0-15之间 
	int r;
	//r的低四位与low各位的数一致,r的高四位与hi各位的数一致
	r = hi << 4 +  low;	//错误	实际上相当于 r = hi << (4 + low) <<的优先级低于+ 
	printf("%d\n", r);	//3584
	//两种正确方法
	r = (hi << 4) + low;
	printf("%d\n", r);	//117
	r = hi << 4 | low;
	printf("%d\n", r); //117
	return 0;
	#endif
	
	#if 0
	int a[3] = {10, 5, 2};
	int* p = a;
	int b = *p++;	//相当于*(p++) 而不是(*p)++ 
	int c = *p;
	printf("%d\n", b);//10
	printf("%d\n", c);//5
	
	//如果p是一个函数指针,要调用p所指向的函数,必须这样写(*p)()
	//*p()编译器会解释成*(p()) 
	#endif
	//任何逻辑运算符低于关系运算符
	//移位运算符比算术运算符低，但比关系运算符高 
	#if 0
	//==和!=的优先级低于其他关系运算符 
	
	#endif 
} 
