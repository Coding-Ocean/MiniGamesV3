#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "CONTAINER.h"
#include "GAME09.h"
#include "TITLE.h"

namespace GAME09
{
	TITLE::TITLE(class GAME* game) :
		SCENE(game) {

	}
	TITLE::~TITLE() {

	}
	void TITLE::create() {
		Title = game()->container()->data().title;
	}
	void TITLE::draw() {
		clear(128);
		//ƒ^ƒCƒgƒ‹
		fill(Title.textStrokeColor);
		textSize(Title.titleSize);
		text(Title.titleStr, Title.titlePos.x + Title.titleSize * Title.textStrokeRate, Title.titlePos.y + Title.titleSize * Title.textStrokeRate);
		text(Title.titleStr, Title.titlePos.x - Title.titleSize * Title.textStrokeRate, Title.titlePos.y + Title.titleSize * Title.textStrokeRate);
		text(Title.titleStr, Title.titlePos.x + Title.titleSize * Title.textStrokeRate, Title.titlePos.y - Title.titleSize * Title.textStrokeRate);
		text(Title.titleStr, Title.titlePos.x - Title.titleSize * Title.textStrokeRate, Title.titlePos.y - Title.titleSize * Title.textStrokeRate);
		fill(Title.textColor);
		textSize(Title.titleSize);
		text(Title.titleStr, Title.titlePos.x, Title.titlePos.y);
		//click to start
		fill(Title.textStrokeColor);
		textSize(Title.startSize);
		text(Title.startStr, Title.startPos.x + Title.startSize * Title.textStrokeRate, Title.startPos.y + Title.startSize * Title.textStrokeRate);
		text(Title.startStr, Title.startPos.x - Title.startSize * Title.textStrokeRate, Title.startPos.y + Title.startSize * Title.textStrokeRate);
		text(Title.startStr, Title.startPos.x + Title.startSize * Title.textStrokeRate, Title.startPos.y - Title.startSize * Title.textStrokeRate);
		text(Title.startStr, Title.startPos.x - Title.startSize * Title.textStrokeRate, Title.startPos.y - Title.startSize * Title.textStrokeRate);
		fill(Title.textColor);
		textSize(Title.startSize);
		text(Title.startStr, Title.startPos.x, Title.startPos.y);
	}
	void TITLE::nextScene() {
		if (isTrigger(MOUSE_LBUTTON)) {
			game()->fade()->outStart();
		}
		if (game()->fade()->outEndFlag()) {
			game()->changeScene(GAME::SELECT_ID);
		}
	}
}