#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class LINE :
        public GAME_OBJECT
    {
	private:
		VECTOR2 SP;//始点
		VECTOR2 EP;//終点
		VECTOR2 V; //始点から終点のベクトル
		VECTOR2 N; //単位法線ベクトル

		float Sw; //線の太さ
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