#pragma once
#include "ControlNvl1.hpp"
#include "ParalaxManager.hpp"

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AvionNvl1
	/// </summary>
	public ref class AvionNvl1 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ mybuffer;
		BufferedGraphics^ bCanvas;
		Random^ r;
		ParalaxManager^ paralax;
		Sprite_DB^ sprite_db;
		MnJg_Avion* ctrlAvion;
		bool pausa = false;

	private: System::Windows::Forms::Timer^ timer2;
	public:
		AvionNvl1(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();
			mybuffer = BufferedGraphicsManager::Current;
			bCanvas = mybuffer->Allocate(g, this->ClientRectangle);
			
			r = gcnew Random();
			paralax = gcnew ParalaxManager(1, 2);
			sprite_db = gcnew Sprite_DB(11);	//Nivel 1_1
			ctrlAvion = new MnJg_Avion();

			//lbl_pausa->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AvionNvl1()
		{
			if (components)
			{
				delete components;
			}

			delete ctrlAvion;
			delete r;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

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
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 16;
			this->timer1->Tick += gcnew System::EventHandler(this, &AvionNvl1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 360;
			this->timer2->Tick += gcnew System::EventHandler(this, &AvionNvl1::timer2_Tick);
			// 
			// AvionNvl1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1147, 608);
			this->Name = L"AvionNvl1";
			this->Text = L"AvionNvl1";
			this->Load += gcnew System::EventHandler(this, &AvionNvl1::AvionNvl1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AvionNvl1::AvionNvl1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &AvionNvl1::AvionNvl1_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bCanvas->Graphics->Clear(Color::White);
		paralax->draw(bCanvas);

		ctrlAvion->updateAll(bCanvas);
		ctrlAvion->updateCollisions();
		ctrlAvion->drawAll(bCanvas, sprite_db);

		//bCanvas->Render(g);

		if (pausa) {
			this->timer2->Enabled = false;
			bCanvas->Graphics->FillRectangle(Brushes::White,
				this->ClientSize.Width / 2 - 100,
				this->ClientSize.Height / 2 - 50,
				250, 80);
			bCanvas->Graphics->DrawString("PAUSA",
				gcnew Drawing::Font("Arial", 48, Drawing::FontStyle::Bold),
				Brushes::Black,
				this->ClientSize.Width / 2 - 100,
				this->ClientSize.Height / 2 - 50);
			this->timer1->Enabled = false;
		}

		bCanvas->Render(g);

		if(ctrlAvion->getVidaBombardino() <= 0){
			this->timer1->Enabled = false;
			this->timer2->Enabled = false;
			this->Hide();
			MessageBox::Show("¡Has derrotado a Bombardino Crocodilo!\n¡Felicidades, has completado el nivel!");
			this->Close();
		}
	}
	///
	private: System::Void AvionNvl1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::W) {
			ctrlAvion->input(Direcciones::Arriba);
		}
		else if (e->KeyCode == Keys::A) {
			ctrlAvion->input(Direcciones::Izquierda);
		}
		else if (e->KeyCode == Keys::S) {
			ctrlAvion->input(Direcciones::Abajo);
		}
		else if (e->KeyCode == Keys::D) {
			ctrlAvion->input(Direcciones::Derecha);
		}
		else if (e->KeyCode == Keys::Space) {
			ctrlAvion->input(Direcciones::Salto);
		}
	}
	private: System::Void AvionNvl1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode != Keys::Space) {
			ctrlAvion->input(Direcciones::Ninguna);
		}
		if (e->KeyCode == Keys::Escape) {
			pausa = !pausa;
			
			if (!pausa) {
				this->timer1->Enabled = true;
				this->timer2->Enabled = true;
			}
		}
	}

	private: System::Void AvionNvl1_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {	//Control de spawns de drones
	if (r->Next(0, 100) < 20) {	//20% de probabilidad de spawn cada tick
		ctrlAvion->addDrone(this->ClientSize.Height-30);
	}
}
};
}