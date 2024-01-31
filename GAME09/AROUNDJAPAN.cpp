#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "AROUNDJAPAN.h"

namespace GAME09
{
	AROUNDJAPAN::AROUNDJAPAN(class GAME* game) :
		SCENE(game) {

	}
	AROUNDJAPAN::~AROUNDJAPAN() {

	}
	void AROUNDJAPAN::init() {
		
	}
	void AROUNDJAPAN::create() {
		AroundJapan = game()->container()->data().aroundJapan;
	}
	void AROUNDJAPAN::update() {
		
	}
	void AROUNDJAPAN::draw() {
		clear(128);
		rectMode(CORNER);
		fill(255);
		textSize(100);
		text("“ú–{ˆêŽü", 10, 110);
	}
	void AROUNDJAPAN::nextScene() {
		if (isTrigger(MOUSE_LBUTTON)) {
			if (game()->button()->collisionMouse()) {
				game()->fade()->outStart();
			}
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}