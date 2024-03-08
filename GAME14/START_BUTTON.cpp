#include "START_BUTTON.h"
#include"CONTAINER.h"
#include"GAME14.h"
namespace GAME14 {
    START_BUTTON::START_BUTTON(class GAME* game):
        BUTTON(game){}
    START_BUTTON::~START_BUTTON(){}
    void START_BUTTON::create(int* serectId){
        Button = game()->container()->data().start_button;
        Button.serectId = serectId;

    }

}