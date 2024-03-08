#pragma once
#include"PLAYER.h"
#include"BUILDING.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"CREDIT.h"
#include"TIME.h"
#include"BUTTON.h"
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
			GAME14::CREDIT::DATA credit;
			GAME14::TIME::DATA time;
			GAME14::BUTTON::DATA title_button;
			GAME14::BUTTON::DATA start_button;
			GAME14::BUTTON::DATA retry_button;
			GAME14::BUTTON::DATA exit_button;
			GAME14::BUTTON::DATA credit_button;
		};
		DATA Data;
		void setData();
		void setImage();
	public:
		void load();
		const DATA& data() { return Data; }
	};
}

