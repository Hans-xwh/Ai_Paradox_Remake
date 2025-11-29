#pragma once
#include "Controladora_2do.h"	//Aqui se importa "Sprite_DB.h"
#include "Sprite_DB.hpp"
#include "SegundoForm.h"
#include "Dialogo.hpp"

namespace AiParadoxRemake {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		//Todo esto es public, consideren hacerlas private
	private:
		//No hay necesidad de crear y borrar el buffer en cada frame
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		
		Sprite_DB^ spriteDB;
		Controladora2do* controladora;
		Random^ random;
		Bitmap^ fondo;
		//Bitmap^ sprite;
		//Borrar
		//Bitmap^ spriteRobot;
		//Bitmap^ spriteRoca;
		//Bitmap^ spriteReymundo;
		Dialogo* dialogo;		//debug
		
		bool SoundCamino = false;
		bool SoundWaterYRocaActive = false;
		int contadorTiempo;
		int tiempoSiguienteRobot;
		int tiempoSiguienteRoca;
		int tiempo;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
		
	public:	//Seguros que tienen que ser public?

		// AUDIOS DEL SEGUNDO NIVEL

		SoundPlayer^ nivelTwoSound = gcnew SoundPlayer("Audio/SoundNivel2.wav");
		SoundPlayer^ caminando = gcnew SoundPlayer("Audio/SoundCaminando.wav");
		SoundPlayer^ aguita = gcnew SoundPlayer("Audio/SoundWater.wav");
		SoundPlayer^ roquita = gcnew SoundPlayer("Audio/SoundRoca.wav");
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label3;
	public:


	private: System::Windows::Forms::Timer^ timer2;
	public:

		//

		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			spriteDB = gcnew Sprite_DB(2);
			random = gcnew Random();
			controladora = new Controladora2do();
			fondo = gcnew Bitmap("Imagenes/fondoSegundoNivel.png");
			//sprite = gcnew Bitmap("Imagenes/ProtagonistaHombre.png");
			//spriteRoca = gcnew Bitmap("Imagenes/piedresinha.png");
			//spriteRobot = gcnew Bitmap("Imagenes/espirituAgua.png");
			//spriteReymundo = gcnew Bitmap("Imagenes/Reymundo.png");
			dialogo = new Dialogo("Bayonneta es el mejor juego");		// Debug
			dialogo->setHeight(100);


			contadorTiempo = 0;
			tiempoSiguienteRobot = random->Next(1000, 5000);
			tiempoSiguienteRoca = random->Next(1000, 5000);
	

			tiempo = 0;
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

			delete controladora;
			delete fondo;
			delete spriteDB;
			delete dialogo;
			delete random;
			delete buffer, space, g;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(174, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Faltan:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(278, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(100, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(346, 29);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 26);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Tiempo:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(459, 32);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(55, 19);
			this->label5->TabIndex = 5;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label6->Location = System::Drawing::Point(613, 27);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 26);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Vidas:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Location = System::Drawing::Point(701, 34);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(55, 19);
			this->label7->TabIndex = 7;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(808, 400);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(170, 16);
			this->label8->TabIndex = 8;
			this->label8->Text = L"PARA HABLAR CONMIGO!";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(825, 384);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(129, 16);
			this->label9->TabIndex = 9;
			this->label9->Text = L"PASA ESTE NIVEL..";
			this->label9->Click += gcnew System::EventHandler(this, &MainForm::label9_Click);
			// 
			// timer2
			// 
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MainForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MainForm::timer3_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(546, 11);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(50, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 517);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(300, 19);
			this->label3->TabIndex = 11;
			this->label3->Text = L"RECOLECTA 10 ESPIRITUS DE AGUA";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(989, 545);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load_1);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Graphics^ g = this->CreateGraphics();
		//BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		//BufferedGraphics^ buffer = space->Allocate(g, this->ClientRectangle);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(fondo, 0, 0, ancho, alto);
		//controladora->moverPersonajeControladora(buffer);
		//controladora->moverRobotControladora(buffer);
		//controladora->moverRocaControladora(buffer);
		//controladora->aparecerReymundoControladora(buffer);
		controladora->updateAll(buffer);
		controladora->drawAll(buffer, spriteDB);


		controladora->colision(buffer);

		// part sound
		if (controladora->getSoundWater() && !SoundWaterYRocaActive) {
			SoundWaterYRocaActive = true;
			caminando->Stop();
			aguita->Play();
			SoundCamino = false;
			controladora->resetSoundWater();
			timer2->Start();
		}

		if (controladora->getSoundRoca() && !SoundWaterYRocaActive) {
			SoundWaterYRocaActive = true;
			caminando->Stop();
			roquita->Play();
			SoundCamino = false;
			controladora->resetSoundRoca();
			timer2->Start();
		}
		//

		tiempo++;

		label2->Text = Convert::ToString(controladora->getPersonaje()->getAgua());
		label5->Text = Convert::ToString(tiempo / 6);
		label7->Text = Convert::ToString(controladora->getPersonaje()->getVidas());


		///
		if (tiempo >= 1200) {
			timer1->Enabled = false;
			MessageBox::Show("NO PUDISTE AGARRARLO A TIEMPO!");
			this->Close();
		}
		if (controladora->getPersonaje()->getAgua() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("SI PUDISTE!!!");
			this->Hide();

			//conexion para la segunda parte del segundo nivel

			SegundoForm^ segundoForm = gcnew SegundoForm();
			segundoForm->ShowDialog();

			this->Close();
		}
		///

		///
		if (controladora->getPersonaje()->getVidas() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE TODAS TUS VIDAS!!");
			this -> Close();
		}
		///

		///
		contadorTiempo += timer1->Interval;
		if (contadorTiempo >= tiempoSiguienteRobot) {
			int ancho = this->ClientSize.Width;
			int alto = this->ClientSize.Height;
			int x = rand() % ancho;
			int y = rand() % alto;
			int x1 = 40;
			int y2 = 20;

			controladora->agregarRobotPosicion(x, y);
			controladora->agregarRocaPosicion(x1, y2);
			contadorTiempo = 0;
			tiempoSiguienteRobot = random->Next(1000, 5000);
			tiempoSiguienteRoca = random->Next(1000, 5000);
		}

		//dialogo->dibujar(buffer->Graphics);

		buffer->Render(g);
	}

	private: System::Void MainForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controladora->getPersonaje()->direccion = Direcciones::Ninguna;
	
		if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Right || e->KeyCode == Keys::Up || e->KeyCode == Keys::Down) {
			if (!SoundWaterYRocaActive) {
				caminando->Stop();
				SoundCamino = false;
			}
	    }
	
	}
	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
		if (!SoundCamino && !SoundWaterYRocaActive) {
			caminando->PlayLooping();
			SoundCamino = true;
		}
		
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
		case Keys::Space:
			controladora->getPersonaje()->direccion = Direcciones::Salto;
		}
	}


	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void MainForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
    }
   private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	   SoundWaterYRocaActive = false;
	   timer2->Stop();

    }
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	nivelTwoSound->Stop();
	caminando->Stop();
	aguita->Stop();
	roquita->Stop();
}
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
