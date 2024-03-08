#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME05
{
    class GAME :
        public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void init(struct DATA* d);
        void init2(struct DATA* d);
        void proc();
        void destroy();
    private:
        enum STATE {
            TITLE,
            EASY,
            HARD,
            OPERATION,
            OPERATION2,
            EXPLAIN,
            EXPLAIN2,
            PLAY,
            PLAY2,
            RESULT
        };

        STATE State = TITLE;
        void Title(struct DATA* d);
        void Easy(struct DATA* d);
        void Hard(struct DATA* d);
        void Operation(struct DATA* d);
        void Operation2(struct DATA* d);
        void Explain(struct DATA* d);
        void Explain2(struct DATA* d);
        void Play(struct DATA* d);
        void Result(struct DATA* d);
        int collision(struct CHARA* c, struct BULLET* b);
        int collision2(struct CHARA* c, struct ITEM* i);
        void draw(struct DATA* d);
        void hpGauge(struct CHARA* c);

        //ミサイルの回数(イージー)
        int useCnt = 0;
        //ミサイルの回数(ハード)
        int useCnt2 = 0;

        int OnigasimaImg = 0;
        int ShootSnd = 0;
        int Shoot2Snd = 0;
        int WinSnd = 0;
        int LoseSnd = 0;
        int ClickSnd = 0;
        int FinalFightSnd = 0;
        int VoiceSnd = 0;
        int YouwinSnd = 0;
        int ExplosionSnd = 0;
        int CancelSnd = 0;
        int PclearSnd = 0;
        int Count = 0;
        int maxhp = 0;
        int HealSnd = 0;
        float hpWarning = 0;
        float hpDanger = 0;
        int Drawbox = 0;
        
        
        struct DATA* d = 0;
        struct CHARA* c = 0;
        struct BULLET* b = 0;
        struct ITEM* i = 0;
    };
    struct CHARA {
        //各画像番号
        int normalImg;
        int damageImg;
        int loseImg;
        int winImg;
        int pwinImg;
        int healImg;
        //現在の画像番号
        int img;
        //位置
        float px;
        float py;
        //移動方向
        float vx;
        float vy;
        //弾発射位置
        float bulletOfsY;
        //HP
        float hp;
        //HP最大値
        float Maxhp;
        //HPバーの位置
        float hpGaugeOfsY;
        //当たり判定用、半分の高さと幅
        float halfW;
        float halfH;
        //無敵時間
        float invincibleRestTime = 0;
        float invincibleTime = 0;
    };
    //ツボと星用
    struct BULLET {
        //画像番号
        int img;
        //位置
        float px;
        float py;
        //移動方向
        float vx;
        float vy;
        //HP
        int hp;
        //使用回数
        int use;
        //当たり判定用、半分の高さと幅
        float halfW;
        float halfH;
    };
    struct ITEM {
        //画像
        int img;
        //位置
        float px;
        float py;
        //移動方向
        float vy;
        //HP
        float hp;
        //当たり判定用　半分の高さと幅
        float halfW;
        float halfH;
    };
    struct DATA {
        int frameRestrictInput;
        int frameCnt;
        //キャラデータ
        struct CHARA hitman;
        struct CHARA oni;
        struct BULLET tama;
        struct BULLET fire;
        struct BULLET misairu;
        struct ITEM kaihukuyaku;
    };
}