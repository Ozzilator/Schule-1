//#include "stdafx.h"
#include <stdlib.h>
#include "Car.h"

Car::Car(int tortx, int torty, int tsize, int tspeed, Color tfarbe)
{
	farbe = tfarbe;
	size = tsize;
	ortx = tortx;
	orty = torty;
	speed = tspeed;
}

void Car::draw(Graphics ^c)
{
	Brush^ b = gcnew SolidBrush(farbe);
	Pen^ p = gcnew Pen(Color::Black, 3);
	SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);
	SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
	SolidBrush^ silverBrush = gcnew SolidBrush(Color::Silver);

	int x2 = ortx + size;
	int y2 = orty + size / 2;
	int x3 = x2 - size / 4;
	int r = size / 8;
	int x4 = ortx + size / 13 + r / 2;
	int x5 = x2 - size / 13 - r / 2;

	/*Karosserie*/
	c->FillRectangle(b, ortx, orty, size, size / 2);
	c->DrawRectangle(p, ortx, orty, size, size / 2);

	/*Fenster*/
	c->FillRectangle(whiteBrush, x3, orty + 2, size / 4, size / 4);
	c->DrawRectangle(p, x3, orty + 2, size / 4, size / 4);

	/*Rad*/
	c->FillEllipse(blackBrush, x4 - r, y2 - r, r * 2, r * 2);
	c->FillEllipse(blackBrush, x5 - r, y2 - r, r * 2, r * 2);

	/*Felge*/
	r = r / 2;
	c->FillEllipse(silverBrush, x4 - r, y2 - r, r * 2, r * 2);
	c->FillEllipse(silverBrush, x5 - r, y2 - r, r * 2, r * 2);
}

void Car::drive(int delta, long double width)
{
	ortx = ortx + delta * speed;
	if (ortx > width)
	{
		ortx = - size;
	}

	if (ortx < - size)
	{
		ortx = width;
	}
}
