#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME11
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    private:
        enum STATE {TITLE,PLAY,CLEAR,OVER};
        STATE State = TITLE;
        void Title();
        void Init();
        void Play();
        void Clear();
        void Over();
        //PC
        float Px = 0, Py = 0, Vx = 0,Vy = 0, Radius = 0;
        //‚»‚êˆÈŠO
        float oPx = 0, oPy = 0, oRadius = 0,
            Countdown = 0, CountSeconds = 0, o2Px = 0, o2Py = 0,
            o3Px = 0, o3Py = 0,o4Px = 0, o4Py = 0;
        int ObjectImg = 0, HaikeiImg = 0, KaoImg = 0, LoseImg = 0
            , GameSound = 0, LoseSound = 0, WinSound = 0,PerfectSound=0,FinalSound=0;
        int  Stagecount = 0, oCount = 0;
    };
}
