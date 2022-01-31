#include "pushpull.h"
#include <conio.h>
#include <windows.h>

// _getch() value of ESC key
#define MAGIC_KEY 224
#define ESC 27
#define A 65
#define a 97
#define L 76
#define l 108
#define ENTER 13

void game_fun(void);
void start_game(void);

char key;
char t_name1[20];
char t_name2[20];
int x = 40;
int y = 11;
int win = 0;
int win_lose = 0;
int input = 0;

enum MENU
{
	GAMESTART = 0,
	EXIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

// ���� ���� ���� �Լ�
void pushpull() {
	system("cls");
	PlaySound(TEXT("happy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1) {
		switch (game()) {
		case GAMESTART:
			x = 40;
			start_game();
			break;

		case EXIT:
			PlaySound(NULL, 0, 0);
			main();

			break;
		}
	}
	return 0;
}

// ���� ����ȭ�� �Լ�
void main_show() {
	system("cls");
	gotoxy(36, 5);
	printf("               ���� �ٴٸ��� ����");
	gotoxy(36, 7);
	printf("��          �̹������� �ٴٸ��� �Դϴ�          ��");
	gotoxy(36, 9);
	printf("�� A�� LŰ ��Ÿ�� ������ ����� ���� ����Դϴ� ��");
	gotoxy(36, 11);
	printf("��       �׷� ���ӽ��� ������ �������ּ���      ��");
	gotoxy(36, 13);
	printf("��               �������� = �޴�ȭ��            ��");
	gotoxy(36, 15);
	printf("����  �ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�    ����");

	gotoxy(40, 17);
	printf("��");
	gotoxy(39, 18);
	printf("��|/");
	gotoxy(40, 19);
	printf("456");
	gotoxy(40, 20);
	printf("/��");

	x = 6;
	y = 5;
	print_auto_y(&x, &y, " ./���ߣ���");
	print_auto_y(&x, &y, " �� _/��_ ��");
	print_auto_y(&x, &y, " |������ ����i");
	print_auto_y(&x, &y, " ��= (_��_) ");
	print_auto_y(&x, &y, "   ========");
	print_auto_y(&x, &y, "  �������ҡ�/��)��������������");
	print_auto_y(&x, &y, ". /���������ߣ���");
	print_auto_y(&x, &y, ". |��������");
	print_auto_y(&x, &y, "  �� ��_����");
	print_auto_y(&x, &y, "   ��/.��_/");

	x = 90;
	y = 10;
	print_auto_y(&x, &y, "             ���ҡ�");
	print_auto_y(&x, &y, "           ����   ��");
	print_auto_y(&x, &y, "	    /������  ��");
	print_auto_y(&x, &y, "	   /��������   ��");
	print_auto_y(&x, &y, "	   ( / �� ��    )");
	print_auto_y(&x, &y, "	   f  ��       ��");
	print_auto_y(&x, &y, "	   | �ܡ����ܡ���");
	print_auto_y(&x, &y, "	   |�� �䡡������");
	print_auto_y(&x, &y, "         |�ߣ� �� ����");
	print_auto_y(&x, &y, "	   ���������ˣ�l��");
	print_auto_y(&x, &y, "	   ��(_(_(��L��)��");



	gotoxy(77, 17);
	printf(" ��");
	gotoxy(76, 18);
	printf("��|/");
	gotoxy(77, 19);
	printf("001");
	gotoxy(77, 20);
	printf("/��");

	gotoxy(56, 18);
	printf("���� ����");

	gotoxy(56, 20);
	printf("���� ����");

	print_by_name("������ ����� ������");
}

// �޴� ���� Ŀ�� �Լ�
enum MENU game() {
	int y = 0;
	while (1) {
		main_show();

		if (y <= 0)
		{
			y = 0;
		}
		else if (y >= 4)
		{
			y = 2;
		}

		gotoxy(53, 18 + y);
		printf(">");

		input = _getch();

		if (input == MAGIC_KEY)
		{
			switch (_getch())
			{
			case UP:
				gotoxy(53, 18 + y);
				printf("  ");
				y = y - 2;
				break;
			case DOWN:
				gotoxy(53, 18 + y);
				printf("  ");
				y = y + 2;
				break;
			}
		}
		else if (input == 13)
		{
			switch (y)
			{
			case 0:
				return GAMESTART;
			case 2:
				return EXIT;
			}
		}
	}
}


// �ٴٸ��� �׷��ִ� �Լ�
void line(int x, int y)
{
	system("cls");
	int i, line[41] = { 0 };
	line[20] = 1;
	line[8] = 2;
	line[32] = 2;
	gotoxy(31, 13);
	for (i = 0; i < 78; i++)
		printf(" ");

	gotoxy(28, 8);
	printf("%s", t_name1);
	gotoxy(86, 8);
	printf("%s", t_name2);

	int peple = 0;
	gotoxy(x - 16, 10);
	printf("��  �� �� ��  ��  ��  �� ��");
	gotoxy(x - 16, 11);
	printf("����࡬�࡬���࡬��࡬��࡬");
	gotoxy(x - 15, 12);
	printf("| | |  |  | | | | |");
	gotoxy(x - 16, 13);
	printf("/��/��/��/��/��/��/��");

	gotoxy(x + 37, 10);
	printf("  ��  ��  ��  �� �� ��  �� ��");
	gotoxy(x + 34, 11);
	printf("/��/��/����/|��/����/��/��/��/");
	gotoxy(x + 37, 12);
	printf(" | | | |  |  | | | |");
	gotoxy(x + 37, 13);
	printf("/��/��/��/��/��/��/��");

	gotoxy(0, 14);
	printf("����������������������������������������������");
	gotoxy(77, 14);
	printf("�������������������������������������������");

	gotoxy(40, 24);
	printf("�� ��__ /_          /��/__-_       ����_   _/  (");
	gotoxy(20, 25);
	printf("�������������������������������������������������������������������������������������������");
	gotoxy(42, 2);
	printf("�������� �ʴ´ٸ� �ѿ�Ű �ٲٱ�!");

	// x,y�Լ��� line�׷��� x =40, y = 11
	gotoxy(x, 11);
	for (i = 0; i < 41; i++)
		if (line[i] == 0)
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");

	gotoxy(58, 8);
	printf("������");
	gotoxy(60, 10);
	printf("��");
	gotoxy(60, 12);
	printf("��");


	gotoxy(45, 26);
	printf("�޴��� ���ư����� ESC�� �����ּ���\n");

	char end = _getch();
	if (end == ESC) {
		pushpull();
	}
}

void start_game() {
	system("cls");
	gotoxy(62, 12);
	printf("VS");
	gotoxy(45, 9);
	printf("������ ������ �� ����� �����Ͻʽÿ�\n");
	gotoxy(25, 12);
	printf("ù��° �� �̸��Է� �� ����> ");
	scanf_s("%s", &t_name1, 20);
	gotoxy(68, 12);
	printf("�ι�° �� �̸��Է� �� ����> ");
	scanf_s("%s", &t_name2, 20);
	// �̸� �Է� �� ȭ�� �����
	system("cls");
	//line �׷���
	line(x, y);
	//�����Լ� ����
	game_fun();
}

void game_fun() {
	while (1) {
		char click = _getch();

		switch (click) {
		case A: case a: // A
			x -= 2;
			line(x, y);
			Sleep(100);
			if (x == 28) {
				gotoxy(78, 14);
				printf("                                         ");
				Sleep(500);
				system("color 40");
				Sleep(1000);
				system("color 0C");
				system("cls");
				print_by_text(t_name1);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}
			break;

		case L: case l: // L
			x += 2;
			line(x, y);
			Sleep(100);
			if (x == 52) {
				gotoxy(0, 14);
				printf("                                              ");
				Sleep(500);
				system("color 40");
				Sleep(1000);
				system("color 0C");
				system("cls");
				print_by_text(t_name1);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}
			break;
		case ESC:
			pushpull();
		}
	}
}