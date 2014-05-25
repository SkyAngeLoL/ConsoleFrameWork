#pragma once
#include <Windows.h>
#include <string>

#define BUFFER_MAX_SIZE 10240
#define DEF_SIMBOL ' '
#define DEF_ATTR 0x00F0

#define hOut GetStdHandle(STD_OUTPUT_HANDLE)

#define TEXT_ALIGN_LEFT 0
#define TEXT_ALIGN_CENTER 1
#define TEXT_ALIGN_RIGHT 2

#define or ||   // i love Lua
#define and &&	// i love Lua


class cbuffer {
		
	public:
	cbuffer( ) {
		this->pos = { 0, 0 };
		this->size = { 50, 50 };
		clear( );
	}
	cbuffer(COORD pos, COORD size) {
		this->pos = pos;
		this->size = size;
		clear( );
	}

	void clear() {
		for (int i = 0; i < (size.X * size.Y); ++i) {
			this->charArray[i].Char.AsciiChar = DEF_SIMBOL;
			this->charArray[i].Attributes = DEF_ATTR;
		}
	}

	void draw(bool clr) {
		SMALL_RECT sr;
		sr.Left = pos.X;
		sr.Top = pos.Y;
		sr.Right = pos.X + size.X;
		sr.Bottom = pos.Y + size.Y;

		WriteConsoleOutputA(hOut, charArray, size, { 0, 0 }, &sr);

		if (clr) { clear( ); }
	}

	void draw( ) { draw(false); }



	/* 
		.AddPoint()
			Adds a 1 simbol to buffer
	*/
	void AddPoint(int x, int y, char sim, WORD attr) {
		if (x < 0 or x > size.X - 1) { return; }
		if (y < 0 or y > size.Y - 1) { return; }

		int I = y * size.X + x;

		charArray[I].Char.AsciiChar = sim;
		charArray[I].Attributes = attr;
	}

	void AddPoint(COORD Pos, char Sim, WORD Attr) { AddPoint(Pos.X, Pos.Y, Sim, Attr); }
	void AddPoint(int Z, char Sim, WORD Attr) {
		if (Z > (size.X * size.Y) or Z < 0) { return; }
		charArray[Z].Char.AsciiChar = Sim;
		charArray[Z].Attributes = Attr;
	};

	/*
		.AddTextEx(), .AddText()
			Adds a text string to buffer, horizontal or vertical
	*/
	void AddTextEx(int x, int y, std::string text, WORD attr, int align, bool vertical) {
		if (align == TEXT_ALIGN_CENTER) {
			if(vertical) {
				y -= (int)text.size() / 2;
			}else{
				x -= (int)text.size() / 2;
			}
		} else if (align == TEXT_ALIGN_RIGHT) {
			if(vertical) {
				y -= (int)text.size();
			}else{
				x -= (int)text.size();
			}
		}
	
		for (int i = 0; i < (int)text.size(); i++) {
			AddPoint(x + (vertical ? 0 : i), y + (vertical ? i : 0), text[i], attr);
		}
	}
	void AddText(int x, int y, std::string text, WORD attr, int align) { AddTextEx(x, y, text, attr, align, false); }
	void AddText(int x, int y, std::string text, WORD attr) { AddTextEx(x, y, text, attr, 0, false); }

	/*
		.AddLine()
			Adds a line from point 1 to 2
	*/
	void AddLine(int x1, int y1, int x2, int y2, char sim, WORD attr) {
		const int deltaX = abs(x2 - x1);
		const int deltaY = abs(y2 - y1);
		const int signX = x1 < x2 ? 1 : -1;
		const int signY = y1 < y2 ? 1 : -1;

		int error = deltaX - deltaY;

		while (x1 != x2 || y1 != y2) {
			AddPoint(x1, y1, sim, attr);

			const int error2 = error * 2;

			if (error2 > -deltaY) {
				error -= deltaY;
				x1 += signX;
			}
			if(error2 < deltaX) {
				error += deltaX;
				y1 += signY;
			}
		}
		AddPoint(x1, y1, sim, attr);
	}

