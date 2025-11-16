#pragma once

#include "MainForm.h"

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuInicio
	/// </summary>
	public ref class MenuInicio : public System::Windows::Forms::Form
	{
	public:
		MenuInicio(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	private:
		MainForm^ mundo2;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(312, 247);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 65);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Mundo 2";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuInicio::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(289, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 39);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Menu preliminar";
			// 
			// MenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(876, 602);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MenuInicio";
			this->Text = L"MenuInicio";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {	//Boton mundo 2
		mundo2 = gcnew MainForm();
		this->Hide();
		mundo2->ShowDialog();
		delete mundo2;
		this->Show();
	}
	};
}
