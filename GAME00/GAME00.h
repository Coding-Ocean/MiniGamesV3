#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME00 
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {
        };
        int create();
        void destroy();
        
    private:
        enum STATE { TITLE, PLAY, CLEAR, OVER };
        STATE State = TITLE;
        void Title();
        void proc();
        void Init();
        void Play();
        void Draw();
        void LifeGauge();
        void Clear();
        int collision();

        bool ClearFlag = false;

        int sakanaImg = 0;
        int ningenImg = 0;
        int sakana2Img = 0;
        int sasimiImg = 0;
        int umiImg = 0;
        float ex = 0;
        float ey = 0;
        float SakanaLife = 0;
        float ew = 0;
        float eh = 0;
        float px = 0;
        float py = 0;
        float vx = 0;
        float NingenLife = 0;
        float pw = 0;
        float ph = 0;
        float cx = 0;
        float cy = 0;
   
    };
}
