#include "RETRY_BUTTON.h"
#include"CONTAINER.h"
#include"GAME14.h"
namespace GAME14 {
    RETRY_BUTTON::RETRY_BUTTON(class GAME* game):
        BUTTON(game){}
    RETRY_BUTTON::~RETRY_BUTTON(){}
    void RETRY_BUTTON::create(int* serectId){
        Button = game()->container()->data().retry_button;
        Button.serectId = serectId;
    }

}