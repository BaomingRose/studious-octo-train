#include<stdio.h>
//360������
//��·��ֵ
//�����߼��������������ı��ʽΪ 0����ô�Ҳ಻�ڼ���
//�����߼��������������ı��ʽΪ 1����ô�Ҳ಻�ڼ���
int main1() {
	//����++�ȼ۴���
	/*int i;
	int tmp = i;
	i += 1;
	return tmp;*/
	//ǰ��++�ȼ۴���
	/*int i;
	i += 1;
	return i;*/
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && c++ && d++;
	i = a++ || ++b || c++ || d++;
	printf("a = %d\nb = %d\nc = %d\nd = %d\ni = %d\n", a, b, c, d, i);
	system("pause");
	return 0;
}