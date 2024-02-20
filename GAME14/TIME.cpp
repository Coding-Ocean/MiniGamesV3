#include"GAME14.h"
#include"CONTAINER.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/graphic.h"
#include<string>
#include<iostream>
#include "TIME.h"
namespace GAME14 {
    TIME::TIME(class GAME* game) :
        GAME_OBJECT(game) {

    }
    TIME::~TIME(){}
    void TIME::create(){
        Time = game()->container()->data().time;
    }
    void TIME::init(){
        Flag = false;
    }
    void TIME::update(){
        Time.limitTime -= Time.reduceTime * delta;
    }
    void TIME::draw(){
        std::string str = std::to_string((int)Time.limitTime);
        float ofset = Time.timeTextSize/2  * (Time.maxDigit - str.size());
        fill(Time.timeColor);
        textSize(Time.timeTextSize);
        text(str.c_str(), Time.timePos.x+ofset , Time.timePos.y);
        text(Time.timeStr, Time.timeTextPos.x, Time.timeTextPos.y);

    }
    bool TIME::timeUp(){
        return Flag;
    }

}