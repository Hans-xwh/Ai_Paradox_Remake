#pragma once
#include "Guardado.hpp"

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Ranking
	/// </summary>
	public ref class Ranking : public System::Windows::Forms::Form
	{
	private:
		Guardado* saveMngr;
		GameSave* nvl1;
		GameSave* nvl2;
		GameSave* nvl3;
	public:
		Ranking(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			saveMngr = new Guardado();
			nvl1 = saveMngr->readSave(1);
			nvl2 = saveMngr->readSave(2);
			nvl3 = saveMngr->readSave(3);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ranking()
		{
			if (components)
			{
				delete components;
			}

			delete saveMngr;
			delete nvl1;
			delete nvl2;
			delete nvl3;
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lbl_Name1;
	private: System::Windows::Forms::Label^ lbl_Ptj1;
	private: System::Windows::Forms::Label^ lbl_Ptj2;

	private: System::Windows::Forms::Label^ lbl_Name2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ lbl_Ptj3;

	private: System::Windows::Forms::Label^ lbl_Name3;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Ranking::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl_Name1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Ptj1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Ptj2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Name2 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lbl_Ptj3 = (gcnew System::Windows::Forms::Label());
			this->lbl_Name3 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(104, 135);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nivel 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(394, 136);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 31);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nivel 2";
			this->label2->Click += gcnew System::EventHandler(this, &Ranking::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(692, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 31);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Nivel 3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(386, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 31);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Records";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(79, 306);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Nombre: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(79, 358);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Puntaje: ";
			// 
			// lbl_Name1
			// 
			this->lbl_Name1->AutoSize = true;
			this->lbl_Name1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Name1->Location = System::Drawing::Point(184, 306);
			this->lbl_Name1->Name = L"lbl_Name1";
			this->lbl_Name1->Size = System::Drawing::Size(52, 24);
			this->lbl_Name1->TabIndex = 6;
			this->lbl_Name1->Text = L"XXX";
			// 
			// lbl_Ptj1
			// 
			this->lbl_Ptj1->AutoSize = true;
			this->lbl_Ptj1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Ptj1->Location = System::Drawing::Point(184, 358);
			this->lbl_Ptj1->Name = L"lbl_Ptj1";
			this->lbl_Ptj1->Size = System::Drawing::Size(52, 24);
			this->lbl_Ptj1->TabIndex = 7;
			this->lbl_Ptj1->Text = L"XXX";
			// 
			// lbl_Ptj2
			// 
			this->lbl_Ptj2->AutoSize = true;
			this->lbl_Ptj2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Ptj2->Location = System::Drawing::Point(478, 358);
			this->lbl_Ptj2->Name = L"lbl_Ptj2";
			this->lbl_Ptj2->Size = System::Drawing::Size(52, 24);
			this->lbl_Ptj2->TabIndex = 11;
			this->lbl_Ptj2->Text = L"XXX";
			// 
			// lbl_Name2
			// 
			this->lbl_Name2->AutoSize = true;
			this->lbl_Name2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Name2->Location = System::Drawing::Point(478, 306);
			this->lbl_Name2->Name = L"lbl_Name2";
			this->lbl_Name2->Size = System::Drawing::Size(52, 24);
			this->lbl_Name2->TabIndex = 10;
			this->lbl_Name2->Text = L"XXX";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(373, 358);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(83, 24);
			this->label11->TabIndex = 9;
			this->label11->Text = L"Puntaje: ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(373, 306);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(89, 24);
			this->label12->TabIndex = 8;
			this->label12->Text = L"Nombre: ";
			// 
			// lbl_Ptj3
			// 
			this->lbl_Ptj3->AutoSize = true;
			this->lbl_Ptj3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Ptj3->Location = System::Drawing::Point(781, 358);
			this->lbl_Ptj3->Name = L"lbl_Ptj3";
			this->lbl_Ptj3->Size = System::Drawing::Size(52, 24);
			this->lbl_Ptj3->TabIndex = 15;
			this->lbl_Ptj3->Text = L"XXX";
			// 
			// lbl_Name3
			// 
			this->lbl_Name3->AutoSize = true;
			this->lbl_Name3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Name3->Location = System::Drawing::Point(781, 306);
			this->lbl_Name3->Name = L"lbl_Name3";
			this->lbl_Name3->Size = System::Drawing::Size(52, 24);
			this->lbl_Name3->TabIndex = 14;
			this->lbl_Name3->Text = L"XXX";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(676, 358);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(83, 24);
			this->label15->TabIndex = 13;
			this->label15->Text = L"Puntaje: ";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(676, 306);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(89, 24);
			this->label16->TabIndex = 12;
			this->label16->Text = L"Nombre: ";
			// 
			// Ranking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(884, 601);
			this->Controls->Add(this->lbl_Ptj3);
			this->Controls->Add(this->lbl_Name3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->lbl_Ptj2);
			this->Controls->Add(this->lbl_Name2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->lbl_Ptj1);
			this->Controls->Add(this->lbl_Name1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Ranking";
			this->Text = L"Ranking";
			this->Load += gcnew System::EventHandler(this, &Ranking::Ranking_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Ranking::Ranking_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Ranking_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void Ranking_Load(System::Object^ sender, System::EventArgs^ e) {
	this->lbl_Name1->Text = gcnew String(nvl1->nombre);
	this->lbl_Ptj1->Text = gcnew String(nvl1->puntaje.ToString());

	this->lbl_Name2->Text = gcnew String(nvl2->nombre);
	this->lbl_Ptj2->Text = gcnew String(nvl2->puntaje.ToString());

	this->lbl_Name3->Text = gcnew String(nvl3->nombre);
	this->lbl_Ptj3->Text = gcnew String(nvl3->puntaje.ToString());
}

};
}
