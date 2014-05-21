#include "Derma.h"
#include "ConWork.h"

int main() {

	ConWork::setConsoleSize(55, 26);
	BufWork::draw();



//	elems::Box(1,1,10,10,' ',0x0051);
//	elems::Line(1,1, 10,10,' ',0x000F);
//	elems::textEx(5, 8, "TestText", 0x00F3, TEXT_ALIGN_LEFT, true);
//	elems::textEx(6, 8, "TestText", 0x00F3, TEXT_ALIGN_CENTER, true);
//	elems::textEx(7, 8, "TestText", 0x00F3, TEXT_ALIGN_RIGHT, true);
//	std::string Ar = "X ";	elems::fill(Ar, 0x00A5);


	frame Fr1;
	
	Fr1.draw();

	BufWork::draw();




	Sleep(2500);
	system("pause");

	return 0;
}