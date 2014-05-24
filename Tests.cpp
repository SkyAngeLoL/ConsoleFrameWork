#include "Derma.h"
#include "ConWork.h"

int main() {

	ConWork::setConsoleSize(100, 46);
	ConWork::setCursorVisible(false);
	BufWork::draw();



	elems::Box(99, 20, 10, 3, ' ',0x0051);
//	elems::Line(      1,1,    9,1,      ' ',0x000F);
	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
	elems::TextEx(10, 0, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, true);
	elems::TextEx(0, 10, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, true);


//	elems::Fill("░▒" , 0x00A5);
//	elems::FillZone({ 1, 1 }, { 98, 44 }, "XYZ", 0x00F0);





//	panel Fr1;
//		Fr1.setPos({ 10, 10 });
//		Fr1.setSize({ 10, 10 });
//	Fr1.draw();


	int S = 0;
//
	while (true) {
//
////		Fr1.setPos({ S++, 10 });
//
//		Fr1.draw();

		elems::Box(S++, 1, 10, 3, ' ', 0x0051);

		BufWork::draw(true);
		
		if (S > BufWork::size.X) { S = -10; };
		Sleep(20);
	}
//
//










	BufWork::draw();
	ConWork::setCursorPos(0, 40);
	system("pause");

	return 0;
}