#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	
	#if 0 
	int calendar[12][31];		//һ��ӵ��12���������͵�Ԫ��,����ÿ��Ԫ����ӵ��31������Ԫ�ص����� 
	printf("%d\n", sizeof(calendar));	// 31*12*4 = 1488
	
	int *ip;
	int i = 0;
	ip = &i; 
	*ip = 17;
	printf("%d\n", i);	//17
	
	/*����ָ��ָ�����ͬһ�������е�Ԫ��,���ǿ��԰�������ָ�����,q-p�õ�i��ֵ
	���p��qָ��Ĳ���ͬһ�������е�Ԫ��,��ʹ������ָ��ĵ�ַ���ڴ��е�λ�����ü��һ������Ԫ��
	��������,���õĽ����Ȼ���޷���֤����ȷ�Ե� */
	i = 2;
	int p[] = { 0, 1, 2, 3, 4, 5 };
	int *q = p + i;
	printf("%d\n", q - p);
	
	#endif
	
	#if 0 
	int a[] = { 0, 1, 2, 3, 4, 5 };
	int *p = a;
	//p = &a;	����дANSI C���ǷǷ���, ��Ϊ&a��һ��ָ�������ָ��,��p��һ��ָ�����ͱ�����ָ��
	p = p + 1;
	p++;
	printf("%d\n", *p);
	
	*a = 81;
	printf(" %d  %d  %d  ", a[0], a[3], *(a + 3));	//81  3  3
	//a[i] ��*(a + 3) �ȼ�
	#endif
	
	#if 0
	int calendar[12][31];
	int *p;
	int i;
	p = calendar[4];	//pָ��������calendar[4]���±�Ϊ0��Ԫ�� 
	printf("%d\n", sizeof(calendar[4]));	//31*4 = 124
	
	calendar[4][7] = 11;
	i = calendar[4][7];
	printf("%d ", i);
	i = *(calendar[4] + 7);
	printf("%d ", i);
	i = *(*(calendar + 4) + 7);
	printf("%d \n", i);
	//����������ȫ��ͬ
	
	int (*monthp)[31];	//����ָ�� ��ָ��ӵ��31������Ԫ�ص����� 
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
	//�����������ַ������ӳɵ����ַ���r 
	char *s = "hello ";
	char *t = "world";
	/*
	char *r;
	strcpy(r, s);
	strcat(r, t);
	���ַ�������,����ȷ��rָ��δ�,����r��ָ��ĵ�ַ��Ӧ�����ڴ�ռ������ַ��� 
	*/
	
	/*
	char r[100];
	strcpy(r, s);
	strcat(r, t);
	printf(r);
	���ַ���ȱ�����ڲ���ȷ��r�㹻��
	*/
	
	/*
	char *r;
	r = (char*)malloc(strlen(s) + strlen(t));
	strcpy(r, s);
	strcat(r, t);
	printf(r); 
	������ӻ��Ǵ�ģ�����ԭ�� 
	1.malloc�����п����޷��ṩ������ڴ�,�������malloc�᷵��һ����ָ����Ϊ�ڴ����ʧ�ܵ��ź�
	2.r������ڴ�ʹ����Ӧ�ü�ʱ�ͷ�
	3.strlen���������ַ���Ŀ,������־�Ŀ��ַ���δ�������� 
	*/
	
	//��������ȷ�Ľ��
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
	//ANSI C��׼�н�ֹ��string literal�����޸� ,�������ϲ���ȷ
	char a[] = "xyz";
	char *q = a;
	*(q + 1) = 'Y' ;
	printf(a);
	#endif
	
	
}
