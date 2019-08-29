#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	
	#if 0 
	int calendar[12][31];		//一个拥有12个数组类型的元素,其中每个元素是拥有31个整型元素的数组 
	printf("%d\n", sizeof(calendar));	// 31*12*4 = 1488
	
	int *ip;
	int i = 0;
	ip = &i; 
	*ip = 17;
	printf("%d\n", i);	//17
	
	/*两个指针指向的是同一个数组中的元素,我们可以把这两个指针相减,q-p得到i的值
	如果p与q指向的不是同一个数组中的元素,即使它们所指向的地址在内存中的位置正好间隔一个数组元素
	的整数倍,所得的结果仍然是无法保证其正确性的 */
	i = 2;
	int p[] = { 0, 1, 2, 3, 4, 5 };
	int *q = p + i;
	printf("%d\n", q - p);
	
	#endif
	
	#if 0 
	int a[] = { 0, 1, 2, 3, 4, 5 };
	int *p = a;
	//p = &a;	这样写ANSI C中是非法的, 因为&a是一个指向数组的指针,而p是一个指向整型变量的指针
	p = p + 1;
	p++;
	printf("%d\n", *p);
	
	*a = 81;
	printf(" %d  %d  %d  ", a[0], a[3], *(a + 3));	//81  3  3
	//a[i] 与*(a + 3) 等价
	#endif
	
	#if 0
	int calendar[12][31];
	int *p;
	int i;
	p = calendar[4];	//p指向了数组calendar[4]中下标为0的元素 
	printf("%d\n", sizeof(calendar[4]));	//31*4 = 124
	
	calendar[4][7] = 11;
	i = calendar[4][7];
	printf("%d ", i);
	i = *(calendar[4] + 7);
	printf("%d ", i);
	i = *(*(calendar + 4) + 7);
	printf("%d \n", i);
	//以上三种完全相同
	
	int (*monthp)[31];	//数组指针 是指向拥有31个整型元素的数组 
	monthp = calendar; 
	int month;
	for(month = 0; month < 12; month++) {
		int day;
		for(day = 0; day < 31; day++) {
			//calendar[month][day] = day;
			*(*(calendar + month) + day) = day;
		}
	}
	for(month = 0; month < 12; month++) {
		int day;
		for(day = 0; day < 31; day++) {
			printf("%d ", *(*(calendar + month) + day));
		}
		putchar('\n');
	} 
	
	for(monthp = calendar; monthp < &calendar[12]; monthp++) {
		int *dayp;
		for(dayp = *monthp; dayp < &(*monthp)[31]; dayp++) {
			printf("%d ", *dayp);
		}
		putchar('\n');
	}
	#endif
	
	#if 0
	//将下面两个字符串连接成单个字符串r 
	char *s = "hello ";
	char *t = "world";
	/*
	char *r;
	strcpy(r, s);
	strcat(r, t);
	这种方法不行,不能确定r指向何处,而且r所指向的地址处应该有内存空间容纳字符串 
	*/
	
	/*
	char r[100];
	strcpy(r, s);
	strcat(r, t);
	printf(r);
	这种方法缺陷在于不够确保r足够大
	*/
	
	/*
	char *r;
	r = (char*)malloc(strlen(s) + strlen(t));
	strcpy(r, s);
	strcat(r, t);
	printf(r); 
	这个例子还是错的，三个原因 
	1.malloc函数有可能无法提供请求的内存,这种情况malloc会返回一个空指针作为内存分配失败的信号
	2.r分配的内存使用完应该及时释放
	3.strlen函数返回字符数目,结束标志的空字符并未计算在内 
	*/
	
	//下面是正确的结果
	char *r;
	r = (char*)malloc(strlen(s) + strlen(t) + 1);
	if(!r) {
		complain();
		exit(1);
	}
	
	strcpy(r, s);
	strcat(r, t);
	printf(r);
	
	free(r);
	return 0;
	#endif
	
	#if 1
	/*
	char *p, *q;
	p = "xyz";
	q = p;
	*(q + 1) = 'Y';
	printf(p);
	*/
	//ANSI C标准中禁止对string literal做出修改 ,所以以上不正确
	char a[] = "xyz";
	char *q = a;
	*(q + 1) = 'Y' ;
	printf(a);
	#endif
	
	
}
