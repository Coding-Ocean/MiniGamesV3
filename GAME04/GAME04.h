#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME04
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
        void Init(struct DATA* d);
    private:
        //シーン分け
        enum STATE { TITLE, PLAY, RESULT };
        STATE State = TITLE;
        void Title(struct DATA* d);
        void Play(struct DATA* d);
        void Result(struct DATA* d);
        int Collision(struct CHARA* c,struct BULLET* b);
        void Draw(struct DATA* d);
       void HpGauge(struct CHARA* c);
       int FireSoundP;
       int FireSoundN;
       int DamageSndP;
       int DamageSndN;
       int BgmSound;
       int GAMECSound;
       int GAMEOSound;

        struct DATA* d = 0;
        struct CHARA* c = 0;
        struct BULLET* b = 0;
        int PBulletsnd = 0;
        int NBulletsnd = 0;
    };
    struct CHARA {
        //各画像番号
        int normalImg;
        int damageImg;
        int loseImg;
        int winImg;
        //現在の画像番号
        int img;
        //位置
        float px;
        float py;
        //移動方向ベクトル
        float vx;
        float vy;
        //弾発射オフセット位置
        float bulletOfsY;
        //体力
        int hp;
        //ＨＰゲージ表示オフセット位置
        float hpGaugeOfsY;
        //当たり判定用、半分の幅と高さ
        float halfW;
        float halfH;
    };
    //プレイヤーの弾とNPCの弾用構造体型
    struct BULLET {
        //画像番号
        int img;
        //位置
        float px;
        float py;
        //方向ベクトル
        float vx;
        float vy;
        //体力？（ウィンドウ内を飛んでいるかを意味する）
        int hp;
        //当たり判定用、半分の幅と高さ
        float halfW;
        float halfH;
    };
    //全データを管理する構造体型
    struct DATA {
        //----------------------------------------
        //RESULTの時、キー入力を無効化するフレーム数
        int frameRestrictInput;
        int frameCnt;
        //----------------------------------------
        //キャラクタデータ
        struct CHARA Player;
        struct CHARA NPC;
        struct BULLET PBullet;
        struct BULLET NBullet;
        int titleImg;
        int backImg;
    };
}

