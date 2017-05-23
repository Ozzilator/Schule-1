//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Symbol5.h"
//---------------------------------------------------------------------------
TSymbol5::TSymbol5()
{
	posX[0] = 5;
	posX[1] = 5;
	posX[2] = 5;
	posX[3] = 5;
	posY[0] = 0;
	posY[1] = 1;
	posY[2] = 2;
	posY[3] = 3;
	drehPos = 0;
}
//---------------------------------------------------------------------------
void TSymbol5::drehen()
{
	switch (drehPos)
	{
	case 0:
		posX[0] ++;
		posX[2] --;
		posX[3] = posX[3] - 2;
		posY[0] ++;
		posY[2] --;
		posY[3] = posY[3] - 2;
		drehPos = 1;
		break;
	case 1:
		posX[0] --;
		posX[2] ++;
		posX[3] = posX[3] + 2;
		posY[0] --;
		posY[2] ++;
		posY[3] = posY[3] + 2;
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