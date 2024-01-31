#include "BACKBUTTON.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"

namespace GAME09
{
	BACKBUTTON::BACKBUTTON(GAME* game) :
		GAME_OBJECT(game) {

	}
	BACKBUTTON::~BACKBUTTON() {

	}

	void BACKBUTTON::create() {
		Back = game()->container()->data().back;
	}

	void BACKBUTTON::proc() {
		rectMode(CENTER);
		image(Back.img, Back.pos.x, Back.pos.y,0,Back.imgSize);
		if (0) {
			fill(255, 0, 0, 128);
			noStroke();
			rect(Back.pos.x + Back.colliOfst.x, Back.pos.y + Back.colliOfst.y, Back.colliSize.x * 2, Back.colliSize.y * 2);
		}
	}

	bool BACKBUTTON::collisionMouse() {
		if (abs(Back.pos.x + Back.colliOfst.x - mouseX) < Back.colliSize.x &&
			abs(Back.pos.y + Back.colliOfst.y - mouseY) < Back.colliSize.y) {
			return true;
		}
		else {
			return false;
		}
	}
}