#pragma once
#include "TITLE.h"
#include "SELECT.h"
#include "FADE.h"
#include "MESSAGE.h"
#include "AROUNDJAPAN.h"
#include "BINGO.h"
#include "BACKBUTTON.h"
#include "BACKGROUND.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			SELECT::DATA select;
			FADE::DATA fade;
			MESSAGE::DATA message;
			AROUNDJAPAN::DATA aroundJapan;
			BINGO::DATA bingo;
			BACKBUTTON::DATA back;
			BACKGROUND::DATA backG;
		};
		DATA Data;
	public:
		void load();
		void setData();
		void loadGraphic();
		const DATA& data() {
			return Data;
		}
	};
}