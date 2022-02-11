#include <stdio.h>
void* shape1();
void* shape2();
void* shape3();
int modeSize(int);

int shape() {
	int  s= modeSize(1);
	int (*sh)[40] = (int(*)[40])shape1();
	printf("%d",sh[0][0]);

}

int modeSize(int mode) {
	switch (mode)
	{
	case 1:
		return 32;
	case 2:
		return 30;
	default:
		return 38;
		break;
	}
}
void *shape1() {
	static int shapes[32][2] = { 0 };
	shapes[0][0] = 20; shapes[0][1] = 2;
	shapes[1][0] = 18; shapes[1][1] = 3;
	shapes[2][0] = 60; shapes[2][1] = 3;
	shapes[3][0] = 16; shapes[3][1] = 4;
	shapes[4][0] = 62; shapes[4][1] = 4;
	shapes[5][0] = 14; shapes[5][1] = 5;
	shapes[6][0] = 64; shapes[6][1] = 5;
	shapes[7][0] = 12; shapes[7][1] = 6;
	shapes[8][0] = 66; shapes[8][1] = 6;
	shapes[9][0] = 10; shapes[9][1] = 7;
	shapes[10][0] = 68; shapes[10][1] = 7;
	shapes[11][0] = 9; shapes[11][1] = 8;
	shapes[12][0] = 69; shapes[12][1] = 8;
	shapes[13][0] = 9; shapes[13][1] = 9;
	shapes[14][0] = 69; shapes[14][1] = 9;
	shapes[15][0] = 9; shapes[15][1] = 10;
	shapes[16][0] = 69; shapes[16][1] = 10;
	shapes[17][0] = 9; shapes[17][1] = 11;
	shapes[18][0] = 69; shapes[18][1] = 11;
	shapes[19][0] = 9; shapes[19][1] = 12;
	shapes[20][0] = 69; shapes[20][1] = 12;
	shapes[21][0] = 10; shapes[21][1] = 13;
	shapes[22][0] = 68; shapes[22][1] = 13;
	shapes[23][0] = 12; shapes[23][1] = 14;
	shapes[24][0] = 66; shapes[24][1] = 14;
	shapes[25][0] = 14; shapes[25][1] = 15;
	shapes[26][0] = 64; shapes[26][1] = 15;
	shapes[27][0] = 16; shapes[27][1] = 16;
	shapes[28][0] = 62; shapes[28][1] = 16;
	shapes[29][0] = 18; shapes[29][1] = 17;
	shapes[30][0] = 60; shapes[30][1] = 17;
	shapes[31][0] = 20; shapes[31][1] = 18;

	return (void*)shapes;

}
void* shape2() {
	static int shapes[30][2]= { 0 };
	shapes[0][0] = 30; shapes[0][1] = 2;
	shapes[1][0] = 28; shapes[1][1] = 3;
	shapes[2][0] = 32; shapes[2][1] = 3;
	shapes[3][0] = 26; shapes[3][1] = 4;
	shapes[4][0] = 34; shapes[4][1] = 4;
	shapes[5][0] = 24; shapes[5][1] = 5;
	shapes[6][0] = 36; shapes[6][1] = 5;
	shapes[7][0] = 22; shapes[7][1] = 6;
	shapes[8][0] = 38; shapes[8][1] = 5;
	shapes[9][0] = 22; shapes[9][1] = 6;
	shapes[10][0] = 38; shapes[10][1] = 6;
	shapes[11][0] = 20; shapes[11][1] = 7;
	shapes[12][0] = 40; shapes[12][1] = 7;
	shapes[13][0] = 18; shapes[13][1] = 8;
	shapes[14][0] = 42; shapes[14][1] = 8;
	shapes[15][0] = 16; shapes[15][1] = 9;
	shapes[16][0] = 44; shapes[16][1] = 9;
	shapes[17][0] = 14; shapes[17][1] = 10;
	shapes[18][0] = 46; shapes[18][1] = 10;
	shapes[19][0] = 12; shapes[19][1] = 11;
	shapes[20][0] = 48; shapes[20][1] = 11;
	shapes[21][0] = 10; shapes[21][1] = 12;
	shapes[22][0] = 50; shapes[22][1] = 12;
	shapes[23][0] = 8; shapes[23][1] = 13;
	shapes[24][0] = 52; shapes[24][1] = 13;
	shapes[25][0] = 6; shapes[25][1] = 14;
	shapes[26][0] = 54; shapes[26][1] = 14;
	shapes[27][0] = 4; shapes[27][1] = 15;
	shapes[28][0] = 56; shapes[28][1] = 15;
	shapes[29][0] = 3; shapes[29][1] = 16;
	return (void*) shapes;
}

void* shape3() {
	static int shapes[38][2]= { 0 };
	shapes[0][0] = 30; shapes[0][1] = 2;
	shapes[1][0] = 30; shapes[1][1] = 3;
	shapes[2][0] = 68; shapes[2][1] = 3;
	shapes[3][0] = 30; shapes[3][1] = 4;
	shapes[4][0] = 68; shapes[4][1] = 4;
	shapes[5][0] = 30; shapes[5][1] = 5;
	shapes[6][0] = 68; shapes[6][1] = 5;
	shapes[7][0] = 30; shapes[7][1] = 6;
	shapes[8][0] = 68; shapes[8][1] = 6;
	shapes[9][0] = 30; shapes[9][1] = 7;
	shapes[10][0] = 68; shapes[10][1] = 7;
	shapes[11][0] = 30; shapes[11][1] = 8;
	shapes[12][0] = 68; shapes[12][1] = 8;
	shapes[13][0] = 30; shapes[13][1] = 9;
	shapes[14][0] = 68; shapes[14][1] = 9;
	shapes[15][0] = 30; shapes[15][1] = 10;
	shapes[16][0] = 68; shapes[16][1] = 10;
	shapes[17][0] = 30; shapes[17][1] = 11;
	shapes[18][0] = 68; shapes[18][1] = 11;
	shapes[19][0] = 30; shapes[19][1] = 12;
	shapes[20][0] = 68; shapes[20][1] = 12;
	shapes[21][0] = 30; shapes[21][1] = 13;
	shapes[22][0] = 68; shapes[22][1] = 13;
	shapes[23][0] = 30; shapes[23][1] = 14;
	shapes[24][0] = 68; shapes[24][1] = 14;
	shapes[25][0] = 30; shapes[25][1] = 15;
	shapes[26][0] = 68; shapes[26][1] = 15;
	shapes[27][0] = 30; shapes[27][1] = 16;
	shapes[28][0] = 68; shapes[28][1] = 16;
	shapes[29][0] = 30; shapes[29][1] = 17;
	shapes[30][0] = 68; shapes[30][1] = 17;
	shapes[31][0] = 30; shapes[31][1] = 18;
	shapes[32][0] = 68; shapes[32][1] = 18;
	shapes[33][0] = 30; shapes[33][1] = 19;
	shapes[34][0] = 68; shapes[34][1] = 19;
	shapes[35][0] = 30; shapes[35][1] = 20;
	shapes[36][0] = 68; shapes[36][1] = 20;
	shapes[37][0] = 30; shapes[37][1] = 21;

	return (void*)shapes;
}