#pragma once
#include "SCENE.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class TITLE :
        public SCENE
    {
    public:
        struct DATA {
            char titleStr[64] = {};
            int img = 0;
            COLOR textColor = COLOR(0);
            VECTOR2 pos = VECTOR2(0, 0);
            int textSize = 0;

        };
    private:
        struct DATA Title;
    public:
        TITLE(class GAME* game);
        void create();
        void update();
        void draw();
        void nextScene();
    };
}

