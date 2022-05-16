#include <stdio.h>   //ǥ����������
#include <stdlib.h>   //malloc, free ��
#include <Windows.h>//windows console api ���
#include <time.h>   //���� �õ�� time �Լ� ���
#include <conio.h>   //gotoxyD���� ����� api ���
#include "dalgona.h"

#define MAGIC_KEY 224
#define FIELD_WIDTH 65   //�ʵ尡�α���
#define FIELD_HEIGHT 25   //�ʵ弼�α���
#define LEFT 75         //Ű���� �� ȭ��ǥ�� char��
#define RIGHT 77      //Ű���� ��
#define UP 72         //Ű���� ��
#define DOWN 80         //������ �Ʒ�
#define ITEM_GOLD 101   //��� ������ �ε�������
#define ITEM_EXP 102   //����ġ ������ �ε�������
#define LEFT_MARGIN 25   //ȭ����ʸ���(����)
#define TOP_MARGIN 3   //ȭ�� ��ܸ���(����)
#define DELAYTIME 200   //Sleep�Լ��� �� x/1000 �� (�����̼ӵ�/������200)��
#define TIMER 40.0   //Sleep�Լ��� �� x/1000 ��

#define SHAPES_SIZE 2
#define SHAPES_CIRCLE 54
#define SHAPES_ANGLE 40
#define SHAPES_SQUARE 56

int inputkey = 0;
int mode = 1;    // ��翡 ���� �迭���� 
char* mshape = 'o';
clock_t start;   // Ÿ�̸� ���ӽ��۽ð� 
double limit = TIMER;   // ���� �ð�
int(*shapes)[2];    // ��� �׸� ��ġ�迭

void printstart();
void playgame();
void selectShape();
void timerlimit();

enum MENU
{
    GAMESTART = 0,
    EXIT
};

//�����̸� ������ ���߿��Ḯ��Ʈ ����ü
#pragma pack(push,1)
typedef struct _WORM
{
    int x;   //x��ǥ
    int y;   //y��ǥ
    char direction;   //�������
    struct _WORM* next;   //��������ּ�
    struct _WORM* before;//��������ּ�
}WORM, * pWORM;

