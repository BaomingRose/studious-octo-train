#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>
char chess_board[MAX_ROW][MAX_COL];
int Menu() {
	printf("**************\n");
	printf("**1.��ʼ��Ϸ**\n");
	printf("**0.������Ϸ**\n");
	printf("**************\n");
	printf("��ѡ��\n");
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
	printf("������ӣ�\n");
	while (1) {
		printf("������һ�����꣨row��col����\n");
			int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("��������Ƿ���\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("���������Ѿ��������ˣ�\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void ComputerMove() {
	printf("��������!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ') {
			//������
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
	//�������̣���ά�����ʼ�� �� ��
	INIT();
	char winner;
	
	while (1) {
		system("cls");
		//��ӡ����
		PRINT();
		//��������ӣ���ʾ�����������λ�õ�����
		PlayerMove();
		PRINT();
		//�����Ϸ���Ƿ����
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
		//�õ������ӣ�����һ�������
		ComputerMove();
		//�����Ϸ�Ƿ����
		winner = CheckGameOver();
		if (winner != ' ') {
			break;
		}
	}
	system("cls");
	PRINT();	
	if (winner == 'x') {
		printf("���ʤ����\n");
	}
	else if (winner == 'o') {
		printf("�㻹��̫����!\n");
	}
	else if (winner == 'q') {
		printf("ƽ���ˣ�\n");
	}
	else {
		printf("�����ˣ�\n");
	}
}
int main() {
	
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			Game();
		} else if (choice == 0) {
			printf("�ݰ�����\n");
			break;
		} else {
			printf("������������\n");
		}
	}
	system("pause");
	return 0;
}