#pragma once
#include "SCENE.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class GAME_OVER :
        public SCENE
    {
    public:
        struct DATA {
            int img = 0;
            char str[64] = {};
            COLOR textColor = COLOR(0, 0, 0);
            VECTOR2 pos = VECTOR2(0, 0);
            int textSize = 0;

        };
    private:
        struct DATA Game_Over;
    public:
        GAME_OVER(class GAME* game);
        void create();
        void update();
        void draw();
        void nextScene();

    };
}

