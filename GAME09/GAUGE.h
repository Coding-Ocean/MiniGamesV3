#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
	class GAUGE :
		public GAME_OBJECT
	{
	public:
		struct DATA {
			int buttonImg;
			int frameImg;
			VECTOR2 buttonPos;
			VECTOR2 framePos;
			float buttonSize;
			float frameSize;
			VECTOR2 gaugeSize;
			float buttonRadius;
			int hueMin;
			int hueMax;
			int powerSpeed;
			int powerMax;
			int powerMin;
		};
		enum STATE {
			UP,
			DOWN,
			STOP
		};
	private:
		DATA Gauge;
		float Power;
		STATE State;
		float ReturnPower;

		bool Collision();
	public:
		GAUGE(class GAME* game);
		~GAUGE();
		void create();
		void init();
		void update();
		void draw();

		float getPower() { return ReturnPower; }
	};
}