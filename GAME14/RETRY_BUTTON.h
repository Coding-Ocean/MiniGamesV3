#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class RETRY_BUTTON :
        public BUTTON
    {
    public:
        RETRY_BUTTON(class GAME* game);
        ~RETRY_BUTTON();
        void create(int* serectId);
    };
}

