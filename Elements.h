#include "BufferWork.h"
#include <string>

#define TEXT_ALIGN_LEFT 0
#define TEXT_ALIGN_CENTER 1
#define TEXT_ALIGN_RIGHT 2

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

	void Box(int x, int y, int w, int h, char sim, WORD attr) {
		int x2 = min(x + w, BufWork::size.X - 1);
		int y2 = y + h;

		while (x <= x2) {
			Line(x, y, x, y2, sim, attr);
			x++;
		}
	}

	static void TextEx(int x, int y, std::string text, WORD attr, int align, bool vertical) {
		
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
	
	static void Text(int x, int y, std::string text, WORD attr, int align) {
		TextEx(x, y, text, attr, align, false);
	}

	static void Text(int x, int y, std::string text, WORD attr) {
		TextEx(x, y, text, attr, 0, false);
	}

	static void Fill(std::string simbols, WORD attr) {
		const int size = simbols.size();
		int sim = 0;
		for(int i = 0; i< (BufWork::size.X * BufWork::size.Y); i++) {
			BufWork::point(i, simbols[sim], attr);
			sim = sim < size - 1 ? sim + 1 : 0;
		}
	}

	//static void fillPoints(COORD points[], int count, char sim, WORD attr) {
	//	for (int i = 0; i < count; i++) {
	//		BufWork::point(points[i], sim, attr);
	//	}
	//}

	static void FillZone(COORD pos1, COORD pos2, std::string simbols, WORD attr) {
		const int size = simbols.size();
		int sim = 0;

		for (int i = pos1.X; i < (pos1.X + pos2.X); i++) {
			for (int j = pos1.Y; j < (pos1.Y + pos2.Y); j++) {
				int I = j * BufWork::size.X + i;

				BufWork::point(I, simbols[sim], attr);

				sim = sim < size - 1 ? sim + 1 : 0;
			}
		}



	}
}