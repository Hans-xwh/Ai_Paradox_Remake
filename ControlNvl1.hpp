#pragma once

#include <vector>
#include "AvionHaluno.hpp"
#include "Proyectil.hpp"


class MnJg_Avion {
private:
	HalunoAvion* avion;
	std::vector<Proyectil*> Balas;

public:
	MnJg_Avion() {
		avion = new HalunoAvion();
	}
	~MnJg_Avion() {
		delete avion;

		for (Proyectil* b : Balas) {
			delete b;
		}

	}

	void updateAll(BufferedGraphics^ buffer) {
		avion->move(buffer);

		for (int i = 0; i < Balas.size(); i++) {
			Proyectil* b = Balas[i];
			b->autoMove(buffer);

			if (!b->isActive()) {
				delete b;
				Balas.erase(Balas.begin() + i);
				i--;
			}
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		avion->draw(buffer, spriteDb);

		for (Proyectil* b : Balas) {
			b->draw(buffer, spriteDb);
		}
	}

	void input(Direcciones d) {
		if (d != Direcciones::Salto) {
			avion->setDir(d);
		}
		else if (d == Direcciones::Salto) {
			Balas.push_back(DameBala(avion->getOffsetedX(), avion->getOffsetedY()));
		}
	}

	Proyectil* DameBala(int X, int Y) {
		Proyectil* tmp = new Proyectil(X, Y, false);
		tmp->setTiling(8, 1);
		tmp->setIteraX(2);
		tmp->setSprite(Sprites::Bala1);
		tmp->setDir(Direcciones::Derecha);
		tmp->setEscala(0.25f);
		return tmp;
	}
};