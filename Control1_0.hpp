#pragma once

#include <vector>
#include "Personaje.h"
#include "MovingEntity.hpp"
#include "Prop.hpp"
#include "AudioManager.hpp"

class MnJg_Robots {
private:
	Personaje* haluno;
	std::vector<Moving_Entity*> robots;
	std::vector<Prop*> chips;
public:
	MnJg_Robots() {
		haluno = new Personaje(10,20);
	}
	~MnJg_Robots() {
		delete haluno;
		for (Moving_Entity* r: robots) {
			delete r;
		}
		for (Prop* c : chips) {
			delete c;
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		for (Moving_Entity* r : robots) {
			r->draw(buffer, spriteDb);
		}
		for (Prop* c : chips) {
			c->draw(buffer, spriteDb);
		}
	}

	void updateAll(BufferedGraphics^ buffer) {
		haluno->moverPersonaje(buffer);
	}

	void input(Direcciones d, AudioMngr^ A = nullptr) {
		if (d != Direcciones::Salto) {
			haluno->direccion = d;
		}
	}

	void addExplosion(int X, int Y, int S) {
		Prop* exp = new Prop(X - 80, Y - 20, Sprites::Explosion, true, false);
		exp->setTiling(12, 1);
		exp->setEscala(S * 1.5f);
		exp->setShowHitbox(false);
		//explosiones.push_back(exp);
	}
};