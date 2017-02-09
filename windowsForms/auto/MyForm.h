#pragma once
#include "Car.h"

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

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Car^ myCar;
		MyForm(void) /*Konstruktor*/
		{
			InitializeComponent();
			myCar = gcnew Car();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm() /*Destruktor*/
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(12, 205);
			this->trackBar1->Maximum = 50;
			this->trackBar1->Minimum = -50;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(510, 45);
			this->trackBar1->SmallChange = 5;
			this->trackBar1->TabIndex = 2;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 262);
			this->Controls->Add(this->trackBar1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		/*Graphics ^c = CreateGraphics();
		myCar -> draw(c, 50, 50, 150);*/
		//this->timer1->Enabled = true;

	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		//myCar -> draw(e->Graphics, 0, 0, 0);
		myCar->draw(e->Graphics);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		this->timer1->Enabled = true;
		myCar->drive(trackBar1->Value);
		Refresh();
	}
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
	{

	}
};
}
