#pragma once
//ando buscnaod una iamgen primero

#include "Entidad.h"

using namespace System;

class Agua : public Entidad
{

public:
	Agua(int x, int y) : Entidad(x, y) {
		this->x = x;
		this->y =y;
		direccion = getDireccionRandom();
		iteraX = 0;
		iteraY = 3;
	}
	void setDireccionRobot(Direcciones dix){
		this->direccion = dix;
		}

	~Agua() { }
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

	void dibujarAgua(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 54;

		dibujarEntidad(buffer, bmp);
	}

	void moverAgua(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (iteraX >= 0 && iteraX < 6) iteraX++;
		else iteraX = 0;

		switch (direccion) {
		case Arriba:
			dx = 0;
			dy = -10;
			break;
		case Abajo:
			dx = 0;
			dy = 10;
			break;
		case Izquierda:
			dx = -10;
			dy = 0;
			break;
		case Derecha:
			dx = 10;
			dy = 0;
			break;
					
		}


		if (x + dx < 0) setDireccionRobot(Derecha);
		if (x + dx + ancho > buffer->Graphics->VisibleClipBounds.Width) setDireccionRobot(Izquierda);
		if (y + dy < 0) setDireccionRobot(Abajo);
		if (y + dy + ancho > buffer->Graphics->VisibleClipBounds.Height) setDireccionRobot(Arriba);
		x += dx;
		y += dy;

		dibujarAgua(buffer, bmp);

	}

};
