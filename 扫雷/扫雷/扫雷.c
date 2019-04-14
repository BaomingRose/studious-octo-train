#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu() {
	printf("***************\n");
	printf("** 1.��ʼ��Ϸ *\n");
	printf("** 0.������Ϸ *\n");
	printf("***************\n");
	printf("��ѡ��\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void INIT(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//δ�ƿ�����*���ƿ�������Χ�׵����ֱ�ʾ
	//���׵�λ����1��ʾ�����׵�λ����0��ʾ
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
	//10������
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
	//������ά�����ʾ��ͼ �ֱ��ʾ��û�� ��������
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	INIT(show_map, mine_map);
	//�Ѿ��������Ӹ�������Ҫ�ж��Ƿ�ȫ��������������
	int blank = 0;
	while (1) {
		system("cls");
		//����
		PrintMap(mine_map);
		printf("\n");
		//��ӡ��ͼ
		PrintMap(show_map);
		//��ʾ����������꣬��У��
		int row = 0;
		int col = 0;
		printf("���������һ�����꣨row col����\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("��������Ƿ������������룺\n");
			continue;
		}
		if (show_map[row][col] == '*') {
			printf("�������Ѿ������ˣ����������룺\n");
			continue;
		}
		//�ж��Ƿ����
		if (mine_map[row][col] == '1') {
			printf("�����ˣ���Ϸ������\n");
			PrintMap(mine_map);
			return;
		}
		//�ж��Ƿ��������ȫ�����������ɹ�
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
			printf("�ݰ��ˣ�\n");
			break;
		}
		else {
			printf("������������\n");
			continue;
		}
	}
	system("pause");
	return 0;
}