#pragma once
#include "Entidad.h"

class Prop : public Entidad {
private:
	bool active;
	bool animated;
	bool loopAnim;	//Si es false se destruye al acabar de recorrer su spritesheet
public:
	Prop(int X, int Y): Entidad(X, Y) {
		animated = false;
		loopAnim = false;
	}
	Prop(int X, int Y, Sprites S, bool A=false, bool L=false) : Entidad(X, Y) {
		sprite = S;
		animated = A;
		loopAnim = L;
	}

	void draw(BufferedGraphics^ buffer, Sprite_DB^ db) override {
		if (animated){
			if (iteraX < tilingX - 1) { iteraX++; }
			else {
				if (loopAnim) { iteraX = 0; }
				else { active = false; return; }
			}
		}
		if (active) {
			Entidad::draw(buffer, db);
		}
	}

	bool isActive() { return active; }
	void setActive(bool a) { active = a; }
};