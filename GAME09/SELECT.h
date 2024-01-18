#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class SELECT :
        public SCENE
    {
    public:
        struct DATA {
            int a;
        };
    private:
        DATA Select;
    public:
        SELECT(class GAME* game);
        ~SELECT();
        void create();
        void draw();
        void nextScene();
    };
}