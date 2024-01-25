#pragma once
#include "GAME_OBJECT.h"
#include <vector>
#include <string>
#include "../../libOne/inc/VECTOR2.h"
#include "../../libOne/inc/COLOR.h"

namespace GAME09
{
    class MESSAGE :
        public GAME_OBJECT
    {
    public:
        struct DATA {
            float showTime;
            float fadeTime;
            float strSize;
            COLOR strColor;
            VECTOR2 rectSize;
            COLOR rectColor;
        };
    private:
        DATA Message;
        enum STATE_ID {
            SHOW,
            FADE,
            END
        };
        struct Mes{
            std::string str;
            float time;
            STATE_ID state;
        };
        std::vector<Mes> Messages;
    public:
        MESSAGE(class GAME* game);
        ~MESSAGE();
        void create();
        void proc();
        void upperMessage(const char* str);
    };
}
