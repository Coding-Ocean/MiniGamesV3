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
        int flag = 0;

       /* for (int i = 0; i < game()->building()->maxBuilding(); i++) {
            if (pos.y >= Buildings[i].pos.y + Buildings[i].scale.y&& pos.x + range.x <= Buildings[i].pos.x)flag = 1;
            if (pos.x + range.x >= Buildings[i].pos.x&&pos.y <= Buildings[i].pos.y + Buildings[i].scale.y)flag = 2;
            
            if (pos.y >= Buildings[i].pos.y + Buildings[i].scale.y && (
                (pos.x >= Buildings[i].pos.x && pos.x <= Buildings[i].pos.x + Buildings[i].scale.x) ||
                (pos.x + range.x >= Buildings[i].pos.x && pos.x + range.x <= Buildings[i].pos.x + Buildings[i].scale.x)
                )) {
                if (flag == 1) {
                    game()->player()->setX(Buildings[i].pos.x - range.x);
                    return false;
                }
                else if (flag == 2)game()->player()->setY(Buildings[i].pos.y + Buildings[i].scale.y);
                return true;
            }
        }*/
        for (int i = 0; i < game()->building()->maxBuilding(); i++) {
            if (pos.x >= Buildings[i].pos.x && pos.x <= Buildings[i].pos.x + Buildings[i].scale.x ||
                pos.x + range1.x >= Buildings[i].pos.x && pos.x + range1.x <= Buildings[i].pos.x + Buildings[i].scale.x) {
                if (pos.y >= Buildings[i].pos.y + Buildings[i].scale.y) {
                    game()->player()->setY(Buildings[i].pos.y + Buildings[i].scale.y);
                    return true;
                }
                else if (pos.y < Buildings[i].pos.y + Buildings[i].scale.y) {
                    return false;
                }
            }
        
        
        }
                return false;
    }

    void BUILDING::draw(){
        fill(Building.color);
        for (int i = 0; i < Building.maxBuilding; i++) {
            rect(Buildings[i].pos.x, Buildings[i].pos.y, Buildings[i].scale.x, Buildings[i].scale.y);
        }

        
    }

}