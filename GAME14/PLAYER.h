#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class PLAYER :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img = 0;
            COLOR color = COLOR(0);
            VECTOR2 pos = VECTOR2(0, 0);
            VECTOR2 scale = VECTOR2(0, 0);
            float vec = 0;
            float speed = 0;
            float jumpSpeed = 0;
            float gravity = 0;
            float highLimt = 0;
            bool farstJumpFlag = true;
            bool doubleJumpFlag = true;
            VECTOR2 range1 = VECTOR2(0, 0);//‘«Œ³‚Ì“–‚½‚è”»’è
            VECTOR2 range2 = VECTOR2(0, 0);//‘¤–Ê‚Ì“–‚½‚è”»’è
            bool collisionFlag = false;
        };
    private:
        DATA Player;
    public:
        PLAYER(class GAME* game);
        void create();
        void init();
        void update();
        void draw();
        void jump();
        VECTOR2 pos() { return Player.pos; }
        VECTOR2 range1() { return Player.range1; }
        VECTOR2 range2() { return Player.range2; }
        void setY(float y) { Player.pos.y = y; }
        void setX(float x) { Player.pos.x = x; }
        void setFJFlag(bool flag) { Player.farstJumpFlag = flag; }
        bool setDJFlag(bool flag) { Player.doubleJumpFlag = flag; }
    };
}

