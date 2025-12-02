#pragma once

#include "Dev_menu.h"
#include "MainForm.h"
#include "SegundoForm.h"
#include "creditos.h"
#include "TercerForm.h"
#include "Instrucciones.h"
#include "Intro.h"

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
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public:
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button2;

	public:
	private: System::Windows::Forms::Button^ button3;

	private:
		MainForm^ mundo2;
	private: System::Windows::Forms::Button^ btn_dev;
	private: System::Windows::Forms::Button^ button1;
		   SegundoForm^ mundo2parte2;
		   TercerForm^ mundo3;


	private: System::Windows::Forms::Button^ button6;
		   Creditos^ creditos;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuInicio::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btn_dev = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->Location = System::Drawing::Point(371, 42);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(656, 172);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(385, 52);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(626, 147);
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Font = (gcnew System::Drawing::Font(L"Snap ITC", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(446, 257);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(525, 124);
			this->button2->TabIndex = 4;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Snap ITC", 22.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(197, 214);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(186, 54);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MenuInicio::button3_Click);
			// 
			// btn_dev
			// 
			this->btn_dev->Location = System::Drawing::Point(777, 558);
			this->btn_dev->Name = L"btn_dev";
			this->btn_dev->Size = System::Drawing::Size(90, 32);
			this->btn_dev->TabIndex = 4;
			this->btn_dev->Text = L"Dev Menu";
			this->btn_dev->UseVisualStyleBackColor = true;
			this->btn_dev->Click += gcnew System::EventHandler(this, &MenuInicio::btn_dev_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(200, 444);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(183, 80);
			this->button1->TabIndex = 5;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuInicio::button1_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(209, 329);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(174, 75);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Instrucciones";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MenuInicio::button6_Click);
			// 
			// MenuInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(879, 602);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn_dev);
			this->Controls->Add(this->button3);
			this->Name = L"MenuInicio";
			this->Text = L"MenuInicio";
			this->Load += gcnew System::EventHandler(this, &MenuInicio::MenuInicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {	//Boton mundo 2
		
		Intro^ intro = gcnew Intro();
		this->Hide();
		intro->ShowDialog();
		delete intro;
		this->Show();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MenuInicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e) {//Boton mundo 2  parte 2
	mundo2parte2 = gcnew SegundoForm();
	this->Hide();
	mundo2parte2->ShowDialog();
	delete mundo2parte2;
	this->Show();

}
private: System::Void btn_dev_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	Dev_menu^ devmenu = gcnew Dev_menu();
	devmenu->ShowDialog();
	delete devmenu;
	this->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	creditos = gcnew Creditos();
	this->Hide();
	creditos->ShowDialog();
	delete creditos;
	this->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	mundo3 = gcnew TercerForm();
	this->Hide();
	mundo3->ShowDialog();
	delete mundo3;
	this->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	mundo2parte2 = gcnew SegundoForm();
	this->Hide();
	mundo2parte2->ShowDialog();
	delete mundo2parte2;
	this->Show();

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Instrucciones^ inst = gcnew Instrucciones();
	this->Hide();
	inst->ShowDialog();
	delete inst;
	this->Show();
}
};
}
