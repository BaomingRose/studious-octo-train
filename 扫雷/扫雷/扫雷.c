#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu() {
	printf("***************\n");
	printf("** 1.开始游戏 *\n");
	printf("** 0.结束游戏 *\n");
	printf("***************\n");
	printf("请选择：\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void INIT(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//未掀开的用*，掀开的用周围雷的数字表示
	//有雷的位置用1表示，无雷的位置用0表示
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col <= MAX_COL; ++col) {
			show_map[row][col] = 'x';
		}
	}
	for (int row = 0; row <= MAX_ROW; ++row) {
		for (int col = 0; col <= MAX_COL; ++col) {
			mine_map[row][col] = '0';
		}
	}
	//10个地雷
	int mine_count = 10;
	while (mine_count > 0) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]) {
	printf("   |");
	for (int col = 0; col < MAX_COL; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW ; ++row) {
		printf(" %d |", row);
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int  row,int  col, char mine_map[MAX_ROW][MAX_COL], char show_map[MAX_ROW][MAX_COL]) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && mine_map[row - 1][col] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 < MAX_COL && mine_map[row - 1][col] == '1') {
		++count;
	}
	if (col - 1 >= 0 && mine_map[row][col - 1] == '1') {
		++count;
	}
	if (mine_map[row][col] == '1') {
		++count;
	}
	if ( col + 1 < MAX_COL && mine_map[row][col + 1] == '1') {
		++count;
	}
	if (col - 1 >= 0 && row + 1 < MAX_COL && mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (row + 1 < MAX_COL && mine_map[row + 1][col] == '1') {
		++count;
	}
	if (col + 1 < MAX_ROW && row + 1 < MAX_COL && mine_map[row + 1][col + 1] == '1') {
		++count;
	}
	show_map[row][col] = count + '0';
}
void Game() {
	//两个二维数组表示地图 分别表示翻没翻 和有无雷
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	INIT(show_map, mine_map);
	//已经翻开格子个数，需要判定是否全部翻开非雷坐标
	int blank = 0;
	while (1) {
		system("cls");
		//调试
		PrintMap(mine_map);
		printf("\n");
		//打印地图
		PrintMap(show_map);
		//提示玩家输入坐标，并校验
		int row = 0;
		int col = 0;
		printf("请玩家输入一组坐标（row col）：\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您的输入非法！请重新输入：\n");
			continue;
		}
		if (show_map[row][col] == '*') {
			printf("该坐标已经翻过了！请重新输入：\n");
			continue;
		}
		//判断是否踩雷
		if (mine_map[row][col] == '1') {
			printf("踩雷了！游戏结束！\n");
			PrintMap(mine_map);
			return;
		}
		//判定是否非雷坐标全部翻开，即成功
		++blank;
		if (blank == MAX_ROW * MAX_COL - 10) {
			
			PrintMap(mine_map);
			return;
		}
		UpdateShowMap(row, col, mine_map, show_map);
		PrintMap(show_map);
	}
}
int main() {
	srand((unsigned int)time(0));
	while (1) {
		int chioce = Menu();
		if (chioce == 1) {
			 Game();
		}
		else if (chioce == 0) {
			printf("拜拜了！\n");
			break;
		}
		else {
			printf("您的输入有误！\n");
			continue;
		}
	}
	system("pause");
	return 0;
}