	/*
		.AddBox()
			Adds a box 
	*/
	void AddBox(int x, int y, int w, int h, char sim, WORD attr) {
		int x2 = x + w - 1;
		int y2 = y + h - 1;
		x = max(x, 0);
		y = max(y, 0);
		while (x <= x2) {
			AddLine(x, y, x, y2, sim, attr);
			x++;
		}
	}

	/*
		.FillZone()
			Fills the zone simbols
	*/
	void FillZone(COORD pos1, COORD pos2, std::string simbols, WORD attr) {
		const int lenght = simbols.size( );
		int sim = 0;

		for (int i = pos1.Y; i < (pos1.Y + pos2.Y); i++) {
			for (int j = pos1.X; j < (pos1.X + pos2.X); j++) {
				int I = i * size.X + j;

				AddPoint(I, simbols[sim], attr);

				sim = sim < lenght - 1 ? sim + 1 : 0;
			}
		}
	}

	private:
	COORD pos;
	COORD size;
	CHAR_INFO charArray[BUFFER_MAX_SIZE];
};

	







//#undef or
//#undef and



//
//// Lua 
//
////#define if  if(
////#define then ){
////#define end }
////#define for  for(
////#define do ){
////#define while  while(
////#define or ||
////#define and &&
//
//// not good idea
//
//namespace BufWork {
//	
//	const char DEF_SIMBOL = ' ';
//	const WORD DEF_ATTR = 0x00F0;
//
//	static CHAR_INFO printBuffer[BUFFER_MAX_SIZE];
//	static COORD size;
//	bool first = true;
//
//	void clear() {
//		for (int i = 0; i < (size.X * size.Y); ++i) {
//			printBuffer[i].Char.AsciiChar = DEF_SIMBOL;
//			printBuffer[i].Attributes = DEF_ATTR;
//		};
//	}
//	
//	void draw(bool clr) {
//		CONSOLE_SCREEN_BUFFER_INFO csbi;
//			GetConsoleScreenBufferInfo(hOut, &csbi);
//
//		size.X = csbi.dwSize.X;
//		size.Y = csbi.dwSize.Y;
//
//		SMALL_RECT sr;
//			sr.Left = 2;
//			sr.Top = 2;
//			sr.Bottom = 40;
//			sr.Right = 5;
//
//		if(first) {
//			clear();
//			first = false;
//		}
//		
//		WriteConsoleOutputA(hOut, printBuffer, size, *new COORD(), &sr);
//
//		if(clr) {
//			clear();
//		};
//	};
//
//	void draw() {
//		draw(false);
//	};
//
//	void point(int X, int Y, char Sim, WORD Attr) {
//		int I = Y * size.X + X;
//		if (I > (size.X * size.Y) || I < 0) { return; }
//		printBuffer[I].Char.AsciiChar = Sim;
//		printBuffer[I].Attributes = Attr;
//	};
//
//	void point(COORD Pos, char Sim, WORD Attr) {
//		point(Pos.X, Pos.Y, Sim, Attr);
//	};
//
//	void point(int Z, char Sim, WORD Attr) {
//		if (Z > (size.X * size.Y) || Z < 0) { return; }
//		printBuffer[Z].Char.AsciiChar = Sim;
//		printBuffer[Z].Attributes = Attr;
//	};
//
//	char getSimbol(COORD pos) {
//		int Z = pos.Y * size.X + pos.X;
//		return printBuffer[Z].Char.AsciiChar;
//	};
//
//	char getSimbol(int Z) {
//		return printBuffer[Z].Char.AsciiChar;
//	};
//
//	WORD getAttr(COORD pos) {
//		int Z = pos.Y * size.X + pos.X;
//		return printBuffer[Z].Attributes;
//	}
//
//	WORD getAttr(int Z) {
//		return printBuffer[Z].Attributes;
//	};
//
//};
//
