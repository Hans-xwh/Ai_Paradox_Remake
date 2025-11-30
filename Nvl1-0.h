#pragma once
#include "Control1_0.hpp"

namespace AiParadoxRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Nvl10
	/// </summary>
	public ref class Nvl10 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphicsContext^ mybuffer;
		BufferedGraphics^ bCanvas;
		Random^ r;
		MnJg_Robots* ctrlRobots;
	private: System::Windows::Forms::Timer^ RbtSpawn;
	private: System::Windows::Forms::Timer^ ChipSpawn;
		   Sprite_DB^ sprite_db;
	public:
		Nvl10(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			mybuffer = BufferedGraphicsManager::Current;
			bCanvas = mybuffer->Allocate(g, this->ClientRectangle);

			r = gcnew Random();
			sprite_db = gcnew Sprite_DB(10);
			ctrlRobots = new MnJg_Robots();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Nvl10()
		{
			if (components)
			{
				delete components;
			}
			delete mybuffer;
			delete bCanvas;
			delete g;
			delete r;
			delete sprite_db;
			delete ctrlRobots;
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
			this->RbtSpawn = (gcnew System::Windows::Forms::Timer(this->components));
			this->ChipSpawn = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nvl10::timer1_Tick);
			// 
			// Nvl10
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1127, 566);
			this->Name = L"Nvl10";
			this->Text = L"Nvl10";
			this->Load += gcnew System::EventHandler(this, &Nvl10::Nvl10_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nvl10::Nvl10_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Nvl10::Nvl10_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Nvl10_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bCanvas->Graphics->Clear(Color::White);

		ctrlRobots->updateAll(bCanvas);
		ctrlRobots->drawAll(bCanvas, sprite_db);

		bCanvas->Render(g);
	}
	private: System::Void Nvl10_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			ctrlRobots->input(Direcciones::Izquierda);
			break;
		case Keys::D:
			ctrlRobots->input(Direcciones::Derecha);
			break;
		case Keys::W:
			ctrlRobots->input(Direcciones::Arriba);
			break;
		case Keys::S:
			ctrlRobots->input(Direcciones::Abajo);
			break;
		case Keys::Space:
			ctrlRobots->input(Direcciones::Salto);
		}
	}
	private: System::Void Nvl10_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		ctrlRobots->input(Direcciones::Ninguna);
	}
};
}
