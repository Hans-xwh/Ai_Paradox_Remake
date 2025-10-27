#pragma once
#include "Entidad.h"

class Personaje : public Entidad {

private:
	Direcciones ultTecla;
public:
	Personaje(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y = y;
		iteraX = 0;
		iteraY = 1;
		dx = 0;
		dy = 0;
	}
	~Personaje() { }
	Direcciones direccion;

	void dibujarPersonaje(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 55;

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

		dibujarPersonaje(buffer, bmp);
	}


};