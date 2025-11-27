#pragma once
#include "Entidad.h"

using namespace System;

class Rocas : public Entidad
{

public:
	Rocas(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y = y;
		direccion = getDireccionRandom();
		iteraX = 0;
		iteraY = 0;
		setTiling(6, 1);
		escala = 1;
		sprite = Sprites::GolemRoca;
	}
	void setDireccionRobot(Direcciones dix) {
		this->direccion = dix;
	}

	~Rocas() {}
	Direcciones getDireccionRandom() {
		Random r;
		int valor = r.Next(1, 5);
		switch (valor) {
		case 1:
			return Direcciones::Abajo;
			break;
		case 2:
			return Direcciones::Arriba;
			break;
		case 3:
			return Direcciones::Izquierda;
			break;
		case 4:
			return Direcciones::Derecha;
			break;
		}
	}

	void dibujarRocas(BufferedGraphics^ buffer) {
		//ancho = bmp->Width / 6;
		//alto = bmp->Height / 1;

		//dibujar(buffer, bmp);
	}

	void moverRocas(BufferedGraphics^ buffer) {
		if (iteraX >= 0 && iteraX < 5) iteraX++;
		else iteraX = 0;

		switch (direccion) {
		case Arriba:
			dx = -10;
			dy = -10;
			break;
		case Abajo:
			dx = 10;
			dy = 10;
			break;
		case Izquierda:
			dx = -10;
			dy = -10;
			break;
		case Derecha:
			dx = 10;
			dy = 10;
			break;

		}


		if (x + dx < 0) setDireccionRobot(Derecha);
		if (x + dx + ancho > buffer->Graphics->VisibleClipBounds.Width) setDireccionRobot(Izquierda);
		if (y + dy < 0) setDireccionRobot(Abajo);
		if (y + dy + ancho > buffer->Graphics->VisibleClipBounds.Height) setDireccionRobot(Arriba);
		x += dx;
		y += dy;

		//dibujar(buffer, bmp);

	}

};

