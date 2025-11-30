#pragma once

#include <vector>
#include "Personaje.h"
#include "MovingEntity.hpp"
#include "Prop.hpp"
#include "AudioManager.hpp"

class MnJg_Robots {
private:
	Personaje* haluno;
	std::vector<Moving_Entity*> robots;
	std::vector<Prop*> chips;
public:
	MnJg_Robots() {

	}
	~MnJg_Robots() {
		delete haluno;
		for (Moving_Entity* r: robots) {
			delete r;
		}
		for (Prop* c : chips) {
			delete c;
		}
	}

	void drawAll(BufferedGraphics^ buffer, Sprite_DB^ spriteDb) {
		for (Moving_Entity* r : robots) {
			r->draw(buffer, spriteDb);
		}
		for (Prop* c : chips) {
			c->draw(buffer, spriteDb);
		}
	}
};