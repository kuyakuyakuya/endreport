#include "setting.h"

WINDOW* win;

void getCurrentDirectory(char* currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

void printRule() {
	mvprintw(9, 95, "%s","�Q�[�����[��");
	mvprintw(11, 84,"%s", "�u��ʂɕ\�����ꂽ��������͂���v");
	mvprintw(18, 98,"%s", "���ӓ_");
	mvprintw(20, 87,"%s", "�u�啶���E��������ʂ���I�v");;
	mvprintw(22, 85,"%s", "�u�X�y�[�X�͓��͂��Ȃ��ėǂ��I�v");
}