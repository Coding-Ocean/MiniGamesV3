#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
	class HOLE :
		public GAME_OBJECT
	{
	private:
		VECTOR2 Pos;
	public:
		HOLE(class GAME* game, VECTOR2 pos);
		~HOLE();
		void draw();

		VECTOR2 getPos() { return Pos; }
	};
}