#pragma once
#include "Entidad.h"

//PENDIENTE ELIMINAR ESTA CLASE
//Es lo mismo que entidad

using namespace std;

class ReymundoS : public Entidad
{

public:
	ReymundoS(int x, int y)  : Entidad(x, y)
	{
		this->x = x;
		this->y = y;
		iteraX = 0;
		iteraY = 2;
		sprite = Sprites::Reymundo;
	
	}
	~ReymundoS() { }


	/*void dibujarReymundo(BufferedGraphics^ buffer, Bitmap^ bmp) {
		ancho = bmp->Width / 13;
		alto = bmp->Height / 54;

		dibujar(buffer, bmp);
	}*/

};