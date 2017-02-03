#pragma once

namespace Auto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	void draw(Graphics ^c, int ortx, int orty, int size)
	{
		Brush^ b = gcnew SolidBrush(Color::Red);
		Pen^ p = gcnew Pen(Color::Black, 3);
		SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);
		SolidBrush^ blackBrush = gcnew SolidBrush(Color::Black);
		SolidBrush^ silverBrush = gcnew SolidBrush(Color::Silver);

		int x2 = ortx + size;
		int y2 = orty + size / 2;
		int x3 = x2 - size / 4;
		int r = size / 8;
		int x4 = ortx + size / 13 + r / 2;
		int x5 = x2 - size / 13 - r / 2;

		/*Karosserie*/
		c->FillRectangle(b, ortx, orty, size, size / 2);
		c->DrawRectangle(p, ortx, orty, size, size / 2);

		/*Fenster*/
		c->FillRectangle(whiteBrush, x3, orty + 2, size / 4, size / 4);
		c->DrawRectangle(p, x3, orty + 2, size / 4, size / 4);

		/*Rad*/
		c->FillEllipse(blackBrush, x4 - r, y2 - r, r * 2, r * 2);
		c->FillEllipse(blackBrush, x5 - r, y2 - r, r * 2, r * 2);

		/*Felge*/
		r = r / 2;
		c->FillEllipse(silverBrush, x4 - r, y2 - r, r * 2, r * 2);
		c->FillEllipse(silverBrush, x5 - r, y2 - r, r * 2, r * 2);
	}

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(106, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"zeichnen";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Graphics ^c = CreateGraphics();
		draw(c, 50, 50, 150);
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		draw(e->Graphics, 0, 0, 0);
	}
	};
}
