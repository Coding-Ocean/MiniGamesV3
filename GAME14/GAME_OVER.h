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
            int img;
            VECTOR2 imgPos;
            float imgSize;
            char str[64];
            COLOR textColor;
            VECTOR2 pos;
            int textSize;
            COLOR backColor;
            COLOR rectColor;
            VECTOR2 rectSize;
        };
    private:
        struct DATA Game_Over;
        class RETRY_BUTTON* Retry;
        class TITLE_BUTTON* Title;
        class EXIT_BUTTON* Exit;
        int SerectId;

    public:
        GAME_OVER(class GAME* game);
        ~GAME_OVER();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();

    };
}

