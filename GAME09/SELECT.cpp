#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "SELECT.h"

namespace GAME09
{
	SELECT::SELECT(class GAME* game) :
		SCENE(game) {

	}
	SELECT::~SELECT() {

	}
	void SELECT::create() {
		Select = game()->container()->data().select;
	}
	void SELECT::draw() {
		clear(128);
		print("select");
	}
	void SELECT::nextScene() {
		//if (isTrigger(KEY_Z)) {
		//	game()->changeScene(GAME::STAGE_ID);
		//}
	}
}