#include "funktionen.h"

bool schaltjahr(int jahr)
{
	bool schaltjahr;

	if (jahr >= 1582)
	{
		if (jahr % 4 == 0)
		{
			schaltjahr = true;
		}

		if (jahr % 100 == 0)
		{
			schaltjahr = false;
		}

		if (jahr % 400 == 0)
		{
			schaltjahr = true;
		}


	}

	else
	{
		if (jahr % 4 == 0)
		{
			schaltjahr = true;
		}
	}

	return schaltjahr;
}