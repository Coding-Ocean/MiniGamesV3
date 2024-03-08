#include"CONTAINER.h"
#include"GAME14.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "CREDIT.h"
namespace GAME14 {
    CREDIT::CREDIT(class GAME* game):
        SCENE(game){}
    CREDIT::~CREDIT(){}
    void CREDIT::create(){
        Credit = game()->container()->data().credit;
    }
    void CREDIT::draw(){
        clear(Credit.backColor);
        fill(Credit.textColor);
        textSize(Credit.textSize);
        text(Credit.nStr1, Credit.nStrPos.x, Credit.nStrPos.y);
        text(Credit.nStr2, Credit.nStrPos.x, Credit.nStrPos.y+300);
        text(Credit.uStr1, Credit.uStrPos.x, Credit.uStrPos.y);
        text(Credit.uStr2, Credit.uStrPos.x, Credit.uStrPos.y+300);

    }
    void CREDIT::nextScene(){
        if (isTrigger(KEY_SPACE)) {
            game()->changeScene(GAME::TITLE_ID);
        }
    }

}