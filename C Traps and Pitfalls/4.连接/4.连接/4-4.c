#if 0
#include<stdio.h>

main() {
	int i;
	char c;
	for (i = 0; i < 5; i++) {
		scanf("%d", &c);
		printf("%d ", i);
	}
	putchar('\n');
}
/*某编译器输出 0 0 0 0 0 1 2 3 4*/
/*这里c被声明char类型,而不是int类型,scanf函数得到的是一个指向字符的指针,scanf不能分辨,它只是将这个指向字符的指针作为指向整数的指针接受.
因为整数所占的存储空间要大于字符所占的存储空间,所以字符c附近的内存将被覆盖
本例中c附近存放的是整数i的低端部分,因此每次读入一个数值到c时,都将i的低端部分覆盖为0*/
#endif