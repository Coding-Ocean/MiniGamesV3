#include"GAME14.h"
#include"CONTAINER.h"
#include"BUILDING.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "STAGE.h"
namespace GAME14 {
	STAGE::STAGE(class GAME* game):
		SCENE(game){}
	void STAGE::create(){
		Stage = game()->container()->data().stage;

	}
	void STAGE::update(){
		if (isTrigger(KEY_Z)) {
			game()->building()->init();
			game()->player()->init();
		}
		game()->building()->update();
		game()->player()->update();
	}
	void STAGE::draw(){
		clear(Stage.backColor);
		game()->player()->draw();
		game()->building()->draw();
	}
	void STAGE::nextScene(){}

}