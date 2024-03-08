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
		Data.title.titleSize = 200;
		Data.title.startSize = 100;
		Data.title.titlePos = VECTOR2(360, 500);
		Data.title.startPos = VECTOR2(610,800);
		strcpy_s(Data.title.titleStr, "êVä≤ê¸ÉQÅ[ÉÄ");
		strcpy_s(Data.title.startStr, "click to start");

		Data.select.col = 3;
		Data.select.row = 2;
		Data.select.imgSize = VECTOR2(400, 300);
		Data.select.imgOfst = VECTOR2(80, 50);
		Data.select.selectOfst = VECTOR2(120,160);//560,460
		Data.select.selectText = "ÉQÅ[ÉÄëIë";
		Data.select.textPos = VECTOR2(710,110);
		Data.select.textSize = 100;
		Data.select.textColor = COLOR(255,255,255);
		Data.select.textStrokeWeight = 1.5f;
		Data.select.textStroke = COLOR(0, 0, 0);

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
		Data.aroundJapan.winTextPos = VECTOR2(600, 60);
		Data.aroundJapan.loseTextPos = VECTOR2(600, 110);
		Data.aroundJapan.textSize = 50;

		Data.bingo.img = 0;

		Data.back.imgSize = 0.2f;
		Data.back.pos = VECTOR2(130, 80);
		Data.back.colliOfst = VECTOR2(-22, 0);
		Data.back.colliSize = VECTOR2(76, 56);

		Data.backG.imgSize = 1.0f;
		Data.backG.pos = VECTOR2(0, 0);

		Data.coin.imgSize = 0.025f;
		Data.coin.startPos = VECTOR2(1100, 100);
		Data.coin.startV = VECTOR2(-400, 0);
		Data.coin.radius = 21;
		Data.coin.friction = 0.5f;
		Data.coin.limmitV = 100.0f;
		Data.coin.sw = 2;

		Data.phisicsAj.gravity = VECTOR2(0, 1000);
		Data.phisicsAj.wallDataFileName = "..\\main\\assets\\game09\\wall_data.txt";
		Data.phisicsAj.holeDataFileName = "..\\main\\assets\\game09\\hole_data.txt";
		Data.phisicsAj.distanceWall = 315;
		Data.phisicsAj.coinSize = Data.coin.radius;
		Data.phisicsAj.tolerance = 3;
		Data.phisicsAj.powerDiameter = 17.0f;
		Data.phisicsAj.winHolePos = VECTOR2(779, 955);

		Data.gauge.buttonPos = VECTOR2(1400, 1000);
		Data.gauge.framePos = VECTOR2(1400, 560);
		Data.gauge.buttonSize = 0.3f;
		Data.gauge.frameSize = 0.6f;
		Data.gauge.buttonRadius = 150;
		Data.gauge.gaugeSize = VECTOR2(75,750);
		Data.gauge.hueMax = 0;
		Data.gauge.hueMin = 120;
		Data.gauge.powerSpeed = 150;
		Data.gauge.powerMax = 100;
		Data.gauge.powerMin = 0;
	}
	void CONTAINER::loadGraphic() {
		Data.aroundJapan.fieldImg = loadImage("..\\main\\assets\\game09\\travel_field.png");
		Data.aroundJapan.fieldFrameImg = loadImage("..\\main\\assets\\game09\\travel_field_frame.png");
		Data.aroundJapan.inletImg = loadImage("..\\main\\assets\\game09\\inlet.png");
		Data.back.img = loadImage("..\\main\\assets\\game09\\back_button.png");
		Data.backG.img = loadImage("..\\main\\assets\\game09\\back_ground.png");
		Data.coin.img = loadImage("..\\main\\assets\\game09\\coin.png");
		Data.gauge.buttonImg = loadImage("..\\main\\assets\\game09\\gauge_button.png");
		Data.gauge.frameImg = loadImage("..\\main\\assets\\game09\\gauge_frame.png");
	}
}