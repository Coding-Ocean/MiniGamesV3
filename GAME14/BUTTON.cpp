#include "BUTTON.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
namespace GAME14 {
    BUTTON::BUTTON(class GAME* game):
        GAME_OBJECT(game){}
    BUTTON::~BUTTON(){}
    void BUTTON:: create(){
        
    }
    void BUTTON:: draw(float x ,float y){
        
        if (Button.myId == *Button.serectId) {
            fill(SerectColor);
        }
        else {
            fill(NormalColor);
        }
        textSize(TextSize);
        text(Button.buttonName, Button.pos.x+x, Button.pos.y+y);
    }
    void BUTTON::scene_move() {

        if (Button.myId == *Button.serectId) {
            if (Button.myId == BUTTON::EXIT) {
                game()->setExitFlag(true);
            }
            else {
                game()->changeScene((GAME::SCENE_ID)Button.myId);
            }
        }

    }

}