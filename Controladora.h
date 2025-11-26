#pragma once
#include "Sprite_DB.h"
#include "Personaje.h"
#include "Agua.h"
#include <vector>
#include <time.h>
#include "Rocas.h"
#include "Reymundo.h"
//#include "arbol.h"
//holad
using namespace std;		//CUIDADO CON IMPORTAR STD COMPLETO
using namespace System::Drawing;	//creo que ya se importa pero mejor prevenir que lamentar xd
using nmspc_SpriteDB::Sprite_DB;	//clase Sprite_DB
using nmspc_SpriteDB::Sprites;	//enum Sprites

class Controladora
{

private:
	vector<Agua*>awita;
	Personaje* personaji;
	Entidad* reymundo;
	vector<Rocas*>roquita;
	vector<Entidad*> arbolitos;

	// sonidos
	bool SoundWater = false;
	bool SoundRoca = false;

public:
	Controladora() {
		srand(time(NULL));
		personaji = new Personaje(rand() % 250, rand() % 250);
		reymundo = new Entidad(630, 325); 
		reymundo->setTiling(13, 54); reymundo->setIteraY(2);

	}

	~Controladora() {}

	void moverPersonajeControladora(BufferedGraphics^ buffer) {
		personaji->moverPersonaje(buffer);
	}

	/*void aparecerReymundoControladora(BufferedGraphics^ buffer) {
		reymundo->dibujar(buffer);
	}*/

	Personaje* getPersonaje() {
		return personaji;
	}

	void agregarRobotPosicion(int x, int y) {
		awita.push_back(new Agua(x, y));
	}

	void agregarRocaPosicion(int x, int y) {
		roquita.push_back(new Rocas(x, y));
	}

	void agregarArbolPosicion(int x, int y) {
		arbolitos.push_back(new Entidad(x, y));
	}
	/*
	void moverRobotControladora(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (size_t i = 0; i < awita.size(); i++) {
			awita[i]->moverAgua(buffer, bmp);
		}
	}
	void moverRocaControladora(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (size_t i = 0; i < roquita.size(); i++)
		{
			roquita[i]->moverRocas(buffer, bmp);
		}
	}

	void dibujarArbolesControladora(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (size_t i = 0; i < arbolitos.size(); i++) {
			arbolitos[i]->dibujar(buffer, bmp);
		}
	}
	*/

	void updateAll(BufferedGraphics^ buffer) {

		//reymundo no se mueve
		personaji->moverPersonaje(buffer);

		for (Agua* a : awita) {
			a->moverAgua(buffer);
		}

		for (Rocas* r : roquita) {
			r->moverRocas(buffer);
		}
	}

	void drawAll(BufferedGraphics^buffer, Sprite_DB^ spriteDb) {
		personaji->draw(buffer, spriteDb);
		reymundo->draw(buffer, spriteDb);

		for (Agua* a : awita) {
			a->draw(buffer, spriteDb);
		}

		for (Rocas* r : roquita) {
			r->draw(buffer, spriteDb);
		}
	}

	void colision(BufferedGraphics^ buffer) {
		for (size_t i = 0; i < awita.size(); i++) {
			if (awita[i]->getRectangle().IntersectsWith(personaji->getRectangle())) {
				
				personaji->setAgua(-1);
				awita[i]->setVisible(false);
				SoundWater = true;
				
			}
		}

		for (size_t i = 0; i < awita.size(); i++) {
			if (!awita[i]->getVisible()) {
				delete awita[i];
				awita.erase(awita.begin() + i);

			}
		}

		//////

		for (size_t i = 0; i < roquita.size(); i++) {
			if (roquita[i]->getRectangle().IntersectsWith(personaji->getRectangle())) {
				personaji->setVidas(-1);
				roquita[i]->setVisible(false);
				SoundRoca = true;
			}
		}

		for (size_t i = 0; i < roquita.size(); i++) {
			if (!roquita[i]->getVisible()) {
				delete roquita[i];
				roquita.erase(roquita.begin() + i);

			}
		}
	}

	bool getSoundWater() {
		return SoundWater;
	}
	bool getSoundRoca() {
		return SoundRoca;
	}
	void resetSoundWater() {
	    SoundWater = false;
	}
	void resetSoundRoca() { 
		SoundRoca = false; 
	}
	void resetSounds() {
		SoundRoca = SoundWater = false;
	}
};

