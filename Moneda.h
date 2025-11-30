#pragma once
#include "MovingEntity.hpp"
#include "Entidad.h"

class Moneda : public Moving_Entity {
public:
	Moneda(int X, int Y, bool A) : Moving_Entity(X, Y) {
		animated = A;
		speed = 10;
	}

    void setAnimated(bool a) { animated = a; }

};