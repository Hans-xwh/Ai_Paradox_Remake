#pragma once
#include "Controladora.h"
#include "Entidad.h"
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
		Entidad* arbol;
		Bitmap^ spriteArbol;
	public:
		SegundoForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			fondo2 = gcnew Bitmap("Imagenes/fondoSegundoSegundo.png");
			spriteArbol = gcnew Bitmap("Imagenes/ArbolSprite.png");

			arbol = new Entidad(0, 0);
			arbol->setTiling(5, 1);
			arbol->setEscala(0.3);
			arbol->setVisible(true);
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &SegundoForm::timer1_Tick);
			// 
			// SegundoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 545);
			this->Name = L"SegundoForm";
			this->Text = L"SegundoForm";
			this->Load += gcnew System::EventHandler(this, &SegundoForm::SegundoForm_Load);
			this->ResumeLayout(false);
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &SegundoForm::OnKeyDown);

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
		buffer->Graphics->DrawImage(fondo2, 0, 0, ancho, alto);

		int anchoFrame = spriteArbol->Width / 5;
		int altoFrame = spriteArbol->Height;
		float scale = arbol->getEscala();

		arbol->setX(ancho / 2);
		arbol->setY(alto / 2);

		arbol->dibujar(buffer, spriteArbol);


		buffer->Render(g);
		delete buffer, space, g;
	}
	private: System::Void OnKeyDown(System::Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::F) {
			if (arbol->getIteraX() < 4)
				arbol->setIteraX(arbol->getIteraX() + 1);
		}
	}
	};
}
