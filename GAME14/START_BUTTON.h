#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class START_BUTTON :
        public BUTTON
    {
    public:
        START_BUTTON(class GAME* game);
        ~START_BUTTON();
        void create(int* serectId);
    };
}

