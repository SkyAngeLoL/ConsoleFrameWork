#include "Derma.h"
#include "ConWork.h"

#include <time.h>

int main() {

	ConWork::setConsoleSize(100, 50);
	ConWork::setCursorVisible(false);


	cbuffer Header({ 0, 0 }, { 100, 5 });
	cbuffer Body({ 0, 6 }, { 100, 44 });

	int a = -30;

	while (true) {
		Body.AddText(0, 0, "0123456789",0x00F0);
		Body.AddTextEx(0, 0, "0123456789", 0x00F0,0,true);

		Body.AddText(10, 10, "background text", 0x00F0);

		Body.AddBox(a, 0, 100, 44, ' ', 0x0043);
		if (a > 120) { a = -120; };
		a += 1;
		Body.AddText(11, 15, "Foreground text", 0x00F0);



		Header.AddText(1, 1, "Box x pos " + std::to_string(a), 0x00FC);

		Header.draw(true);
		Body.draw(true);
		Sleep(20);
	}




//	BufWork::draw();



//	elems::Box(1, 1, 10, 3, ' ',0x0051);
//	elems::Box(40, 25, 10, 1, ' ', 0x0051);
//	elems::Line(10,28, 20, 28,      ' ',0x000F);
//	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
//	elems::TextEx(10, 0, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, false);
//	elems::TextEx(0, 0, "0123456789", 0x00F3, TEXT_ALIGN_LEFT, true);
//	elems::TextEx(0, 10, " 123456789", 0x00F3, TEXT_ALIGN_LEFT, true);

//	elems::FillZone({ 10, 24 }, { 10, 3 }, "XE", 0x00F0);





//	panel Fr1;
//		Fr1.setPos({ 10, 10 });
//		Fr1.setSize({ 10, 10 });
//	Fr1.draw();


//	int S = 0;
//
//	while (true) {
//
//		Fr1.setPos({ S++, 10 });
//
//		Fr1.draw();

//		elems::Box(S++, 1, 10, 3, ' ', 0x0051);

//		BufWork::draw();
		
//		if (S > BufWork::size.X) { S = -10; };
//		Sleep(5);
//	}



//	BufWork::draw();
//	ConWork::setCursorPos(0, 40);


	system("pause");

	return 0;
}