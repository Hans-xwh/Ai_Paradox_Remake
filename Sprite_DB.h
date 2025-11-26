#pragma once

namespace nmspc_SpriteDB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sprite_DB
	/// </summary>
	 
	enum Sprites //Lista de sprites disponibles, usar esto para pedir sprites en los hijos de entidad
	{
		//Todo
		Error,
		Haluno,

		//Nivel 2
		EspirituAgua,
		GolemRoca,
		Reymundo,
		Arbol1,
	};
	
	public ref class Sprite_DB : public System::Windows::Forms::Form
	{
	private:
		//Para todo el juego
		Bitmap^ spr_haluno;
		Bitmap^ spr_error; //Sprite por defecto en caso de error, sacado de source xd


		//Primer nivel


		//Segundo nivel
		Bitmap^ spr_agua;
		Bitmap^ spr_roca;
		Bitmap^ spr_reymundo;

		Bitmap^ spr_arbol;

	public:
		Sprite_DB(int lvl)	//Inicializa los sprites dependiendo del nivel
		{
			InitializeComponent();

			spr_error = gcnew Bitmap("Imagenes/debugempty.png");
			
			spr_haluno = gcnew Bitmap("Imagenes/ProtagonistaHombre.png");	//haluno siempre esta cargado

			switch (lvl)
			{
			case 1:
				Init_Nivel1();
				break;
			case 2:
				Init_Nivel2();
				break;
			default:
				//No sean flojos inicialicen bien 
				break;
			}
			
			//
			//TODO: Add the constructor code here
			//
		}

		/// Revisar destructor abajo ///

		//Inicializan los sprites dependendo de cada nivel.
		// LLamar esto desde el formulario de cada nivel, por q creo q la controladora no puede contener un form
		void Init_Nivel1() {

		}

		void Init_Nivel2() {
			spr_roca = gcnew Bitmap("Imagenes/piedresinha.png");
			spr_agua = gcnew Bitmap("Imagenes/espirituAgua.png");
			spr_reymundo = gcnew Bitmap("Imagenes/Reymundo.png");
			spr_arbol = gcnew Bitmap("Imagenes/ArbolSprite.png");
		}

		Bitmap^ getSprite(Sprites s) {
			switch (s)
			{
			case Haluno:
				return spr_haluno;
			case EspirituAgua:
				return spr_agua;
			case GolemRoca:
				return spr_roca;
			case Reymundo:
				return spr_reymundo;
			case Arbol1:
				return spr_arbol;
			case Error:
				return spr_error;
			default:
				return spr_error;
			}
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Sprite_DB()
		{
			if (components)
			{
				delete components;
			}

			if (spr_error) { delete spr_error; }
			if (spr_haluno) { delete spr_haluno; }
			if (spr_agua) { delete spr_agua; }
			if (spr_roca) { delete spr_roca; }
			if (spr_reymundo) { delete spr_reymundo; }
			if (spr_arbol) { delete spr_arbol; }
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(547, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"COMPILAME ESTA XD";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(165, 408);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(394, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"(Este formulario solo sirve como base de datos, no me lo invoquen en ningun lado)"
				L"";
			// 
			// Sprite_DB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(566, 430);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Sprite_DB";
			this->Text = L"Sprite_DB";
			this->Load += gcnew System::EventHandler(this, &Sprite_DB::Sprite_DB_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Sprite_DB_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
