#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "AROUNDJAPAN.h"
#include "PHYSICS_ENGINE_AJ.h"
#include "GAUGE.h"

namespace GAME09
{
	AROUNDJAPAN::AROUNDJAPAN(class GAME* game) :
		SCENE(game) {

	}
	AROUNDJAPAN::~AROUNDJAPAN() {
		delete Gauge;
		delete Physics;
	}
	void AROUNDJAPAN::init() {
		Physics->init();
		Gauge->init();
	}
	void AROUNDJAPAN::create() {
		AroundJapan = game()->container()->data().aroundJapan;
		Physics = new PHYSICS_ENGINE_AJ(game());
		Gauge = new GAUGE(game());
		Physics->create();
		Gauge->create();
	}
	void AROUNDJAPAN::update() {
		Gauge->update();
		Physics->addForceToCoin(Gauge->getPower());
		Physics->update();
	}
	void AROUNDJAPAN::draw() {
		rectMode(CENTER);
		image(AroundJapan.fieldImg, AroundJapan.imgPos.x, AroundJapan.imgPos.y, 0, AroundJapan.imgSize);
		Physics->draw();
		image(AroundJapan.fieldFrameImg, AroundJapan.imgPos.x, AroundJapan.imgPos.y, 0, AroundJapan.imgSize);
		image(AroundJapan.inletImg, AroundJapan.imgPos.x, AroundJapan.imgPos.y, 0, AroundJapan.imgSize);
		Gauge->draw();

		fill(0);
		textMode(BOTTOM);
		textSize(AroundJapan.textSize);
		text((let)"¬Œ÷‰ñ”F" + Physics->win(), AroundJapan.winTextPos.x, AroundJapan.winTextPos.y);
		text((let)"Ž¸”s‰ñ”F" + Physics->lose(), AroundJapan.loseTextPos.x, AroundJapan.loseTextPos.y);
	}
	void AROUNDJAPAN::nextScene() {
		if (isTrigger(MOUSE_LBUTTON)) {
			if (game()->button()->collisionMouse()) {
				game()->fade()->outStart();
			}
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::TITLE_ID);
		}
	}
}