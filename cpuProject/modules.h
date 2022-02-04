#pragma once
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>;
#include <string.h>
#pragma comment(lib, "winmm.lib")

// color
enum {
	GREY = 8,
	BLUE,
	GREEN,
	MINT,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	BLACK =0
};

void gotoxy(int x, int y);
int get_key(void);
void move_arrow_key(
	char key,
	int* x,
	int* y,
	int size,
	int y_min,
	int y_max,
	int x_min,
	int x_max
);
void print_auto_y(int* x, int* y, char* str);
void print_by_name(char* name);
void print_by_text(char* text, char* color, int x, int y);
void rectangle(int width, int height, int x, int y);