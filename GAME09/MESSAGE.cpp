#include "MESSAGE.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"

namespace GAME09
{
	MESSAGE::MESSAGE(class GAME* game) :
		GAME_OBJECT(game) {

	}
	MESSAGE::~MESSAGE() {

	}
	void MESSAGE::create() {
		Message = game()->container()->data().message;
	}
	void MESSAGE::proc() {
		//update
		for (auto it = Messages.begin(); it != Messages.end();) {
			it->time += delta;
			if (it->state == SHOW) {
				if (it->time > Message.showTime) {
					it->state = FADE;
					it->time -= Message.showTime;
				}
				++it;
			}
			else if (it->state == FADE) {
				if (it->time > Message.fadeTime) {
					it->state = END;
				}
				++it;
			}
			else {
				it = Messages.erase(it);
			}
		}

		//draw
		rectMode(CENTER);
		textMode(BOTTOM);
		noStroke();
		for (Mes mes : Messages) {
			if (mes.state == SHOW) {
				fill(Message.rectColor);
				rect(width / 2, height / 2, Message.rectSize.x, Message.rectSize.y);
				fill(Message.strColor);
				text(mes.str.c_str(), width / 2 - Message.strSize * ((float)mes.str.length() / 3.6f), height / 2 + Message.strSize / 2);
			}
			if (mes.state == FADE) {
				float ratio = 1.0f - (mes.time / Message.fadeTime);
				fill(Message.rectColor.r, Message.rectColor.g, Message.rectColor.b, Message.rectColor.a * ratio);
				rect(width / 2, height / 2, Message.rectSize.x, Message.rectSize.y);
				fill(Message.strColor.r, Message.strColor.g, Message.strColor.b, Message.strColor.a * ratio);
				text(mes.str.c_str(), width / 2 - Message.strSize * ((float)mes.str.length() / 3.6f), height / 2 + Message.strSize / 2);
			}
		}
	}
	void MESSAGE::upperMessage(const char* str) {
		Messages.emplace_back(Mes{ str,0,SHOW });
	}
	void MESSAGE::resetMessage() {
		Messages.clear();
	}
}