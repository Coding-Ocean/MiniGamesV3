#pragma once
#include "SCENE.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class STAGE :
        public SCENE
    {
    public:
        struct DATA {
            int img ;
            COLOR backColor ;
            float cnt = 0;
            float animeTime;
            COLOR rectColor;
            VECTOR2 rectSize;

        };
    private:
        struct DATA Stage;
        class TIME* Time;
        float AnimeTime;
        float ColorA;
        bool Flag = false;
        bool FadeStart;
        bool FadeEnd;
    public:
        STAGE(class GAME* game);
        ~STAGE();
        void init();
        void create();
        void update();
        void draw();
        void nextScene();
        void fade();
        void setFlag(bool flag) { Flag = flag; }
        class TIME* time() { return Time; }

    };
}

