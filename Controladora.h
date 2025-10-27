#pragma once
#include "Personaje.h"
#include "Robot.h"
#include <vector>
#include <time.h>
using namespace std;

class Controladora
{

private:
	vector<Robot*>robotin;
	Personaje* personaji;


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

	void agregarRobots(int cant) {
		Robot* robotines;
		for (size_t i = 0; i < cant; i++) {
			robotines = new Robot(rand() % 250, rand() % 250);
			robotin.push_back(robotines);
		}
	}
	void moverRobotControladora(BufferedGraphics ^ buffer, Bitmap ^ bmp) {
			for (size_t i = 0; i < robotin.size(); i++) {
				robotin[i]->moverRobot(buffer, bmp);
			}
    }

	void colision(BufferedGraphics^ buffer) {
		for (size_t i = 0; i < robotin.size(); i++) {
			if (robotin[i]->getRectangle().IntersectsWith(personaji->getRectangle())) {
				personaji->setVidas(-1);
				robotin[i]->setVisibilidad(false);
			}
		}

		for (size_t i = 0; i < robotin.size(); i++) {
			if (!robotin[i]->getVisibilidad()) {
				robotin.erase(robotin.begin() + i);

			}
		}
	}
};

