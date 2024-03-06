#pragma once
#include "GAME_OBJECT.h"
#include "LINE.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class COIN :
        public GAME_OBJECT
    {
	public:
		struct DATA {
			int img;
			float imgSize;
			VECTOR2 startPos;
			VECTOR2 startV; //‰‘¬
			float radius;
			float friction; //–€ŽCŒW”
			float limmitV;  //‘¬“x‚ÌÕ“Ë•ûŒü¬•ª‚ÌãŒÀ’l

			float sw;       //ü‚Ì‘¾‚³
		};
	private:
		DATA Coin;
		VECTOR2 Pos;    //dSˆÊ’u
		VECTOR2 V;      //‘¬“x
		float Theta;    //‰ñ“]Šp“x
		float Omega;    //Šp‘¬“x
		float M;        //Ž¿—Ê
		float I;        //Šµ«ƒ‚[ƒƒ“ƒg
		float R;        //”¼Œa

		bool Active;

		//•„†‚ð•Ô‚·(³‚È‚ç1A0‚È‚ç0A•‰‚È‚ç-1)
		int Sign(float A) {
			return (A > 0) - (A < 0);
		}

		//¬‚³‚¢‚Ù‚¤‚Ì’l‚ð•Ô‚·
		float Min(float a, float b) {
			return a < b ? a : b;
		}
	public:
		COIN(class GAME* game);
        ~COIN();
        void create();
        void init();
		void update();
		void draw();
		void addImpulseLocal(const VECTOR2& impulse, const VECTOR2& addLocalPos);
		void addImpulse(const VECTOR2& impulse, const VECTOR2& addPos);
		void applyForce(const VECTOR2& force);
		void collisionWalls(std::vector<LINE>& walls);
		
		void setActive(bool active) { Active = active; }
		bool active() { return Active; }
		VECTOR2 getPos() { return Pos; }
    };
}