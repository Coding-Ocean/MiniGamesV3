#include"GAME14.h"
#include"CONTAINER.h"
#include"START_BUTTON.h"
#include"CREDIT_BUTTON.h"
#include"EXIT_BUTTON.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/mathUtil.h"
#include "TITLE.h"
namespace GAME14 {
    TITLE::TITLE(class GAME* game) :
        SCENE(game) {}
    TITLE::~TITLE() {
        delete Exit;
        delete Credit;
        delete Start;
    }
    void TITLE::create(){
        Title = game()->container()->data().title;
        Start = new START_BUTTON(game());
        Credit = new CREDIT_BUTTON(game());
        Exit = new EXIT_BUTTON(game());
        SerectId = BUTTON::START;
        Start->create(&SerectId);
        Credit->create(&SerectId);
        Exit->create(&SerectId);
    }
    void TITLE::init(){
        SerectId = BUTTON::START;
        AnimeTime = 0;
        FadeStart = false;
        FadeEnd = false;
        SceneMove = false;
        ColorA = Title.rectColor.a;
    }
    void TITLE::update(){
        if (isTrigger(KEY_DOWN)) {
            switch (SerectId) {
            case BUTTON::START:
                SerectId = BUTTON::EXIT;
                break;
            case BUTTON::EXIT:
                SerectId = BUTTON::CREDIT;
                break;
            case BUTTON::CREDIT:
                SerectId = BUTTON::START;
                break;
            }
        }
        else if (isTrigger(KEY_UP)) {
            switch (SerectId) {
            case BUTTON::START:
                SerectId = BUTTON::CREDIT;
                break;
            case BUTTON::EXIT:
                SerectId = BUTTON::START;
                break;
            case BUTTON::CREDIT:
                SerectId = BUTTON::EXIT;
                break;
            }

        }
        if (isTrigger(KEY_SPACE)&&SerectId == BUTTON::START) {
            FadeStart = true;
        }
        else if (isTrigger(KEY_SPACE)) {
            SceneMove = true;
        }
       game()->building()->update();

    }
    void TITLE::draw(){
        clear(Title.backColor);
        game()->building()->draw();
        fill(Title.textColor);
        textSize(Title.textSize);
        text(Title.titleStr, Title.pos.x, Title.pos.y);
        Start->draw();
         Exit->draw();
       Credit->draw();
       if (FadeStart)fade();
        print(Title.animeTime);
        print(Start->getMyId());
        print(Exit->getMyId());
        print(Credit->getMyId());
    }
    void TITLE::nextScene(){

            if (FadeEnd)Start->scene_move();
            if (SceneMove) {
                Credit->scene_move();
                Exit->scene_move();
            }

    }
    void TITLE::fade() {
        AnimeTime += delta;
        if ( AnimeTime <= Title.animeTime) {
            float theta = AnimeTime/Title.animeTime * 90.0f;
            float ratio = Sin(theta);
            Title.rectColor.a = ColorA * ratio;
        }
        else {
            FadeStart = false;
            FadeEnd = true;
        }
        fill(Title.rectColor);
        rect(0, 0, Title.rectSize.x, Title.rectSize.y);
    }
}