#include <stdio.h>
#include <curses.h>
#include <Windows.h>

int cnt = 0;
int cnt2 = 0;
int cnt3 = 0;

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

		case 1:	//レベル遷移
			wclear(win);
			box(win, '|', '-');
			box(sub, '|', '-');
			switch (key) {
			case 0x31:	//1
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvwaddstr(win, 10, 25, "D o g");
				cnt++;
				break;

			case 0x32:	//2
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvwaddstr(win, 10, 25, "C o m p u t e r");
				cnt += 2;
				break;

			case 0x33:	//3
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvwaddstr(win, 10, 25, "I  p l a y  t h e  g u i t a r");
				cnt += 3;
				break;
			}

			wrefresh(win);
			break;

		case 2:	//LEVEL1
			switch (cnt2) {
			case 0:
				switch (cnt3) {
				case 0:
					if (key == 'D') {
						mvwaddstr(win, 10, 25, " ");
						cnt3++;
					}
					break;

				case 1:
					if (key == 'o') {
						mvwaddstr(win, 10, 27, " ");
						cnt3++;
					}
					break;

				case 2:
					if (key == 'g') {
						mvwaddstr(win, 10, 29, " ");
						mvwaddstr(win, 10, 25, "A p p l e");
						cnt3++;
					}
					break;

				case 3:
					if (key == 'A') {
						mvwaddstr(win, 10, 25, " ");
						cnt3++;
					}
					break;

				case 4:
					if (key == 'p') {
						mvwaddstr(win, 10, 27, " ");
						cnt3++;
					}
					break;

				case 5:
					if (key == 'p') {
						mvwaddstr(win, 10, 29, " ");
						cnt3++;
					}
					break;

				case 6:
					if (key == 'l') {
						mvwaddstr(win, 10, 31, " ");
						cnt3++;
					}
					break;

				case 7:
					if (key == 'e') {
						mvwaddstr(win, 10, 33, " ");
						mvwaddstr(win, 10, 25, "W a t e r");
						cnt3++;
					}
					break;

				case 8:
					if (key == 'W') {
						mvwaddstr(win, 10, 25, " ");
						cnt3++;
					}
					break;

				case 9:
					if (key == 'a') {
						mvwaddstr(win, 10, 27, " ");
						cnt3++;
					}
					break;

				case 10:
					if (key == 't') {
						mvwaddstr(win, 10, 29, " ");
						cnt3++;
					}
					break;

				case 11:
					if (key == 'e') {
						mvwaddstr(win, 10, 31, " ");
						cnt3++;
					}
					break;

				case 12:
					if (key == 'r') {
						mvwaddstr(win, 10, 33, " ");
						mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
						cnt3 == 0;
					}
					break;
				}
				break;

			}
			wrefresh(win);
			break;

		case 3:	//LEVEL2
			switch (cnt3) {
			case 0:
				if (key == 'C') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 1:
				if (key == 'o') {
					mvwaddstr(win, 10, 27, " ");
					cnt3++;
				}
				break;

			case 2:
				if (key == 'm') {
					mvwaddstr(win, 10, 29, " ");
					cnt3++;
				}
				break;

			case 3:
				if (key == 'p') {
					mvwaddstr(win, 10, 31, " ");
					cnt3++;
				}
				break;

			case 4:
				if (key == 'u') {
					mvwaddstr(win, 10, 33, " ");
					cnt3++;
				}
				break;

			case 5:
				if (key == 't') {
					mvwaddstr(win, 10, 35, " ");
					cnt3++;
				}
				break;

			case 6:
				if (key == 'e') {
					mvwaddstr(win, 10, 37, " ");
					cnt3++;
				}
				break;

			case 7:
				if (key == 'r') {
					mvwaddstr(win, 10, 39, " ");
					mvwaddstr(win, 10, 25, "W e d n e s d a y");
					cnt3++;
				}
				break;

			case 8:
				if (key == 'W') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 9:
				if (key == 'e') {
					mvwaddstr(win, 10, 27, " ");
					cnt3++;
				}
				break;

			case 10:
				if (key == 'd') {
					mvwaddstr(win, 10, 29, " ");
					cnt3++;
				}
				break;

			case 11:
				if (key == 'n') {
					mvwaddstr(win, 10, 31, " ");
					cnt3++;
				}
				break;

			case 12:
				if (key == 'e') {
					mvwaddstr(win, 10, 33, " ");
					cnt3++;
				}
				break;

			case 13:
				if (key == 's') {
					mvwaddstr(win, 10, 35, " ");
					cnt3++;
				}
				break;

			case 14:
				if (key == 'd') {
					mvwaddstr(win, 10, 37, " ");
					cnt3++;
				}
				break;

			case 15:
				if (key == 'a') {
					mvwaddstr(win, 10, 39, " ");
					cnt3++;
				}
				break;

			case 16:
				if (key == 'y') {
					mvwaddstr(win, 10, 41, " ");
					mvwaddstr(win, 10, 25, "U n d e r s t a n d");
					cnt3++;
				}
				break;
			case 17:
				if (key == 'U') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 18:
				if (key == 'n') {
					mvwaddstr(win, 10, 27, " ");
					cnt3++;
				}
				break;

			case 19:
				if (key == 'd') {
					mvwaddstr(win, 10, 29, " ");
					cnt3++;
				}
				break;

			case 20:
				if (key == 'e') {
					mvwaddstr(win, 10, 31, " ");
					cnt3++;
				}
				break;

			case 21:
				if (key == 'r') {
					mvwaddstr(win, 10, 33, " ");
					cnt3++;
				}

			case 22:
				if (key == 's') {
					mvwaddstr(win, 10, 35, " ");
					cnt3++;
				}
				break;

			case 23:
				if (key == 't') {
					mvwaddstr(win, 10, 37, " ");
					cnt3++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvwaddstr(win, 10, 39, " ");
					cnt3++;
				}
				break;

			case 25:
				if (key == 'n') {
					mvwaddstr(win, 10, 41, " ");
					cnt3++;
				}
				break;

			case 26:
				if (key == 'd') {
					mvwaddstr(win, 10, 43, " ");
					mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
					cnt3++;
				}
				break;
			}
			wrefresh(win);
			break;

		case 4:	//LEVEL3
			switch (cnt3) {
			case 0:
				if (key == 'I') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 1:
				if (key == 'p') {
					mvwaddstr(win, 10, 28, " ");
					cnt3++;
				}
				break;

			case 2:
				if (key == 'l') {
					mvwaddstr(win, 10, 30, " ");
					cnt3++;
				}
				break;

			case 3:
				if (key == 'a') {
					mvwaddstr(win, 10, 32, " ");
					cnt3++;
				}
				break;

			case 4:
				if (key == 'y') {
					mvwaddstr(win, 10, 34, " ");
					cnt3++;
				}
				break;


			case 5:
				if (key == 't') {
					mvwaddstr(win, 10, 37, " ");
					cnt3++;
				}
				break;

			case 6:
				if (key == 'h') {
					mvwaddstr(win, 10, 39, " ");
					cnt3++;
				}
				break;

			case 7:
				if (key == 'e') {
					mvwaddstr(win, 10, 41, " ");
					cnt3++;
				}
				break;

			case 8:
				if (key == 'g') {
					mvwaddstr(win, 10, 44, " ");
					cnt3++;
				}
				break;

			case 9:
				if (key == 'u') {
					mvwaddstr(win, 10, 46, " ");
					cnt3++;
				}
				break;

			case 10:
				if (key == 'i') {
					mvwaddstr(win, 10, 48, " ");
					cnt3++;
				}
				break;

			case 11:
				if (key == 't') {
					mvwaddstr(win, 10, 50, " ");
					cnt3++;
				}
				break;

			case 12:
				if (key == 'a') {
					mvwaddstr(win, 10, 52, " ");
					cnt3++;
				}
				break;

			case 13:
				if (key == 'r') {
					mvwaddstr(win, 10, 54, " ");
					mvwaddstr(win, 10, 25, "H e  m a k e s  b r e a k f a s t");
					cnt3++;
				}
				break;

			case 14:
				if (key == 'H') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 15:
				if (key == 'e') {
					mvwaddstr(win, 10, 27, " ");
					cnt3++;
				}
				break;

			case 16:
				if (key == 'm') {
					mvwaddstr(win, 10, 30, " ");
					cnt3++;
				}
				break;
			case 17:
				if (key == 'a') {
					mvwaddstr(win, 10, 32, " ");
					cnt3++;
				}
				break;

			case 18:
				if (key == 'k') {
					mvwaddstr(win, 10, 34, " ");
					cnt3++;
				}
				break;

			case 19:
				if (key == 'e') {
					mvwaddstr(win, 10, 36, " ");
					cnt3++;
				}
				break;

			case 20:
				if (key == 's') {
					mvwaddstr(win, 10, 38, " ");
					cnt3++;
				}
				break;

			case 21:
				if (key == 'b') {
					mvwaddstr(win, 10, 41, " ");
					cnt3++;
				}

			case 22:
				if (key == 'r') {
					mvwaddstr(win, 10, 43, " ");
					cnt3++;
				}
				break;

			case 23:
				if (key == 'e') {
					mvwaddstr(win, 10, 45, " ");
					cnt3++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvwaddstr(win, 10, 47, " ");
					cnt3++;
				}
				break;

			case 25:
				if (key == 'k') {
					mvwaddstr(win, 10, 49, " ");
					cnt3++;
				}
				break;

			case 26:
				if (key == 'f') {
					mvwaddstr(win, 10, 51, " ");
					cnt3++;
				}
				break;

			case 27:
				if (key == 'a') {
					mvwaddstr(win, 10, 53, " ");
					cnt3++;
				}
				break;

			case 28:
				if (key == 's') {
					mvwaddstr(win, 10, 55, " ");
					cnt3++;
				}
				break;

			case 29:
				if (key == 't') {
					mvwaddstr(win, 10, 57, " ");
					mvwaddstr(win, 10, 25, "S h e  h a s  t o  d o  h o m e w o r k");
					cnt3++;
				}
				break;

			case 30:
				if (key == 'S') {
					mvwaddstr(win, 10, 25, " ");
					cnt3++;
				}
				break;

			case 31:
				if (key == 'h') {
					mvwaddstr(win, 10, 27, " ");
					cnt3++;
				}
				break;

			case 32:
				if (key == 'e') {
					mvwaddstr(win, 10, 29, " ");
					cnt3++;
				}
				break;

			case 33:
				if (key == 'h') {
					mvwaddstr(win, 10, 32, " ");
					cnt3++;
				}
				break;

			case 34:
				if (key == 'a') {
					mvwaddstr(win, 10, 34, " ");
					cnt3++;
				}
				break;

			case 35:
				if (key == 's') {
					mvwaddstr(win, 10, 36, " ");
					cnt3++;
				}
				break;

			case 36:
				if (key == 't') {
					mvwaddstr(win, 10, 39, " ");
					cnt3++;
				}
				break;

			case 37:
				if (key == 'o') {
					mvwaddstr(win, 10, 41, " ");
					cnt3++;
				}
				break;

			case 38:
				if (key == 'd') {
					mvwaddstr(win, 10, 44, " ");
					cnt3++;
				}
				break;

			case 39:
				if (key == 'o') {
					mvwaddstr(win, 10, 46, " ");
					cnt3++;
				}
				break;

			case 40:
				if (key == 'h') {
					mvwaddstr(win, 10, 49, " ");
					cnt3++;
				}
				break;

			case 41:
				if (key == 'o') {
					mvwaddstr(win, 10, 51, " ");
					cnt3++;
				}
				break;

			case 42:
				if (key == 'm') {
					mvwaddstr(win, 10, 53, " ");
					cnt3++;
				}
				break;

			case 43:
				if (key == 'e') {
					mvwaddstr(win, 10, 55, " ");
					cnt3++;
				}
				break;

			case 44:
				if (key == 'w') {
					mvwaddstr(win, 10, 57, " ");
					cnt3++;
				}
				break;

			case 45:
				if (key == 'o') {
					mvwaddstr(win, 10, 59, " ");
					cnt3++;
				}
				break;

			case 46:
				if (key == 'r') {
					mvwaddstr(win, 10, 61, " ");
					cnt3++;
				}
				break;

			case 47:
				if (key == 'k') {
					mvwaddstr(win, 10, 63, " ");
					mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
					cnt3++;
				}
				break;

			}
			wrefresh(win);
			break;

		}
	}

	/* 後処理 */
	wrefresh(win);
	//wgetch(win);
	endwin();
	return 0;
}