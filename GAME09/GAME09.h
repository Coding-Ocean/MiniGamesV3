#pragma once
#include "../MAIN/GAME_BASE.h"

namespace GAME09
{
    class GAME :
        public GAME_BASE
    {
    //ƒRƒ“ƒeƒi
    private:
        class CONTAINER* Container;
    public:
        class CONTAINER* container() {
            return Container;
        }
    public:
        enum SCENE_ID {
            TITLE_ID,
            SELECT_ID,
            NUM_SCENES
        };
        enum GAME_ID {
            AroundJapan,
            Bingo,
            Enpty1,
            Enpty2,
            Enpty3,
            Enpty4,
            NUM_GAMES
        };
    private:
        class SCENE* Scenes[NUM_SCENES + NUM_GAMES];
        class FADE* Fade;
        class MESSAGE* Message;
        SCENE_ID CurSceneId;
    public:
        GAME(class MAIN* main) : GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
        void changeScene(SCENE_ID sceneId);
        void launchGame(GAME_ID gameId);
        class FADE* fade() { return Fade; }
        class MESSAGE* message() { return Message; }
    };
}
