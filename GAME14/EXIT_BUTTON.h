#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class EXIT_BUTTON :
        public BUTTON
    {
    public:
        EXIT_BUTTON(class GAME* game);
        ~EXIT_BUTTON();
        void create(int* serectId);
    };
}

