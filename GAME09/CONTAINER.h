#pragma once
#include "TITLE.h"
#include "SELECT.h"

namespace GAME09
{
	class CONTAINER
	{
		struct DATA {
			TITLE::DATA title;
			SELECT::DATA select;
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