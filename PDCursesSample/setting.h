#pragma once
#include <stdio.h>
#include <curses.h>
#include <Windows.h>
#define CHARBUFF 124
#define BUFFSIZE 1024


extern int cnt;
extern int cnt2;
extern int missCnt;

void getCurrentDirectory(char* currentDirectory);
void printRule();

struct Question {
	char Q1[CHARBUFF];
	char Q2[CHARBUFF];
	char Q3[CHARBUFF];

};
