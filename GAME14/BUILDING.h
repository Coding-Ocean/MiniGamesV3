#pragma once
#include "GAME_OBJECT.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
namespace GAME14 {
    class BUILDING :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img = 0;
            VECTOR2 pos = VECTOR2(0, 0);
            float posOfset = 0;
            float speed = 0;
            int minHight = 0;
            int minWide = 0;
            int maxHight = 0;
            int maxWide = 0;
            COLOR color = COLOR(0);
            int maxBuilding = 0;
        };
        struct BUILDINGS {
            VECTOR2 pos = VECTOR2(0, 0);
            VECTOR2 scale = VECTOR2(0, 0);
        };
    private:
        struct DATA Building;
        struct BUILDINGS* Buildings= nullptr;
    public:
        BUILDING(class GAME* game);
        ~BUILDING();
        void create();
        void init();
        void reScale(int i);
        void update();
        bool collision();
        void draw();
        int maxBuilding() { return Building.maxBuilding; }
        BUILDINGS* buildings() { return Buildings; }
        float speed() { return Building.speed; }
    };
}

