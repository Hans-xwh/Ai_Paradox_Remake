#pragma once
#include "Entidad.h"

class Personaje : public Entidad {

private:
	Direcciones ultTecla;
	int agua;
	int vidas;
public:
	Personaje(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y = y;
		iteraX = 0;
		iteraY = 1;
		dx = 0;
		dy = 0;
		agua = 10;
		vidas = 10;
		setTiling(13, 54);
		sprite = Sprites::Haluno;
	}
	~Personaje() { }
	Direcciones direccion;
	
	/*	//Usar metodo draw de Entidad
	void dibujarPersonaje(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 54;

		dibujar(buffer, bmp);

	}
	*/

	void moverPersonaje(BufferedGraphics^ buffer) {
		if (iteraX >= 0 && iteraX < 3) iteraX++;
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
		case Salto:
			dy = 0;
			dx = 0;
			if (ultTecla == Arriba) {
				dy = -25;
				dx = 0;
				iteraY = 26;
				ultTecla = Arriba;
			}
			else if (ultTecla == Abajo) {
				dy = 25;
				dx = 0;
				iteraY = 28;
				ultTecla = Abajo;
			}
			else if (ultTecla == Derecha) {
				dy = 0;
				dx = 25;
				iteraY = 29;
				ultTecla = Derecha;
			}
			else if (ultTecla == Izquierda) {
				dy = 0;
				dx = -25;
				iteraY = 27;
				ultTecla = Izquierda;
				
			}
			break;

		}

		if (x + dx < 0 || x + dx + (ancho * escala) > buffer->Graphics->VisibleClipBounds.Width) {
			dx = 0;
		}
		if (y + dy < 0 || y + dy + (ancho * escala) > buffer->Graphics->VisibleClipBounds.Height) {
			dy = 0;
		}
		x += dx;
		y += dy;

		//dibujar(buffer);	//NO DIBUJAR EN LA MISMA FUNCIÓN QUE MOVER
	}
	void setAgua(int val) {
		this->agua += val;
	}
	int getAgua() {
		return this->agua;
	}

	void setVidas(int valu) {
		this->vidas += valu;
	}
	int getVidas() {
		return this->vidas;
	}
};