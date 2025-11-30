#pragma once
#include "Sprite_DB.hpp"
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

class Controladora2do
{

private:
	vector<Agua*> awita;
	Personaje* personaji;
	ArbolSabio* arbolsabio;
	Entidad* reymundo;
	vector<Rocas*>roquita;

	// sonidos
	bool SoundWater = false;
	bool SoundRoca = false;

public:
	Controladora2do() {
		srand(time(NULL));
		personaji = new Personaje(rand() % 250, rand() % 250);
		reymundo = new Entidad(630, 325); 
		arbolsabio = new ArbolSabio(0, 5);
		reymundo->setTiling(13, 54); reymundo->setIteraY(2);

	}

	~Controladora2do() {
		delete personaji;
		delete reymundo;
		for (Agua* awa : awita) {
			delete awa;
		}
		for (Rocas* roca : roquita) {
			delete roca;
		}

	}

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

		personaji->moverPersonaje(buffer);

		for (Agua* a : awita) {
			a->moverAgua(buffer);
		}

		for (Rocas* r : roquita) {
			r->moverRocas(buffer);
		}


	}

	void updateArbol(BufferedGraphics^ buffer) {
		arbolsabio->siguienteSprite();

		arbolsabio->siguienteSprite();

	}

	void drawAll(BufferedGraphics^buffer, Sprite_DB^ spriteDb) {
		personaji->draw(buffer, spriteDb);
		reymundo->draw(buffer, spriteDb);
		arbolsabio->draw(buffer, spriteDb);

		for (Agua* a : awita) {
			a->draw(buffer, spriteDb);
		}

		for (Rocas* r : roquita) {
			r->draw(buffer, spriteDb);
		}

	}

	void drawArbol(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		arbolsabio->draw(buffer, spriteDb);

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


	ArbolSabio* getArbol() {
		return arbolsabio;
	}
};

