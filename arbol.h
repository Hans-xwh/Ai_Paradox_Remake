#pragma once
#include "Entidad.h"

class Arbol : public Entidad
{

private:
	bool visible;
public:
	Arbol(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y = y;
		visible = true;
	}
	~Arbol() { }

	void dibujarArbol(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width;
		alto = bmp->Height;
		if (visible = true) {
			buffer->Graphics->DrawImage(bmp, x, y, ancho, alto);

		}
	}
	bool getVisil() { return visible; }
	void setVisil(bool vi) { visible = vi; }
};
