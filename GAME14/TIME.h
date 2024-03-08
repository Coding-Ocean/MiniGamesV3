#pragma once
#include"..//..//libOne/inc/VECTOR2.h"
#include"..//..//libOne/inc/COLOR.h"
#include "GAME_OBJECT.h"
namespace GAME14 {

    class TIME :
        public GAME_OBJECT {
    public:
        struct DATA {
            VECTOR2 timeTextPos;
            VECTOR2 timePos;
            COLOR timeColor;
            char timeStr[32];
            int maxDigit;
            float timeTextSize;
            float limitTime;
            float reduceTime;
        };
    private:
        DATA Time;
        bool Flag = false;
    public:
        TIME(class GAME* game);
        ~TIME();
        void create();
        void init();
        void update();
        void draw();
        bool timeUp();

        
    };
}

