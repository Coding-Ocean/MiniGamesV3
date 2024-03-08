#include"GAME14.h"
#include"CONTAINER.h"
#include"BUILDING.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/mathUtil.h"
#include "STAGE.h"
namespace GAME14 {
	STAGE::STAGE(class GAME* game):
		SCENE(game){}
	STAGE::~STAGE() {
		delete Time;
	}
	void STAGE::create(){
		Stage = game()->container()->data().stage;

		Time = new TIME(game());
		Time->create();
	}
	void STAGE::init() {
		game()->building()->init();
		game()->player()->init();
		Time->init();
		Flag = false;
		FadeStart = true;
		FadeEnd = false;
		ColorA = Stage.rectColor.a;
		AnimeTime = 0;
	}
	void STAGE::update(){
		if (isTrigger(KEY_Z)) {
			init();
		}
			game()->building()->update();
			game()->player()->update();
		if (FadeEnd) {
			if (Flag) {
				Time->update();
			}
			else {
				if (!game()->player()->getStay() && isTrigger(KEY_SPACE)) Flag = true;
			}
		}
	}
	void STAGE::draw(){
		clear(Stage.backColor);
		game()->player()->draw();
		game()->building()->draw();
		Time->draw();
		if (FadeStart)fade();
		//print(Stage.animeTime);
	}
	void STAGE::nextScene(){
		if (Time->timeUp()||isTrigger(KEY_S)) {
			game()->changeScene(game()->GAME_CLEAR_ID);
		}
		if (!game()->player()->checkAlive()||isTrigger(KEY_D)) {
			game()->changeScene(game()->GAME_OVER_ID);
		}
	}
	void STAGE::fade() {
		AnimeTime += delta;
		if (AnimeTime <= Stage.animeTime) {
			float theta = AnimeTime / Stage.animeTime * 90.0f;
			float ratio = Cos(theta);
			Stage.rectColor.a = ColorA * ratio;
		}
		else {
			FadeStart = false;
			FadeEnd = true;
		}
		fill(Stage.rectColor);
		rect(0, 0, Stage.rectSize.x, Stage.rectSize.y);
	}

}