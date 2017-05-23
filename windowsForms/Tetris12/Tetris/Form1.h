#include "../Tetris_logik/Spiel.h"
#pragma once

namespace Tetris {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		int gross;
		int posFeldX;
		int posFeldY;
	private: TSpiel* einSpiel;
	public:
		Form1(void)
		{
			InitializeComponent();
			gross = 25; //Würfelgrösse
			posFeldX = 10; // Spielfeldpos x
			posFeldY = 10; // Spielfeldpos y
			einSpiel = new TSpiel();
		}
		//*** Operation block zeichnet einen Block;
		void block(Graphics^ g, int x, int y)
		{
			g->FillRectangle(Brushes::Blue, x * gross + posFeldX, y * gross + posFeldY, gross, gross);
			g->DrawRectangle(Pens::Black, x * gross + posFeldX, y * gross + posFeldY, gross, gross);
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(365, 577);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		int x, y;
		int *xWerte, *yWerte;
		e->Graphics->FillRectangle(Brushes::White, posFeldX, posFeldY, gross * 10, gross * 18);
		xWerte = einSpiel->getSymbolX();
		yWerte = einSpiel->getSymbolY();
		for (int i = 0; i < 4; i++)
		{
			x = xWerte[i];
			y = yWerte[i];
			block(e->Graphics, x, y);
		}
	}
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::Down)
		{
			einSpiel->symbolWeiter();
		}
		if (e->KeyCode == Keys::Up)
		{
			einSpiel->symbolDrehen();
		}
		if (e->KeyCode == Keys::Left)
		{
			einSpiel->symbolLinks();
		}
		if (e->KeyCode == Keys::Right)
		{
			einSpiel->symbolRechts();
		}
		Refresh();
	} // Ende KeyDown
	};
}

