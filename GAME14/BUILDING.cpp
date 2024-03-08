#include"GAME14.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
#include "BUILDING.h"
namespace GAME14 {
    BUILDING::BUILDING(class GAME* game) :
    GAME_OBJECT(game) {}
    BUILDING::~BUILDING() {
        delete[] Buildings;
    }
    void BUILDING::create(){
        Building = game()->container()->data().building;
        Buildings = new BUILDINGS[Building.maxBuilding];

        init();
    }
    void BUILDING::init(){
        int rangeX = Building.maxWide - Building.minWide + 1;
        int rangeY = Building.maxHight - Building.minHight + 1;
        for (int i = 0; i < Building.maxBuilding; i++) {
            Buildings[i].pos = VECTOR2(Building.pos.x + Building.posOfset * i, Building.pos.y);
            Buildings[i].scale = VECTOR2(rand() % rangeX + Building.minWide, -(rand() % rangeY + Building.minHight));
        }
    }
    void BUILDING::reScale(int i) {
        int rangeX = Building.maxWide - Building.minWide + 1;
        int rangeY = Building.maxHight - Building.minHight + 1;
        Buildings[i].scale = VECTOR2(rand() % rangeX + Building.minWide, -(rand() % rangeY + Building.minHight));
    }
    void BUILDING::update(){
        for (int i = 0; i < Building.maxBuilding; i++) {
            Buildings[i].pos.x += Building.speed * delta;
            if (Buildings[i].pos.x + Buildings[i].scale.x <0) {
                Buildings[i].pos.x = Buildings[(i + Building.maxBuilding - 1) % Building.maxBuilding].pos.x + Building.posOfset;
                reScale(i);
            }
        }
    }
    bool BUILDING::collision() {
        
        VECTOR2 pos = game()->player()->pos();
        VECTOR2 range1 = game()->player()->range1();
        VECTOR2 range2 = game()->player()->range2();
        VECTOR2 scale = game()->player()->scale();
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < Building.maxBuilding; i++) {
            VECTOR2 vec1 = { (pos.x + range1.x)-Buildings[i].pos.x  ,
                              pos.y-(Buildings[i].pos.y+Buildings[i].scale.y)};
            VECTOR2 vec2 = { (pos.x + scale.x) - Buildings[i].pos.x ,
                            (pos.y + range1.y) - (Buildings[i].pos.y + Buildings[i].scale.y) };
            if (pos.x >= Buildings[i].pos.x && pos.x <= Buildings[i].pos.x + Buildings[i].scale.x ||
                pos.x + range1.x >= Buildings[i].pos.x && pos.x + range1.x <= Buildings[i].pos.x + Buildings[i].scale.x) {
                if (pos.y >= Buildings[i].pos.y + Buildings[i].scale.y) {
                    if (vec1.x >=vec1.y) {
                        game()->player()->setY(Buildings[i].pos.y + Buildings[i].scale.y);
                        game()->player()->setFJFlag(true);
                        game()->player()->setDJFlag(true);
                        flag =  true;
                        cnt++;
                    }
                    else if (vec1.x < vec1.y) {
                        game()->player()->setX(Buildings[i].pos.x - range1.x);
                        game()->player()->setFJFlag(true);
                        game()->player()->setDJFlag(true);
                        flag  = false;
                        cnt++;
                    }
                }
            }
            if (pos.x+scale.x >= Buildings[i].pos.x && pos.x+scale.x <= Buildings[i].pos.x + Buildings[i].scale.x ||
                pos.x + scale.x+range2.x >= Buildings[i].pos.x && pos.x + scale.x+range2.x <= Buildings[i].pos.x + Buildings[i].scale.x) {
                if (pos.y+range1.y >= Buildings[i].pos.y + Buildings[i].scale.y) {
                    if (vec2.x >= vec2.y) {
                        game()->player()->setY(Buildings[i].pos.y + Buildings[i].scale.y-range1.y);
                        game()->player()->setFJFlag(true);
                        game()->player()->setDJFlag(true);
                        flag =  true;
                        cnt++;
                    }
                    else if (vec2.x < vec2.y) {
                        game()->player()->setX(Buildings[i].pos.x - scale.x);
                        game()->player()->setFJFlag(true);
                        game()->player()->setDJFlag(true);
                        flag =  false;
                        cnt++;
                    }
                }
            }
            if (cnt)break;

        }


        //game()->player()->setFJFlag(false);
        return flag;
    }

    void BUILDING::draw(){
        for (int i = 0; i < Building.maxBuilding; i++) {
        fill(Building.color);
            
            rect(Buildings[i].pos.x, Buildings[i].pos.y, Buildings[i].scale.x, Buildings[i].scale.y);

        }

        
    }

}