//5*6矩阵，按下按钮该点及该点周围(上下左右)状态都会改变
//有一个初始状态,如何按下哪些按钮,所有灯都熄灭

//基本思路:如果存在某个局部,一旦这个局部的状态被确定,那么剩余的其他部分状态只能是确定的一种,或者不多的n种,那么只枚举这个局部
//第一行就是局部,要熄灭第一行,只能通过第二行,依次类推
//只要没有第一行,推算最后一行开关状态,如果全部熄灭则符合题解,否则不符合题解,尝试枚举下一个 

#include<iostream>
using namespace std;

int puzzle[6][8], press[6][8];

bool guess() {
	int c, r;		//col, row
	//根据press第一行和puzzle数组，计算press其他行的值 
	for (r = 1; r < 5; r++) {
		for (c = 1; c < 7; c++) {
			press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
		}
	}
	//判断所计算的press数组能否熄灭第五行所有的灯 
	for (c = 1; c < 7; c++) {
		if ((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) % 2 != puzzle[5][c])
		return false;
	}
	return true;
}

void enumerate() {
	int c;
	bool success;
	for (c = 1; c < 7; c++) {
		press[1][c] = 0;
	}
	while (guess() == false) {
		press[1][1]++;
		c = 1;
		while (press[1][c > 1]) {
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}
	return;
}

int main() {
	int cases, i, r, c;
	cin >> cases;
	for (r = 0; r < 6; r++) {
		press[r][0] = press[r][7] = 0;
	}
	for (c = 1; r < 7; r++) {
		press[0][c] = 0;
	}
	for (i = 0; i < cases; i++) {
		for (r = 1; r < 6; r++) {
			for (c = 1; c < 7; c++) {
				cin >> puzzle[r][c];
			}
		}
	}
	enumerate();
	cout << "PUZZLE#" << i + 1 << endl;
	for (r = 1; r < 6; r++) {
		for (c = 1; c < 7; c++) {
			cout << press[r][c];
		}
		cout << endl;
	} 
	return 0;
} 
