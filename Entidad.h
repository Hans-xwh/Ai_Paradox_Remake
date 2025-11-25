#pragma once
using namespace System::Drawing;

enum Direcciones{Arriba, Abajo, Derecha, Izquierda, Ninguna, Salto, Plantar};

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int iteraX, iteraY;
	float escala;
	Direcciones direccion;
	bool useNN;
	bool visible;
	int tilingX;
	int tilingY;

public:
	Entidad() {}
	~Entidad() {}

	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
		visible = true;
		dx = 0;
		dy = 0;
		ancho = 0;
		alto = 0;
		escala = 1.5;
		tilingX = tilingY = 1;
		iteraX = 0;
		iteraY = 0;
		useNN = true;
	}
	/*void dibujarEntidad(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}*/

	virtual void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp){		
		if (visible) {
			if (useNN) {
				buffer->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
			}

			ancho = bmp->Width / tilingX;
			alto = bmp->Height / tilingY;

			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * escala, alto * escala);
			buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}

	// getters y setters
	bool getVisible() { return visible; }
	bool getEscala() { return escala; }

	void setVisible(bool vi) { visible = vi; }
	void setEscala(float es) { escala = es; }
	void setTiling(int tx, int ty) { tilingX = tx; tilingY = ty; }	// para entidades con spritesheets diferentes
	void useNearestNeighbour(bool N) { useNN = N; }
	void setIteraX(int ix) { iteraX = ix; }
	void setIteraY(int iy) { iteraY = iy; }
	int getIteraX() { return iteraX; }
	int getIteraY() { return iteraY; }
	int getX() { return x; }
	int getY() { return y; }
	void setX(int nx) { x = nx; }
	void setY(int ny) { y = ny; }
};