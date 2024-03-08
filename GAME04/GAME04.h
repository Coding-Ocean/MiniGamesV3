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
        //�V�[������
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
        //�e�摜�ԍ�
        int normalImg;
        int damageImg;
        int loseImg;
        int winImg;
        //���݂̉摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�ړ������x�N�g��
        float vx;
        float vy;
        //�e���˃I�t�Z�b�g�ʒu
        float bulletOfsY;
        //�̗�
        int hp;
        //�g�o�Q�[�W�\���I�t�Z�b�g�ʒu
        float hpGaugeOfsY;
        //�����蔻��p�A�����̕��ƍ���
        float halfW;
        float halfH;
    };
    //�v���C���[�̒e��NPC�̒e�p�\���̌^
    struct BULLET {
        //�摜�ԍ�
        int img;
        //�ʒu
        float px;
        float py;
        //�����x�N�g��
        float vx;
        float vy;
        //�̗́H�i�E�B���h�E������ł��邩���Ӗ�����j
        int hp;
        //�����蔻��p�A�����̕��ƍ���
        float halfW;
        float halfH;
    };
    //�S�f�[�^���Ǘ�����\���̌^
    struct DATA {
        //----------------------------------------
        //RESULT�̎��A�L�[���͂𖳌�������t���[����
        int frameRestrictInput;
        int frameCnt;
        //----------------------------------------
        //�L�����N�^�f�[�^
        struct CHARA Player;
        struct CHARA NPC;
        struct BULLET PBullet;
        struct BULLET NBullet;
        int titleImg;
        int backImg;
    };
}

