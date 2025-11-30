#pragma once

#include "MovingEntity.hpp"

class Balanza : public Moving_Entity {
private:
	int spriteActualBalanza = 0;
public:
	Balanza(int X, int Y) : Moving_Entity(X, Y) {
		spriteActualBalanza = 0;
		animated = false;
		setDx(0);
		setDy(0);
		setSpeed(0);
	}
	~Balanza() {}

	void aumentarSprites() {
		if (spriteActualBalanza < 3) {
			spriteActualBalanza++;
			setIteraX(spriteActualBalanza);
		}
	}

	bool llegoAlMaximo() { return spriteActualBalanza == 3; }
	int getspriteActualBalanza() { return spriteActualBalanza; }
};