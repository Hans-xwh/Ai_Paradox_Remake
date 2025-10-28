#pragma once
#include "Entidad.h"

using namespace std;

class Reymundo : public Entidad
{

public:
	Reymundo(int x, int y)  : Entidad(x, y)
	{
		this->x = x;
		this->y = y;
		iteraX = 0;
		iteraY = 2;
	
	}
	~Reymundo() { }


	void dibujarReymundo(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 54;

		dibujarEntidad(buffer, bmp);
	}

};