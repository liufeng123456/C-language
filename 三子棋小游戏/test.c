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
//创建一个字符型的二维数组（3×3）表示棋盘（x表示玩家落子，o表示电脑落子，‘ ’表示未落子）
//1、游戏开始时，进行初始化棋盘
void Init() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess_board[row][col] = ' ';
		}
	}
}
//打印一个3*3的棋盘
void print() {
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("|---|---|---|\n");
	}
}
void playermove() {
	printf("玩家落子!\n");
	while (1) {
		printf("请输入落子位置的坐标(row col):");
		int row = 0;;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您的输入不合法，请重新输入！\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您要落子的位置已经被占用了！\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("玩家落子完毕！\n");
}
void computermove(){
	printf("电脑落子：\n");
	int row, col;
	//判断第一行
	if ((chess_board[0][0] == ' ') && (chess_board[0][1] == 'x') && (chess_board[0][2] == 'x')) {
		chess_board[0][0] = 'o';
	}
    else if ((chess_board[0][1] == ' ')&&(chess_board[0][0] == 'x') && (chess_board[0][2] == 'x')) {
		chess_board[0][1] = 'o';
	}
	else if ((chess_board[0][2] == ' ')&&(chess_board[0][0] == 'x') && (chess_board[0][1] == 'x')) {
		chess_board[0][2] = 'o';
	}
	//判断第二行
	else if ((chess_board[1][0] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[1][2] == 'x')) {
		chess_board[1][0] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[1][2] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[1][2] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[1][1] == 'x')) {
		chess_board[1][2] = 'o';
	}
	//判断第三行
	else if ((chess_board[2][0] == ' ')&&(chess_board[2][1] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[2][0] = 'o';
	} else if ((chess_board[2][1] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[2][1] = 'o';
	}
    else if ((chess_board[2][2] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[2][1] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//判断第一列
	else if ((chess_board[0][0] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[2][0] == 'x')) {
		chess_board[0][0] = 'o';
	}
	else if ((chess_board[1][0] == ' ')&&(chess_board[2][0] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[1][0] = 'o';
	}
	else if ((chess_board[2][0] == ' ')&&(chess_board[1][0] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[2][0] = 'o';
	}
	//判断第二列
	else if ((chess_board[0][1] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[2][1] == 'x')) {
		chess_board[0][1] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[2][1] == 'x'&&chess_board[0][1] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[2][1] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[0][1] == 'x')) {
		chess_board[2][1] = 'o';
	}
	//判断第三列
	else if ((chess_board[0][2] == ' ')&&(chess_board[1][2] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[0][2] = 'o';
	}
	else if ((chess_board[1][2] == ' ')&&(chess_board[2][2] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[1][2] = 'o';
	}
	else if ((chess_board[2][2] == ' ')&&(chess_board[1][2] == 'x'&&chess_board[0][2] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//判断左对角线
	else if ((chess_board[0][0] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[2][2] == 'x')) {
		chess_board[0][0] = 'o';
	}
	else if ((chess_board[1][1] == ' ')&&(chess_board[2][2] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[1][1] = 'o';
	}
	else if ((chess_board[2][2] == ' ')&&(chess_board[1][1] == 'x'&&chess_board[0][0] == 'x')) {
		chess_board[2][2] = 'o';
	}
	//判断右对角线
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
//用返回值表示胜利者是谁
//x表示玩家胜，y表示电脑胜，q表示平局，用空格表示未分出胜负；
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
//1、初始化棋盘
	Init();
	while (1) {
//2、打印棋盘
	print();
//3、玩家落子
	playermove();
//4、检测胜负
	winner = check_winner();
		if (winner != ' ') {
		break;
		}
//5、电脑落子
	computermove();
//6、检测胜负
	winner = check_winner();
		if (winner != ' ') {
		break;
		}
	}
	print();
	if (winner == 'x') {
		printf("您赢了：\n");
	}
	else if (winner == 'o') {
		printf("您真菜，连电脑都下不过：\n");
	}
	else if (winner == 'q') {
		printf("您和电脑打成平手：\n");
	}
	else {
		printf("代码出错了：\n");
	}
}
int main() {
	srand((unsigned)time(0));
	int input = 0;
	while (1) {
		menu();
		printf("请选择：");
		scanf("%d", &input);
		if (input == 1) {
			game();
		}
		else if (input == 0) {
			printf("退出游戏：\n");
			break;
		}
		else {
			printf("您的输入有误，请重新输入：\n");
		}
	}
	system("pause");
	return 0;
}
	
