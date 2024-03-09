#pragma once

#include "../MAIN/GAME_BASE.h"


namespace GAME13
{
    class GAME : public GAME_BASE
    {
    public:
        GAME(class MAIN* main) : GAME_BASE(main) {};
        ~GAME() {};
        int create();
        void proc();
        void destroy();

    private:
        enum STATE { TITLE, OPERATION, PLAY };
        STATE State = TITLE;
        void Title();
        void Operation();
        void Play();

        enum Hand { NONE, ROCK, PAPER, SCISSORS };
        Hand playerHand;
        Hand computerHand;

        int consecutiveWins = 0;
        int resultDisplayTime = 2000; // ���ʕ\�����ԁi�~���b�j
        unsigned long lastResultTime = 0; // �Ō�Ɍ��ʂ�\����������

        void determineWinner();
    };
}