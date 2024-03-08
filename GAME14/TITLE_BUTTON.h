#pragma once
#include "BUTTON.h"
namespace GAME14 {
    class TITLE_BUTTON :
        public BUTTON{
    private:
    public:
        TITLE_BUTTON(class GAME* game);
        ~TITLE_BUTTON();
        void create(int* serectId);
    };
}

