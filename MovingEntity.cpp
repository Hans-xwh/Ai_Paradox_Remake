#include "MovingEntity.hpp"

void Moving_Entity::doBehavior(BufferedGraphics^ buffer) {
	if (behavior == Behavior::FollowTarget) return;

	switch (behavior) {
	case Behavior::LinearMove:
		if (active && x + (dx * speed) > 0 && x + (ancho * escala) + (dx * speed) < buffer->Graphics->VisibleClipBounds.Width) {
			x += dx * speed;
		}
		else {
			active = false;
		}

		if (active && y + (dy * speed) > 0 && y + (alto * escala) + (dy * speed) < buffer->Graphics->VisibleClipBounds.Height) {
			y += dy * speed;
		}
		else {
			active = false;
		}
		break;
	}
}

void Moving_Entity::follow(int X, int Y) {
	if (behavior != Behavior::FollowTarget) return;
}