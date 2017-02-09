#pragma once
using namespace System::Drawing;

ref class Car
{
	public:
		Color farbe;
		int ortx;
		int orty;
		int size;
		int delta;
		int speed;
		long double width;
	
	/*Methoden*/
		Car(int ortx, int orty, int size, int speed, Color farbe);
		void draw(Graphics ^c/*, int ortx, int orty, int size*/);
		void drive(int delta, long double width);
};
