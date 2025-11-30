#pragma once

namespace nmspc_SpriteDB {	//uso de namespce por que si xd
	using namespace System;
	using namespace System::Drawing;

	enum Sprites //Lista de sprites disponibles, usar esto para pedir sprites en los hijos de entidad
	{
		//Todo
		Error,
		Haluno,
		Explosion,

		//Nivel 1_0
		Eprom,
		Robot,

		//Nivel 1_1
		Bala1,
		Bala2,
		AvionH,
		BombardiroN,
		BombardiroR,
		RobotVolador,

		//Nivel 2
		EspirituAgua,
		GolemRoca,
		Reymundo,
		Arbol1,
		ArbolSabio,

		//Nivel 3
		moneditas,
		Balanza,
		
	};

	public ref class Sprite_DB : public System::Windows::Forms::Form
	{
	private:
		//Para todo el juego
		Bitmap^ spr_haluno;
		Bitmap^ spr_error; //Sprite por defecto en caso de error, sacado de source xd
		Bitmap^ spr_explosion;

		//Primer nivel - 0
		Bitmap^ spr_robot;
		Bitmap^ spr_eprom;

		//Primer nivel - 1
		Bitmap^ spr_avion;
		Bitmap^ spr_bala1;
		Bitmap^ spr_bala2;
		Bitmap^ spr_bombardiroN;
		Bitmap^ spr_bombardiroR;
		Bitmap^ spr_robotVolador;

		//Segundo nivel
		Bitmap^ spr_agua;
		Bitmap^ spr_roca;
		Bitmap^ spr_reymundo;
		Bitmap^ spr_arbolsabio;

		Bitmap^ spr_arbol;

		//Tercer nivel
		Bitmap^ spr_moneditas;
		Bitmap^ spr_balanza;

	public:
		Sprite_DB(int lvl){	//Inicializa los sprites dependiendo del nivel
			spr_error = gcnew Bitmap("Imagenes/debugempty.png");
			spr_haluno = gcnew Bitmap("Imagenes/haluno.png");	//haluno siempre esta cargado

			switch (lvl){
			case 10:
				Init_Nivel1_0();
			case 11:
				Init_Nivel1_1();
				break;
			case 2:
				Init_Nivel2();
				break;
			case 3:
				Init_Nivel3();
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
			if (spr_avion) { delete spr_avion; }
			if (spr_bala1) { delete spr_bala1; }
			if (spr_bala2) { delete spr_bala2; }
			if (spr_bombardiroN) { delete spr_bombardiroN; }
			if (spr_bombardiroR) { delete spr_bombardiroR; }
			if (spr_robotVolador) { delete spr_robotVolador; }
			if (spr_explosion) { delete spr_explosion; }
			if (spr_moneditas) { delete spr_moneditas;}
			if (spr_balanza) { delete spr_balanza; }
			if (spr_arbolsabio) { delete spr_arbolsabio; }
			if (spr_robot) { delete spr_robot; }
			if (spr_eprom) { delete spr_eprom; }
		}

		

		//Inicializan los sprites dependendo de cada nivel.
		// LLamar esto desde el formulario de cada nivel, por q creo q la controladora no puede contener un ref class
		void Init_Nivel1_0() {
			spr_eprom = gcnew Bitmap("Imagenes/nvl_1_0/eprom.png");
			spr_robot = gcnew Bitmap("Imagenes/nvl_1_0/robot.png");
		}
		void Init_Nivel1_1() {
			spr_avion = gcnew Bitmap("Imagenes/AVIONHALUNO.png");
			spr_bala1 = gcnew Bitmap("Imagenes/disparo2azul.png");
			spr_bala2 = gcnew Bitmap("Imagenes/disparoRojopng.png");
			spr_bombardiroN = gcnew Bitmap("Imagenes/bombardiroN.png");
			spr_bombardiroR = gcnew Bitmap("Imagenes/bombardiroR.png");
			spr_robotVolador = gcnew Bitmap("Imagenes/robotVolador.png");
			spr_explosion = gcnew Bitmap("Imagenes/explosion.png");
		}
		void Unld_Nivel1_0() {
			delete spr_eprom;
			delete spr_robot;
		}
		void Unld_Nivel1_1() {
			delete spr_avion;
			delete spr_bala1;
			delete spr_bala2;
			delete spr_bombardiroN;
			delete spr_bombardiroR;
			delete spr_robotVolador;
			delete spr_explosion;
		}


		void Init_Nivel2() {

			spr_roca = gcnew Bitmap("Imagenes/piedresinha.png");
			spr_agua = gcnew Bitmap("Imagenes/espirituAgua.png");
			spr_reymundo = gcnew Bitmap("Imagenes/Reymundo.png");
			spr_arbol = gcnew Bitmap("Imagenes/ArbolSprite.png");
			spr_arbolsabio = gcnew Bitmap("Imagenes/ArbolSabio.png");	
	}
		void Unld_Nivel2() {
			delete spr_roca;
			delete spr_agua;
			delete spr_reymundo;
			delete spr_arbol;
			delete spr_arbolsabio;
		}

		void Init_Nivel3() {
			spr_avion = gcnew Bitmap("Imagenes/AVIONHALUNO.png");
			spr_moneditas = gcnew Bitmap("Imagenes/moneditas.png");
			spr_balanza = gcnew Bitmap("Imagenes/Balanza.png");
		}

		void Unld_Nivel3() {
			delete spr_avion;
			delete spr_moneditas;
			delete spr_balanza;
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
			case Bala1:
				return spr_bala1;
			case Bala2:
				return spr_bala2;
			case BombardiroN:
				return spr_bombardiroN;
			case BombardiroR:
				return spr_bombardiroR;
			case RobotVolador:
				return spr_robotVolador;
			case Explosion:
				return spr_explosion;
			case Balanza:
				return spr_balanza;
			case moneditas:
				return spr_moneditas;
			case ArbolSabio:
				return spr_arbolsabio;
			case Robot:
				return spr_robot;
			case Eprom:
				return spr_eprom;

			case Error:
				return spr_error;
			default:
				return spr_error;
			}
		}
	};
}