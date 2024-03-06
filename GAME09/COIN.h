#pragma once
#include "GAME_OBJECT.h"
#include "LINE.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class COIN :
        public GAME_OBJECT
    {
	public:
		struct DATA {
			int img;
			float imgSize;
			VECTOR2 startPos;
			VECTOR2 startV; //����
			float radius;
			float friction; //���C�W��
			float limmitV;  //���x�̏Փ˕��������̏���l

			float sw;       //���̑���
		};
	private:
		DATA Coin;
		VECTOR2 Pos;    //�d�S�ʒu
		VECTOR2 V;      //���x
		float Theta;    //��]�p�x
		float Omega;    //�p���x
		float M;        //����
		float I;        //�������[�����g
		float R;        //���a

		bool Active;

		//������Ԃ�(���Ȃ�1�A0�Ȃ�0�A���Ȃ�-1)
		int Sign(float A) {
			return (A > 0) - (A < 0);
		}

		//�������ق��̒l��Ԃ�
		float Min(float a, float b) {
			return a < b ? a : b;
		}
	public:
		COIN(class GAME* game);
        ~COIN();
        void create();
        void init();
		void update();
		void draw();
		void addImpulseLocal(const VECTOR2& impulse, const VECTOR2& addLocalPos);
		void addImpulse(const VECTOR2& impulse, const VECTOR2& addPos);
		void applyForce(const VECTOR2& force);
		void collisionWalls(std::vector<LINE>& walls);
		
		void setActive(bool active) { Active = active; }
		bool active() { return Active; }
		VECTOR2 getPos() { return Pos; }
    };
}