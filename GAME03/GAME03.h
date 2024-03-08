#pragma once
#include "../MAIN/GAME_BASE.h"
#include "../MAIN/GAME_FACTORY.h"
namespace GAME03
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
        //ÉVÅ[ÉìëJà⁄
        enum STATE { TITLE, PLAY1, PLAY2, PLAY3, PLAY4, PLAY5, CLEAR, OVER };
        STATE State = TITLE;
        void Title();
        void Init();
        void Play1();
        void Play2();
        void Play3();
        void Play4();
        void Play5();
        void Clear();
        void Over();
        void run();
        void Run();
        bool ClearFlag = false;
        float Px = 0, Py = 0, Radius = 0;
        int cnt = 1, a = 0, s = 0, d = 0, f = 0, g = 0, score = 101;
        int Img1 = 0, Img2 = 0, Img3 = 0, Img4 = 0, Img5 = 0, Img6 = 0, Img7 = 0, Img8 = 0;
        int Snd0 = 0, Snd0_1 = 0, Snd1 = 0, Snd2 = 0, Snd3 = 0, Snd4 = 0;
        int volume1 = 80;        
        int volume2 = 80;
        int counter = 0, interval = 6;
        int imgs[19];
        int select = true;
        int II = 0;
        int SS = 0;
        int TIME = 0;
        int scnt = 0;
        int hcnt = 0;
        bool onlyOnce = true;
        bool loopBgm = true;
        bool loopBgm2 = true;
        class FADE* Fade = nullptr;
    };
}
