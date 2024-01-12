#pragma once
#include"GAME14.h"
namespace GAME14 {
	class CONTAINER
	{
		struct DATA {
			GAME14::GAME::PLAYER player;
			GAME14::GAME::BUILDING building;
			GAME14::GAME::TITLE title;
			GAME14::GAME::STAGE stage;
			GAME14::GAME::GAME_CREAR game_crear;
			GAME14::GAME::GAME_OVER game_over;
		};
		DATA Data;
		void setData();
	public:
		void load();
		const DATA& data() { return Data; }
	};
}

