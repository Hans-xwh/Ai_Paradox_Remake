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
	int shootCount;
	int vidaBombardino = 400;

public:
	MnJg_Avion() {
		avion = new HalunoAvion();
		bombardino = new Moving_Entity(900, 100, Behavior::RndmUpDwn);
		bombardino->setSprite(Sprites::BombardiroN); bombardino->setTiling(9, 1); bombardino->setSpeed(5);
		bombardino->setEscala(1), bombardino->setColliderScale(1.75); bombardino->setDy(-1);

		shootInterval = shootCount = 0;
	}
	~MnJg_Avion() {
		delete avion;
		delete bombardino;

		for (Proyectil* b : Balas) {
			delete b;
		}
		for (Proyectil* b : balasEnemy) {
			delete b;
		}
		for (Moving_Entity* d : drones) {
			delete d;
		}
	}

	void updateAll(BufferedGraphics^ buffer) {
		System::Random r;
		avion->move(buffer);
		bombardino->autoMove(buffer);

		//Balas amigas
		for (int i = 0; i < Balas.size(); i++) {
			Proyectil* b = Balas[i];
			b->autoMove(buffer);

			if (!b->isActive()) {
				delete b;
				Balas.erase(Balas.begin() + i);
				i--;
			}
		}

		//Balas enemigas
		for (int i = 0; i < balasEnemy.size(); i++) {
			Proyectil* b = balasEnemy[i];
			b->autoMove(buffer);

			if (!b->isActive()) {
				delete b;
				balasEnemy.erase(balasEnemy.begin() + i);
				i--;
			}
		}

		//Drones
		for (int i = 0; i < drones.size(); i++) {
			Moving_Entity* d = drones[i];
			d->autoMove(buffer);

			if (!d->isActive()) {
				delete d;
				drones.erase(drones.begin() + i);
				i--;
			}
		}

		//Disparo bombardino
		shootCount++;
		if (shootCount >= shootInterval) {
			shootInterval = r.Next(60, 120);
			shootCount = 0;
			balasEnemy.push_back(DameBala(bombardino->getX(), bombardino->getOffsetedY(), Direcciones::Izquierda));
		}
	}

	void updateCollisions() {
		for (int i = 0; i < Balas.size(); i++) {
			//Balas amigas -> Bombardino
			if (Balas[i]->getRectangle().IntersectsWith(bombardino->getCollider())) {
				Balas[i]->setActive(false);
				bombardino->setSprite(Sprites::BombardiroR);
				vidaBombardino--;
			}

			//Balas amigas -> Bombardino
			for (int j = 0; j < drones.size(); j++) {
				if (Balas[i]->getRectangle().IntersectsWith(drones[j]->getCollider())) {
					Balas[i]->setActive(false);
					drones[j]->setActive(false);
					delete drones[j];
					drones.erase(drones.begin() + j);
					break;
				}
			}

			if (Balas[i]->isActive() == false) {
				delete Balas[i];
				Balas.erase(Balas.begin() + i);
				i--;
			}
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		for (Moving_Entity* d : drones) {
			d->draw(buffer, spriteDb);
		}
		for (Proyectil* b : Balas) {		//Las balas deben ser lo ultimo en dibujarse
			b->draw(buffer, spriteDb);
		}
		for (Proyectil* b : balasEnemy) {
			b->draw(buffer, spriteDb);
		}

		avion->draw(buffer, spriteDb); avion->draw(buffer, spriteDb);
		bombardino->draw(buffer, spriteDb);

		bombardino->setSprite(Sprites::BombardiroN);

		//// Dibujado interface ////
		buffer->Graphics->FillRectangle(Brushes::SlateGray,	//Barra de vida bombardiro
			int(buffer->Graphics->VisibleClipBounds.Width / 2) - 400,
			25,
			800,
			30);
		buffer->Graphics->FillRectangle(Brushes::OrangeRed,	//Barra de vida bombardiro
			int(buffer->Graphics->VisibleClipBounds.Width / 2) - 400,
			25,
			vidaBombardino * 2,
			30);
		buffer->Graphics->DrawRectangle(Pens::Black,			//Marco barra de vida bombardino
			int(buffer->Graphics->VisibleClipBounds.Width / 2) - 400,
			25,
			800,
			30);	
		buffer->Graphics->DrawString("Bombardino Crocodilo: Protector de Sahur", 
			gcnew System::Drawing::Font("Arial", 18),
			Brushes::Black,
			int(buffer->Graphics->VisibleClipBounds.Width / 2) - 200,
			28);
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

	void addDrone(int lmtY) {
		System::Random r;
		Moving_Entity* drone = new Moving_Entity(1150, r.Next(35, lmtY), Sprites::RobotVolador, Behavior::LinearMove);
		drone->setTiling(12, 1);
		drone->setDir(Direcciones::Izquierda);
		drone->setDx(-1);
		drone->setSpeed(7);
		drone->setDestroyOnlyExit(true);
		drone->setEscala(0.5f);
		//drone->setColliderScale(1.25f);
		drones.push_back(drone);
	}
};