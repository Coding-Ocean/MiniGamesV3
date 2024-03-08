#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME08
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
        void title();
        void play();
        void result();
        void omikuji();
        void color();
        void getDegit();
        void pressFlag();
        void judgement();
        void weather();
        void init();
        void draw();

    private:


        struct HAND {
            int hand;
            int img[3];
            float px, py, angle;
            float r, g, b;
            int life;
        };
        struct DATA {
            const int OmikujiKind = 7;
            const int WeatherKind = 7;
            enum {
                TITLE,
                PLAY,
                RESULT,
                OMIKUJI,
                COLOR,
                WEATHER
            };
            int  state = TITLE;


            int GU = 0;
            int CHOKI = 1;
            int PA = 2;


            struct HAND player;
            struct HAND pc;


            int lifeImg[15]; //ライフ写真

            int TitleBackImg;
            int SbackImg; //背景

            int PnameImg[5]; //文字
            int Ppx, Ppy,Pmx;

            int EnameImg[5]; //文字
            int Epx, Epy, Emx;

            int VersusImg[2]; //文字
            int Vpx, Vpy, Vmx;


            int clearImg;
            int overImg;

            int rpx, rpy;
            float rsize;


            int lifeNumber[6];//ライフ
            int lpx, lpy;
            int lmx;
            float lsize;


            float resultSize;


            int RbackImg; //背景

            bool PushFlag = false;

            int OmikujiImg; //おみくじ
            int OmikujiesImg[7];
            int NowOmikuji = OmikujiKind;

            int WeatherImg; //天気
            int WeathersImg[7];
            int NowWeather = WeatherKind;


            //カラー
            int select = 0;
            int born[8] = {};
            int colorKind = 0;
            int sum[2] = {0,0};
            int colorSum = 0;
            int color = 0;
            bool pressFlag = false;

            int ColorImg; 
            int ColorsImg[9];
            bool changeFlag = false;

        };
        struct DATA d;

    };
}
//用意して①