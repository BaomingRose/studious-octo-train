#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main() {
	char str[1024];
	scanf("%[^\n]", str);
	puts(str);

	//��Ϊ��һ���������س�,������һ������str[0]='\n'
	scanf("%[^@]", str);	//ֱ������@��ֹͣ���� 
	puts(str);

	//��Ϊ��һ����������@ֹͣ,��һ�����������@ �ͻس�,������һ����������str[0]='@' str[1]='\n'
	scanf("%[^0-9]", str);
	puts(str);

	//��Ϊ�ϸ������������ֽ���,��ô���Ǹ�����֮��,��������һ������
	fgets(str, 1000, stdin);
	puts(str);

	cin.getline(str, 100);
	puts(str);

//	gets(str);	//����ȫ,C99֮��ɾ��������� 
//	puts(str);

	string s;
	getline(cin, s);
	cout << s << endl;

	return 0;
}