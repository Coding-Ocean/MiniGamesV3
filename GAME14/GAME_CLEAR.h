#pragma once
#include "SCENE.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"

namespace GAME14 {
    class GAME_CLEAR :
        public SCENE
    {
    public:
        struct DATA {
            int img;
            VECTOR2 imgPos;
            float imgSize;
            char str[64];
            COLOR textColor ;
            VECTOR2 pos ;
            int textSize;
            COLOR backColor;

        };
    private:
        struct DATA Game_Clear;
        class RETRY_BUTTON* Retry;
        class TITLE_BUTTON* Title;
        class EXIT_BUTTON* Exit;
        int SerectId;
    public:
        GAME_CLEAR(class GAME* game);
        ~GAME_CLEAR();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();


    };
}

