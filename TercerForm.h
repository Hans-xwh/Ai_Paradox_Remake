#pragma once
#include "ControlNvl3.h"
#include "Entidad.h"
#include "Sprite_DB.hpp"
#include "FinalForm.h"
namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de TercerForm
	/// </summary>
	public ref class TercerForm : public System::Windows::Forms::Form
	{

	private:
		Graphics^ g;
		BufferedGraphicsContext^ mybuffer;
		BufferedGraphics^ bCanvas;
		MnJg_Nivel3* juegoNivel3;
		Sprite_DB^ sprite_db;
		Bitmap^ fondo;
	private: System::Windows::Forms::Label^ label1;

		   bool pausa;

	public:
		TercerForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			g = this->CreateGraphics();
			mybuffer = BufferedGraphicsManager::Current;
			bCanvas = mybuffer->Allocate(g, this->ClientRectangle);
			sprite_db = gcnew Sprite_DB(3);

			fondo = gcnew Bitmap("Imagenes/fondoNivel3.jpg");
			juegoNivel3 = new MnJg_Nivel3();
			juegoNivel3->addBalanzaDoble(bCanvas);

			pausa = false;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~TercerForm()
		{
			if (components)
			{
				delete components;
				delete juegoNivel3;
				delete fondo;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TercerForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &TercerForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(241, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(735, 64);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->Click += gcnew System::EventHandler(this, &TercerForm::label1_Click);
			// 
			// TercerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1173, 461);
			this->Controls->Add(this->label1);
			this->Name = L"TercerForm";
			this->Text = L"TercerForm";
			this->Load += gcnew System::EventHandler(this, &TercerForm::TercerForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TercerForm::KeyDown1);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TercerForm::KeyUp1);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TercerForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bCanvas->Graphics->Clear(Color::White);
		int ancho = bCanvas->Graphics->VisibleClipBounds.Width;
		int alto = bCanvas->Graphics->VisibleClipBounds.Height;
		bCanvas->Graphics->DrawImage(fondo, 0, 0, ancho, alto);

		juegoNivel3->updateAll(bCanvas);
		juegoNivel3->updateCollisions();
		juegoNivel3->drawAll(bCanvas, sprite_db);

		if (juegoNivel3->getVictoria()) {
			this->Hide();
			this->timer1->Enabled = false;
			FinalForm^ final = gcnew FinalForm();
			final->ShowDialog();
			delete final;

			this->Close();
		}
		if (pausa) {
			timer1->Enabled = false;
			bCanvas->Graphics->FillRectangle(Brushes::White,
				this->ClientSize.Width / 2 - 100,
				this->ClientSize.Height / 2 - 50,
				250, 80);
			bCanvas->Graphics->DrawString("PAUSA",
				gcnew Drawing::Font("Arial", 48, Drawing::FontStyle::Bold),
				Brushes::Black,
				this->ClientSize.Width / 2 - 100,
				this->ClientSize.Height / 2 - 50);
		}

		bCanvas->Render(g);
	}

	private: System::Void KeyDown1(System::Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::A) {
			juegoNivel3->input(Direcciones::Izquierda);
		}
		else if (e->KeyCode == Keys::D) {
			juegoNivel3->input(Direcciones::Derecha);
		}
		else if (e->KeyCode == Keys::Space) {
			juegoNivel3->input(Direcciones::Salto);
		}
	}
private: System::Void KeyUp1(System::Object^ sender, KeyEventArgs^ e) {
	if (e->KeyCode == Keys::A || e->KeyCode == Keys::D) {
		juegoNivel3->input(Direcciones::Ninguna);
	}
	if (e->KeyCode == Keys::Escape) {
		pausa = !pausa;

		if (!pausa) {
			this->timer1->Enabled = true;
		}
	}
}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}