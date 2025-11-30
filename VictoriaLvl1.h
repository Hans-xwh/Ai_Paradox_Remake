#pragma once

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VictoriaLvl1
	/// </summary>
	public ref class VictoriaLvl1 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Label^ lbl_feliz;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lbl_score;

	private: System::Windows::Forms::Button^ btn_save;
	private: System::Windows::Forms::Button^ btn_next;
	private:
		   int puntaje;
	public:
		VictoriaLvl1(int pntj)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			puntaje = pntj;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VictoriaLvl1()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VictoriaLvl1::typeid));
			this->lbl_feliz = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_score = (gcnew System::Windows::Forms::Label());
			this->btn_save = (gcnew System::Windows::Forms::Button());
			this->btn_next = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_feliz
			// 
			this->lbl_feliz->AutoSize = true;
			this->lbl_feliz->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_feliz->Location = System::Drawing::Point(28, 24);
			this->lbl_feliz->Name = L"lbl_feliz";
			this->lbl_feliz->Size = System::Drawing::Size(697, 31);
			this->lbl_feliz->TabIndex = 0;
			this->lbl_feliz->Text = L"¡Felicidades, has derrotado a Bombardino Crocodilo!";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(260, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Tu puntaje es:";
			// 
			// lbl_score
			// 
			this->lbl_score->AutoSize = true;
			this->lbl_score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_score->Location = System::Drawing::Point(415, 88);
			this->lbl_score->Name = L"lbl_score";
			this->lbl_score->Size = System::Drawing::Size(54, 25);
			this->lbl_score->TabIndex = 2;
			this->lbl_score->Text = L"XXX";
			// 
			// btn_save
			// 
			this->btn_save->Location = System::Drawing::Point(265, 152);
			this->btn_save->Name = L"btn_save";
			this->btn_save->Size = System::Drawing::Size(204, 23);
			this->btn_save->TabIndex = 3;
			this->btn_save->TabStop = false;
			this->btn_save->Text = L"Guardar Partida";
			this->btn_save->UseVisualStyleBackColor = true;
			this->btn_save->Click += gcnew System::EventHandler(this, &VictoriaLvl1::btn_save_Click);
			// 
			// btn_next
			// 
			this->btn_next->Location = System::Drawing::Point(666, 405);
			this->btn_next->Name = L"btn_next";
			this->btn_next->Size = System::Drawing::Size(74, 56);
			this->btn_next->TabIndex = 4;
			this->btn_next->TabStop = false;
			this->btn_next->Text = L"Siguiente";
			this->btn_next->UseVisualStyleBackColor = true;
			this->btn_next->Click += gcnew System::EventHandler(this, &VictoriaLvl1::btn_next_Click);
			// 
			// VictoriaLvl1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(752, 473);
			this->Controls->Add(this->btn_next);
			this->Controls->Add(this->btn_save);
			this->Controls->Add(this->lbl_score);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_feliz);
			this->KeyPreview = true;
			this->Name = L"VictoriaLvl1";
			this->Text = L"VictoriaLvl1";
			this->Load += gcnew System::EventHandler(this, &VictoriaLvl1::VictoriaLvl1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VictoriaLvl1::VictoriaLvl1_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VictoriaLvl1_Load(System::Object^ sender, System::EventArgs^ e) { 
	}
	private: System::Void VictoriaLvl1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//g->DrawImage(victoriaImg, 0, 0, this->ClientSize.Width, this->ClientSize.Height);
		this->lbl_score->Text = puntaje.ToString();
	}
	private: System::Void btn_next_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Close();
	}
private: System::Void btn_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (puntaje >= 0) {
		this->btn_save->Text = "Partida guardada!";
	}
	else
	{
		this->btn_save->Text = "No se ha podido guardar";
	}
	this->btn_save->Enabled = false;
}
};
}
