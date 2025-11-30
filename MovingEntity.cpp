#include "MovingEntity.hpp"


void Moving_Entity::doBehavior(int lmX, int lmY) {
	if (behavior == Behavior::FollowTarget) return;
	System::Random r;

	switch (behavior) {
	case Behavior::LinearMove:
		if (active && x + (dx * speed) + (ancho * escala) > 0 && x + (dx * speed) < lmX) {
			x += dx * speed;
		}
		else {
			active = false;
		}

		if (active && y + (dy * speed) > 0 && y + (alto * escala) + (dy * speed) < lmY) {
			y += dy * speed;
		}
		else {
			active = false;
		}
		
		if (destroyOnlyExit && !active) {
			if (x <= 0 && direccion == Direcciones::Derecha) {
				active = true;
			}
			if (x >= lmX && direccion == Direcciones::Izquierda) {
				active = true;
			}
		}
		break;

	case Behavior::RndmUpDwn:
		if (active && x + (dx * speed) > 0 && x + (ancho * escala) + (dx * speed) < lmX) {
			x += dx * speed;
		}
		else {
			dx *= -1;
		}

		if (active && y + (dy * speed) > 0 && y + (alto * escala) + (dy * speed) < lmY) {
			y += dy * speed;
		}
		else {
			dy *= -1;
		}

		if (dx != 0) { stepsX++; }
		if (dy != 0) { stepsY++; }
		if (dx != 0 && stepsX > targetStepX) {
			stepsX = 0;
			targetStepX = r.Next(20, 50);
			dx *= -1;
		}
		if (dy != 0 && stepsY > targetStepY) {
			stepsY = 0;
			targetStepY = r.Next(20, 50);
			dy *= -1;
		}
		break;
	}
}

void Moving_Entity::follow(int tX, int tY) {
	if (behavior != Behavior::FollowTarget) return;

	if (x < tX) {
		dx = 1;
	} else if (x > tX) {
		dx = -1;
	} else {
		dx = 0;
	}

	if (y < tY) {
		dy = 1;
	} else if (y > tY) {
		dy = -1;
	} else {
		dy = 0;
	}

	x += dx * speed;
	y += dy * speed;
}