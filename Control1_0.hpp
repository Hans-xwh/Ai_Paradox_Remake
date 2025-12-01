#pragma once

#include <vector>
#include <fstream>
#include "Personaje.h"
#include "MovingEntity.hpp"
#include "Prop.hpp"
#include "AudioManager.hpp"
#include "AvionNvl1.h"


using std::ifstream;
using std::fstream;
using std::ofstream;
using std::ios;

class MnJg_Robots {
private:
	Personaje* haluno;
	Prop* puerta;
	bool state = false;

	//Parte 2
	std::vector<Moving_Entity*> robots;
	std::vector<Prop*> chips;
	std::vector<Prop*> tornillos;
	int chp, trn;

	//Parte 1
	Prop* aliado;
	Prop* avion;

public:
	MnJg_Robots() {
		puerta = new Prop(1050, 250, Sprites::Puerta); puerta->setEscala(2);
		haluno = new Personaje(10, 20); haluno->setShowHitbox(true);
		aliado = new Prop(400, 450, Sprites::Robot);
		avion = new Prop(600, 450, Sprites::AvionStop);
		avion->setEscala(0.75);
		aliado->setTiling(7, 2);
		aliado->setEscala(0.25);
		loadProps();
		chp = trn = 0;
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
		for (Prop* t : tornillos) {
			t->draw(buffer, spriteDb);
		}
		puerta->draw(buffer, spriteDb);
		haluno->draw(buffer, spriteDb);
	}

	bool collision1() {
		if (puerta->getRectangle().IntersectsWith(haluno->getCollider())) {
			state = !state;
			haluno->setX(10); haluno->setY(20);
		}

		return state;
	}

	void colision2() {
		for (int i = 0; i < chips.size(); i++) {
			if (haluno->getCollider().IntersectsWith(chips[i]->getRectangle())) {
				chp++;
				chips[i]->setActive(false);
			}
		}
		for (int i = 0; i < tornillos.size(); i++) {
			if (haluno->getCollider().IntersectsWith(tornillos[i]->getRectangle())) {
				trn++;
				tornillos[i]->setActive(false);
			}
		}
		for (int i = 0; i < chips.size(); i++) {
			if (!chips[i]->isActive()) {
				delete chips[i];
				chips.erase(chips.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < tornillos.size(); i++) {
			if (!tornillos[i]->isActive()) {
				delete tornillos[i];
				tornillos.erase(tornillos.begin() + i);
				i--;
			}
		}
	}

	bool colision3() {
		if (!state && (chp + trn) == 11 && avion->getRectangle().IntersectsWith(haluno->getCollider())) {
			return true;
		}
		else {
			return false;
		}
	}

	void updateAll(BufferedGraphics^ buffer) {
		haluno->moverPersonaje(buffer);
		for (Moving_Entity* r : robots) {
			r->follow(haluno->getX(), haluno->getY());
		}
		colision2();
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

		file.open("config/robots.csv", ios::in);
		if (file.is_open() || true) {
			int tmpX, tmpY;
			char trash;

			while (file >> tmpX >> trash >> tmpY) {
				addRobot(tmpX, tmpY);
			}
		}
		file.close();

		file.open("config/chips.csv", ios::in);
		if (file.is_open() || true) {
			int tmpX, tmpY;
			char trash;

			while (file >> tmpX >> trash >> tmpY) {
				addChip(tmpX, tmpY);
			}
		}
		file.close();

		file.open("config/tornillos.csv", ios::in);
		if (file.is_open() || true) {
			int tmpX, tmpY;
			char trash;

			while (file >> tmpX >> trash >> tmpY) {
				addTornillo(tmpX, tmpY);
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

	void addTornillo(int X, int Y) {
		Prop* tmp = new Prop(X, Y, Sprites::Tornillo);
		tmp->setTiling(1, 1);
		tmp->setEscala(0.125);
		tmp->setShowHitbox(true);
		tornillos.push_back(tmp);
	}


	//// Parte 1 ////
	void drawAll2(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		aliado->draw(buffer, spriteDb);
		puerta->draw(buffer, spriteDb);
		avion->draw(buffer, spriteDb);

		haluno->draw(buffer, spriteDb);
		if (chp == 5 && trn == 6) {
			buffer->Graphics->DrawString("Felicidades, sube al avíon!",
				gcnew System::Drawing::Font("Arial", 16),
				Brushes::Black,
				350,
				330);
		}
		else {
			buffer->Graphics->DrawString("Para reparar el avion, debes recolectar: ",
				gcnew System::Drawing::Font("Arial", 16),
				Brushes::Black,
				350,
				330);
			buffer->Graphics->DrawString(int(6 - trn).ToString() + " Tornillos ",
				gcnew System::Drawing::Font("Arial", 14),
				Brushes::Black,
				350,
				350);
			buffer->Graphics->DrawString(int(5 - chp).ToString() + " Chips ",
				gcnew System::Drawing::Font("Arial", 14),
				Brushes::Black,
				350,
				370);
		}
	}

	void updateAll2(BufferedGraphics^ buffer) {
		haluno->moverPersonaje(buffer);
	}
};