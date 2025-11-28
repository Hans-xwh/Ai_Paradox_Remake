#pragma once

#include "AvionHaluno.hpp"

class MnJg_Avion {
private:
	HalunoAvion* avion;

public:
	MnJg_Avion() {
		avion = new HalunoAvion();
	}
	~MnJg_Avion() {
		delete avion;
	}

	void updateAll(BufferedGraphics^ buffer) {
		avion->move(buffer);
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		avion->draw(buffer, spriteDb);
	}

	void input(Direcciones d) {
		avion->setDir(d);
	}

};