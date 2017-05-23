//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Symbol7.h"
//---------------------------------------------------------------------------
TSymbol7::TSymbol7()
{
	posX[0] = 4;
	posX[1] = 5;
	posX[2] = 5;
	posX[3] = 6;
	posY[0] = 1;
	posY[1] = 1;
	posY[2] = 0;
	posY[3] = 0;
	drehPos = 0;
}
//---------------------------------------------------------------------------
void TSymbol7::drehen()
{
	switch (drehPos)
	{
	case 0:
		posX[0] ++;
		posX[2] ++;
		posX[3];
		posY[0] --;
		posY[2] ++;
		posY[3] = posY[3] + 2;
		drehPos = 1;
		break;
	case 1:
		posX[0] --;
		posX[2] --;
		posX[3];
		posY[0] ++;
		posY[2] --;
		posY[3] = posY[3] - 2;
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