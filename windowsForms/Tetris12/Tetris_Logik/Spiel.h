#ifndef SpielH
#define SpielH
#include "Symbole\Symbol7.h"
//---------------------------------------------------------------------------
class TSpiel
{
private:	TSymbol7* einSymbol;
			int score;
public:	TSpiel();
		~TSpiel();
		void onMyTimer();
		int* getSymbolX() { return einSymbol->getPosX(); }
		int* getSymbolY() { return einSymbol->getPosY(); }
		void symbolLinks();
		void symbolRechts();
		void symbolSchnell();
		void symbolWeiter();
		void symbolDrehen();
		int getScore() { return score; }
		void newGame();
		void startGame();
		void pauseGame();
};
#endif