//Ŀ���� ���� ��ǥ�� �̵�
void gotoxyD(int x, int y)
{
    COORD Pos;
    Pos.X = x + LEFT_MARGIN;//���μ��� ������ ���߱� ���ؼ� ������ ��ǥ�� 2��
    Pos.Y = y + TOP_MARGIN;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
// ùȭ�� �������� ���� Ŀ�� �Լ�
enum MENU gamemenu() {
    int y = 0;
    while (1) {
        printstart();

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

        inputkey = _getch();

        if (inputkey == MAGIC_KEY)
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
        else if (inputkey == 13)
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

// ���� ����ȭ�� 
void printstart() {
    int x = 40;
    int y = 11;
    system("cls");
    gotoxy(34, 5);
    printf("���  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ����");
    gotoxy(34, 7);
    printf("|                   ���� �̱� ����                   |");
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
    print_auto_y(&x, &y, "       l|�ߡ� ���� ");
    print_auto_y(&x, &y, "      |��|���� ����--�� ");
    print_auto_y(&x, &y, "      |Ϣ|������(   0��0) ");
    print_auto_y(&x, &y, "      |Ϣ|�������� �� �� ");
    print_auto_y(&x, &y, "      |Ϣ|�� �� �����Īġ� ");
    print_auto_y(&x, &y, "      |Ϣ|����������| ����| ");
    print_auto_y(&x, &y, "     ------------------------------------------------");

    gotoxy(56, 18);
    printf("���� ����");

    gotoxy(56, 20);
    printf("���� ����");

    print_by_name("������ ������ �����");
}

// ���ӽ��� ��������ó�� �Լ�
void dalgona() {
    system("cls");
    //PlaySound(TEXT("push.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    while (1) {
        switch (gamemenu()) {
        case GAMESTART:
            selectShape();
            //break;

        case EXIT:
            //PlaySound(NULL, 0, 0);
            main();
            break;
        }
    }
}

// ���� ��缱�� �Լ�
void printShape() {
    int x = 10;
    int y = 20;
    system("cls");
    gotoxy(34, 5);
    printf("���  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ����");
    gotoxy(34, 7);
    printf("|     ���� ��� �ϳ��� ������ �̵��Ͻñ�ٶ��ϴ�.    |");
    //gotoxy(45, 9);
    //printf("���ݺ��� ������ �����ϰڽ��ϴ�");
    gotoxy(34, 9);
    printf("|    ���͸� ������ Ÿ�̸ӿ� �Բ� ������ �����մϴ�.  |");
    gotoxy(34, 11);
    printf("���  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �ߡ�");


    print_auto_y(&x, &y, "            �ۡۡۡ�    ");
    print_auto_y(&x, &y, "          ��        ��");
    print_auto_y(&x, &y, "	   ��          ��");
    print_auto_y(&x, &y, "	    ��        ��");
    print_auto_y(&x, &y, "	      �ۡۡۡ�   ");
    print_auto_y(&x, &y, "	             ");
    print_auto_y(&x, &y, "	    ");
    print_auto_y(&x, &y, "	  ");
    print_auto_y(&x, &y, "     ");

    x = 40;
    y = 20;
    print_auto_y(&x, &y, "             ��     ");
    print_auto_y(&x, &y, "           ��   ��");
    print_auto_y(&x, &y, "	  ��      ��");
    print_auto_y(&x, &y, "	 ��         ��");
    print_auto_y(&x, &y, "	�� �� �� ��  ��   ");
    print_auto_y(&x, &y, "	            ");
    print_auto_y(&x, &y, "	    ");
    print_auto_y(&x, &y, "	  ");
    print_auto_y(&x, &y, "     ");

    x = 70;
    y = 20;
    print_auto_y(&x, &y, "         ��������");
    print_auto_y(&x, &y, "         ��          ��");
    print_auto_y(&x, &y, "	       ��          ��");
    print_auto_y(&x, &y, "	       ��          ��");
    print_auto_y(&x, &y, "	       ��          ��   ");
    print_auto_y(&x, &y, "	       ��������    ");
    print_auto_y(&x, &y, "	  ");
    print_auto_y(&x, &y, "     ");
}
void selectShape() {
    system("cls");
    int kx = 24;
    int ky = 15;
    int gap = 30;

    while (1) {
        printShape();
        if (kx > 24 + gap * 2) {
            kx = 24 + gap * 2;
        }
        else if (kx < 20) {
            kx = 20;
        }
        gotoxy(kx, ky);
        printf("����,,��");
        gotoxy(kx, ky + 1);
        printf("(-����0-)");
        gotoxy(kx, ky + 2);
        printf("��(O O)");
        gotoxy(kx, ky + 3);
        printf("�� T-T");

        inputkey = _getch();
        if (inputkey == MAGIC_KEY) // ����Ű
        {
            switch (_getch())
            {
            case LEFT:
                gotoxy(kx, ky);
                printf("  ");
                gotoxy(kx, ky + 1);
                printf("    ");
                gotoxy(kx, ky + 2);
                printf("   ");
                kx -= gap;
                break;
            case RIGHT:
                gotoxy(kx, ky);
                printf("  ");
                gotoxy(kx, ky + 1);
                printf("    ");
                gotoxy(kx, ky + 2);
                printf("   ");
                kx += gap;
                break;
            }
        }
        else if (inputkey == 13)   // ����
        {
            switch (kx)
            {
            case 24:
                mode = modeSize(1);
                shapes = shape1();
                mshape = "o";
                break;
            case 24 + 30:
                mode = modeSize(2);
                shapes = shape2();
                mshape = "��";
                break;
            case 24 + 30 * 2:
                mode = modeSize(3);
                shapes = shape3();
                mshape = "��";
                break;
            }
            gotoxy(0, 0);
            for (int i = 0; i < 4; i++) {
                printf("%d\n", shapes[i][0]);
            }
            playgame();
            return 0;
        }
    }
}


//���ӿ������
void PrintField()
{
    for (int i = 1; i < FIELD_WIDTH; i++)
    {
        gotoxyD(i, 0);
        printf("��");
        gotoxyD(i, FIELD_HEIGHT);
        printf("��");
    }

    for (int i = 1; i < FIELD_HEIGHT; i++)
    {
        gotoxyD(0, i);
        printf("��");
        gotoxyD(FIELD_WIDTH, i);
        printf("��");
    }
    gotoxyD(0, 0);
    printf("��");
    gotoxyD(0, FIELD_HEIGHT);
    printf("��");
    gotoxyD(FIELD_WIDTH, 0);
    printf("��");
    gotoxyD(FIELD_WIDTH, FIELD_HEIGHT);
    printf("��");
}

//�����̸� �ø��� �Լ�(���߿��Ḯ��Ʈ�� �����ʿ� ��� �߰�)
void AddWorm(pWORM wormTailNode)
{
    pWORM newNode = malloc(sizeof(WORM));
    pWORM temp = wormTailNode->next;

    //�� ����� �ּڰ� �̾��ֱ�;
    newNode->before = wormTailNode;
    newNode->next = wormTailNode->next;
    wormTailNode->next = newNode;
    newNode->next->before = newNode;
    newNode->direction = temp->direction;
    newNode->x = temp->x;
    newNode->y = temp->y;
    switch (temp->direction)
    {
    case LEFT:
        newNode->x = newNode->x + 1;
        break;
    case RIGHT:
        newNode->x = newNode->x - 1;
        break;
    case UP:
        newNode->y = newNode->y + 1;
        break;
    case DOWN:
        newNode->y = newNode->y - 1;
        break;
    default:
        break;
    }


}

//���Ḯ��Ʈ�� �޾Ƽ� ������ ���
void PrintWorm(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr = wormTailNode->next;
    while (curr != wormHeadNode)
    {
        gotoxyD(curr->x, curr->y);
        printf("@");
        curr = curr->next;
    }
}

//�������� ���
void PrintScore(int score, int left)
{
    gotoxyD(FIELD_WIDTH + 3, 3);
    printf("%s �߸��ް����� : %d��", mshape, score);
    gotoxyD(FIELD_WIDTH + 3, 5);
    printf("%s �����ް����� : %d��", mshape, left);
    gotoxy(FIELD_WIDTH / 2 + 15, 29);
    printf("�����Ϸ��� ESC�� �����ÿ�");
}

//���� ������ �ڸ� �����
void ClearWorm(int x, int y)
{
    if (x == x && y == y) {
        gotoxyD(x, y);
        printf(" ");
    }

    printf(" ");
}

//�� �����̱� 
void MoveWorm(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr;

    curr = wormTailNode->next;
    while (curr != NULL && curr != wormHeadNode->before)
    {
        curr->x = curr->next->x;
        curr->y = curr->next->y;
        curr = curr->next;
    }
    curr = wormHeadNode->before;
    if (curr->direction == LEFT)
    {
        curr->x--;
    }
    else if (curr->direction == RIGHT)
    {
        curr->x++;
    }
    else if (curr->direction == UP)
    {
        curr->y--;
    }
    else if (curr->direction == DOWN)
    {
        curr->y++;
    }
}


//�� ����Ʈ�� �Ҵ�� �޸𸮸� ������ ����
void FreeWormList(pWORM wormTailNode)
{
    pWORM curr;
    pWORM temp;
    curr = wormTailNode;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

//������(�����)�� ���� ��尡 �������� �˻�, 
// left, result�� ���������� �������� �Ѱ���
int CheckItemHit(pWORM wormHeadPointer, int* left, int* result)
{
    for (int i = 0; i < mode; i++) {
        if (wormHeadPointer->x == (shapes[i][0] - LEFT_MARGIN) && wormHeadPointer->y == (shapes[i][1] - TOP_MARGIN)) {
            *result += 1;   // �������� ������Ʈ
            *left -= 1;     // �������� ������Ʈ
            shapes[i][0] = 0;
            continue;
        }
        if (shapes[i][0] > 0) {
            gotoxyD(shapes[i][0] - LEFT_MARGIN, shapes[i][1] - TOP_MARGIN);
            printf("o");
        }
    }

    return 1;
}

// Ÿ�̸�
void timerlimit() {
    clock_t end = clock();
    double time = ((double)(end - start)) / CLOCKS_PER_SEC; //�ʴ��� ��ȯ
    limit = TIMER - time;
    gotoxy(FIELD_WIDTH / 2 + 20, 1);
    printf("[ Ÿ�̸� : %0.2lf ]\n", limit); //�Ҽ��� ��° �ڸ�����
    gotoxy(FIELD_WIDTH / 2 + 20, 2);
    printf("    ||      ||"); //�Ҽ��� ��° �ڸ�����
}

void playgame()
{
    pWORM wormHeadNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ �����
    pWORM wormTailNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ ���ϳ��
    pWORM addWorm = malloc(sizeof(WORM));//ù��° ������ 

    wormHeadNode->next = NULL;
    wormHeadNode->before = addWorm;
    addWorm->next = wormHeadNode;
    addWorm->before = wormTailNode;
    addWorm->x = FIELD_WIDTH / 2;
    addWorm->y = FIELD_HEIGHT / 2;
    addWorm->direction = RIGHT;
    wormTailNode->next = addWorm;
    wormTailNode->before = NULL;

    //������ ���ӽ��� ������ ����
    for (int i = 9; i > 0; i--)
        AddWorm(wormTailNode);

    //���� �Ӹ��� ����Ű�� ������
    pWORM wormHeadPointer = addWorm;

    int score = 0;         //��������
    char key;            //Ű�Է¹��� ����
    start = clock();   //���� �ð�
    int left = mode;
    int result = 0;

    system("cls");   //ȭ�������
    PrintField();   //�ʵ� ���


    while (1)
    {
        //�׽�Ʈ�� ��ºκ�
        //gotoxyD(-LEFT_MARGIN, 0);
        //PrintItemList(itemNode);
        timerlimit();
        if (_kbhit() != 0)
        {
            key = _getch();
            if (key == 27)  // escŰ ����������
            {
                printf("%c", key);
                break;
            }
            if (key == LEFT && wormHeadPointer->direction != RIGHT)
            {
                wormHeadPointer->direction = LEFT;
            }
            else if (key == RIGHT && wormHeadPointer->direction != LEFT)
            {
                wormHeadPointer->direction = RIGHT;
            }
            else if (key == UP && wormHeadPointer->direction != DOWN)
            {
                wormHeadPointer->direction = UP;
            }
            else if (key == DOWN && wormHeadPointer->direction != UP)
            {
                wormHeadPointer->direction = DOWN;
            }
        }

        //�� ������ �ڸ� �����
        ClearWorm(wormTailNode->next->x, wormTailNode->next->y);

        //�� ��ĭ�� �����̱�
        MoveWorm(wormTailNode, wormHeadNode);

        //���� �ε����� ���ӿ���
        if (wormHeadPointer->x == 0 || wormHeadPointer->x == FIELD_WIDTH || wormHeadPointer->y == 0 || wormHeadPointer->y == FIELD_HEIGHT)
        {
            system("cls");
            gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2);
            printf("���� �ε������ϴ�. GAME OVER");
            Sleep(2000);
            break;
        }

        //�ð� �ٵŸ� ����
        if (limit <= 0.0) {
            system("cls");
            gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2);
            printf("%d", result);
            gotoxyD(FIELD_WIDTH / 2 - 7, FIELD_HEIGHT / 2);
            printf("��ŭ ��������ϴ�");
            gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 2);
            printf("%d", left);
            gotoxyD(FIELD_WIDTH / 2 - 7, FIELD_HEIGHT / 2 - 2);
            printf("��ŭ ���ҽ��ϴ�");

            // Sleep(2000);
            // break;
            if (result <= 10)
            {
                //system("cls");
                gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 4);
                printf("10���� ���� ���߽��ϴ�. ���� ���");
                Sleep(2000);
                break;
            }
            if (result <= 20)
            {
                //system("cls");
                gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 4);
                printf("���ݵ� ���� ���߽��ϴ�. ���� ���");
                Sleep(2000);
                break;
            }

            if (result <= 30)
            {
                //system("cls");
                gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 4);
                printf("�������� ������ϴ�. �׷��� ���");
                Sleep(2000);
                break;
            }
            if (result <= 40)
            {
                //system("cls");
                gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 4);
                printf("���� �� ����µ�.. �Ʊ��� ��� ");
                Sleep(2000);
                break;
            }
            if (result <= 50)
            {
                //system("cls");
                gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 4);
                printf("��¥ �̼��� ���̷� ���...");
                Sleep(2000);
                break;
            }




        }
        // ������ ���
        CheckItemHit(wormHeadPointer, &left, &result);
        score = result * 100;

        //������ �� ������ ����
        if (left <= 0)
        {
            system("cls");
            gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2);
            printf("�����, ���� �������� �Ѿ�ϴ١�");
            gotoxyD(FIELD_WIDTH / 2 - 10, FIELD_HEIGHT / 2 - 5);
            printf("�۽ð��� %0.2lf\n", limit);

            Sleep(2000);
            break;
        }

        PrintWorm(wormTailNode, wormHeadNode);
        PrintScore(result, left);
        Sleep(DELAYTIME);
    }
    FreeWormList(wormTailNode);
}


