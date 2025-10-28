#pragma once
#include "Personaje.h"
#include "Agua.h"
#include <vector>
#include <time.h>
#include "Rocas.h"
using namespace std;

class Controladora
{

private:
	vector<Agua*>awita;
	Personaje* personaji;
	vector<Rocas*>roquita;

public:
	Controladora() {
		srand(time(NULL));
		personaji = new Personaje(rand() % 250, rand() % 250);

	}

	~Controladora() { }
	void moverPersonajeControladora(BufferedGraphics^ buffer, Bitmap^ bmp) {
		personaji->moverPersonaje(buffer, bmp);
	}

	Personaje* getPersonaje() {
		return personaji;
	}

	void agregarRobotPosicion(int x, int y) {
		awita.push_back(new Agua(x, y));
	}

	void agregarRocaPosicion(int x, int y) {
		roquita.push_back(new Rocas(x, y));
	}
	void moverRobotControladora(BufferedGraphics ^ buffer, Bitmap ^ bmp) {
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
	void colision(BufferedGraphics^ buffer) {
		for (size_t i = 0; i < awita.size(); i++) {
			if (awita[i]->getRectangle().IntersectsWith(personaji->getRectangle())) {
				personaji->setAgua(-1);
				awita[i]->setVisibilidad(false);
			}
		}

		for (size_t i = 0; i < awita.size(); i++) {
			if (!awita[i]->getVisibilidad()) {
				awita.erase(awita.begin() + i);

			}
		}

		//////

		for (size_t i = 0; i < roquita.size(); i++) {
			if (roquita[i]->getRectangle().IntersectsWith(personaji->getRectangle())) {
				personaji->setVidas(-1);
				roquita[i]->setVisibilidad(false);
			}
		}

		for (size_t i = 0; i < roquita.size(); i++) {
			if (!roquita[i]->getVisibilidad()) {
				roquita.erase(roquita.begin() + i);

			}
		}

		//



	}
};

