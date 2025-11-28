#pragma once

#include "Entidad.h"

class Proyectil : public Entidad{
private:
	bool active;
	bool animated;

public:
	 Proyectil(int X, int Y, bool A): Entidad(X, Y){
		 animated = A;
		 active = true;
		 speed = 10;
	 }
	 ~Proyectil(){}

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

		if (active && x + (dx * speed) > 0 && x + (ancho * escala) + (dx * speed) < buffer->Graphics->VisibleClipBounds.Width) {
			x += dx * speed;
		}
		else {
			active = false;
		}

		if (active && y + (dy * speed) > 0 && y + (alto * escala) + (dy * speed) < buffer->Graphics->VisibleClipBounds.Height) {
			y += dy * speed;
		}
		else {
			active = false;
		}
	}

	bool isActive() { return active; }
	void setAnimated(bool a) { animated = a; }
};