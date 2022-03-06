#include <stdio.h>

#define SHAPES_SIZE 2
#define SHAPES_CIRCLE 54
#define SHAPES_ANGLE 40
#define SHAPES_SQUARE 56

int(*shape1())[SHAPES_SIZE];
int(*shape2())[SHAPES_SIZE];
int(*shape3())[SHAPES_SIZE];
int modeSize(int);

void shape() {
    /*
    int  s = modeSize(1);
    int(*sh)[2] = shape1();
    printf("%d", sh[0][1]);*/
}

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