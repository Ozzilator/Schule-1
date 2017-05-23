//---------------------------------------------------------------------------
#include "stdafx.h"
#include "Symbol3.h"
//---------------------------------------------------------------------------
TSymbol3::TSymbol3()
{
	posX[0] = 4;
	posX[1] = 5;
	posX[2] = 5;
	posX[3] = 5;
	posY[0] = 2;
	posY[1] = 2;
	posY[2] = 1;
	posY[3] = 0;
	drehPos = 0;
}
//---------------------------------------------------------------------------
void TSymbol3::drehen()
{
	switch (drehPos)
	{
	case 0:
		posX[0];
		posX[1] --;
		posX[3] ++;
		posY[0] = posY[0] - 2;
		posY[1] --;
		posY[3] ++;
		drehPos = 1;
		break;
	case 1:
		posX[0] = posX[0] + 2;
		posX[1] ++;
		posX[3] --;
		posY[0];
		posY[1] --;
		posY[3] ++;
		drehPos = 2;
		break;
	case 2:
		posX[0];
		posX[1] ++;
		posX[3] --;
		posY[0] = posY[0] + 2;
		posY[1] ++;
		posY[3] --;
		drehPos = 3;
		break;
	case 3:
		posX[0] = posX[0] - 2;
		posX[1] --;
		posX[3] ++;
		posY[0];
		posY[1] ++;
		posY[3] --;
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