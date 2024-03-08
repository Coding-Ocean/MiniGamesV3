#include"GAME14.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
#include"../../libOne/inc/mathUtil.h"
#include "PLAYER.h"
namespace GAME14 {
    PLAYER::PLAYER(class GAME* game):
        GAME_OBJECT(game){}
    void PLAYER::create(){
      //  Player = game()->container()->data().player;
        init();
    }
    void PLAYER::init(){
        Player = game()->container()->data().player;
        CurImg = Player.eImg;
        CurImgSize = Player.eImgSize;
        CurState = ANIM;
        AnimeTime = 0;
        BeforWait = 0;
        Angle = 0;
        Life = true;
        Stay = true;
    }
    void PLAYER::update() {
       /* if (isPress(KEY_DOWN)) {
            Player.pos.y += 200 * delta;
        }
        if (isPress(KEY_UP)) {
            Player.pos.y -= 200 * delta;
        }
        if (isPress(KEY_RIGHT)) {
            Player.pos.x += 200 * delta;
        }
        if (isPress(KEY_LEFT)) {
            Player.pos.x -= 400 * delta;
        }*/

        if (CurState == ANIM) {
            AnimeTime += delta;
            if (AnimeTime <= Player.enterAnimeTime) {
             eAnime(Player.targetPos, Player.enterAnimeTime, 0);
            }
            else {
                CurState = STAY;
                AnimeTime = 0;
            }
        }
        else if (CurState == STAY) {
            AnimeTime += 90.0f*delta;
            Player.pos.y +=  BeforWait-Sin(AnimeTime) * Player.stayWaid;
            BeforWait = Sin(AnimeTime) * Player.stayWaid;
            if (isTrigger(KEY_SPACE)) {
                Stay = false;
                Player.pos.x = Player.stPosX;
                Player.pos.y = Player.stPosY;
                CurImg = Player.jumpImg;
                CurImgSize = Player.jumpImgSize;
                AnimeTime = 0;
                jump(&Player.doubleJumpFlag);
                CurState = DOUBLEJUMP;
            }
        }
        else if (CurState == FALL) {
            Player.speed += Player.gravity;
            if (game()->building()->collision()) {
                if(Player.speed>0)
                Player.speed = 0;
                CurState = COLLISION;
           }
            if (Player.farstJumpFlag) {
                if (isTrigger(KEY_SPACE)||isPress(KEY_SPACE)) {
                    jump(&Player.farstJumpFlag);
                }

            }
            else if (Player.doubleJumpFlag) {
                if (isTrigger(KEY_SPACE)) {
                    jump(&Player.doubleJumpFlag);
                    CurImg = Player.jumpImg;
                    CurImgSize = Player.jumpImgSize;
                    CurState = DOUBLEJUMP;
                }
            }
            if (Player.pos.x + Player.scale.x<0 || Player.pos.y + Player.scale.y>height) {
                Life = false;
            }
        }
        else if (CurState == COLLISION) {
            if (!game()->building()->collision()) {
                Player.farstJumpFlag = false;
                CurState = FALL;
            }
            if (Player.farstJumpFlag) {
                if (isTrigger(KEY_SPACE)) {
                    jump(&Player.farstJumpFlag);
                }

            }

        }
        else if (CurState == DOUBLEJUMP) {
            game()->building()->collision();
            Player.speed += Player.gravity;
            AnimeTime += delta;
            if (AnimeTime <= Player.jumpAnimeTime) {
                angleMode(DEGREES);
                float addAngle = 360 / Player.jumpAnimeTime;
                Angle += addAngle * delta;
            }
            else {
                CurImg = Player.img;
                CurImgSize = Player.imgSize;
                Angle = 0;
                AnimeTime = 0;
                CurState = FALL;
            }

        }
        else if (CurState == CLEAR) {
            eAnime(EPos, 0, game()->building()->speed());
        }
        if (game()->stage()->time()->timeUp()) {
            Angle = 0;
            AnimeTime = 0;
            CurImg = Player.eImg;
            CurImgSize = Player.eImgSize;
            CurState = CLEAR;
        }
        else {
            Player.pos.y += Player.speed * delta;
        }
    }
    void PLAYER::draw(){
        image(CurImg, Player.pos.x, Player.pos.y+Player.scale.y,Angle,CurImgSize);
        fill(255, 0, 0,125);
       // rect(Player.pos.x, Player.pos.y, Player.scale.x, Player.scale.y);
        fill(Player.color);
       //rect(Player.pos.x, Player.pos.y, Player.range1.x, Player.range1.y);
       //rect(Player.pos.x + Player.scale.x, Player.pos.y+Player.range1.y , Player.range2.x, Player.range2.y);
        //fill(125);
        //circle(Player.pos.x, Player.pos.y, 10);
        //circle(Player.targetPos.x, Player.targetPos.y, 10);
        //print(Player.pos.x);
        //print(Sin(AnimeTime));
    }
    void PLAYER::jump(bool* flag) {
        Player.speed = Player.jumpSpeed;
        *flag = false;
    }
    void PLAYER::eAnime(VECTOR2 targetPos,float time,float speed) {
        VECTOR2 range = (targetPos - Player.pos);
        if (time != 0) {
            float speedX = targetPos.x / time;
            float speedY = targetPos.y / time;
            Player.pos.x += speedX * delta;
            Player.pos.y += speedY * delta;
        }
        else if(speed!=0){
            if (Player.pos.x > -300 && Player.pos.y > -300) {
                Player.pos.x += speed * delta;
                Player.pos.y += speed * delta;
            }
        }
        else {
            return;
        }
    }
}