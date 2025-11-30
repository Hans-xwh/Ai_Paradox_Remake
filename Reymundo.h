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

};


class ArbolSabio : public Entidad {
private:
    int spriteActual;

public:
    ArbolSabio(int X, int Y) : Entidad(X, Y) {
        spriteActual = 0;
        setSprite(Sprites::ArbolSabio);
        setEscala(5.0f);
        setTiling(14, 1);
        setIteraY(0);
        setIteraX(0);
    }

    ~ArbolSabio() {}

    void siguienteSprite() {
        spriteActual = (spriteActual + 1) % 14;
        setIteraX(spriteActual);
    }
};
