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

        //�~�T�C���̉�(�C�[�W�[)
        int useCnt = 0;
        //�~�T�C���̉�(�n�[�h)
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
        //�e�摜�ԍ�
        int normalImg;
        int damageImg;
        int loseImg;
        int winImg;
        int pwinImg;
        int healImg;
        //���݂̉摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�ړ�����
        float vx;
        float vy;
        //�e���ˈʒu
        float bulletOfsY;
        //HP
        float hp;
        //HP�ő�l
        float Maxhp;
        //HP�o�[�̈ʒu
        float hpGaugeOfsY;
        //�����蔻��p�A�����̍����ƕ�
        float halfW;
        float halfH;
        //���G����
        float invincibleRestTime = 0;
        float invincibleTime = 0;
    };
    //�c�{�Ɛ��p
    struct BULLET {
        //�摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�ړ�����
        float vx;
        float vy;
        //HP
        int hp;
        //�g�p��
        int use;
        //�����蔻��p�A�����̍����ƕ�
        float halfW;
        float halfH;
    };
    struct ITEM {
        //�摜
        int img;
        //�ʒu
        float px;
        float py;
        //�ړ�����
        float vy;
        //HP
        float hp;
        //�����蔻��p�@�����̍����ƕ�
        float halfW;
        float halfH;
    };
    struct DATA {
        int frameRestrictInput;
        int frameCnt;
        //�L�����f�[�^
        struct CHARA hitman;
        struct CHARA oni;
        struct BULLET tama;
        struct BULLET fire;
        struct BULLET misairu;
        struct ITEM kaihukuyaku;
    };
}