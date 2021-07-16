#include "setting.h"

int main(int argc, char* argv[])
{
	int cnt = 0;
	int cnt2 = 0;
	int missCnt = 0;


	Question Level1;
	Question Level2;
	Question Level3;


	FILE* fp;
	errno_t error;

	//iniファイルを使用するための初期設定
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "section1");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "keyword1");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
	char keyValue[CHARBUFF];
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level1.Q1, keyValue);
	sprintf_s(keyWord, "keyword2");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level1.Q2, keyValue);
	sprintf_s(keyWord, "keyword3");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level1.Q3, keyValue);
	sprintf_s(section, "section2");
	sprintf_s(keyWord, "keyword1");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level2.Q1, keyValue);
	sprintf_s(keyWord, "keyword2");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level2.Q2, keyValue);
	sprintf_s(keyWord, "keyword3");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level2.Q3, keyValue);
	sprintf_s(section, "section3");
	sprintf_s(keyWord, "keyword1");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level3.Q1, keyValue);
	sprintf_s(keyWord, "keyword2");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level3.Q2, keyValue);
	sprintf_s(keyWord, "keyword3");
	GetPrivateProfileString(section, keyWord, "none", keyValue, CHARBUFF, settingFile);
	sprintf_s(Level3.Q3, keyValue);

	
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
				mvprintw(10, 25, "%s", Level1.Q1);
				mvprintw(18, 33, "ミスした回数：%d", missCnt);
				cnt++;
				break;

			case 0x32:	//2
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvprintw(10, 25, "%s", Level2.Q1);
				mvprintw(18, 33, "ミスした回数：%d", missCnt);
				cnt += 2;
				break;

			case 0x33:	//3
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvprintw(10, 25, "%s", Level3.Q1);
				mvprintw(18, 33, "ミスした回数：%d", missCnt);
				cnt += 3;
				break;
			}

			wrefresh(win);
			break;

		case 2:	//LEVEL1
			switch (cnt2) {
			case 0:
				if (key == 'D') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'o') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'g') {
					mvprintw(10, 29, "%s", " ");
					mvprintw(10, 25, "%s", Level1.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'A') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'p') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 5:
				if (key == 'p') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'l') {
					mvprintw(10, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'e') {
					mvprintw(10, 33, "%s", " ");
					mvprintw(10, 25, "%s", Level1.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'W') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'a') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 't') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 'e') {
					mvprintw(10, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'r') {
					mvprintw(10, 33, "%s", " ");
					mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
					mvwaddstr(win, 13, 25, "ゲーム終了：Press 'q'");
					//ファイルオープン//
					error = fopen_s(&fp, "result.txt", "w");
					if (error != 0) {
						fprintf_s(stderr, "failed to open");
					}
					fprintf_s(fp, "ミスした回数：%d\n", missCnt);
				}
				else {
					missCnt++;
				}
				break;
			}
			mvprintw(18, 33, "ミスした回数：%d", missCnt);
			wrefresh(win);
			break;

		case 3:	//LEVEL2
			switch (cnt2) {
			case 0:
				if (key == 'C') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'o') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'm') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'p') {
					mvprintw(10, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'u') {
					mvprintw(10, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 5:
				if (key == 't') {
					mvprintw(10, 35, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'e') {
					mvprintw(10, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'r') {
					mvprintw(10, 39, "%s", " ");
					mvprintw(10, 25, "%s", Level2.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'W') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'e') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 'd') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 'n') {
					mvprintw(10, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'e') {
					mvprintw(10, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 13:
				if (key == 's') {
					mvprintw(10, 35, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 14:
				if (key == 'd') {
					mvprintw(10, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 15:
				if (key == 'a') {
					mvprintw(10, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 16:
				if (key == 'y') {
					mvprintw(10, 41, "%s", " ");
					mvprintw(10, 25, "%s", Level2.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;
			case 17:
				if (key == 'U') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 18:
				if (key == 'n') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 19:
				if (key == 'd') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 20:
				if (key == 'e') {
					mvprintw(10, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 21:
				if (key == 'r') {
					mvprintw(10, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}

			case 22:
				if (key == 's') {
					mvprintw(10, 35, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 23:
				if (key == 't') {
					mvprintw(10, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvprintw(10, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 25:
				if (key == 'n') {
					mvprintw(10, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 26:
				if (key == 'd') {
					mvprintw(10, 43, "%s", " ");
					mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
					mvwaddstr(win, 13, 25, "ゲーム終了：Press 'q'");
					//ファイルオープン//
					error = fopen_s(&fp, "result.txt", "w");
					if (error != 0) {
						fprintf_s(stderr, "failed to open");
					}
					fprintf_s(fp, "ミスした回数：%d\n", missCnt);
				}
				else {
					missCnt++;
				}
				break;
			}
			mvprintw(18, 33, "ミスした回数：%d", missCnt);
			wrefresh(win);
			break;

		case 4:	//LEVEL3
			switch (cnt2) {
			case 0:
				if (key == 'I') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'p') {
					mvprintw(10, 28, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'l') {
					mvprintw(10, 30, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'a') {
					mvprintw(10, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'y') {
					mvprintw(10, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;


			case 5:
				if (key == 't') {
					mvprintw(10, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'h') {
					mvprintw(10, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'e') {
					mvprintw(10, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'g') {
					mvprintw(10, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'u') {
					mvprintw(10, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 'i') {
					mvprintw(10, 48, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 't') {
					mvprintw(10, 50, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'a') {
					mvprintw(10, 52, "%s", " ");
					cnt2++;
				}
				break;

			case 13:
				if (key == 'r') {
					mvprintw(10, 54, "%s", " ");
					mvprintw(10, 25, "%s", Level3.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 14:
				if (key == 'H') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 15:
				if (key == 'e') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 16:
				if (key == 'm') {
					mvprintw(10, 30, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;
			case 17:
				if (key == 'a') {
					mvprintw(10, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 18:
				if (key == 'k') {
					mvprintw(10, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 19:
				if (key == 'e') {
					mvprintw(10, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 20:
				if (key == 's') {
					mvprintw(10, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 21:
				if (key == 'b') {
					mvprintw(10, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 22:
				if (key == 'r') {
					mvprintw(10, 43, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 23:
				if (key == 'e') {
					mvprintw(10, 45, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvprintw(10, 47, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 25:
				if (key == 'k') {
					mvprintw(10, 49, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 26:
				if (key == 'f') {
					mvprintw(10, 51, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 27:
				if (key == 'a') {
					mvprintw(10, 53, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 28:
				if (key == 's') {
					mvprintw(10, 55, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 29:
				if (key == 't') {
					mvprintw(10, 57, "%s", " ");
					mvprintw(10, 25, "%s", Level3.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 30:
				if (key == 'S') {
					mvprintw(10, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 31:
				if (key == 'h') {
					mvprintw(10, 27, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 32:
				if (key == 'e') {
					mvprintw(10, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 33:
				if (key == 'h') {
					mvprintw(10, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 34:
				if (key == 'a') {
					mvprintw(10, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 35:
				if (key == 's') {
					mvprintw(10, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 36:
				if (key == 't') {
					mvprintw(10, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 37:
				if (key == 'o') {
					mvprintw(10, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 38:
				if (key == 'd') {
					mvprintw(10, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 39:
				if (key == 'o') {
					mvprintw(10, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 40:
				if (key == 'h') {
					mvprintw(10, 49, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 41:
				if (key == 'o') {
					mvprintw(10, 51, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 42:
				if (key == 'm') {
					mvprintw(10, 53, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 43:
				if (key == 'e') {
					mvprintw(10, 55, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 44:
				if (key == 'w') {
					mvprintw(10, 57, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 45:
				if (key == 'o') {
					mvprintw(10, 59, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 46:
				if (key == 'r') {
					mvprintw(10, 61, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 47:
				if (key == 'k') {
					mvprintw(10, 63, "%s", " ");
					mvwaddstr(win, 10, 25, "G A M E  C L E A R ! !");
					mvwaddstr(win, 13, 25, "ゲーム終了：Press 'q'");
					//ファイルオープン//
					error = fopen_s(&fp, "result.txt", "w");
					if (error != 0) {
						fprintf_s(stderr, "failed to open");
					}
					fprintf_s(fp, "ミスした回数：%d\n", missCnt);
				}
				else {
					missCnt++;
				}
				break;

			}
			mvprintw(18, 33, "ミスした回数：%d", missCnt);
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