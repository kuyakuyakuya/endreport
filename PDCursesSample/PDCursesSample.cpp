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
	sub = subwin(win, LINES - 2, COLS - 40, 1, 2);

	//初期画面の描画
	mvwaddstr(win, LINES / 2, COLS / 2 - 10, "Press the Key 'q'");
	wrefresh(win);
	napms(1500);	//数秒間初期画面を描画するためのディレイ

	while (1) {
		key = getch();
		if (key == 0x39) break;
		switch (cnt) {
		case 0:	//レベル選択画面
			wrefresh(win);
			if (key == 'q') {
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvwaddstr(win, 10, 35, "TYPING GAME");
				mvwaddstr(win, 14, 28, "LEVEL1 : Press the KEY '1'");
				mvwaddstr(win, 16, 28, "LEVEL2 : Press the KEY '2'");
				mvwaddstr(win, 18, 28, "LEVEL3 : Press the KEY '3'");

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
				mvprintw(12, 38, "%s", Level1.Q1);
				mvprintw(23, 33, "ミスした回数：%d", missCnt);
				cnt++;
				break;

			case 0x32:	//2
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvprintw(12, 33, "%s", Level2.Q1);
				mvprintw(23, 33, "ミスした回数：%d", missCnt);
				cnt += 2;
				break;

			case 0x33:	//3
				wclear(win);
				box(win, '|', '-');
				box(sub, '|', '-');
				mvprintw(12, 25, "%s", Level3.Q1);
				mvprintw(23, 33, "ミスした回数：%d", missCnt);
				cnt += 3;
				break;
			}

			wrefresh(win);
			break;

		case 2:	//LEVEL1
			switch (cnt2) {
			case 0:
				if (key == 'D') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'o') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'g') {
					mvprintw(12, 42, "%s", " ");
					mvprintw(12, 36, "%s", Level1.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'A') {
					mvprintw(12, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'p') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 5:
				if (key == 'p') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'l') {
					mvprintw(12, 42, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'e') {
					mvprintw(12, 44, "%s", " ");
					mvprintw(12, 36, "%s", Level1.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'W') {
					mvprintw(12, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'a') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 't') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 'e') {
					mvprintw(12, 42, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'r') {
					mvprintw(12, 44, "%s", " ");
					mvwaddstr(win, 12, 30, "G A M E  C L E A R ! !");
					mvwaddstr(win, 19, 31, "ゲーム終了：Press '9'");
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
			mvprintw(23, 33, "ミスした回数：%d", missCnt);
			wrefresh(win);
			break;

		case 3:	//LEVEL2
			switch (cnt2) {
			case 0:
				if (key == 'C') {
					mvprintw(12, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'o') {
					mvprintw(12, 35, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'm') {
					mvprintw(12, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'p') {
					mvprintw(12, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'u') {
					mvprintw(12, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 5:
				if (key == 't') {
					mvprintw(12, 43, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'e') {
					mvprintw(12, 45, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'r') {
					mvprintw(12, 47, "%s", " ");
					mvprintw(12, 32, "%s", Level2.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'W') {
					mvprintw(12, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'e') {
					mvprintw(12, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 'd') {
					mvprintw(12, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 'n') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'e') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 13:
				if (key == 's') {
					mvprintw(12, 42, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 14:
				if (key == 'd') {
					mvprintw(12, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 15:
				if (key == 'a') {
					mvprintw(12, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 16:
				if (key == 'y') {
					mvprintw(12, 48, "%s", " ");
					mvprintw(12, 32, "%s", Level2.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;
			case 17:
				if (key == 'U') {
					mvprintw(12, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 18:
				if (key == 'n') {
					mvprintw(12, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 19:
				if (key == 'd') {
					mvprintw(12, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 20:
				if (key == 'e') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 21:
				if (key == 'r') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}

			case 22:
				if (key == 's') {
					mvprintw(12, 42, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 23:
				if (key == 't') {
					mvprintw(12, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvprintw(12, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 25:
				if (key == 'n') {
					mvprintw(12, 48, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 26:
				if (key == 'd') {
					mvprintw(12, 50, "%s", " ");
					mvwaddstr(win, 12, 30, "G A M E  C L E A R ! !");
					mvwaddstr(win, 19, 31, "ゲーム終了：Press '9'");
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
			mvprintw(23, 33, "ミスした回数：%d", missCnt);
			wrefresh(win);
			break;

		case 4:	//LEVEL3
			switch (cnt2) {
			case 0:
				if (key == 'I') {
					mvprintw(12, 25, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 1:
				if (key == 'p') {
					mvprintw(12, 28, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 2:
				if (key == 'l') {
					mvprintw(12, 30, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 3:
				if (key == 'a') {
					mvprintw(12, 32, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 4:
				if (key == 'y') {
					mvprintw(12, 34, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;


			case 5:
				if (key == 't') {
					mvprintw(12, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 6:
				if (key == 'h') {
					mvprintw(12, 39, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 7:
				if (key == 'e') {
					mvprintw(12, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 8:
				if (key == 'g') {
					mvprintw(12, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 9:
				if (key == 'u') {
					mvprintw(12, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 10:
				if (key == 'i') {
					mvprintw(12, 48, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 11:
				if (key == 't') {
					mvprintw(12, 50, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 12:
				if (key == 'a') {
					mvprintw(12, 52, "%s", " ");
					cnt2++;
				}
				break;

			case 13:
				if (key == 'r') {
					mvprintw(12, 54, "%s", " ");
					mvprintw(12, 24, "%s", Level3.Q2);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 14:
				if (key == 'H') {
					mvprintw(12, 24, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 15:
				if (key == 'e') {
					mvprintw(12, 26, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 16:
				if (key == 'm') {
					mvprintw(12, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;
			case 17:
				if (key == 'a') {
					mvprintw(12, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 18:
				if (key == 'k') {
					mvprintw(12, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 19:
				if (key == 'e') {
					mvprintw(12, 35, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 20:
				if (key == 's') {
					mvprintw(12, 37, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 21:
				if (key == 'b') {
					mvprintw(12, 40, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 22:
				if (key == 'r') {
					mvprintw(12, 42, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 23:
				if (key == 'e') {
					mvprintw(12, 44, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 24:
				if (key == 'a') {
					mvprintw(12, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 25:
				if (key == 'k') {
					mvprintw(12, 48, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 26:
				if (key == 'f') {
					mvprintw(12, 50, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 27:
				if (key == 'a') {
					mvprintw(12, 52, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 28:
				if (key == 's') {
					mvprintw(12, 54, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 29:
				if (key == 't') {
					mvprintw(12, 56, "%s", " ");
					mvprintw(12, 22, "%s", Level3.Q3);
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 30:
				if (key == 'S') {
					mvprintw(12, 22, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 31:
				if (key == 'h') {
					mvprintw(12, 24, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 32:
				if (key == 'e') {
					mvprintw(12, 26, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 33:
				if (key == 'h') {
					mvprintw(12, 29, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 34:
				if (key == 'a') {
					mvprintw(12, 31, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 35:
				if (key == 's') {
					mvprintw(12, 33, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 36:
				if (key == 't') {
					mvprintw(12, 36, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 37:
				if (key == 'o') {
					mvprintw(12, 38, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 38:
				if (key == 'd') {
					mvprintw(12, 41, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 39:
				if (key == 'o') {
					mvprintw(12, 43, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 40:
				if (key == 'h') {
					mvprintw(12, 46, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 41:
				if (key == 'o') {
					mvprintw(12, 48, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 42:
				if (key == 'm') {
					mvprintw(12, 50, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 43:
				if (key == 'e') {
					mvprintw(12, 52, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 44:
				if (key == 'w') {
					mvprintw(12, 54, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 45:
				if (key == 'o') {
					mvprintw(12, 56, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 46:
				if (key == 'r') {
					mvprintw(12, 58, "%s", " ");
					cnt2++;
				}
				else {
					missCnt++;
				}
				break;

			case 47:
				if (key == 'k') {
					mvprintw(12, 60, "%s", " ");
					mvwaddstr(win, 12, 30, "G A M E  C L E A R ! !");
					mvwaddstr(win, 19, 31, "ゲーム終了：Press '9'");
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
			mvprintw(23, 33, "ミスした回数：%d", missCnt);
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