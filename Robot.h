#pragma once
//ando buscnaod una iamgen primero

#include "Entidad.h"

using namespace System;

class Robot : public Entidad
{

public:
	Robot(int x, int y) : Entidad(x, y) {
		this->x = 0;
		this->y = 0;
	}
	void setDireccionRobot(Direcciones dix){
		this->direccion = dix;
		}

	~Robot() { }
	Direcciones getDireccionRandom() {
		Random r;
		int valor = r.Next(1, 5);
		switch (valor) {
		case 1: 
			return Direcciones::Arriba;
			break;
		case 2:
			return Direcciones::Abajo;
			break;
		case 3:
			return Direcciones::Izquierda;
			break;
		case 4:
			return Direcciones::Derecha;
			break;
		}
	}

	void dibujarRobot(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 4;
		alto = bmp->Height / 4;

		dibujarEntidad(buffer, bmp);
	}

	void moverRobot(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (iteraX >= 0 && iteraX < 3) iteraX++;
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

		dibujarRobot(buffer, bmp);

	}

};
