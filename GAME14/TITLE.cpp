#include"GAME14.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include "TITLE.h"
namespace GAME14 {
    TITLE::TITLE(class GAME* game) :
        SCENE(game) {}
    void TITLE::create(){
        Title = game()->container()->data().title;
    }
    void TITLE::update(){
    }
    void TITLE::draw(){
        clear(255);
        fill(Title.textColor);
        textSize(Title.textSize);
        text(Title.titleStr, Title.pos.x, Title.pos.y);
    }
    void TITLE::nextScene(){
        if (isTrigger(KEY_SPACE)) {
            game()->changeScene(game()->GAME::STAGE_ID);
        }
    }

}