#include "GAME_OVER.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"RETRY_BUTTON.h"
#include"TITLE_BUTTON.h"
#include"EXIT_BUTTON.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"

namespace GAME14 {
    GAME_OVER::GAME_OVER(class GAME* game) :
        SCENE(game) {

    }
    GAME_OVER::~GAME_OVER() {
        delete Exit;
        delete Title;
        delete Retry;

    }

    void GAME_OVER::create(){
        Game_Over = game()->container()->data().game_over;
        Retry = new RETRY_BUTTON(game());
        Title = new TITLE_BUTTON(game());
        Exit = new EXIT_BUTTON(game());
        SerectId = BUTTON::RETRY;
        Retry->create(&SerectId);
        Title->create(&SerectId);
        Exit->create(&SerectId);

    }
    void GAME_OVER::init(){
        SerectId = BUTTON::RETRY;

    }
    void GAME_OVER::update(){
        if (isTrigger(KEY_DOWN)) {
            switch (SerectId) {
            case BUTTON::RETRY:
                SerectId = BUTTON::TITLE;
                break;
            case BUTTON::TITLE:
                SerectId = BUTTON::EXIT;
                break;
            case BUTTON::EXIT:
                SerectId = BUTTON::RETRY;
                break;
            }
        }
        else if (isTrigger(KEY_UP)) {
            switch (SerectId) {
            case BUTTON::RETRY:
                SerectId = BUTTON::EXIT;
                break;
            case BUTTON::TITLE:
                SerectId = BUTTON::RETRY;
                break;
            case BUTTON::EXIT:
                SerectId = BUTTON::TITLE;
                break;
            }
        }

    }
    void GAME_OVER::draw(){
        clear(Game_Over.backColor);
        game()->player()->draw();
        game()->building()->draw();
        fill(Game_Over.rectColor);
        rect(0, 0, Game_Over.rectSize.x, Game_Over.rectSize.y);
        rectMode(CENTER);
        image(Game_Over.img, Game_Over.imgPos.x, Game_Over.imgPos.y, 0, Game_Over.imgSize);
        fill(Game_Over.textColor);
        textSize(Game_Over.textSize);
        text(Game_Over.str, Game_Over.pos.x, Game_Over.pos.y);
        Retry->draw();
        Title->draw();
        Exit->draw(0, 100);
        rectMode(CORNER);

    }
    void GAME_OVER::nextScene(){
        if (isTrigger(KEY_SPACE)) {
            Retry->scene_move();
            Title->scene_move();
            Exit->scene_move();
        }

    }

}