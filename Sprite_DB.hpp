#pragma once

namespace nmspc_SpriteDB {	//uso de namespce por que si xd
	using namespace System;
	using namespace System::Drawing;

	enum Sprites //Lista de sprites disponibles, usar esto para pedir sprites en los hijos de entidad
	{
		//Todo
		Error,
		Haluno,

		//Nivel 1
		AvionH,

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
		Bitmap^ spr_avion;

		//Segundo nivel
		Bitmap^ spr_agua;
		Bitmap^ spr_roca;
		Bitmap^ spr_reymundo;

		Bitmap^ spr_arbol;

	public:
		Sprite_DB(int lvl){	//Inicializa los sprites dependiendo del nivel
			spr_error = gcnew Bitmap("Imagenes/debugempty.png");
			spr_haluno = gcnew Bitmap("Imagenes/ProtagonistaHombre.png");	//haluno siempre esta cargado

			switch (lvl){
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

		~Sprite_DB(){ /// IMPORTANTISIMO ACTUALIZAR DESTRUCTOR AL AÑADIR UN SPRITE///
			if (spr_error) { delete spr_error; }
			if (spr_haluno) { delete spr_haluno; }
			if (spr_agua) { delete spr_agua; }
			if (spr_roca) { delete spr_roca; }
			if (spr_reymundo) { delete spr_reymundo; }
			if (spr_arbol) { delete spr_arbol; }
		}

		

		//Inicializan los sprites dependendo de cada nivel.
		// LLamar esto desde el formulario de cada nivel, por q creo q la controladora no puede contener un ref class
		void Init_Nivel1() {
			spr_avion = gcnew Bitmap("Imagenes/AVIONHALUNO.png");
		}
		void Unld_Nivel1() {
			delete spr_avion;
		}


		void Init_Nivel2() {
			spr_roca = gcnew Bitmap("Imagenes/piedresinha.png");
			spr_agua = gcnew Bitmap("Imagenes/espirituAgua.png");
			spr_reymundo = gcnew Bitmap("Imagenes/Reymundo.png");
			spr_arbol = gcnew Bitmap("Imagenes/ArbolSprite.png");
		}
		void Unld_Nivel2() {
			delete spr_roca;
			delete spr_agua;
			delete spr_reymundo;
			delete spr_arbol;
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
			case AvionH:
				return spr_avion;
			case Error:
				return spr_error;
			default:
				return spr_error;
			}
		}
	};
}