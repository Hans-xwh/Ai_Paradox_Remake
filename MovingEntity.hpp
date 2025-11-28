#pragma once
#include "Entidad.h"

enum Behavior {
	Bounce,			//Rebota en todas las direcciones
	BounceUpDwn,	//Rebota arriba abjo, se mueve linear
	BounceLfRh,		//Rebota izq der, arriba abajo linear
	LinearMove,		//Linear simple
	RndmBounce,		//Direcciones aleatorias, cambia cuando rebota. Se puede quedar atascado
	RndmLinear,		//Direcciones y pasos aleatorios.
	FollowTarget,	//Sige un X Y, fucnion separada
	DontMove		//Mpovimiento desacticvado
};

class Moving_Entity : public Entidad{
protected:
	Behavior behavior;
	Direcciones shootDir;
	bool active;
	bool animated;
	int behavior;
	int stepsX, stepsY;
	int targetX, targetY;
public:
	Moving_Entity(int X, int Y, Behavior B = Behavior::LinearMove) : Entidad(X, Y) {
		active = true;
		behavior = B;
	}
	Moving_Entity(int X, int Y, Sprites S) : Entidad(X, Y) {
		sprite = S;
	}

	void doBehavior(BufferedGraphics^ buffer);
	void follow(int X, int Y);

	void autoMove(BufferedGraphics^ buffer) {
		if (animated && iteraX >= 0 && iteraX < tilingX - 1) iteraX++;
		else if (animated) iteraX = 0;

		switch (direccion) {
		case Arriba:
			dx = 0;
			dy = -1;
			break;
		case Abajo:
			dx = 0;
			dy = 1;
			break;
		case Izquierda:
			dx = -1;
			dy = 0;
			break;
		case Derecha:
			dx = 1;
			dy = 0;
			break;
		}

		doBehavior(buffer);
	}

	void setDir(Direcciones D) override {
		if (D != Ninguna) {
			shootDir = direccion;
		}
		direccion = D;
	}
};