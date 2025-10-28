#pragma once
#include "Controladora.h"
#include "SegundoForm.h"
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
		Controladora* controladora;
		Bitmap^ fondo;
		Bitmap^ sprite;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
		   Bitmap^ spriteRobot;
		   int contadorTiempo;
		   int tiempoSiguienteRobot;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   Random^ random;
		  
		
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			random = gcnew Random();
			contadorTiempo = 0;
			tiempoSiguienteRobot = random->Next(1000, 5000);
		
			controladora = new Controladora();
			fondo = gcnew Bitmap("Imagenes/fondo.png");
			sprite = gcnew Bitmap("Imagenes/ProtagonistaHombre.png");
		    spriteRobot = gcnew Bitmap("Imagenes/Agua.png");
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(96, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Faltan:";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(167, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 418);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(224, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"RECOLECTA 10 DE AGUA Y GANA!";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(925, 519);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
		controladora->moverPersonajeControladora(buffer, sprite);
		controladora->moverRobotControladora(buffer, spriteRobot);

		controladora->colision(buffer);

		label2->Text = Convert::ToString(controladora->getPersonaje()->getVidas());

		contadorTiempo += timer1->Interval;
		if (contadorTiempo >= tiempoSiguienteRobot) {
			int ancho = this->ClientSize.Width;
			int alto = this->ClientSize.Height;
			int x = rand() % ancho;
			int y = rand() % alto;

			controladora->agregarRobotPosicion(x, y);
			contadorTiempo = 0;
			tiempoSiguienteRobot = random->Next(1000, 5000);
		}
		if (controladora->getPersonaje()->getVidas() == 0) {
			SegundoForm^ miForm = gcnew SegundoForm();
			miForm->Show();
			//XD

		}

		buffer->Render(g);
		delete buffer, space, g;


	
	}

	private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controladora->getPersonaje()->direccion = Direcciones::Ninguna;
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left:
			controladora->getPersonaje()->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			controladora->getPersonaje()->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			controladora->getPersonaje()->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			controladora->getPersonaje()->direccion = Direcciones::Abajo;
			break;
		}
	

	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
