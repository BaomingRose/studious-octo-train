#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//malloc���ڴ��ڶ���
//�ѱȽϴ�,ջ�Ƚ�С
//�ѵĴ�С�������ڴ���
//ջ�Ĵ�С�ǿ����õ�
//linux�ڴ����Խ�����ʾ"�δ���" linux Ĭ��ջ�ռ�8M WindowdĬ��1M
//Linux ulimit -a������Բ鿴stack�ռ�	ulimit -s 10240 �ı�ռ�ռ�Ϊ10240
//��������ռ�Ч�ʽϵ�
//ջ������ռ�Ч�ʷǳ���

#if 0
/**��δ���Ĵ��󣺡�����
*û���ж�malloc�Ƿ�ɹ�
*malloc��û��free
*str��ΪGetMemory�Ĳ���,��û�������ı�str
*/
/**����:
*��һ�������������ָ��
*�ж�str����ռ�ɹ�û��
if (str == NULL) {
	return;
}
*���free(str)
*/
void GetMemory(char * p) {
	p = (char*)malloc(sizeof(char) * 10);
}
void test() {
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}
#endif

#if 0
//���µ�p�Ǿֲ�������ִ���걻�ͷţ�����str�����˷Ƿ��ڴ棬��ӡ"����������"
//��p[] �ĳ�ָ�룬�Ϳ���������ӡ��
char* GetMemory() {
	char p[] = "hello world";
	return p;
}
void test() {
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
#endif

#if 0
void GetMemory(char** p, int num) {
	*p = (char*)malloc(num);
}
void test() {
	char* str = NULL;
	GetMemory(&str, 100);
	//�ж�malloc����ɹ���
	if (str == NULL) {
		return;
	strcpy(str, "hello");
	printf(str);
	//Ҫ�ͷ�
	free(str);
}
#endif

#if 0
void test(void) {
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL) {
		strcpy(str, "world");	//str���ͷ�֮����Ȼ�������ã���������ڴ��Ա������ȥ
		printf(str);	//��Ȼ���ӡworld ��������д������ȷ
	}
}
#endif

void a() {

}

int b = 0;

int main() {
#if 0
	//malloc�п��ܻ�ʧ�ܵ�
	int *p = (int*)malloc(INT_MAX);	//Լ2G
	*p = 20;
	printf("%d ", *p);
	free(p);
#endif

#if 0
	int i = 0;
	int *p = (int*)malloc(10 * sizeof(int));
	if (NULL == p) {
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; ++i) {
		*(p + i) = i;	//��iΪ10��ʱ��Խ��
	}
	free(p);
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	free(p);
	p = NULL;
	//C���Ա�׼�涨����һ�� ��ָ�� ����free��û���κθ�����
	free(p);
	//���������
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	free(p);
	*p = 10;
	printf("%d\n", *p);	//�����Ĵ����ǲ���ȷ�ģ������ӻ��ӡ10
#endif

#if 0
	int *p = (int*)malloc(sizeof(int) * 10);
	p = p + 1;
	free(p);	//	free����ĵ�ַ������malloc���ص���ʼ��ַ
#endif

	//test();
	int *c = (int*)malloc(sizeof(int));
	int d = 0;
	printf("����Σ�%p\n", a);
	printf("���ݶΣ�%p\n", &b);
	printf("�ѣ�%p\n", c);
	printf("ջ��%p\n", &d);
	//Linux���ڴ�ֲ��Ӹߵ�ַ���͵�ַ����Ϊ��ջ->��->���ݶ�->�����
	return 0;
}