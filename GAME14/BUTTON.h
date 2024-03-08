#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include"GAME14.h"
#include "GAME_OBJECT.h"
namespace GAME14 {
    class BUTTON :
        public GAME_OBJECT {
    public:
        enum BUTTON_ID {
            START = GAME::STAGE_ID,
            CREDIT = GAME::CREDIT_ID,
            EXIT,
            TITLE = GAME::TITLE_ID,
            RETRY = GAME::STAGE_ID,
        };
        struct DATA {
            int myId;
            int* serectId;
            VECTOR2 pos;
            char buttonName[16];

        };
    protected:
        DATA Button;
        float TextSize = 100.0f;
        COLOR NormalColor = COLOR(125, 125, 125);
        COLOR SerectColor = COLOR(225, 225, 225);
    public:
        BUTTON(class GAME* game);
        ~BUTTON();
        virtual void create();
        virtual void draw(float x=0,float y=0);
        virtual void scene_move();
        int getMyId() { return Button.myId; }
        int getSerectId() { return *Button.serectId; }
    };
}
