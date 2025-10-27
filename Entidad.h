#pragma once
using namespace System::Drawing;

enum Direcciones{Arriba, Abajo, Derecha, Izquierda, Ninguna};

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int iteraX, iteraY;
	Direcciones direccion;
	bool visibilidad;
public:
	Entidad() {}
	~Entidad() {}

	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		ancho = 0;
		alto = 0;
		iteraX = 0;
		iteraY = 0;
	}
	void dibujarEntidad(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

	bool getVisibilidad() {
		return this->visibilidad; 
	}
	void setVisibilidad(bool v) {
		this->visibilidad = v;
	}
};