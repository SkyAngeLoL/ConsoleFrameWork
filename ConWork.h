#pragma once
#include <Windows.h>

#define hOut GetStdHandle(STD_OUTPUT_HANDLE)

namespace ConWork {
	static COORD size;

	static COORD setConsoleSize(int X, int Y) {
		size.X = X;
		size.Y = Y;

		SMALL_RECT sr;
		sr.Bottom = Y - 1;
		sr.Left = 0;
		sr.Right = X - 1;
		sr.Top = 0;

		SetConsoleScreenBufferSize(hOut, size);
		SetConsoleWindowInfo(hOut, true, &sr);
		Sleep(1);
		SetConsoleScreenBufferSize(hOut, size); /* Yeees! Double shoot! */

		Sleep(10);

		return size;
	}

	static void setCursorVisible(bool state) {
		CONSOLE_CURSOR_INFO cci;
			cci.bVisible = state;
			cci.dwSize = 1;
		SetConsoleCursorInfo(hOut, &cci);
	}

	static void setCursorPos(int x, int y) {
		SetConsoleCursorPosition(hOut, { x, y });
	}

};