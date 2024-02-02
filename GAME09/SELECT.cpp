#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "SELECT.h"
#include "MESSAGE.h"

namespace GAME09
{
	SELECT::SELECT(class GAME* game) :
		SCENE(game) {

	}
	SELECT::~SELECT() {
		
	}
	void SELECT::init() {
		Mouseover = -1;
	}
	void SELECT::create() {
		Select = game()->container()->data().select;
	}
	void SELECT::update() {
		Mouseover = -1;
		for (int y = 0; y < Select.row; y++) {
			for (int x = 0; x < Select.col; x++) {
				float selectPosX = (width - Select.selectOfst.x * 2) / Select.col * x;
				float imgPosX = selectPosX + Select.selectOfst.x + Select.imgOfst.x;
				float selectPosY = (height - Select.selectOfst.y) / Select.row * y;
				float imgPosY = selectPosY + Select.selectOfst.y + Select.imgOfst.y;
				if (imgPosX < mouseX && mouseX < imgPosX + Select.imgSize.x &&
					imgPosY < mouseY && mouseY < imgPosY + Select.imgSize.y) {
					Mouseover = Select.col * y + x;
				}
			}
		}
	}
	void SELECT::draw() {
		rectMode(CORNER);
		textSize(100);
		text("ƒQ[ƒ€‘I‘ð", 10, 110);
		stroke(0);
		strokeWeight(2);
		for (int y = 0; y < Select.row; y++) {
			for (int x = 0; x < Select.col; x++) {
				if (Mouseover == Select.col * y + x) {
					fill(180);
				}
				else {
					fill(255);
				}
				rect((width - Select.selectOfst.x * 2) / Select.col * x + Select.selectOfst.x + Select.imgOfst.x,
					(height - Select.selectOfst.y) / Select.row * y + Select.selectOfst.y + Select.imgOfst.y,
					Select.imgSize.x, Select.imgSize.y);
			}
		}
	}
	void SELECT::nextScene() {
		if (game()->fade()->inEndFlag()) {
			if (isTrigger(MOUSE_LBUTTON)) {
				if (game()->button()->collisionMouse()) {
					game()->fade()->outStart();
					GameId = GAME::TITLE_ID - GAME::NUM_SCENES;
				}
				if (Mouseover != -1) {
					game()->launchGame((GAME::GAME_ID)Mouseover);
					GameId = Mouseover;
				}
			}
		}
		if(game()->fade()->outEndFlag()){
			game()->changeScene(GAME::NUM_SCENES + GameId);
		}
	}
}