#include "CONTAINER.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"
#include"../../libOne/inc/graphic.h"
namespace GAME14 {
    void CONTAINER::load() {
        setData();
        setImage();
    }
    void CONTAINER::setData() {
        //シンプルなゲームなら次のように、ここで行ってもよい。
        Data.player.color = COLOR(0, 255, 0, 125);
        Data.player.scale = VECTOR2(788 * 0.2-6, -788 * 0.2+8);
        Data.player.range1 = VECTOR2(110, -40);
        Data.player.range2 = VECTOR2(-40, -(788 * 0.2-8));
        Data.player.pos = VECTOR2(0,0);
        Data.player.targetPos = VECTOR2((width - 200) / 2, 200);
        Data.player.stPosX = (width - 200) / 2;
        Data.player.stPosY = 200;
        Data.player.stayWaid = 25;
        Data.player.speed = 0;
        Data.player.animeSpeed = -400;
        Data.player.jumpSpeed = -500;
        Data.player.gravity = 9.8f;
        Data.player.highLimt = 0;
        Data.player.farstJumpFlag = false;
        Data.player.doubleJumpFlag = true;
        Data.player.collisionFlag = false;
        Data.player.jumpAnimeTime = 0.5f;
        Data.player.imgSize = 0.2f;
        Data.player.jumpImgSize = 0.45f;
        Data.player.eImgSize = 0.1f;
        Data.player.enterAnimeTime = 2.0f;

        Data.building.img = 0;
        Data.building.pos = VECTOR2(100, height );
        Data.building.posOfset = 400;
        Data.building.speed = -400;
        Data.building.minHight = 400;
        Data.building.minWide = 100;
        Data.building.maxHight = 800;
        Data.building.maxWide = 200;
        Data.building.color = COLOR(97, 97, 97,180);
        Data.building.maxBuilding = 6;

        strcpy_s(Data.title.titleStr, "車からの景色");
        Data.title.img = 0;
        Data.title.textColor = COLOR(225, 225, 225);
        Data.title.pos = VECTOR2(220, height / 2);
        Data.title.textSize = 250;
        Data.title.backColor = COLOR(68, 127, 255);
        Data.title.rectColor = COLOR(200, 200, 200,255);
        Data.title.rectSize = VECTOR2(width, height);
        Data.title.animeTime = 1.0f;

        Data.stage.img = 0;
        Data.stage.backColor = COLOR(68, 127, 255);
        Data.stage.cnt = 0;
        Data.stage.rectColor = COLOR(200,200,200,255);
        Data.stage.rectSize = VECTOR2(width,height);
        Data.stage.animeTime = Data.title.animeTime;

        Data.game_clear.img = 0;
        Data.game_clear.imgPos = VECTOR2(width-411, height-151);
        Data.game_clear.imgSize = 0.8f;
        strcpy_s(Data.game_clear.str, "GAME CLEAR");
        Data.game_clear.textColor = COLOR(225, 125, 125);
        Data.game_clear.pos = VECTOR2(20, height / 2);
        Data.game_clear.textSize = 380;
        Data.game_clear.backColor = COLOR(68, 127, 255);
        

        Data.game_over.img = 0;
        Data.game_over.imgPos = VECTOR2(width - 411, height - 151);
        Data.game_over.imgSize = 0.8f;
        strcpy_s(Data.game_over.str, "GAME OVER");
        Data.game_over.textColor = COLOR(225, 125, 125);
        Data.game_over.pos = VECTOR2(100, height / 2);
        Data.game_over.textSize = 380;
        Data.game_over.backColor = COLOR(68, 127, 255);
        Data.game_over.rectColor = COLOR(125,0, 0,125);
        Data.game_over.rectSize = VECTOR2(width, height);

        Data.credit.nStrPos = VECTOR2(100, 300);
        Data.credit.uStrPos = VECTOR2(width - 1100, 300);
        Data.credit.textColor = COLOR(0, 0, 0);
        Data.credit.textSize = 80;
        strcpy_s(Data.credit.nStr1, "いらすとや");
        strcpy_s(Data.credit.nStr2, "フキダシデザイン");
        strcpy_s(Data.credit.uStr1, "https://www.irasutoya.com");
        strcpy_s(Data.credit.uStr2, "https://fukidesign.com");
        Data.credit.backColor = COLOR(255, 255, 255);

        Data.time.timeTextPos = VECTOR2(width - 400, 50);
        Data.time.timePos = VECTOR2(width - 150, 50);
        Data.time.timeColor = COLOR(0, 0, 0);
        Data.time.maxDigit = 4;
        Data.time.timeTextSize = 50.0f;
        Data.time.reduceTime = 15.0f;
        Data.time.limitTime = 10.0f * Data.time.reduceTime;
        strcpy_s(Data.time.timeStr, "目的地まで　　ｍ");


        Data.start_button.myId = BUTTON::START;
        Data.start_button.pos = VECTOR2(width / 2-250/2, height / 1.5);
        strcpy_s(Data.start_button.buttonName, "START");

        Data.exit_button.myId = BUTTON::EXIT;
        Data.exit_button.pos = VECTOR2(Data.start_button.pos.x, Data.start_button.pos.y+100);
        strcpy_s(Data.exit_button.buttonName, "EXIT");

        Data.credit_button.myId = BUTTON::CREDIT;
        Data.credit_button.pos = VECTOR2(Data.start_button.pos.x, Data.start_button.pos.y +200);
        strcpy_s(Data.credit_button.buttonName, "CREDIT");

        Data.retry_button.myId = BUTTON::RETRY;
        Data.retry_button.pos = VECTOR2(Data.start_button.pos.x, Data.start_button.pos.y);
        strcpy_s(Data.retry_button.buttonName, "RETRY");

        Data.title_button.myId = BUTTON::TITLE;
        Data.title_button.pos = VECTOR2(Data.start_button.pos.x, Data.start_button.pos.y +100);
        strcpy_s(Data.title_button.buttonName, "TITLE");

    }
    void CONTAINER::setImage() {
        Data.player.img = loadImage("../GAME14\\assets\\player.png");
        Data.player.jumpImg = loadImage("../GAME14\\assets\\player_jump.png");
        Data.player.eImg = loadImage("../GAME14\\assets\\player_E.png");
        Data.game_clear.img = loadImage("../GAME14\\assets\\game_clear_text.png");
        Data.game_over.img = loadImage("../GAME14\\assets\\game_over_text.png");
    }

}
