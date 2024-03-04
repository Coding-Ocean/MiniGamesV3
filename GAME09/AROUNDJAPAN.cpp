#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "AROUNDJAPAN.h"
#include "PHYSICS_ENGINE_AJ.h"

namespace GAME09
{
	AROUNDJAPAN::AROUNDJAPAN(class GAME* game) :
		SCENE(game) {

	}
	AROUNDJAPAN::~AROUNDJAPAN() {

	}
	void AROUNDJAPAN::init() {
		Physics->init();
	}
	void AROUNDJAPAN::create() {
		AroundJapan = game()->container()->data().aroundJapan;
		Physics = new PHYSICS_ENGINE_AJ(game());
		Physics->create();
	}
	void AROUNDJAPAN::update() {
		Physics->update();
	}
	void AROUNDJAPAN::draw() {
		rectMode(CENTER);
		image(AroundJapan.fieldImg, AroundJapan.imgPos.x, AroundJapan.imgPos.y, 0, AroundJapan.imgSize);
		Physics->draw();
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