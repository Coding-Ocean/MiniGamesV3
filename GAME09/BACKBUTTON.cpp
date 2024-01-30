#include "BACKBUTTON.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"

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
		image(Back.img, Back.pos.x, Back.pos.y);
	}
}