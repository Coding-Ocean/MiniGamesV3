#include"GAME14.h"
#include"CONTAINER.h"
#include"../../libOne/inc/graphic.h"
#include"../../libOne/inc/input.h"
#include"../../libOne/inc/window.h"
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
        CurImg = Player.img;
        CurImgSize = Player.imgSize;
        AnimeTime = 0;
    }
    void PLAYER::update(){
        if (isPress(KEY_DOWN)) {
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
        }

        if (Player.farstJumpFlag) {
            if (isPress(KEY_SPACE)||isTrigger(KEY_SPACE)) {
            jump();
            }
            Player.farstJumpFlag = false;
        }
        else if (Player.doubleJumpFlag) {
            if (isTrigger(KEY_SPACE)) {
            jump();
            Player.doubleJumpFlag = false;
            }
        }
        if (game()->building()->collision()) {
            if(Player.speed>0)
            Player.speed= 0;
        }
        else {
            Player.speed += Player.gravity;
        }
        Player.pos.y += Player.speed * delta;

   }
    void PLAYER::draw(){
        image(CurImg, Player.pos.x, Player.pos.y+Player.scale.y,0,CurImgSize);
        fill(255, 0, 0,125);
       // rect(Player.pos.x, Player.pos.y, Player.scale.x, Player.scale.y);
        fill(Player.color);
       rect(Player.pos.x, Player.pos.y, Player.range1.x, Player.range1.y);
       rect(Player.pos.x + Player.scale.x, Player.pos.y+Player.range1.y , Player.range2.x, Player.range2.y);
        fill(125);
        circle(Player.pos.x, Player.pos.y, 10);
        print(Player.doubleJumpFlag);
    }
    void PLAYER::jump() {
        Player.speed = Player.jumpSpeed;
        CurImg = Player.jumpImg;
        CurImgSize = Player.jumpImgSize;
    }

}