#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// cursor settings function (chohadam 21-03-11)
void set_cursor(int flag, int size) {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = flag;
	cursor.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
void set_console(void) {
	// set the console size
	system("mode con:cols=120 lines=31");
	// hide cursor
	// set title
	system("title CPU KINGDOM");
	// clear console
	system("cls");
}
int main(void) {
	set_console();
	//pushpull();
	dalgona();
	//shape();
}
