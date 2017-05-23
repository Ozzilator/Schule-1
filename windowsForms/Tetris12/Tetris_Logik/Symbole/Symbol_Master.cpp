#include "stdafx.h"
#include "Symbol_Master.h"

Symbol_Master::Symbol_Master()
{
}

void Symbol_Master::weiter()
{
	if (posY[0] < 16 || posY[1] < 16 || posY[2] < 16 || posY[3] < 16)
	{
		posY[0]++;
		posY[1]++;
		posY[2]++;
		posY[3]++;
	}
}

void Symbol_Master::links()
{
	for (int i = 0; i < 4; i++)
	{
		if (posX[i] < 1)
		{
			return;
		}
	}

	posX[0] --;
	posX[1] --;
	posX[2] --;
	posX[3] --;
}

void Symbol_Master::rechts()
{
	for (int i = 0; i < 4; i++)
	{
		if (posX[i] > 8)
		{
			return;
		}
	}

	posX[0] ++;
	posX[1] ++;
	posX[2] ++;
	posX[3] ++;
}

void Symbol_Master::schnell()
{
	/*schnell*/
}

int * Symbol_Master::getPosX()
{
	return posX;
}

int * Symbol_Master::getPosY()
{
	return posY;
}