#pragma once
#include "../MAIN/GAME_BASE.h"
namespace GAME10
{
    class GAME :public GAME_BASE
    {
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void title();
            void init();
        void stage();
        void drawDesign();
        void setTimeColli();
        void drawTbutton();//button�̕`��
        void timeLaps();//���Ԍo��
        void pawnsDraw();//��̕`��
        void collision();//�ݒu����p
        void turnLapse();//�^�[���o�ߗp
        void filldJudg();//�S�����܂��Ă邩�̔���p
        void judgment();//���𔻒�p
        void result();
        void destroy();
    private:
        enum STATE {//�V�[���ύX�p
            TITLE,
            STAGE,
            RESULT
        };
        enum KOMA {//���p
            Red,
            Blue,
            Green,
            Yellow,
            Pink,
            White,
            Space
        };
        enum JUDGE {//�q�b�g�E�u���[�̔���p
            AnsPerfect,
            AnsImPerfect,
            AnsSpace
        };
        struct JUDGEPAWNS {//����p�R�}�̉摜������ꏊ
            int AnsPerfect,
                AnsImPerfect,
                AnsSpace;
        };
        struct PAWNS {//�R�}�̉摜������ꏊ
            int RedP,
                BlueP,
                GreenP,
                YellowP,
                PinkP,
                WhiteP,
                SpaceP;
        };
        STATE State;
        KOMA Koma;
        JUDGE Judge;
        JUDGEPAWNS JudgePawns;
        PAWNS Pawns;
        const int Row = 4;//�s��
        const int Col = 8;//��
        const int AnsCnt = 4;//�����̐�
        int* Box = nullptr;//�ݒu�p�̋������ꏊ
        int* Click = nullptr;//�I��p�̋������ꏊ
        int* Ans = nullptr;//�����p�̋������ꏊ
        int* JudgeP = nullptr;//�W���b�`�����g�p�̋������ꏊ
        float* BoxSize = nullptr;//�ݒu����ꏊ�̉摜�T�C�Y������ꏊ
        float* ClickSize = nullptr;//�I������ꏊ�̉摜�T�C�Y������ꏊ
        //title�Estage�Eresult�̉摜
        int TitleImg = 0;
        int StageImg = 0;
        int ResultImg = 0;
        //���ʉ�
            //title���̌��ʉ�
            int SelectSound = 0;
            bool VoiceFlag = false;//��񂾂��Ȃ�悤�ɂ��邽�߂̃t���b�O
            int PushSound = 0;
            //stage���̌��ʉ�
            int SetSound = 0;
            int JudgeSound = 0;
            //result���̌��ʉ�
            int ClearSound = 0;
            int OverSound = 0;
        //�X�e�[�W�̃C���[�W
            int SCntImage = 0;//�������ԕ\���p
            int SCx = 1650;
            int SCy = 150;
            int Smx = 25;
            int TCntImage = 0;//�o�߃^�[���\���p
            int TCx = 1650;
            int TCy = 950;
        //���y
            int Bgm = 0;
        //�T�C�Y�ύX�p�̕ϐ�
            float DefaultSize = 1.0f;
            float BigSize = 1.3f;
        //click�����Ƃ��̐F�ۊǏꏊ
            int ClickBox = 0;
            int PawnsKind = 6;
        //�ݒu����ꏊ�̈ʒu�w��p
            int Px = 150;
            int Py = 270;
            int Mx = 190;
            int My = 175;
            //�ݒu����ꏊ���ŋ��ύX����Ƃ��Ɏg���ϐ�
                int PreP = 0;//�ړ��O�̏ꏊ��ۑ�
                int TempP = 0;
                bool ChangeFlag = false;
                //�������ʒu�ɖ߂����߂̕ϐ�����
                bool NotInFlag = false;
            //�ݒu����ꏊ�̃f�U�C���C���[�W
                int Ipx = 150;
                int IPy = 530;
                int Imx = 190;
                int stageSetImg = 0;
        //�I��p�̋�z�u�w��
            int Kpx = 525;
            int Kpy = 970;
            int Kmx = 175;
        //�����̔z�u
            int Apx = 1700;
            int Apy = 250;
            int Amx = 175;
            int Amy = 175;
        //�W���b�`�����g�p�̔z�u(�I�����W�Ɣ��̂��)
            int Jpx = 130;
            int Jpy = 100;
            int Jmmx = 35;//���������E�̓���
            int Jmy = 40;//����̓���
            int Jbmx = 190;//�傫�����E�̓���
        //���𔻒�p
            int CorrectCnt = 0;//����
            bool ClearFlag = false;//�N���A�t���b�O
            int PerfectCnt = 0;//���S��v
            int ImPerfectCnt = 0;//�s���S��v
            int SameKindCnt = 0;//���Ԃ萔
        //����p
            struct COLLISION {
            int Cx;
            int Cy;
            int DistanceX;
            int DistanceY;
            int Dist;//�ŏI�I�ɗ���Ă��鋗��
        };
            COLLISION* Colli;//�ݒu�����蔻��
            COLLISION* ClickColli;//�I�𓖂��蔻��
        int Radius = 150;
        int MaxTrun = 8;//�ő�^�[��
        int ElapsedTurns = 0;//�o�߃^�[��
        bool FilldFlag = false;//�S�����܂��Ă邩���܂��ĂȂ����̔���
        int MaxFilld = 4;//���܂鐔�̍ő�
        int FilldCnt = 0;//���܂��Ă鐔�̃J�E���g
        //���Ԑݒ�p
        int DefaultTime = 20;//����Ɋ|���Ă���
        int SetTime = 0;//���Ԃ���ꍞ�ނ��߂̕ϐ�
        int SumTime = 0;//���v����
        int TempTime = 0;
        bool DecisionFlag = false;
        struct TIME {
            int Tpx;
            int Tpy;
            int DistanceX;
            int DistanceY;
            int Dist;
            float Tscale;
            int TimeDecision;
        };
        int Tradius = 200;
        TIME* Time;
        int TimeButton[4];
        int TimeKind = 4;
        int Otpx = 400;
        int Otpy = 800;
        int Tmx = 350;
        int Flame = 60;
    };
}
