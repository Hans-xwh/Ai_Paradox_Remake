#pragma once

#include "MovingEntity.hpp"

class Proyectil : public Moving_Entity{
private:
public:
	 Proyectil(int X, int Y, bool A): Moving_Entity(X, Y){
		 animated = A;
		 speed = 10;
	 }
	 ~Proyectil(){}

	

	void setAnimated(bool a) { animated = a; }
};