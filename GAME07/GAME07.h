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
        //�V�[���J��
        enum STATE { TITLE, PLAY, CLEAR, OVER };
        STATE State = TITLE;
        void Title();
        void Init();
        void Play();
        void Clear();
        //�w�i
        int TitleImg = 0;
        int PlayImg = 0;
        int ResultImg = 0;
        //�{�^��
        float Bx = 0, By = 0;
        float BWidth = 0;
        float BHeight = 0;
        float BAngle = 0;
        //�g�����v���
        char c[SUM + 1];    //c[0]�͉�������Ȃ�
        int P_sum = 0;
        int D_sum = 0;
        float Tx = 0;
        float Ty = 0;
        float TAngle = 0;
        float TRate = 0;
        float TDx = 0;    //���̃g�����v�Ƃ̋���
        float TDy = 0;    //�c�̃g�����v�Ƃ̋���
        //�n�[�g
        int H[CARD_NUMBER + 1];
        //�_�C��
        int D[CARD_NUMBER + 1];
        //�X�y�[�h
        int S[CARD_NUMBER + 1];
        //�N���u
        int C[CARD_NUMBER + 1];
        //���s���L�^����t���O
        int JudgeFlag = 0;
    public:
        GAME(class MAIN* main) :GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();
    };
}
