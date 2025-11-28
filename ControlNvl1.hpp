#pragma once

#include <vector>
#include "AvionHaluno.hpp"
#include "Proyectil.hpp"
#include "MovingEntity.hpp"


class MnJg_Avion {
private:
	HalunoAvion* avion;
	std::vector<Proyectil*> Balas;
	std::vector<Proyectil*> balasEnemy;
	std::vector<Moving_Entity*> drones;
	Moving_Entity* bombardino;

	int shootInterval;
	int shootsCount;

public:
	MnJg_Avion() {
		avion = new HalunoAvion();
		bombardino = new Moving_Entity(900, 100, Behavior::RndmUpDwn);
		bombardino->setSprite(Sprites::BombardiroN); bombardino->setTiling(9, 1); bombardino->setSpeed(5);
		bombardino->setEscala(1), bombardino->setColliderScale(1.75); bombardino->setDy(-1);

		shootInterval = 0;
	}
	~MnJg_Avion() {
		delete avion;
		delete bombardino;

		for (Proyectil* b : Balas) {
			delete b;
		}
	}

	void updateAll(BufferedGraphics^ buffer) {
		avion->move(buffer);
		bombardino->autoMove(buffer);

		for (int i = 0; i < Balas.size(); i++) {
			Proyectil* b = Balas[i];
			b->autoMove(buffer);

			if (!b->isActive()) {
				delete b;
				Balas.erase(Balas.begin() + i);
				i--;
			}
		}

		for (int i = 0; i < balasEnemy.size(); i++) {
			Proyectil* b = balasEnemy[i];
			b->autoMove(buffer);

			if (!b->isActive()) {
				delete b;
				balasEnemy.erase(balasEnemy.begin() + i);
				i--;
			}
		}

		shootInterval++;
		if (shootInterval >= 20) {
			shootInterval = 0;
			balasEnemy.push_back(DameBala(bombardino->getX(), bombardino->getOffsetedY(), Direcciones::Izquierda));
		}
	}

	void updateCollisions() {
		for (int i = 0; i < Balas.size(); i++) {
			if (Balas[i]->getRectangle().IntersectsWith(bombardino->getCollider())) {
				Balas[i]->setActive(false);
				bombardino->setSprite(Sprites::BombardiroR);

				delete Balas[i];
				Balas.erase(Balas.begin() + i);
			}
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		avion->draw(buffer, spriteDb);
		bombardino->draw(buffer, spriteDb);

		for (Proyectil* b : Balas) {
			b->draw(buffer, spriteDb);
		}
		for (Proyectil* b : balasEnemy) {
			b->draw(buffer, spriteDb);
		}

		bombardino->setSprite(Sprites::BombardiroN);
	}

	void input(Direcciones d) {
		if (d != Direcciones::Salto) {
			avion->setDir(d);
		}
		else if (d == Direcciones::Salto) {
			Balas.push_back(DameBala(avion->getOffsetedX(), avion->getOffsetedY()));
		}
	}

	Proyectil* DameBala(int X, int Y, Direcciones dir = Direcciones::Derecha) {
		Proyectil* tmp = new Proyectil(X, Y, true);
		if (dir == Direcciones::Derecha) {
			tmp->setTiling(4, 1);
			tmp->setIteraX(2);
			tmp->setSprite(Sprites::Bala1);
		}
		else { 
			tmp->setTiling(8, 1);
			tmp->setSprite(Sprites::Bala2);
			tmp->setAnimated(false);
			tmp->setIteraX(4);
		}
		tmp->setDir(dir);
		tmp->setEscala(0.5f);
		//tmp->setShowHitbox(false);
		return tmp;
	}
};