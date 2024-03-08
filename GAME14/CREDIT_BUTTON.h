#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class CREDIT_BUTTON :
        public BUTTON
    {
    public:
        CREDIT_BUTTON(class GAME* game);
        ~CREDIT_BUTTON();
        void create(int* serectId);
    };
}

