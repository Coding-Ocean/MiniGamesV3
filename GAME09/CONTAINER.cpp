#include "CONTAINER.h"
#include <string.h>
#include "../../libOne/inc/graphic.h"

namespace GAME09
{
	void CONTAINER::load() {
		setData();
		loadGraphic();
	}
	void CONTAINER::setData() {
		Data.title.textColor = COLOR(255, 255, 255);
		Data.title.textStrokeColor = COLOR(0, 0, 0);
		Data.title.textStrokeRate = 0.01f;
		Data.title.titleSize = 150;
		Data.title.startSize = 100;
		Data.title.titlePos = VECTOR2(60, 500);
		Data.title.startPos = VECTOR2(610,800);
		strcpy_s(Data.title.titleStr, "レトロゲームコレクション");
		strcpy_s(Data.title.startStr, "click to start");

		Data.select.col = 3;
		Data.select.row = 2;
		Data.select.imgSize = VECTOR2(400, 300);
		Data.select.imgOfst = VECTOR2(80, 50);
		Data.select.selectOfst = VECTOR2(120,160);//560,460

		Data.fade.alpha = 0;
		Data.fade.color = COLOR(0,0,0);
		Data.fade.speed = 700;

		Data.message.showTime = 0.7f;
		Data.message.fadeTime = 0.3f;
		Data.message.strSize = 90;
		Data.message.strColor = COLOR(255, 255, 255);
		Data.message.rectSize = VECTOR2(1980, 200);
		Data.message.rectColor = COLOR(255, 0, 0, 128);

		Data.aroundJapan.imgPos = VECTOR2(width / 2, height / 2);
		Data.aroundJapan.imgSize = 0.675f;

		Data.bingo.img = 0;

		Data.back.imgSize = 0.2f;
		Data.back.pos = VECTOR2(130, 80);
		Data.back.colliOfst = VECTOR2(-22, 0);
		Data.back.colliSize = VECTOR2(76, 56);

		Data.backG.imgSize = 1.0f;
		Data.backG.pos = VECTOR2(0, 0);

		Data.coin.imgSize = 1;
		Data.coin.startPos = VECTOR2(1000, 100);
		Data.coin.radius = 100;
		Data.coin.friction = 0.5f;
		Data.coin.limmitV = 100.0f;
		Data.coin.sw = 2;
	}
	void CONTAINER::loadGraphic() {
		Data.aroundJapan.fieldImg = loadImage("..\\main\\assets\\game09\\travel_field.png");
		Data.aroundJapan.fieldFrameImg = loadImage("..\\main\\assets\\game09\\travel_field_frame.png");
		Data.back.img = loadImage("..\\main\\assets\\game09\\back_button.png");
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.png");
	}
}