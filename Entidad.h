#pragma once

#include "Sprite_DB.hpp"
using nmspc_SpriteDB::Sprite_DB;	//clase Sprite_DB
using nmspc_SpriteDB::Sprites;	//enum Sprites
//using namespace nmspc_SpriteDB;
using namespace System::Drawing;

enum Direcciones{Arriba, Abajo, Derecha, Izquierda, Ninguna, Salto, Plantar};

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int speed;
	int ancho, alto;
	int iteraX, iteraY;
	float escala;
	float colliderScale;
	Direcciones direccion;
	bool useNN;
	bool visible;
	bool showHitbox;
	int tilingX;
	int tilingY;
	Sprites sprite;

public:
	Entidad() {}
	~Entidad() {}

	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
		visible = true;
		dx = 0;
		dy = 0;
		speed = 1;
		ancho = 0;
		alto = 0;
		colliderScale = 1;
		escala = 1.5;
		tilingX = tilingY = 1;
		iteraX = 0;
		iteraY = 0;
		useNN = true;
		showHitbox = true;
	}

	virtual void draw (BufferedGraphics^ buffer, Sprite_DB^ db){		
		Bitmap^ bmp = db->getSprite(sprite);
		//bmp = db->getSprite(Sprites::Error);

		if (visible) {
			if (useNN) {
				buffer->Graphics->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
			}

			ancho = bmp->Width / tilingX;
			alto = bmp->Height / tilingY;

			Rectangle sprite = Rectangle(ancho * iteraX, alto * iteraY, ancho, alto);
			Rectangle zoom = Rectangle(x, y, ancho * escala, alto * escala);
			buffer->Graphics->DrawImage(bmp, zoom, sprite, GraphicsUnit::Pixel);

			if (showHitbox) {
				buffer->Graphics->DrawRectangle(Pens::Cyan, this->getRectangle());
				buffer->Graphics->DrawRectangle(Pens::Red, zoom);
				buffer->Graphics->DrawRectangle(Pens::Yellow, this->getCollider());
			}
		}
	}

	void setSprite(Sprites s) { sprite = s; }
	void setSprite(Sprites s, Sprite_DB^ db) {
		sprite = s;

		Bitmap^ tmp_bmp = db->getSprite(s);
		ancho = tmp_bmp->Width / tilingX;
		alto = tmp_bmp->Height / tilingY;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * escala, alto * escala);
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
	int getOffsetedX() { return x + ancho; }
	int getOffsetedY() { return y + (alto / 2); }
	void setX(int nx) { x = nx; }
	void setY(int ny) { y = ny; }
	void setSpeed(int S) { speed = S; }
	void setShowHitbox(bool s) { showHitbox = s; }
	virtual void setDir(Direcciones d) { direccion = d; }
	void setColliderScale(float cs) { colliderScale = cs; }	// A menor numero, mayor el tamaño del sprite

	Rectangle getCollider() {
		return Rectangle(
			x + (ancho/8 * colliderScale),
			y + (alto/8 * colliderScale),
			ancho * escala - (ancho / 4 * colliderScale),
			alto * escala - (alto / 4 * colliderScale)
			);
	}
};