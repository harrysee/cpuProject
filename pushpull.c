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
	PlaySound(TEXT("push.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
	gotoxy(34, 5);
	printf("���  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ����");
	gotoxy(34, 7);
	printf("|                     �ް�����                     |");
	gotoxy(34, 9); 
	printf("|    ���� �ڽ��� ���ϴ� ��� �� �ϳ��� �����մϴ�    |");
	gotoxy(34, 11);
	printf("|     ���̸� ������ ���ѽð� �ȿ� ��ư��� �˴ϴ�    |");
	gotoxy(34, 13);
	printf("|      ���̸� �� �������ϸ� ������ �����Դϴ�        |");
	gotoxy(34, 15);
	printf("���  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �ߡ�");

	x = 100;
	y = 2;
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|_��");
	print_auto_y(&x, &y, "|��|��0` )");
	print_auto_y(&x, &y, "|��|�� ��");
	print_auto_y(&x, &y, "|��|L");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");
	print_auto_y(&x, &y, "|��|");


	x = 45;
	y = 21;
	print_auto_y(&x, &y, "������");
	print_auto_y(&x, &y, "����");
	print_auto_y(&x, &y, "������   ����");
	print_auto_y(&x, &y, "������ (0 �� 0)");
	print_auto_y(&x, &y, "�����������Ϧ�����������");
	print_auto_y(&x, &y, "�� ����  �� �����ۦ����ۦ�");
	print_auto_y(&x, &y, "���ݦ����ݦ����ݦ����ݦ�");
	print_auto_y(&x, &y, "-----------------------------------------------------");

	x = 1;
	y = 20;
	print_auto_y(&x, &y, "            ,===,==, ");
	print_auto_y(&x, &y, "           ||__|��|| ");
	print_auto_y(&x, &y, "	    l|�ߡ� ���� ");
	print_auto_y(&x, &y, "	   |��|���� ����--�� ");
	print_auto_y(&x, &y, "	   |Ϣ|������(   0��0) ");
	print_auto_y(&x, &y, "	   |Ϣ|�������� �� �� ");
	print_auto_y(&x, &y, "	   |Ϣ|�� �� �����Īġ� ");
	print_auto_y(&x, &y, "	   |Ϣ|����������| ����| ");
	print_auto_y(&x, &y, "     ------------------------------------------------");

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
	gotoxy(45, 9);
	printf("���ϴ� ����� �����Ͻÿ�.");
	gotoxy(45, 12);
	printf("�� ");
	gotoxy(56, 12);
	printf("��");
	gotoxy(68, 12);
	printf("��");
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