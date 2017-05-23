//---------------------------------------------------------------------------

#include "StdAfx.h"
#include "Symbole\Symbol7.h"
#include "Spiel.h"

TSpiel::TSpiel()
  {
   score = 0;
   einSymbol = new TSymbol7();
  }
//---------------------------------------------------------------------------
TSpiel::~TSpiel()
  {
   delete einSymbol;
  }
//---------------------------------------------------------------------------

void TSpiel::onMyTimer()
  {
   einSymbol->weiter();
  }
void TSpiel::symbolWeiter()
  {
   einSymbol->weiter();
  }
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TSpiel::symbolLinks()
  {
	  einSymbol->links();
  }
//---------------------------------------------------------------------------
void TSpiel::symbolRechts()
  {
   einSymbol->rechts();
  }
//---------------------------------------------------------------------------
void TSpiel::symbolSchnell()
  {
   einSymbol->schnell();
  }
//---------------------------------------------------------------------------
void TSpiel::symbolDrehen()
  {
   einSymbol->drehen();
  }
void  TSpiel::newGame()
{
  score = 0;
  delete einSymbol;
  einSymbol = new TSymbol7();
}
void  TSpiel::startGame()
{
  //eineUhr->Enabled = true;
}
void  TSpiel::pauseGame()
{
  //eineUhr->Enabled = false;
}

