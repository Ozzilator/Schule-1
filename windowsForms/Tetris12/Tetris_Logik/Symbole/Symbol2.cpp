//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Symbol2.h"
//---------------------------------------------------------------------------
TSymbol2::TSymbol2()
{
	posX[0] = 4;
	posX[1] = 5;
	posX[2] = 5;
	posX[3] = 6;
	posY[0] = 0;
	posY[1] = 0;
	posY[2] = 1;
	posY[3] = 0;
	drehPos = 0;
}
//---------------------------------------------------------------------------
void TSymbol2::drehen()
{
	switch (drehPos)
	{
	case 0:
		posX[0] ++;
		posX[2] --;
		posX[3] --;
		posY[0] --;
		posY[2] --;
		posY[3] ++;
		drehPos = 1;
		break;
	case 1:
		posX[0] ++;
		posX[2] ++;
		posX[3] --;
		posY[0] ++;
		posY[2] --;
		posY[3] --;
		drehPos = 2;
		break;
	case 2:
		posX[0] --;
		posX[2] ++;
		posX[3] ++;
		posY[0] ++;
		posY[2] ++;
		posY[3] --;
		drehPos = 3;
		break;
	case 3:
		posX[0] --;
		posX[2] --;
		posX[3] ++;
		posY[0] --;
		posY[2] ++;
		posY[3] ++;
		drehPos = 0;
		break;
	}
	while (posX[0] < 0 || posX[1] < 0 || posX[2] < 0 || posX[3] < 0)
	{
		posX[0] ++;
		posX[1] ++;
		posX[2] ++;
		posX[3] ++;
	}
	while (posX[0] > 9 || posX[1] > 9 || posX[2] > 9 || posX[0] > 9)
	{
		posX[0] --;
		posX[1] --;
		posX[2] --;
		posX[3] --;
	}
}