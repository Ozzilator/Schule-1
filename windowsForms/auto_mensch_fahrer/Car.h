#pragma once
#include "Fahrer.h"
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
		Fahrer^ myFahrer;
	
		/*Methoden*/
		Car(int ortx, int orty, int size, int speed, Color farbe);
		Car();
		void draw(Graphics ^c/*, int ortx, int orty, int size*/);
		void drive(int delta, long double width);/*width = bildschirmbreite*/
};
