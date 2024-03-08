#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class PLAYER :
        public GAME_OBJECT
    {
    public:
        enum STATE {
            ANIM,
            STAY,
            FALL,
            COLLISION,
            DOUBLEJUMP,
            CLEAR
        };
        struct DATA {
            int img ;
            float imgSize;
            int jumpImg ;
            float jumpImgSize;
            int eImg;
            float eImgSize;
            COLOR color ;
            VECTOR2 pos ;
            VECTOR2 targetPos;
            float stayWaid;
            VECTOR2 scale ;
            float speed ;
            float animeSpeed;
            float jumpSpeed ;
            float gravity ;
            float highLimt;
            bool farstJumpFlag ;
            bool doubleJumpFlag ;
            VECTOR2 range1 ;//‘«Œ³‚Ì“–‚½‚è”»’è
            VECTOR2 range2 ;//‘¤–Ê‚Ì“–‚½‚è”»’è
            bool collisionFlag ;
            float enterAnimeTime;
            float jumpAnimeTime;
            float stPosX;
            float stPosY;
        };
    private:
        DATA Player;
        STATE CurState;
        int CurImg;
        float CurImgSize;
        float AnimeTime;
        float Angle;
        float BeforWait;
        VECTOR2 EPos{ 0,0 };
        bool Life;
        bool Stay;
    public:
        PLAYER(class GAME* game);
        void create();
        void init();
        void update();
        void draw();
        void jump(bool* flag);
        void eAnime(VECTOR2 targetPos,float time = 0,float speed = 0);
        VECTOR2 pos() { return Player.pos; }
        VECTOR2 range1() { return Player.range1; }
        VECTOR2 range2() { return Player.range2; }
        VECTOR2 scale() { return Player.scale; }
        bool getStay() { return Stay; }
        bool checkAlive(){ return Life; }
        void setY(float y) { Player.pos.y = y; }
        void setX(float x) { Player.pos.x = x; }
        void setFJFlag(bool flag) { Player.farstJumpFlag = flag; }
        void setDJFlag(bool flag) { Player.doubleJumpFlag = flag; }
    };
}

