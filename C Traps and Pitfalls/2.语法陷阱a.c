#include<stdio.h>

#if 0 
void sigfunc(int);
void sigfunc(int n) {
	
}
//��sfp��һ��ָ��sigfunc������ָ��,���*sfp���Ա�����,���Կ�����������sfp
void (*sfp)(int);

//signal�����ķ���ֵ������sfp�ķ�������һ�� 
/*�����ʵ��Ĳ����Ե���signal����,��signal��������ֵ(Ϊ����ָ������)�������,Ȼ�󴫵�һ��
 ���β������ý�����ú����ú���,��󷵻�ֵΪvoid����*/
//signal����ֵ��һ��ָ�򷵻�ֵΪvoid���͵ĺ�����ָ�� 
void (*signal(int, void(*)(int)))(int);

//����������� 
typedef void (*HANDLER)(int);
HANDLER signal(int, HANDLER);
#endif

int main() {
	
	#if 0
	//ģ�⿪��������Ӳ�������׵�ַΪ0λ�õ�������
	//void(*)()0 ��ʾ������0ת��Ϊָ�򷵻�ֵΪ�����͵ĺ�����ָ������
	(*(void (*)())0)();
	
	//����������������
	typedef void (*funcptr)();
	(*(funcptr)0)();
	
	return 0;
	#endif
	
	#if 0
	int flag = 8,  FLAG = 12;
	//�ж�flagΪ1����һλ,FLAG��һλ�Ƿ�ͬ��Ϊ1
	//����д������ȷ 
	if(flag & FLAG != 0)	//��������Ϊ if(flag & (FLAG != 0)), !=�����ȼ�����& 
		printf("YES\n"); 
	//��������Ϊ��ȷд�� 
	if(flag & FLAG)		
		printf("YES\n"); 
	if((flag & FLAG) != 0)
		printf("YES\n"); 
	return 0; 
	#endif
	
	#if 0
	int hi = 7, low = 5;	//hi,low��0-15֮�� 
	int r;
	//r�ĵ���λ��low��λ����һ��,r�ĸ���λ��hi��λ����һ��
	r = hi << 4 +  low;	//����	ʵ�����൱�� r = hi << (4 + low) <<�����ȼ�����+ 
	printf("%d\n", r);	//3584
	//������ȷ����
	r = (hi << 4) + low;
	printf("%d\n", r);	//117
	r = hi << 4 | low;
	printf("%d\n", r); //117
	return 0;
	#endif
	
	#if 0
	int a[3] = {10, 5, 2};
	int* p = a;
	int b = *p++;	//�൱��*(p++) ������(*p)++ 
	int c = *p;
	printf("%d\n", b);//10
	printf("%d\n", c);//5
	
	//���p��һ������ָ��,Ҫ����p��ָ��ĺ���,��������д(*p)()
	//*p()����������ͳ�*(p()) 
	#endif
	//�κ��߼���������ڹ�ϵ�����
	//��λ�����������������ͣ����ȹ�ϵ������� 
	#if 0
	//==��!=�����ȼ�����������ϵ����� 
	
	#endif 
} 
