#pragma once

#include <vector>
#include <fstream>
#include "Personaje.h"
#include "MovingEntity.hpp"
#include "Prop.hpp"
#include "AudioManager.hpp"

using std::ifstream;
using std::fstream;
using std::ofstream;
using std::ios;

struct pair {
	int X;
	int Y;
};

class MnJg_Robots {
private:
	Personaje* haluno;
	std::vector<Moving_Entity*> robots;
	std::vector<Prop*> chips;
public:
	MnJg_Robots() {
		haluno = new Personaje(10,20);
		loadProps();
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
		haluno->draw(buffer, spriteDb);
	}

	void updateAll(BufferedGraphics^ buffer) {
		haluno->moverPersonaje(buffer);
		for (Moving_Entity* r : robots) {
			r->follow(haluno->getX(), haluno->getY());
		}
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

	void loadProps() {
		using std::string;	//Importar string solo para esta funcion

		ifstream file;
		string myLine;

		file.open("config/robots.txt", ios::in);
		if (file.is_open() || true) {
			int tmpX, tmpY;
			char trash;

			while (file >> tmpX >> trash >> tmpY) {
				addRobot(tmpX, tmpY);
			}
		}
		file.close();

		file.open("config/chips.txt", ios::in);
		if (file.is_open() || true) {
			int tmpX, tmpY;
			char trash;

			while (file >> tmpX >> trash >> tmpY) {
				addChip(tmpX, tmpY);
			}
		}
		file.close();

	}

	void addRobot(int X, int Y) {
		Moving_Entity* tmp = new Moving_Entity(X, Y, Sprites::Robot, Behavior::FollowTarget);
		tmp->setTiling(7, 2);
		tmp->setEscala(0.25);
		tmp->setSpeed(1);
		tmp->setShowHitbox(true);
		robots.push_back(tmp);
		tmp->setColliderScale(0.25);
	}

	void addChip(int X, int Y) {
		Prop* tmp = new Prop(X, Y, Sprites::Eprom);
		tmp->setTiling(1, 1);
		tmp->setEscala(0.25);
		tmp->setShowHitbox(true);
		chips.push_back(tmp);
	}
};