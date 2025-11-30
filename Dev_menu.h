#pragma once


#include "AvionNvl1.h"
#include "VictoriaLvl1.h"
#include "Guardado.hpp"


namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dev_menu
	/// </summary>
	public ref class Dev_menu : public System::Windows::Forms::Form
	{
	public:
		Dev_menu(void)
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
		~Dev_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Btn_Avion;
	private: System::Windows::Forms::Button^ btn_avionWin;
	private: System::Windows::Forms::Button^ btn_initData;

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
			this->Btn_Avion = (gcnew System::Windows::Forms::Button());
			this->btn_avionWin = (gcnew System::Windows::Forms::Button());
			this->btn_initData = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Btn_Avion
			// 
			this->Btn_Avion->Location = System::Drawing::Point(21, 21);
			this->Btn_Avion->Name = L"Btn_Avion";
			this->Btn_Avion->Size = System::Drawing::Size(127, 42);
			this->Btn_Avion->TabIndex = 0;
			this->Btn_Avion->Text = L"Minijuego Avion";
			this->Btn_Avion->UseVisualStyleBackColor = true;
			this->Btn_Avion->Click += gcnew System::EventHandler(this, &Dev_menu::Btn_Avion_Click);
			// 
			// btn_avionWin
			// 
			this->btn_avionWin->Location = System::Drawing::Point(21, 69);
			this->btn_avionWin->Name = L"btn_avionWin";
			this->btn_avionWin->Size = System::Drawing::Size(127, 42);
			this->btn_avionWin->TabIndex = 1;
			this->btn_avionWin->Text = L"Victoria Avion";
			this->btn_avionWin->UseVisualStyleBackColor = true;
			this->btn_avionWin->Click += gcnew System::EventHandler(this, &Dev_menu::btn_avionWin_Click);
			// 
			// btn_initData
			// 
			this->btn_initData->ForeColor = System::Drawing::Color::Red;
			this->btn_initData->Location = System::Drawing::Point(371, 402);
			this->btn_initData->Name = L"btn_initData";
			this->btn_initData->Size = System::Drawing::Size(127, 42);
			this->btn_initData->TabIndex = 2;
			this->btn_initData->Text = L"Inicializar Data";
			this->btn_initData->UseVisualStyleBackColor = true;
			this->btn_initData->Click += gcnew System::EventHandler(this, &Dev_menu::btn_initData_Click);
			// 
			// Dev_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(510, 528);
			this->Controls->Add(this->btn_initData);
			this->Controls->Add(this->btn_avionWin);
			this->Controls->Add(this->Btn_Avion);
			this->Name = L"Dev_menu";
			this->Text = L"Dev_menu";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Btn_Avion_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		AvionNvl1^ frm_avion = gcnew AvionNvl1();
		frm_avion->ShowDialog();
		delete frm_avion;
		this->Show();
	}
	private: System::Void btn_avionWin_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		VictoriaLvl1^ frm_victoria = gcnew VictoriaLvl1(-1);	//-1 no guarda la partida
		frm_victoria->ShowDialog();
		delete frm_victoria;
		this->Show();
	}
	private: System::Void btn_initData_Click(System::Object^ sender, System::EventArgs^ e) {
		Guardado* gestor = new Guardado();
		gestor->initSaveFile();
		delete gestor;
	}
};
}
