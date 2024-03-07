#pragma once
#include "SCENE.h"
#include "../../libOne/inc/COLOR.h"
#include "../../libOne/inc/VECTOR2.h"
#include <string>

namespace GAME09
{
    class SELECT :
        public SCENE
    {
    public:
        struct DATA {
            int col;
            int row;
            VECTOR2 imgSize;
            VECTOR2 imgOfst;
            VECTOR2 selectOfst;
            std::string selectText;
            VECTOR2 textPos;
            COLOR textColor;
            float textSize;
            COLOR textStroke;
            float textStrokeWeight;
        };
    private:
        DATA Select;
        int Mouseover; //マウスオーバーされてるゲーム番号(なければ-1)
        int GameId;
    public:
        SELECT(class GAME* game);
        ~SELECT();
        void init();
        void create();
        void update();
        void draw();
        void nextScene();
    };
}