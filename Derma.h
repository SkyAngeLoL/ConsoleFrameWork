#include "Elements.h"


class basegui{
	public:

		basegui() { // Конструктор
			this->size = { 10, 5 };
			this->pos = { 1, 1 };
			this->attr = 0x0064;
		}

		void setSize(COORD size) { this->size = size; }
		void setPos(COORD pos) { this->pos = pos; }

	protected:
		COORD size;
		COORD pos;
		WORD attr;
};



class frame : public basegui {
	public:

		frame() { // Конструктор
			this->title = "Frame";
			this->titleAttr = 0x000F;
			this->shadow = true;
			this->fillChars = "|L";
		}

		void draw() {
			if (shadow) {
				elems::Box(pos.X + 1, pos.Y + 1, size.X - 1, size.Y - 1, ' ', 0x0080);
			}
			elems::FillZone(pos, size, fillChars, attr);
			elems::Line(pos.X, pos.Y, pos.X + size.X - 1, pos.Y, ' ', titleAttr);
			elems::Text(pos.X, pos.Y, title, titleAttr);
		}

	protected:
		std::string title;
		WORD titleAttr;
		bool shadow;
		std::string fillChars;

};
