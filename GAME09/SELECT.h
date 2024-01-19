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
            int col;
            int row;
            VECTOR2 imgSize;
            VECTOR2 imgOfst;
            VECTOR2 selectOfst;
        };
        enum GAME_ID {
            AroundJapan,
            Bingo,
            Enpty1,
            Enpty2,
            Enpty3,
            Enpty4,
            NUM_GAMES
        };
    private:
        DATA Select;
        class SCENE* Games[NUM_GAMES];
    public:
        SELECT(class GAME* game);
        ~SELECT();
        void create();
        void draw();
        void nextScene();
    };
}