// shape ----------------------------------------

int(*shape1())[SHAPES_SIZE];
int(*shape2())[SHAPES_SIZE];
int(*shape3())[SHAPES_SIZE];
int modeSize(int);

int modeSize(int mode) {
    switch (mode)
    {
    case 1:
        return SHAPES_CIRCLE;
    case 2:
        return SHAPES_ANGLE;
    default:
        return SHAPES_SQUARE;
        break;
    }
}
int(*shape1())[SHAPES_SIZE] {
    static int shapes[SHAPES_CIRCLE][SHAPES_SIZE] = { 0 };
    shapes[0][0] = 43; shapes[0][1] = 7;
    shapes[1][0] = 45; shapes[1][1] = 7;
    shapes[2][0] = 47; shapes[2][1] = 7;
    shapes[3][0] = 49; shapes[3][1] = 7;
    shapes[4][0] = 51; shapes[4][1] = 7;
    shapes[5][0] = 53; shapes[5][1] = 7;
    shapes[6][0] = 55; shapes[6][1] = 7;
    shapes[7][0] = 57; shapes[7][1] = 7;
    shapes[8][0] = 59; shapes[8][1] = 7;
    shapes[9][0] = 61; shapes[9][1] = 7;
    shapes[10][0] = 63; shapes[10][1] = 7;
    shapes[11][0] = 65; shapes[11][1] = 7;
    shapes[12][0] = 67; shapes[12][1] = 7;
    shapes[13][0] = 69; shapes[13][1] = 7;
    shapes[14][0] = 41; shapes[14][1] = 8;
    shapes[15][0] = 71; shapes[15][1] = 8;
    shapes[16][0] = 39; shapes[16][1] = 9;
    shapes[17][0] = 73; shapes[17][1] = 9;
    shapes[18][0] = 37; shapes[18][1] = 10;
    shapes[19][0] = 75; shapes[19][1] = 10;
    shapes[20][0] = 35; shapes[20][1] = 11;
    shapes[21][0] = 77; shapes[21][1] = 11;
    shapes[22][0] = 35; shapes[22][1] = 12;
    shapes[23][0] = 77; shapes[23][1] = 12;
    shapes[24][0] = 35; shapes[24][1] = 13;
    shapes[25][0] = 77; shapes[25][1] = 13;
    shapes[26][0] = 35; shapes[26][1] = 14;
    shapes[27][0] = 77; shapes[27][1] = 14;
    shapes[28][0] = 35; shapes[28][1] = 15;
    shapes[29][0] = 77; shapes[29][1] = 15;
    shapes[30][0] = 35; shapes[30][1] = 16;
    shapes[31][0] = 77; shapes[31][1] = 16;
    shapes[32][0] = 35; shapes[32][1] = 17;
    shapes[33][0] = 77; shapes[33][1] = 17;
    shapes[34][0] = 37; shapes[34][1] = 18;
    shapes[35][0] = 75; shapes[35][1] = 18;
    shapes[36][0] = 39; shapes[36][1] = 19;
    shapes[37][0] = 73; shapes[37][1] = 19;
    shapes[38][0] = 41; shapes[38][1] = 20;
    shapes[39][0] = 43; shapes[39][1] = 20;
    shapes[40][0] = 45; shapes[40][1] = 20;
    shapes[41][0] = 47; shapes[41][1] = 20;
    shapes[42][0] = 49; shapes[42][1] = 20;
    shapes[43][0] = 51; shapes[43][1] = 20;
    shapes[44][0] = 53; shapes[44][1] = 20;
    shapes[45][0] = 55; shapes[45][1] = 20;
    shapes[46][0] = 57; shapes[46][1] = 20;
    shapes[47][0] = 59; shapes[47][1] = 20;
    shapes[48][0] = 61; shapes[48][1] = 20;
    shapes[49][0] = 63; shapes[49][1] = 20;
    shapes[50][0] = 65; shapes[50][1] = 20;
    shapes[51][0] = 67; shapes[51][1] = 20;
    shapes[52][0] = 69; shapes[52][1] = 20;
    shapes[53][0] = 71; shapes[53][1] = 20;

    return shapes;

}
int(*shape2())[SHAPES_SIZE] {
    static int shapes[SHAPES_ANGLE][SHAPES_SIZE] = { 0 };
    shapes[0][0] = 58; shapes[0][1] = 7;
    shapes[1][0] = 56; shapes[1][1] = 8;
    shapes[2][0] = 60; shapes[2][1] = 8;
    shapes[3][0] = 54; shapes[3][1] = 9;
    shapes[4][0] = 62; shapes[4][1] = 9;
    shapes[5][0] = 52; shapes[5][1] = 10;
    shapes[6][0] = 64; shapes[6][1] = 10;
    shapes[7][0] = 50; shapes[7][1] = 11;
    shapes[8][0] = 66; shapes[8][1] = 11;
    shapes[9][0] = 48; shapes[9][1] = 12;
    shapes[10][0] = 68; shapes[10][1] = 12;
    shapes[11][0] = 46; shapes[11][1] = 13;
    shapes[12][0] = 70; shapes[12][1] = 13;
    shapes[13][0] = 44; shapes[13][1] = 14;
    shapes[14][0] = 72; shapes[14][1] = 14;
    shapes[15][0] = 42; shapes[15][1] = 15;
    shapes[16][0] = 74; shapes[16][1] = 15;
    shapes[17][0] = 40; shapes[17][1] = 16;
    shapes[18][0] = 76; shapes[18][1] = 16;
    shapes[19][0] = 38; shapes[19][1] = 17;
    shapes[20][0] = 40; shapes[20][1] = 17;
    shapes[21][0] = 42; shapes[21][1] = 17;
    shapes[22][0] = 44; shapes[22][1] = 17;
    shapes[23][0] = 46; shapes[23][1] = 17;
    shapes[24][0] = 48; shapes[24][1] = 17;
    shapes[25][0] = 50; shapes[25][1] = 17;
    shapes[26][0] = 52; shapes[26][1] = 17;
    shapes[27][0] = 54; shapes[27][1] = 17;
    shapes[28][0] = 56; shapes[28][1] = 17;
    shapes[29][0] = 58; shapes[29][1] = 17;
    shapes[30][0] = 60; shapes[30][1] = 17;
    shapes[31][0] = 62; shapes[31][1] = 17;
    shapes[32][0] = 64; shapes[32][1] = 17;
    shapes[33][0] = 66; shapes[33][1] = 17;
    shapes[34][0] = 68; shapes[34][1] = 17;
    shapes[35][0] = 70; shapes[35][1] = 17;
    shapes[36][0] = 72; shapes[36][1] = 17;
    shapes[37][0] = 74; shapes[37][1] = 17;
    shapes[38][0] = 76; shapes[38][1] = 17;
    shapes[39][0] = 78; shapes[39][1] = 17;
    return shapes;
}

