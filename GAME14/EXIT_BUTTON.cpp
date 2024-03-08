#include "EXIT_BUTTON.h"
#include"CONTAINER.h"
#include"GAME14.h"
namespace GAME14 {
    EXIT_BUTTON::EXIT_BUTTON(class GAME* game):
        BUTTON(game){}
    EXIT_BUTTON::~EXIT_BUTTON(){}
    void EXIT_BUTTON::create(int* serectId){
        Button = game()->container()->data().exit_button;
        Button.serectId = serectId;

    }

}