#pragma once
#include "../MAIN/GAME_BASE.h"
#define CARD_NUMBER 13
#define SUM 52
namespace GAME07
{
    class GAME :
        public GAME_BASE
    {
    private:
        //シーン遷移
        enum STATE { TITLE, PLAY, CLEAR, OVER };
        STATE State = TITLE;
        void Title();
        void Init();
        void Play();
        void Clear();
        //背景
        int TitleImg = 0;
        int PlayImg = 0;
        int ResultImg = 0;
        //ボタン
        float Bx = 0, By = 0;
        float BWidth = 0;
        float BHeight = 0;
        float BAngle = 0;
        //トランプ情報
        char c[SUM + 1];    //c[0]は何も入れない
        int P_sum = 0;
        int D_sum = 0;
        float Tx = 0;
        float Ty = 0;
        float TAngle = 0;
        float TRate = 0;
        float TDx = 0;    //横のトランプとの距離
        float TDy = 0;    //縦のトランプとの距離
        //ハート
        int H[CARD_NUMBER + 1];
        //ダイヤ
        int D[CARD_NUMBER + 1];
        //スペード
        int S[CARD_NUMBER + 1];
        //クラブ
        int C[CARD_NUMBER + 1];
        //勝敗を記録するフラグ
        int JudgeFlag = 0;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
