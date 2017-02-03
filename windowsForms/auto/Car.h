#pragma once
using namespace System::Drawing;

ref class Car
{
	public:
		Color farbe;
		int ortx;
		int orty;
		int size;
	/*Methoden*/
		Car();
		void draw(Graphics ^c, int ortx, int orty, int size);
		void drive();
};

