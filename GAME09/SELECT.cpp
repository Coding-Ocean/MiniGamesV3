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
	void SELECT::create() {
		Select = game()->container()->data().select;
	}
	void SELECT::update() {
		if (isTrigger(MOUSE_LBUTTON)) {
			game()->message()->upperMessage("テスト用ですわ～");
			//game()->message()->upperMessage("テテテテテテテテ");
			//game()->message()->upperMessage("テストテストテストテストテストテスト");
		}
	}
	void SELECT::draw() {
		clear(128);
		rectMode(CORNER);
		fill(255);
		textSize(100);
		text("ゲーム選択", 10, 110);
		stroke(0);
		strokeWeight(2);
		for (int y = 0; y < Select.row; y++) {
			for (int x = 0; x < Select.col; x++) {
				rect((width - Select.selectOfst.x * 2) / Select.col * x + Select.selectOfst.x + Select.imgOfst.x,
					(height - Select.selectOfst.y) / Select.row * y + Select.selectOfst.y + Select.imgOfst.y,
					Select.imgSize.x, Select.imgSize.y);
			}
		}
	}
	void SELECT::nextScene() {
		//if (isTrigger(KEY_Z)) {
		//	game()->changeScene(GAME::STAGE_ID);
		//}
	}
}