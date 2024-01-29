#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class AROUNDJAPAN :
        public SCENE
    {
    public:
        struct DATA {
            int img;
        };
    private:
        DATA AroundJapan;
    public:
        AROUNDJAPAN(class GAME* game);
        ~AROUNDJAPAN();
        void init();
        void create();
        void update();
        void draw();
        void nextScene();
    };
}