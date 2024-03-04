#pragma once
#include "GAME_OBJECT.h"
#include "LINE.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class PHYSICS_ENGINE_AJ :
        public GAME_OBJECT
    {
    private:
        class COIN* Coin;
        VECTOR2 Gravity = VECTOR2(0, 1000);
        std::vector<LINE> Walls;
    public:
        PHYSICS_ENGINE_AJ(class GAME* game);
        ~PHYSICS_ENGINE_AJ();
        void create();
        void init();
        void update();
        void draw();
    };
}