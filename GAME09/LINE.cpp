#include "LINE.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09
{
	LINE::LINE(class GAME* game, VECTOR2 sp, VECTOR2 ep) :
		GAME_OBJECT(game) {
		SP = sp;
		EP = ep;
		V = EP - SP;
		N = VECTOR2(-V.y, V.x);
		N.normalize();

		Sw = 2;
	}
	LINE::~LINE() {

	}
	void LINE::draw() {
		strokeWeight(Sw);
		stroke(255,0,0);
		line(SP.x, SP.y, EP.x, EP.y);
	}
	VECTOR2 LINE::closest(VECTOR2 p) {
		VECTOR2 v1 = p - SP;
		VECTOR2 v2 = p - EP;
		if (N.cross(v1) < 0 && N.cross(v2) > 0) {
			return SP + V.normalize() * -N.cross(v1);
		}
		else if (N.cross(v1) > 0) {
			return SP;
		}
		else {
			return EP;
		}
	}
	const VECTOR2& LINE::n() {
		return N;
	}
	const VECTOR2& LINE::v() {
		return V;
	}
	const VECTOR2& LINE::sp() {
		return SP;
	}
	const VECTOR2& LINE::ep() {
		return EP;
	}
}