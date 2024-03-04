#include "PHYSICS_ENGINE_AJ.h"
#include "COIN.h"
#include "../../libOne/inc/window.h"

namespace GAME09
{
	PHYSICS_ENGINE_AJ::PHYSICS_ENGINE_AJ(class GAME* game) :
		GAME_OBJECT(game) {

	}
	PHYSICS_ENGINE_AJ::~PHYSICS_ENGINE_AJ() {
		delete Coin;
	}
	void PHYSICS_ENGINE_AJ::create() {
		Coin = new COIN(game());
		Coin->create();
	}
	void PHYSICS_ENGINE_AJ::init() {
		Coin->init();
	}
	void PHYSICS_ENGINE_AJ::update() {
		Coin->applyForce(Gravity * delta);
		Coin->update();
		Coin->collisionWalls(Walls);
	}
	void PHYSICS_ENGINE_AJ::draw() {
		Coin->draw();
	}
}