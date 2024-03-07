#include "GAME09.h"
#include "CONTAINER.h"
#include "PHYSICS_ENGINE_AJ.h"
#include "COIN.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/mathUtil.h"
#include <fstream>

namespace GAME09
{
	PHYSICS_ENGINE_AJ::PHYSICS_ENGINE_AJ(class GAME* game) :
		GAME_OBJECT(game) {

	}
	PHYSICS_ENGINE_AJ::~PHYSICS_ENGINE_AJ() {
		delete WinHole;
		delete Coin;
	}
	void PHYSICS_ENGINE_AJ::create() {
		Physics = game()->container()->data().phisicsAj;
		Coin = new COIN(game());
		WinHole = new HOLE(game(),Physics.winHolePos);
		Coin->create();
		CreateWalls();
		CreateHoles();
	}
	void PHYSICS_ENGINE_AJ::init() {
		Gravity = Physics.gravity;
		Coin->init();
		Win = 0;
		Lose = 0;
	}
	void PHYSICS_ENGINE_AJ::update() {
		Coin->applyForce(Gravity * delta);
		Coin->update();
		Coin->collisionWalls(Walls);
		int result = Coin->collisionHoles(Holes, WinHole);
		if (result == 1) {
			Win++;
		}
		else if(result == -1){
			Lose++;
		}
	}
	void PHYSICS_ENGINE_AJ::draw() {
		Coin->draw();
		//for (auto it = Holes.begin(); it != Holes.end(); it++) {
		//	(*it).draw();
		//}
	}
	void PHYSICS_ENGINE_AJ::addForceToCoin(float Power){
		float CenterToCoin = Coin->getPos().x - width / 2;
		float range = Physics.distanceWall - Physics.coinSize - Physics.tolerance;
		if (CenterToCoin > range) {
			Coin->applyForce(VECTOR2(-Power * Physics.powerDiameter, 0));
		}
		else if (CenterToCoin < -range) {
			Coin->applyForce(VECTOR2(Power * Physics.powerDiameter, 0));
		}
	}
	void PHYSICS_ENGINE_AJ::CreateWalls(){
		std::ifstream file;
		file.open(Physics.wallDataFileName, std::ios::in);
		std::string buffer;
		std::vector<float> rawData;

		while (std::getline(file, buffer)) {
			for (int i = 0; i < 4; i++) {
				std::string content = buffer.substr(0, buffer.find(','));
				rawData.emplace_back(std::stof(content));
				buffer = buffer.substr(buffer.find(',') + 1);
			}
		}
		for (int i = 0; i < rawData.size() / 4; i++) {
			VECTOR2 sp(rawData[i * 4], rawData[i * 4 + 1]);
			VECTOR2 ep(rawData[i * 4 + 2], rawData[i * 4 + 3]);
			Walls.emplace_back(game(), sp, ep);
		}
	}
	void PHYSICS_ENGINE_AJ::CreateHoles() {
		std::ifstream file;
		file.open(Physics.holeDataFileName, std::ios::in);
		std::string buffer;
		std::vector<float> rawData;

		while (std::getline(file, buffer)) {
			for (int i = 0; i < 2; i++) {
				std::string content = buffer.substr(0, buffer.find(','));
				rawData.emplace_back(std::stof(content));
				buffer = buffer.substr(buffer.find(',') + 1);
			}
		}
		for (int i = 0; i < rawData.size() / 2; i++) {
			VECTOR2 pos(rawData[i * 2], rawData[i * 2 + 1]);
			Holes.emplace_back(game(), pos);
		}
	}
}