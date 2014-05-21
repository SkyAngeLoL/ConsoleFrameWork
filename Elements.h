#include "BufferWork.h"
#include <string>

#define TEXT_ALIGN_LEFT1 0
#define TEXT_ALIGN_CENTER1 1
#define TEXT_ALIGN_RIGHT1 2

namespace elems {

	void Line(int x1, int y1, int x2, int y2, char sim, WORD attr) {
		const int deltaX = abs(x2 - x1);
		const int deltaY = abs(y2 - y1);
		const int signX = x1 < x2 ? 1 : -1;
		const int signY = y1 < y2 ? 1 : -1;

		int error = deltaX - deltaY;

		while (x1 != x2 || y1 != y2) {
			BufWork::point(x1, y1, sim, attr);

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
		BufWork::point(x1, y1, sim, attr);
	}

	void Box(int x1, int y1, int x2, int y2, char sim, WORD attr) {
		int temp;
		if (x1>x2) {
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		while (x1 <= x2) {
			Line(x1, y1, x1, y2, sim, attr);
			x1++;
		}
	}

	static void textEx(int x, int y, std::string text, WORD attr, int align, bool vertical) {
		
		if(align == 1) {
			if(vertical) {
				y -= (int)text.size() / 2;
			}else{
				x -= (int)text.size() / 2;
			}
		}else if(align == 2) {
			if(vertical) {
				y -= (int)text.size();
			}else{
				x -= (int)text.size();
			}
		}

		for (int i = 0; i < (int)text.size(); i++) {
			BufWork::point( x + (vertical ? 0 : i) , y + (vertical ? i : 0) , text[i], attr);
		}
	}
	
	static void text(int x, int y, std::string text, WORD attr, int align) {
		textEx(x, y, text, attr, align, false);
	}

	static void text(int x, int y, std::string text, WORD attr) {
		textEx(x, y, text, attr, 0, false);
	}

	static void fill(std::string simbols, WORD attr) {
		const int size = simbols.size();
		int sim = 0;
		for(int i = 0; i< (BufWork::size.X * BufWork::size.Y); i++) {
			BufWork::point(i, simbols[sim], attr);
			sim = sim < size - 1 ? sim + 1 : 0;
		}
	}

	static void fillPoints(COORD points[], int count, char sim, WORD attr) {
		for (int i = 0; i < count; i++) {
			BufWork::point(points[i], sim, attr);
		}
	}

}