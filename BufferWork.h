#pragma once
#include <Windows.h>

#define hOut GetStdHandle(STD_OUTPUT_HANDLE)
#define BUFFER_MAX_SIZE 10240


// Lua 

//#define if  if(
//#define then ){
//#define end }
//#define for  for(
//#define do ){
//#define while  while(
//#define or ||
//#define and &&

// not good idea

namespace BufWork {
	

	const char DEF_SIMBOL = ' ';
	const WORD DEF_ATTR = 0x00F0;

	static CHAR_INFO printBuffer[BUFFER_MAX_SIZE];
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	static SMALL_RECT sr;
	static COORD size;
	static bool first = true;

	static bool draw(bool clear) {
		GetConsoleScreenBufferInfo(hOut, &csbi);

		size.X = csbi.dwSize.X;
		size.Y = csbi.dwSize.Y;

		sr.Bottom = size.Y - 1;
		sr.Left = 0;
		sr.Right = size.X - 1;
		sr.Top = 0;

		if(first) {
			for(int i = 0; i < (size.X * size.Y); ++i) {
				printBuffer[i].Char.AsciiChar = DEF_SIMBOL;
				printBuffer[i].Attributes = DEF_ATTR;
			};

			first = false;
		}

		WriteConsoleOutputA(hOut, printBuffer, size, *new COORD(), &sr);

		if(clear) {
			for(int i = 0; i < (size.X * size.Y); ++i) {
				printBuffer[i].Char.AsciiChar = DEF_SIMBOL;
				printBuffer[i].Attributes = DEF_ATTR;
			};
		};

		return clear;
	};

	static bool draw() {
		draw(false);
		
		return false;
	};

	static void point(int X, int Y, char Sim, WORD Attr) {
		int I = Y * size.X + X;
		if (I > (size.X * size.Y) || I < 0) { return; }
		printBuffer[I].Char.AsciiChar = Sim;
		printBuffer[I].Attributes = Attr;
	};

	static void point(COORD Pos, char Sim, WORD Attr) {
		point(Pos.X, Pos.Y, Sim, Attr);
	};

	static void point(int Z, char Sim, WORD Attr) {
		if (Z > (size.X * size.Y) || Z < 0) { return; }
		printBuffer[Z].Char.AsciiChar = Sim;
		printBuffer[Z].Attributes = Attr;
	};

	static char getSimbol(COORD pos) {
		int Z = pos.Y * size.X + pos.X;
		return printBuffer[Z].Char.AsciiChar;
	};

	static char getSimbol(int Z) {
		return printBuffer[Z].Char.AsciiChar;
	};

	static WORD getAttr(COORD pos) {
		int Z = pos.Y * size.X + pos.X;
		return printBuffer[Z].Attributes;
	}

	static WORD getAttr(int Z) {
		return printBuffer[Z].Attributes;
	};

};

