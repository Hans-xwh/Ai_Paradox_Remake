#pragma once
#include "Personaje.h"
#include "Entidad.h"
#include "Robot.h"

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		Personaje* personaji;
		Robot* robotin;
		Bitmap^ fondo;
		Bitmap^ sprite;
		Bitmap^ spriteRobot;
		
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		
			personaji = new Personaje(5, 5);
			//robotin = new Robot(10, 10);
			fondo = gcnew Bitmap("Imagenes/fondo.png");
			sprite = gcnew Bitmap("Imagenes/ProtagonistaHombre.png");
			//spriteRobot = gcnew Bitmap("Imagenes/robot.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// textBox1
			// 
			//this->textBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			//this->textBox1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				//static_cast<System::Byte>(0)));
			//this->textBox1->ForeColor = System::Drawing::Color::Navy;
			//this->textBox1->Location = System::Drawing::Point(542, 210);
			//this->textBox1->Name = L"textBox1";
			//this->textBox1->Size = System::Drawing::Size(145, 21);
			//this->textBox1->TabIndex = 1;
			//this->textBox1->Text = L"AI PARADOX";
			//this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(925, 519);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = space->Allocate(g, this->ClientRectangle);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(fondo, 0, 0, ancho, alto);
		personaji->moverPersonaje(buffer, sprite);

		robotin->moverRobot(buffer, spriteRobot);
		buffer->Render(g);
		delete buffer, space, g;


	
	}

	private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		personaji->direccion = Direcciones::Ninguna;
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left:
			personaji->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			personaji->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			personaji->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			personaji->direccion = Direcciones::Abajo;
			break;
		}

	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
