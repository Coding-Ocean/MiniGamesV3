#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class TITLE :
        public SCENE
    {
    public:
        struct DATA {
            COLOR textColor;
            COLOR textStrokeColor;
            float textStrokeRate;
            float titleSize;
            float startSize;
            VECTOR2 titlePos;
            VECTOR2 startPos;
            char titleStr[32];
            char startStr[32];
        };
    private:
        DATA Title;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void draw();
        void nextScene();
    };
}