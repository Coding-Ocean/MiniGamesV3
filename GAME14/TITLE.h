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
            COLOR backColor;
            COLOR rectColor;
            VECTOR2 rectSize;
            float animeTime;

        };
    private:
        struct DATA Title;
        class START_BUTTON* Start;
        class EXIT_BUTTON* Exit;
        class CREDIT_BUTTON* Credit;
        int SerectId;
        float AnimeTime;
        float ColorA;
        bool FadeStart;
        bool FadeEnd;
        bool SceneMove;
    public:
        TITLE(class GAME* game);
        ~TITLE();
        void create();
        void init();
        void update();
        void draw();
        void nextScene();
        void fade();
    };
}

