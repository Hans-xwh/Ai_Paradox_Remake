#pragma once

#include <vector>
#include "HalunoTercer.h"
#include "Proyectil.hpp"
#include "MovingEntity.hpp"
#include "Prop.hpp"
#include "Balanza.h"
#include "Moneda.h"
#include "Personaje.h"


class MnJg_Nivel3 {
private:
	//HalunoTercer* halunito;
	Personaje* halunito;
	std::vector<Moneda*> monedas;
	std::vector<Balanza*> balanzas;

	int shootInterval;
	int shootCount;
	bool victoria = false;

public:
	MnJg_Nivel3() {
		//halunito = new HalunoTercer();
		halunito = new Personaje(400, 60);
		halunito->setSpeed(10);
		victoria = false;
	}
	~MnJg_Nivel3() {
		delete halunito;

		for (Moneda* m : monedas) {
			delete m;
		}

		for (Balanza* b : balanzas) {
			delete b;
		}

	}

	void updateAll(BufferedGraphics^ buffer) {
		System::Random r;
		halunito->moverPersonaje(buffer);

		//Monedas que caen a la balanza
		for (int i = 0; i < monedas.size(); i++) {
			Moneda* m = monedas[i];
			m->autoMove(buffer);
			m->setY(m->getY() + 5);

			if (m->getY() > buffer->Graphics->VisibleClipBounds.Height) {
				delete m;
				monedas.erase(monedas.begin() + i);
				i--;
			}
		}
	}

	void updateCollisions() {

		for (int i = 0; i < monedas.size(); i++) {
			Moneda* m = monedas[i];
			for (int j = 0; j < balanzas.size(); j++) {
				Balanza* b = balanzas[j];
				if (m->getCollider().IntersectsWith(b->getCollider())) {
					b->aumentarSprites();
					delete m;
					monedas.erase(monedas.begin() + i);
					i--;
					break;
				}
			}
		}

		if (comprobarSiGano()) {
			victoria = true;
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		for (Balanza* d : balanzas) {
			d->draw(buffer, spriteDb);
		}
		for (Moneda* m : monedas) {
			m->draw(buffer, spriteDb);
		}

		halunito->draw(buffer, spriteDb);

	}

	void input(Direcciones d) {
		if (d == Direcciones::Salto) {
			monedas.push_back(DameMonedas(halunito->getOffsetedX() - 40, halunito->getOffsetedY() - 20));
			
		}
		halunito->direccion = d;	//Noelia pero que es esto xd
	}

	Moneda* DameMonedas(int X, int Y, Direcciones dir = Direcciones::Abajo) {
		Moneda* m = new Moneda(X, Y, true);
			m->setTiling(1, 1);
			m->setSprite(Sprites::moneditas);
			m->setAnimated(false);
			m->setIteraX(0);
		return m;
	}
	void addBalanzaDoble(BufferedGraphics^ buffer) {
		int H = buffer->Graphics->VisibleClipBounds.Height;

		Balanza* b1 = new Balanza(200, H - 181);
		Balanza* b2 = new Balanza(600, H - 181);

		b1->setSprite(Sprites::Balanza);
		b2->setSprite(Sprites::Balanza);

		b1->setTiling(4, 1);
		b2->setTiling(4, 2);

		b1->setIteraY(0);
		b2->setIteraY(1);

		balanzas.push_back(b1);
		balanzas.push_back(b2);
	}


	bool comprobarSiGano() {
		if (balanzas.size() >= 2) {
			if (balanzas[0]->getspriteActualBalanza() >= 3 && balanzas[1]->getspriteActualBalanza() >= 3) {
				return true;
			}
		}
		return false;
	}

	bool getVictoria() { return victoria;  }
};

