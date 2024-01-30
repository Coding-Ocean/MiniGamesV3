#pragma once
#include "GAME_OBJECT.h"
#include "../../libOne/inc/VECTOR2.h"

namespace GAME09
{
    class BACKBUTTON :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            int img;
            VECTOR2 pos;
        };
    private:
        DATA Back;
    public:
        BACKBUTTON(class GAME* game);
        ~BACKBUTTON();
        void create();
        void proc();
    };
}
