#pragma once
#include "GAME_OBJECT.h"
#include "LINE.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>
#include <string>

namespace GAME09
{
    class PHYSICS_ENGINE_AJ :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            VECTOR2 gravity;
            std::string wallDataFileName;
            float distanceWall;
            float coinSize;
            float tolerance;
            float powerDiameter;
        };
    private:
        DATA Physics;
        class COIN* Coin;
        VECTOR2 Gravity = VECTOR2(0, 1000);
        std::vector<LINE> Walls;
        void CreateWalls();
    public:
        PHYSICS_ENGINE_AJ(class GAME* game);
        ~PHYSICS_ENGINE_AJ();
        void create();
        void init();
        void update();
        void draw();

        void addForceToCoin(float Power);
    };
}