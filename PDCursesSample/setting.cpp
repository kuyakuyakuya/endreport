#include "setting.h"

WINDOW* win;

void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

void printRule() {
	mvprintw(9, 95, "%s","ゲームルール");
	mvprintw(11, 84,"%s", "「画面に表示された文字を入力せよ」");
	mvprintw(18, 98,"%s", "注意点");
	mvprintw(20, 87,"%s", "「大文字・小文字区別あり！」");;
	mvprintw(22, 85,"%s", "「スペースは入力しなくて良い！」");
}