#include "CONTAINER.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/graphic.h"
namespace GAME14 {
    void CONTAINER::load() {
        setData();
    }
    void CONTAINER::setData() {
        //シンプルなゲームなら次のように、ここで行ってもよい。
        Data.player.img = 0;
        Data.player.color = COLOR(0, 255, 0, 125);
        Data.player.pos = VECTOR2(width / 2, height / 2);
        Data.player.vec = 0;
        Data.player.speed = 0;
        Data.player.limitSpeed = 0;
        Data.player.gravity = 0;
        Data.player.highLimt = 0;
        Data.player.farstJumpFlag = true;
        Data.player.doubleJumpFlag = true;
        Data.player.range = VECTOR2(100, 200);
        Data.player.collisionFlag = true;

        Data.building.img = 0;
        Data.building.pos = VECTOR2(width / 2, height / 2);
        Data.building.speed = 0;
        Data.building.hight = 0;
        Data.building.wide = 0;
        Data.building.limit = VECTOR2(400, 600);
        Data.building.color = COLOR(125, 125, 125, 125);

        strcpy_s(Data.title.titleStr, "車からの景色");
        Data.title.img = 0;
        Data.title.textColor = COLOR(0, 0, 125);
        Data.title.pos = VECTOR2(width / 2, height / 2);
        Data.title.textSize = 40;

        Data.stage.img = 0;

        Data.game_crear.img = 0;
        strcpy_s(Data.game_crear.str, "game_crear");
        Data.game_crear.textColor = COLOR(125, 0, 0);
        Data.game_crear.pos = VECTOR2(width / 2, height / 2);
        Data.game_crear.textSize = 40;

        Data.game_over.img = 0;
        strcpy_s(Data.game_over.str, "game_over");
        Data.game_over.textColor = COLOR(125, 0, 0);
        Data.game_over.pos = VECTOR2(width / 2, height / 2);
        Data.game_over.textSize = 40;
    }
}
