#include "Elements.h"

int ShadowColor = 0x0080;


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

class panel : public basegui {
	public:

		panel() { // Конструктор
			this->shadow = true;
		}

		void draw() {
			if (shadow) {
				elems::Box(pos.X + 1, pos.Y + 1, size.X, size.Y, ' ', ShadowColor);
			}
			elems::Box(pos.X, pos.Y, size.X, size.Y, ' ', attr);
		}

	protected:
		bool shadow;

};
