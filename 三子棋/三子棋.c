#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
char chess_board[MAX_ROW][MAX_COL];
int Menu() {
	printf("**************\n");
	printf("**1.开始游戏**\n");
	printf("**0.结束游戏**\n");
	printf("**************\n");
	printf("请选择：\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void INIT() {
	int row = 0;
	int col = 0;
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
}
void PRINT() {
	int row = 0;
	int col = 0;
	for (row = 0; row < MAX_ROW; ++row) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW-1) {
			printf("|---|---|---|\n");
		}
	}

}
void PlayerMove() {
	printf("玩家落子！\n");
	while (1) {
		printf("请输入一组坐标（row，col）：\n");
			int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("您的输入非法！\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您的坐标已经有棋子了！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void ComputerMove() {
	printf("电脑落子!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ') {
			//有棋子
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
int isFull() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char CheckGameOver() {
	for (int row = 0; row < MAX_ROW;++row) {
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]) {
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; ++col) {
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]) {
			return chess_board[0][col];
		}
	}
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]) {
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]) {
		return chess_board[0][2];
	}
	if (isFull()) {
		return 'q';
	}
	return ' ';
}
void Game() {
	//创建棋盘，二维数组初始化 ‘ ’
	INIT();
	char winner;
	
	while (1) {
		system("cls");
		//打印棋盘
		PRINT();
		//让玩家落子，提示玩家输入落子位置的坐标
		PlayerMove();
		PRINT();
		//检测游戏是是否结束
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
		//让电脑落子，生成一对随机数
		ComputerMove();
		//检测游戏是否结束
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
	}
	system("cls");
	PRINT();	
	if (winner == 'x') {
		printf("玩家胜利！\n");
	}
	else if (winner == 'o') {
		printf("你还是太嫩了!\n");
	}
	else if (winner == 'q') {
		printf("平局了！\n");
	}
	else {
		printf("出错了！\n");
	}
}
int main() {
	
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		} else if (choice == 0) {
			printf("拜拜啦！\n");
			break;
		} else {
			printf("您的输入有误！\n");
		}
	}
	system("pause");
	return 0;
}