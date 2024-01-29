#include "CONTAINER.h"
#include <string.h>

namespace GAME09
{
	void CONTAINER::load() {
		setData();
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

		Data.aroundJapan.img = 0;
	}
}