#pragma once
#include "../MAIN/GAME_BASE.h"
#include"../../libOne/inc/VECTOR2.h"
#include"../../libOne/inc/COLOR.h"

namespace GAME14
{
    class GAME :
        public GAME_BASE
    {
    private:
        class CONTAINER* Container = nullptr;
    public:
        class CONTAINER* container() { return Container; }
    public:
        struct PLAYER {
            int img =0;
            COLOR color =COLOR(0);
            VECTOR2 pos = VECTOR2(0,0);
            int vec = 0;
            float speed = 0;
            float limitSpeed = 0;
            float gravity = 0;
            float highLimt =0;
            bool farstJumpFlag = true;
            bool doubleJumpFlag = true;
            VECTOR2 range = VECTOR2 (0,0);
            bool collisionFlag = true;
        };
        struct BUILDING {
            int img = 0;
            VECTOR2 pos = VECTOR2(0,0);
            float speed = 0;
            int hight = 0;
            int wide = 0;
            VECTOR2 limit = VECTOR2(0, 0);
            COLOR color = COLOR(0);

        };
        struct TITLE {
            char titleStr[64] = {};
            int img = 0;
            COLOR textColor = COLOR(0);
            VECTOR2 pos = VECTOR2(0,0);
            int textSize = 0;

        };
        struct STAGE {
            int img = 0;
        };
        struct GAME_CREAR {
            int img = 0;
            char str[64] = {};
            COLOR textColor = COLOR(0, 0, 0);
            VECTOR2 pos = VECTOR2(0,0);
            int textSize = 0;

        };
        struct GAME_OVER {
            int img = 0;
            char str[64] = {};
            COLOR textColor = COLOR(0, 0, 0);
            VECTOR2 pos = VECTOR2(0, 0);
            int textSize = 0;

        };
    private:
        struct PLAYER Player;
        struct BUILDING Building;
        struct TITLE Title;
        struct STAGE Stage;
        struct GAME_CREAR Game_Crear;
        struct GAME_OVER Game_Over;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void init();
        void proc();
        void destroy();
        void player();
        void building();
        void title();
        void stage();
        void game_crear();
        void game_over();
    };
}
