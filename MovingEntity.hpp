#pragma once
#include "Entidad.h"

enum Behavior {
	Bounce,			//Rebota en todas las direcciones
	BounceUpDwn,	//Rebota arriba abjo, se mueve linear
	BounceLfRh,		//Rebota izq der, arriba abajo linear
	LinearMove,		//Linear simple
	RndmBounce,		//Direcciones aleatorias, cambia cuando rebota. Se puede quedar atascado
	RndmLinear,		//Direcciones y pasos aleatorios.
	RndmUpDwn,		//Mueve de arriba a abajo en direcciones aleatorias. Rebota si se choca con una pared
	FollowTarget,	//Sige un X Y, fucnion separada
	DontMove		//Mpovimiento desacticvado
};

class Moving_Entity : public Entidad{
protected:
	Behavior behavior;
	Direcciones shootDir;
	bool active;
	bool animated;
	bool destroyOnlyExit;		//Permite que la entidad exitas fuera del limite contrario a la direccion de movimiento
	int stepsX, stepsY;
	int targetStepX, targetStepY;
public:
	Moving_Entity(int X, int Y, Behavior B = Behavior::LinearMove) : Entidad(X, Y) {
		active = true;
		behavior = B;
		targetStepX = 0;
		targetStepY = 1;
		sprite = Sprites::Error;

		if (behavior == Behavior::RndmUpDwn) {
			System::Random r;
			targetStepX = r.Next(20, 50);
			targetStepY = r.Next(20, 50);
		}
	}
	Moving_Entity(int X, int Y, Sprites S, Behavior B = Behavior::LinearMove) : Entidad(X, Y) {
		sprite = S;
		behavior = B;
		targetStepX = 0;
		targetStepY = 1;

		if (behavior == Behavior::RndmUpDwn) {
			System::Random r;
			targetStepX = r.Next(20, 50);
			targetStepY = r.Next(20, 50);
		}
	}

	void doBehavior(int lmX, int lmY);
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

		doBehavior(buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);
	}

	void setDir(Direcciones D) override {
		if (D != Ninguna) {
			shootDir = direccion;
		}
		direccion = D;
	}

	bool isActive() { return active; }
	void setActive(bool a) { active = a; }
	void setDy(int DY) { dy = DY; }
	void setDx(int DX) { dx = DX; }
	void setDestroyOnlyExit(bool D) { destroyOnlyExit = D; }
};