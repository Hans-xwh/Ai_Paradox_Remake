#pragma once
#include "Entidad.h"

class Personaje : public Entidad {

private:
	Direcciones ultTecla;
	int vidas;
public:
	Personaje(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y = y;
		iteraX = 0;
		iteraY = 1;
		dx = 0;
		dy = 0;
		vidas = 10;
	}
	~Personaje() { }
	Direcciones direccion;

	void dibujarPersonaje(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 54;

		dibujarEntidad(buffer, bmp);

	}

	void moverPersonaje(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (iteraX >= 0 && iteraX < 6) iteraX++;
		else iteraX = 0;

		switch (direccion)
		{
		case Arriba:
			dy = -10;
			dx = 0;
			iteraY = 0;
			ultTecla = Arriba;
			break;
		case Abajo:
			dy = 10;
			dx = 0;
			iteraY = 2;
			ultTecla = Abajo;
			break;
		case Derecha:
			dy = 0;
			dx = 10;
			iteraY = 3;
			ultTecla = Derecha;
			break;
		case Izquierda:
			dy = 0;
			dx = -10;
			iteraY = 1;
			ultTecla = Izquierda;
			break;
		case Ninguna:
			dy = 0;
			dx = 0;
			switch (ultTecla)
			{
			case Arriba:
				iteraX = 0;
				iteraY = 0;
				break;
			case Abajo:
				iteraX = 0;
				iteraY = 2;

				break;
			case Derecha:
				iteraX = 0;
				iteraY = 3;
				break;
			case Izquierda:
				iteraX = 0;
				iteraY = 1;
				break;

			}
			break;

		}

		if (x + dx < 0 || x + dx + ancho > buffer->Graphics->VisibleClipBounds.Width) {
			dx = 0;
		}
		if (y + dy < 0 || y + dy + ancho > buffer->Graphics->VisibleClipBounds.Height) {
			dy = 0;
		}
		x += dx;
		y += dy;

		dibujarPersonaje(buffer, bmp);
	}
	void setVidas(int val) {
		this->vidas += val;
	}
	int getVidas() {
		return this->vidas;
	}
};