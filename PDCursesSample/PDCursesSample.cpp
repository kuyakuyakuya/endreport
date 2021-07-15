#include <stdio.h>
#include <curses.h>
#include <Windows.h>

int cnt = 0;
int cnt2 = 0;
int cnt3 = 0;
int i = 0;

int main(int argc, char* argv[])
{
	if (initscr() == NULL) {
		return 1;
	}

	/* 初期化、変数定義 */
	WINDOW* win;
	WINDOW* sub;
	int key;
	keypad(stdscr, TRUE);
	initscr();

	/* エコー／バッファリング禁止 */
	noecho();
	cbreak();

	/* ウィンドウ作成 */
	win = newwin(LINES, COLS, 0, 0);
	WINDOW* subwin(WINDOW * win, int line, int cols, int begin_y, int begin_x);
	sub = subwin(win, LINES - 2, COLS - 47, 0, 15);

	//初期画面の描画
	mvwaddstr(win, LINES / 2, COLS / 2 - 10, "Press the Key '0'");
	wrefresh(win);
	napms(2000);	//数秒間初期画面を描画するためのディレイ

	while (1) {
		key = getch();
		if (key == 'q') break;
		switch (cnt) {
		case 0:	//レベル選択画面
			wrefresh(win);
			if (key == 0x30) {
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvwaddstr(win, 10, 25, "TYPING GAME");
				mvwaddstr(win, 14, 25, "LEVEL1:Press the KEY 1");
				mvwaddstr(win, 16, 25, "LEVEL2:Press the KEY 2");
				mvwaddstr(win, 18, 25, "LEVEL3:Press the KEY 3");

				wrefresh(win);
				cnt++;
				break;
			}
			break;

	}

	/* 後処理 */
	wrefresh(win);
	//wgetch(win);
	endwin();
	return 0;
}