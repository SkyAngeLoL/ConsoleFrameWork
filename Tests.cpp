#include "Derma.h"
#include "ConWork.h"

int main() {

	ConWork::setConsoleSize(100, 46);
	BufWork::draw();



//	elems::Box(2, 2, 1, 1, ' ',0x0051);
//	elems::Line(      1,1,    9,1,      ' ',0x000F);
	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
	elems::TextEx(10, 0, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, true);
	elems::TextEx(0, 10, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, true);
//	std::string Ar = "X ";	elems::Fill(Ar, 0x00A5);
//	elems::FillZone({ 1, 1 }, { 98, 44 }, "XYZ", 0x00F0);

	frame Fr1;
		Fr1.setPos({ 0, 0 });
		Fr1.setSize({ 10, 10 });
	Fr1.draw();













	BufWork::draw();
	ConWork::setCursorPos(0, 40);
	system("pause");

	return 0;
}