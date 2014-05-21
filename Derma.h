#include "Elements.h"

namespace derma{};

class basegui{
	public:
		COORD getSize();
		COORD getPos();
		WORD getAttr();

		basegui() { // Конструктор по умолчанию
			this->size = { 10, 4 };
			this->pos = { 1, 1 };
			this->attr = 0x0064;
		}

		basegui(COORD size, COORD pos, WORD attr) {
			this->size = size;
			this->pos = pos;
			this->attr = attr;
		}

		void draw() {
			elems::Box(pos.X, pos.Y, size.X, size.Y, ' ', attr);
		}

	protected:
		COORD size;
		COORD pos;
		WORD attr;
};



class frame : basegui {
	public:

		frame() {
			this->title = "Frame";
			this->titleAttr = 0x000F;
		}


		void draw() {
			elems::Box(pos.X, pos.Y, size.X, size.Y, ' ', attr);
			elems::Line(pos.X, pos.Y, size.X, pos.Y, ' ', titleAttr);
			elems::text(pos.X, pos.Y, title, titleAttr);
		}

	protected:
		std::string title;
		WORD titleAttr;

};
