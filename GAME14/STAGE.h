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
            int img = 0;
            COLOR backColor = 0;
            bool flag = false;
            float cnt = 0;
        };
    private:
        struct DATA Stage;
    public:
        STAGE(class GAME* game);
        void create();
        void update();
        void draw();
        void nextScene();

    };
}

