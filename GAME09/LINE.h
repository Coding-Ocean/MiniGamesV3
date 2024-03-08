#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class LINE :
        public GAME_OBJECT
    {
	private:
		VECTOR2 SP;//�n�_
		VECTOR2 EP;//�I�_
		VECTOR2 V; //�n�_����I�_�̃x�N�g��
		VECTOR2 N; //�P�ʖ@���x�N�g��

		float Sw; //���̑���
	public:
		LINE(class GAME* game,VECTOR2 sp, VECTOR2 ep);
        ~LINE();
        void draw();

		VECTOR2 closest(VECTOR2 p);
		const VECTOR2& n();
		const VECTOR2& v();
		const VECTOR2& sp();
		const VECTOR2& ep();
    };
}