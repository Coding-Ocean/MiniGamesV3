#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class BINGO :
        public SCENE
    {
    public:
        struct DATA {
            int img;
        };
    private:
        DATA Bingo;
    public:
        BINGO(class GAME* game);
        ~BINGO();
        void init();
        void create();
        void update();
        void draw();
        void nextScene();
    };
}