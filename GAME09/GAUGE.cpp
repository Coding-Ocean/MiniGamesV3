#include "GAUGE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09 {
	GAUGE::GAUGE(class GAME* game):
		GAME_OBJECT(game){

	}
	GAUGE::~GAUGE(){
	
	}
	void GAUGE::create(){
		Gauge = game()->container()->data().gauge;
	}
	void GAUGE::init(){
		Power = Gauge.powerMin;
		State = STOP;
	}
	void GAUGE::update(){
		ReturnPower = 0;
		if (State == STOP) {
			if (isTrigger(MOUSE_LBUTTON) && Collision()) {
				Power = Gauge.powerMin;
				State = UP;
			}
		}
		else if (State == UP) {
			if (isPress(MOUSE_LBUTTON)) {
				Power += Gauge.powerSpeed * delta;
				if (Power > Gauge.powerMax) {
					Power = Gauge.powerMax;
					State = DOWN;
				}
			}
			else {
				ReturnPower = Power;
				State = STOP;
			}
		}
		else {
			if (isPress(MOUSE_LBUTTON)) {
				Power -= Gauge.powerSpeed * delta;
				if (Power < Gauge.powerMin) {
					Power = Gauge.powerMin;
					State = UP;
				}
			}
			else {
				ReturnPower = Power;
				State = STOP;
			}
		}
	}
	void GAUGE::draw(){
		rectMode(CORNER);
		colorMode(HSV);
		angleMode(DEGREES);
		noStroke();
		float lowerY = Gauge.framePos.y + Gauge.gaugeSize.y / 2.0f;
		float memoryHeight = Gauge.gaugeSize.y / Gauge.powerMax;
		for (int i = 0; i < (int)Power; i++) {
			int hue = Map(i, Gauge.powerMin, Gauge.powerMax, Gauge.hueMin, Gauge.hueMax);
			fill(hue, 255, 255);
			rect(Gauge.framePos.x - Gauge.gaugeSize.x / 2.0f, lowerY - memoryHeight * (i + 1), Gauge.gaugeSize.x, memoryHeight);
		}
		rectMode(CENTER);
		colorMode(RGB);
		image(Gauge.frameImg, Gauge.framePos.x, Gauge.framePos.y, 0, Gauge.frameSize);
		image(Gauge.buttonImg, Gauge.buttonPos.x, Gauge.buttonPos.y, 0, Gauge.buttonSize);
	}
	bool GAUGE::Collision() {
		VECTOR2 mousePos(mouseX, mouseY);
		VECTOR2 mToC = Gauge.buttonPos - mousePos;
		if (mToC.mag() < Gauge.buttonRadius / 2.0f) {
			return true;
		}
		else {
			return false;
		}
	}
}