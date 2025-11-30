#pragma once
#include "Controladora_2do.h"
#include "Entidad.h"
#include "Reymundo.h"
#include "Sprite_DB.hpp"
#include "TercerForm.h"
namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de SegundoForm
	/// </summary>
	public ref class SegundoForm : public System::Windows::Forms::Form
	{
		Bitmap^ fondo2;
		Sprite_DB^ sprite_db;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
		   Controladora2do* controladora;

		//Bitmap^ spriteArbol; //Borrar
	public:
		SegundoForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			controladora = new Controladora2do();

			fondo2 = gcnew Bitmap("Imagenes/bosquesinho.png");
			sprite_db = gcnew Sprite_DB(2);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~SegundoForm()
		{
			if (components)
			{
				delete components;

			}

			delete fondo2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SegundoForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &SegundoForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(641, 180);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(306, 67);
			this->button1->TabIndex = 0;
			this->button1->Text = L"A) “¿El software X es bonito y fácil de usar\?”\n";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(641, 279);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(306, 67);
			this->button2->TabIndex = 1;
			this->button2->Text = L"B) “¿Cuántos estudiantes participaron y cómo se seleccionaron\?”";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SegundoForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(641, 377);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(306, 67);
			this->button3->TabIndex = 2;
			this->button3->Text = L"C) “¿A cuántos estudiantes les gustó el software\?”";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(554, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(475, 48);
			this->label1->TabIndex = 3;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(477, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Responde correctamente la pregunta critica para obtener las semillas magicas";
			// 
			// SegundoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1159, 545);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"SegundoForm";
			this->Text = L"SegundoForm";
			this->Load += gcnew System::EventHandler(this, &SegundoForm::SegundoForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SegundoForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = space->Allocate(g, this->ClientRectangle);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		// Dibujar fondo
		buffer->Graphics->DrawImage(fondo2, 0, 0, ancho, alto);

		controladora->updateArbol(buffer);
		controladora->drawArbol(buffer, sprite_db);

		// Renderizar todo
		buffer->Render(g);

		delete buffer;
		delete space;
		delete g;
	}
	private: System::Void OnKeyDown(System::Object^ sender, KeyEventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Hide();
		this->timer1->Enabled = false;
		TercerForm^ tercer = gcnew TercerForm();
		tercer->ShowDialog();
		delete tercer;

		this->Close();

	}
};
}
