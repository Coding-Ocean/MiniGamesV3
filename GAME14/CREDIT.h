#pragma once
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include "SCENE.h"
namespace GAME14 {
    class CREDIT :
        public SCENE
    {
    public:
        struct DATA {
            char nStr1[32];
            char nStr2[32];
            char uStr1[64];
            char uStr2[64];
            VECTOR2 nStrPos;
            VECTOR2 uStrPos;
            COLOR textColor;
            float textSize;
            COLOR backColor;
        };
    private:
        DATA Credit;
    public:
        CREDIT(class GAME* game);
        ~CREDIT();
        void create();
        void draw();
        void nextScene();
    };
}

