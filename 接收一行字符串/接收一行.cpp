#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main() {
	char str[1024];
	scanf("%[^\n]", str);
	puts(str);

	//因为上一个最后输入回车,所以下一个函数str[0]='\n'
	scanf("%[^@]", str);	//直到遇到@才停止接收 
	puts(str);

	//因为上一个函数遇见@停止,下一个函数会接收@ 和回车,所以下一个函数接收str[0]='@' str[1]='\n'
	scanf("%[^0-9]", str);
	puts(str);

	//因为上个函数遇见数字结束,那么从那个数字之后,都传到下一个函数
	fgets(str, 1000, stdin);
	puts(str);

	cin.getline(str, 100);
	puts(str);

//	gets(str);	//不安全,C99之后删掉这个函数 
//	puts(str);

	string s;
	getline(cin, s);
	cout << s << endl;

	return 0;
}