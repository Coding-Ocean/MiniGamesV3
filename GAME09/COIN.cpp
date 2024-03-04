#include "COIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/mathUtil.h"

namespace GAME09
{
	COIN::COIN(class GAME* game) :
		GAME_OBJECT(game) {

	}
	COIN::~COIN() {

	}
	void COIN::create() {
		Coin = game()->container()->data().coin;
	}
	void COIN::init() {
		Pos = Coin.startPos;
		R = Coin.radius;
		V = VECTOR2(0, 0);
		Theta = 0;
		Omega = 0;
		M = 1;
		I = 0.5f * M * R * R;
	}
	void COIN::update() {
		Pos += V * delta;
		Theta += Omega * delta;
	}
	void COIN::draw() {
		strokeWeight(Coin.sw);
		stroke(255);
		fill(0, 0, 0, 0);
		circle(Pos.x, Pos.y, R * 2);
		line(Pos.x, Pos.y, Pos.x + Cos(Theta) * R, Pos.y + Sin(Theta) * R);
	}
	void COIN::addImpulseLocal(const VECTOR2& impulse, const VECTOR2& addLocalPos) {
		V += impulse / M;
		Omega += addLocalPos.cross(impulse) / I;
	}
	void COIN::addImpulse(const VECTOR2& impulse, const VECTOR2& addPos) {
		addImpulseLocal(impulse, addPos - Pos);
	}
	void COIN::applyForce(const VECTOR2& force) {
		V += force;
	}
	void COIN::collisionWalls(std::vector<LINE>& walls) {
		for (LINE& wall : walls) {
			VECTOR2 subV = Pos - wall.closest(Pos);
			float overlap = R - subV.mag(); //�߂荞��ł��
			if (overlap < 0) continue; //overlap�����Ȃ�Փ�
			VECTOR2 nv = subV.normalize(); //�@���x�N�g��
			Pos += nv * overlap; //�����߂�
			float dotV = -V.dot(nv); //���x�̏Փ˕�������
			if (dotV < 0) continue; //�Փ˕����Ɍ����Ă��Ȃ��Ȃ疳��
			VECTOR2 tan = VECTOR2(-nv.y, nv.x); //�ڐ��̕����x�N�g��
			VECTOR2 fDir = -Sign(V.dot(tan) - R * Omega) * tan; //���C�̕����x�N�g��
			addImpulseLocal((nv + fDir * Coin.friction) *
				Min(dotV, Coin.limmitV) * M, -nv * R);//���C�{��������
		}
	}
}