int(*shape3())[SHAPES_SIZE] {
    static int shapes[SHAPES_SQUARE][SHAPES_SIZE] = { 0 };
    shapes[0][0] = 43; shapes[0][1] = 7;
    shapes[1][0] = 45; shapes[1][1] = 7;
    shapes[2][0] = 47; shapes[2][1] = 7;
    shapes[3][0] = 49; shapes[3][1] = 7;
    shapes[4][0] = 51; shapes[4][1] = 7;
    shapes[5][0] = 53; shapes[5][1] = 7;
    shapes[6][0] = 55; shapes[6][1] = 7;
    shapes[7][0] = 57; shapes[7][1] = 7;
    shapes[8][0] = 59; shapes[8][1] = 7;
    shapes[9][0] = 61; shapes[9][1] = 7;
    shapes[10][0] = 63; shapes[10][1] = 7;
    shapes[11][0] = 65; shapes[11][1] = 7;
    shapes[12][0] = 67; shapes[12][1] = 7;
    shapes[13][0] = 69; shapes[13][1] = 7;
    shapes[14][0] = 71; shapes[14][1] = 7;
    shapes[15][0] = 73; shapes[15][1] = 7;
    shapes[16][0] = 43; shapes[16][1] = 8;
    shapes[17][0] = 73; shapes[17][1] = 8;
    shapes[18][0] = 43; shapes[18][1] = 9;
    shapes[19][0] = 73; shapes[19][1] = 9;
    shapes[20][0] = 43; shapes[20][1] = 10;
    shapes[21][0] = 73; shapes[21][1] = 10;
    shapes[22][0] = 43; shapes[22][1] = 11;
    shapes[23][0] = 73; shapes[23][1] = 11;
    shapes[24][0] = 43; shapes[24][1] = 12;
    shapes[25][0] = 73; shapes[25][1] = 12;
    shapes[26][0] = 43; shapes[26][1] = 13;
    shapes[27][0] = 73; shapes[27][1] = 13;
    shapes[28][0] = 43; shapes[28][1] = 14;
    shapes[29][0] = 73; shapes[29][1] = 14;
    shapes[30][0] = 43; shapes[30][1] = 15;
    shapes[31][0] = 73; shapes[31][1] = 15;
    shapes[32][0] = 43; shapes[32][1] = 16;
    shapes[33][0] = 73; shapes[33][1] = 16;
    shapes[34][0] = 43; shapes[34][1] = 17;
    shapes[35][0] = 73; shapes[35][1] = 17;
    shapes[36][0] = 43; shapes[36][1] = 18;
    shapes[37][0] = 73; shapes[37][1] = 18;
    shapes[38][0] = 43; shapes[38][1] = 19;
    shapes[39][0] = 73; shapes[39][1] = 19;
    shapes[40][0] = 43; shapes[40][1] = 20;
    shapes[41][0] = 45; shapes[41][1] = 20;
    shapes[42][0] = 47; shapes[42][1] = 20;
    shapes[43][0] = 49; shapes[43][1] = 20;
    shapes[44][0] = 51; shapes[44][1] = 20;
    shapes[45][0] = 53; shapes[45][1] = 20;
    shapes[46][0] = 55; shapes[46][1] = 20;
    shapes[47][0] = 57; shapes[47][1] = 20;
    shapes[48][0] = 59; shapes[48][1] = 20;
    shapes[49][0] = 61; shapes[49][1] = 20;
    shapes[50][0] = 63; shapes[50][1] = 20;
    shapes[51][0] = 65; shapes[51][1] = 20;
    shapes[52][0] = 67; shapes[52][1] = 20;
    shapes[53][0] = 69; shapes[53][1] = 20;
    shapes[54][0] = 71; shapes[54][1] = 20;
    shapes[55][0] = 73; shapes[55][1] = 20;


    return shapes;
}