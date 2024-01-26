#pragma once
#include"PLAYER.h"
#include"BUILDING.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"GAME14.h"
namespace GAME14 {
	class CONTAINER
	{
		struct DATA {
			GAME14::PLAYER::DATA player;
			GAME14::BUILDING::DATA building;
			GAME14::TITLE::DATA title;
			GAME14::STAGE::DATA stage;
			GAME14::GAME_CLEAR::DATA game_clear;
			GAME14::GAME_OVER::DATA game_over;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		const DATA& data() { return Data; }
	};
}

