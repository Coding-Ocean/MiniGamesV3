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
            int fieldImg;
            int fieldFrameImg;
            int inletImg;
            float imgSize;
            VECTOR2 imgPos;
            VECTOR2 winTextPos;
            VECTOR2 loseTextPos;
            float textSize;
        };
    private:
        DATA AroundJapan;
        class PHYSICS_ENGINE_AJ* Physics;
        class GAUGE* Gauge;
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