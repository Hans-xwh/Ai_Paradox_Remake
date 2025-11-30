#pragma once

#include "Entidad.h"

class HalunoTercer : public Entidad {   //NO HAY NECESIDAD DE CREAR ESTA CLASE -HW 
private:
	Direcciones lastDir;
public:
	HalunoTercer() : Entidad(150, 5) {
		escala = 1;
        this->setTiling(12, 4);
		sprite = Sprites::Haluno;
		speed = 10;
		iteraY = 1;
	}

	void setDir(Direcciones d) override {
		lastDir = direccion;
		direccion = d;
	}

    void move(BufferedGraphics^ buffer) {
        if (iteraX >= 0 && iteraX < tilingX - 1) iteraX++;
        else iteraX = 0;

        switch (direccion) {
        case Derecha:
            dx = 1; dy = 0;
            iteraY = 2;
            break;
        case Izquierda:
            dx = -1; dy = 0;
            iteraY = 0;
            break;
        case Ninguna:
            dx = 0; dy = 0;
            iteraY = 1;
            break;
        }

        if (x + dx * speed > 0 && x + ancho * escala + dx * speed < buffer->Graphics->VisibleClipBounds.Width)
            x += dx * speed;
        if (y + dy * speed > 0 && y + alto * escala + dy * speed < buffer->Graphics->VisibleClipBounds.Height)
            y += dy * speed;
    }


};