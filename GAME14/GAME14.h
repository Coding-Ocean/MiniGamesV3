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
        enum SCENE_ID {
            TITLE_ID,
            STAGE_ID,
            CREDIT_ID,
            GAME_CLEAR_ID,
            GAME_OVER_ID,
            NUM_SCENES
        };
    private:
        class SCENE* Scenes[NUM_SCENES];
        SCENE_ID CurSceneId;
        class PLAYER* Player;
        class  BUILDING* Building;
        bool ExitFlag;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void init();
        void proc();
        void destroy();
        void changeScene(SCENE_ID sceneId);
        class PLAYER* player() { return Player; }
        class BUILDING* building() {return Building; }
        class STAGE* stage() { return (class STAGE*)Scenes[STAGE_ID]; }
        void setExitFlag(bool flag) { ExitFlag = flag; }
    };
}
