#include<stdio.h>
#include<stdlib.h>
//���º궨����Ա���"����"else������ 
#define IF 		if(
#define THEN  	) {
#define ELSE	else{
#define FI		}

int f() {
	printf("1\n");
}

int main() {
	
	#if 0
	//��Ŀ��������ȼ��ϵ�,��ֵ���������Ŀ�������,������������ 
	int home_score, vistor_score;
	home_score = vistor_score = 0;
	//�൱��
	vistor_score = 0;
	home_score = vistor_score;
	
	//����һ���ļ�����һ���ļ� 
	while(c = getc(in) != EOF)	//�൱��while(c = (getc(int) != EOF)) 
		putc(c, out); 
	//ʵ��Ӧ��д�ɣ�
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
	//���colorֵΪ2,����ӡyellowblue
	//�е�ʱ������ⲻдbreak,����switch��� 
	#endif
	
	#if 0
	f();	//f()�ǵ��ú���
	f;		//fʲôҲ���������,�Ǽ��㺯��f�ĵ�ַ,ȴ�����øú���
	printf("%x", f); 
	#endif
	
	#if 1 
	//����ָ����һ����ָ��,ָ�����Ĵ����ַ,����û�е���,�����ڿռ��ַ
	int (* fptr)() = f;
	fptr();
	(*fptr)();
	(*****fptr)();
	//���Ϻ��������Ե���,���ǵ���һ���ĺ��� 
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
