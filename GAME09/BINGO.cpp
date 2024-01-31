#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "BINGO.h"

namespace GAME09
{
	BINGO::BINGO(class GAME* game) :
		SCENE(game) {

	}
	BINGO::~BINGO() {

	}
	void BINGO::init() {

	}
	void BINGO::create() {
		Bingo = game()->container()->data().bingo;
	}
	void BINGO::update() {

	}
	void BINGO::draw() {
		clear(128);
		rectMode(CORNER);
		fill(255);
		textSize(100);
		text("スマートビンゴ", 10, 110);
	}
	void BINGO::nextScene() {
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