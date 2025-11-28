#pragma once

#include "Entidad.h"

class HalunoAvion : public Entidad{
private:
	Direcciones lastDir;
public:
	HalunoAvion() : Entidad(50, 150) {
		speed = 10;
		escala = 1;
		tilingX = tilingY = 4;
		sprite = Sprites::AvionH;
		iteraY = 1;
	}

	void setDir(Direcciones d) override {
		lastDir = direccion;
		direccion = d;
	}

	void move(BufferedGraphics^ buffer) {
		if (iteraX >= 0 && iteraX < tilingX-1) iteraX++;
		else iteraX = 0;

		switch (direccion) {
		case Arriba:
			dy = -1;
			dx = 0;
			iteraY = 0;
			break;
		case Abajo:
			dy = 1;
			dx = 0;
			iteraY = 2;
			break;
		case Ninguna:
			dy = 0;
			dx = 0;
			iteraY = 1;
			break;
		}

		if (x + (dx * speed) > 0 && x + (ancho * escala) + (dx * speed) < buffer->Graphics->VisibleClipBounds.Width) {
			x += dx * speed;
		}
		if (y + (dy * speed) > 0 && y + (alto * escala) + (dy * speed) < buffer->Graphics->VisibleClipBounds.Height) {
			y += dy * speed;
		}
	}

	
};