#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];
void menu() {
	printf("*********************\n");
	printf("****    1.play   ****\n");
	printf("****    0.exit   ****\n");
	printf("*********************\n");
}
//����һ���ַ��͵Ķ�ά���飨3��3����ʾ���̣�x��ʾ������ӣ�o��ʾ�������ӣ��� ����ʾδ���ӣ�
//1����Ϸ��ʼʱ�����г�ʼ������
void Init() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess_board[row][col] = ' ';
		}
	}
}
//��ӡһ��3*3������
void print() {
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("|---|---|---|\n");
	}
}
void playermove() {
	printf("�������!\n");
	while (1) {
		printf("����������λ�õ�����(row col):");
		int row = 0;;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("�������벻�Ϸ������������룡\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("��Ҫ���ӵ�λ���Ѿ���ռ���ˣ�\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("���������ϣ�\n");
}
void computermove(){
	printf("�������ӣ�\n");
	int row, col;
	//�жϵ�һ��
	if ((chess_board[0][0] == ' ') && (chess_board[0][1] == 'x') && (chess_board[0][2] == 'x')) {
		chess_board[0][0] = 'o';
	}
    else if ((chess_board[0][1] == ' ')&&(chess_board[0][0] == 'x') && (chess_board[0][2] == 'x')) {
		chess_board[0][1] = 'o';
	}
	else if ((chess_board[0][2] == ' ')&&(chess_board[0][0] == 'x') && (chess_board[0][1] == 'x')) {
		chess_board[0][2] = 'o';
	}
	//�жϵڶ���
	else if ((chess_board[1][0] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[1][2] == 'x')) {
		chess_board[1][0] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[1][2] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[1][2] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[1][1] == 'x')) {
		chess_board[1][2] = 'o';
	}
	//�жϵ�����
	else if ((chess_board[2][0] == ' ')&&(chess_board[2][1] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[2][0] = 'o';
	} else if ((chess_board[2][1] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[2][1] = 'o';
	}
    else if ((chess_board[2][2] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[2][1] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//�жϵ�һ��
	else if ((chess_board[0][0] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[2][0] == 'x')) {
		chess_board[0][0] = 'o';
	}
	else if ((chess_board[1][0] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[1][0] = 'o';
	}
	else if ((chess_board[2][0] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[2][0] = 'o';
	}
	//�жϵڶ���
	else if ((chess_board[0][1] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[2][1] == 'x')) {
		chess_board[0][1] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[2][1] == 'x'&&chess_board[0][1] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[2][1] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[0][1] == 'x')) {
		chess_board[2][1] = 'o';
	}
	//�жϵ�����
	else if ((chess_board[0][2] == ' ')&&(chess_board[1][2] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[0][2] = 'o';
	}
	else if ((chess_board[1][2] == ' ')&&(chess_board[2][2] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[1][2] = 'o';
	}
	else if ((chess_board[2][2] == ' ')&&(chess_board[1][2] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//�ж���Խ���
	else if ((chess_board[0][0] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[0][0] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[2][2] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[2][2] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//�ж��ҶԽ���
	else if ((chess_board[0][2] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[2][0] == 'x')) {
		chess_board[0][2] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[2][0] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[2][0] = 'o';
	}
	else 
	{	while (1) {
		row = rand() % 3;
		col = rand() % 3;
		 if (chess_board[row][col] != ' ') {
			continue;
			}
			else {
				chess_board[row][col] = 'o';
				break;
			}	
		}
	}	
}
int Isfull() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chess_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
//�÷���ֵ��ʾʤ������˭
//x��ʾ���ʤ��y��ʾ����ʤ��q��ʾƽ�֣��ÿո��ʾδ�ֳ�ʤ����
char check_winner() {
	for (int row = 0; row < MAX_ROW; row++) {
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]&& chess_board[0][2] != ' ') {
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col] && chess_board[0][0] != ' ') {
			return chess_board[0][col];
		}
	}
		if (chess_board[0][0] == chess_board[1][1]
		&& chess_board[0][0] == chess_board[2][2] && chess_board[1][1] != ' ') {
		return chess_board[0][0];
		}
	if (chess_board[0][2] == chess_board[1][1]
		&& chess_board[0][2] == chess_board[2][0] && chess_board[2][0] != ' ') {
		return chess_board[0][2];
		}
	if (Isfull()) {
		return 'q';
	}
	return ' ';
}
void game() {
	char winner = ' ';
//1����ʼ������
	Init();
	while (1) {
//2����ӡ����
	print();
//3���������
	playermove();
//4�����ʤ��
	winner = check_winner();
		if (winner != ' ') {
		break;
		}
//5����������
	computermove();
//6�����ʤ��
	winner = check_winner();
		if (winner != ' ') {
		break;
		}
	}
	print();
	if (winner == 'x') {
		printf("��Ӯ�ˣ�\n");
	}
	else if (winner == 'o') {
		printf("����ˣ������Զ��²�����\n");
	}
	else if (winner == 'q') {
		printf("���͵��Դ��ƽ�֣�\n");
	}
	else {
		printf("��������ˣ�\n");
	}
}
int main() {
	srand((unsigned)time(0));
	int input = 0;
	while (1) {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		if (input == 1) {
			game();
		}
		else if (input == 0) {
			printf("�˳���Ϸ��\n");
			break;
		}
		else {
			printf("���������������������룺\n");
		}
	}
	system("pause");
	return 0;
}
	
