#include"GAME14.h"
#include"CONTAINER.h"
#include"BUILDING.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
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
	void STAGE::update(){
		if (isTrigger(KEY_Z)) {
			game()->building()->init();
			game()->player()->init();
			Time->init();
		}

		if (Stage.cnt >=1&&isTrigger(KEY_SPACE)) Stage.flag = true;
		if (Stage.flag) {
			game()->building()->update();
			game()->player()->update();
			Time->update();
		}
		else {
			Stage.cnt += delta;
		}
	}
	void STAGE::draw(){
		clear(Stage.backColor);
		game()->player()->draw();
		game()->building()->draw();
		Time->draw();
		if(!Stage.flag)
		text("SPACEでスタート", width / 2, height / 2);
	}
	void STAGE::nextScene(){}

}