#ifndef Symbol_MasterH
#define Symbol_MasterH

class Symbol_Master abstract
{
protected:	int posX[4];
			int posY[4];
			int drehPos;
public:	Symbol_Master();
		virtual void drehen() = 0;
		void weiter();
		void links();
		void rechts();
		void schnell();
		int* getPosX();
		int* getPosY();
};
#endif