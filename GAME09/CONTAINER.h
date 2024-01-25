#pragma once
#include "TITLE.h"
#include "SELECT.h"
#include "FADE.h"
#include "MESSAGE.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			SELECT::DATA select;
			FADE::DATA fade;
			MESSAGE::DATA message;
		};
		DATA Data;
	public:
		void load();
		void setData();
		const DATA& data() {
			return Data;
		}
	};
}