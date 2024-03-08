#include "HOLE.h"
#include "../../libOne/inc/graphic.h"

namespace GAME09 {
	HOLE::HOLE(GAME* game, VECTOR2 pos):
		GAME_OBJECT(game){
		Pos = pos;
	}
	HOLE::~HOLE(){
	
	}
	void HOLE::draw() {
		stroke(255, 0, 0);
		strokeWeight(5);
		point(Pos.x, Pos.y);
	}
}