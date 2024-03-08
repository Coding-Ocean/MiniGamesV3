#include "GAME_CLEAR.h"
#include"GAME14.h"
#include"CONTAINER.h"
#include"BUILDING.h"
#include"RETRY_BUTTON.h"
#include"TITLE_BUTTON.h"
#include"EXIT_BUTTON.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"

namespace GAME14 {
    GAME_CLEAR::GAME_CLEAR(class GAME* game):
        SCENE(game){}
    GAME_CLEAR::~GAME_CLEAR() {
        delete Exit;
        delete Title;
        delete Retry;
    }

    void GAME_CLEAR::create(){
        Game_Clear = game()->container()->data().game_clear;
        Retry = new RETRY_BUTTON(game());
        Title = new TITLE_BUTTON(game());
        Exit = new EXIT_BUTTON(game());
        SerectId = BUTTON::RETRY;
        Retry->create(&SerectId);
        Title->create(&SerectId);
        Exit->create(&SerectId);
    }
    void GAME_CLEAR::init(){
        SerectId = BUTTON::RETRY;
    }
    void GAME_CLEAR::update(){
        game()->building()->update();
        game()->player()->update();
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
    void GAME_CLEAR::draw(){
        clear(Game_Clear.backColor);
        game()->player()->draw();
        game()->building()->draw();
        rectMode(CENTER);
        image(Game_Clear.img,Game_Clear.imgPos.x,Game_Clear.imgPos.y, 0, Game_Clear.imgSize);
        fill(Game_Clear.textColor);
        textSize(Game_Clear.textSize);
        text(Game_Clear.str, Game_Clear.pos.x, Game_Clear.pos.y);
        Retry->draw();
        Title->draw();
        Exit->draw(0,100);
        rectMode(CORNER);
    }
    void GAME_CLEAR::nextScene(){
        if(isTrigger(KEY_SPACE)){
        Retry->scene_move();
        Title->scene_move();
        Exit->scene_move();
       }

    }


}