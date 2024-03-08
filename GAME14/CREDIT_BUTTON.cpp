#include "CREDIT_BUTTON.h"
#include"CONTAINER.h"
#include"GAME14.h"
namespace GAME14 {
    CREDIT_BUTTON::CREDIT_BUTTON(class GAME* game):
        BUTTON(game){}
    CREDIT_BUTTON::~CREDIT_BUTTON(){}
    void CREDIT_BUTTON::create(int* serectId){
        Button = game()->container()->data().credit_button;
        Button.serectId = serectId;

    }

}