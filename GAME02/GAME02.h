#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME02
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void reelCheck();
        void proc();
        void destroy();
        void Init();
    private:
        enum STATE { TITLE, PLAY };
        STATE State = TITLE;
        void Title();
        void Play();

        int gameCnt = 0;
        int rand = 0;
        int initflag = 0;
        int reelCheckflag = 0;
        int haraidasiflag = 0;
        int inputAcceptanceTime = 0;
        int sndpat[10] = { 0 };
        int pat[10] = { 0 };
        int randomBB = 0;
        int medal = 0;
        int medalCnt = 0;
        int peka = 1;
        int optionSeed = 0;
        int option = 0;
        int pressflag = 0;
        float ReelsSpeed = 0;
        float StopPy = 0;

        struct REEL {

            int reelRotateFlag = 0;
            int premierReelRotateFlag = 0;
            float reelStopTime = 0;

            float Px = 0, Py[21] = { 0 };
            int Reel[21] = { 0 };
        };
        struct REELCHECK {
            float Py[3] = { 0 };
        };
        REEL reel1;
        REEL reel2;
        REEL reel3;
        REELCHECK reelC1;
        REELCHECK reelC2;
        REELCHECK reelC3;
    };
};