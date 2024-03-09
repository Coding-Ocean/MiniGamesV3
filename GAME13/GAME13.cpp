#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME13.h"

namespace GAME13
{
    

    int GAME::create()
    {
        // �摜�≹���f�[�^�̓ǂݍ��݂Ȃǂ��s��

        // �������� Init() �֐��Ȃǂōs���̂��ǂ����A�V���v���ȃQ�[���Ȃ炱���ōs���Ă��悢
        State = TITLE;

        return 0;
    }

    void GAME::destroy()
    {
        // create() �� new �����ꍇ�͂����� delete ����
    }

    void GAME::proc()
    {
        // �����̓��C�����[�v����Ăяo����Ă���
        if (State == TITLE)Title();
        else if (State == OPERATION)Operation();
        else if (State == PLAY)Play();
    }

    void GAME::Title()
    {
        // ��ʕ`��
        clear(255, 255, 255);

        // �e�L�X�g���
        fill(0);
        textSize(100);
        print("����񂯂�");
        print("�N���b�N�ŃQ�[���X�^�[�g");
        print("Enter�Ń��j���[�ɖ߂�");

        // �V�[���؂�ւ�
        if (isTrigger(MOUSE_LBUTTON)) {
            State = OPERATION;
            return;
        }

        // ���j���[�ɖ߂�
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::Operation()
    {
        // ��ʕ`��
        clear(255, 255, 255);

        // �e�L�X�g���
        fill(0);
        print("A�ŃO�[");
        print("S�Ń`���L");
        print("D�Ńp�[");
        print("");

        State = PLAY;
    }

    void GAME::Play()
    {
        // �v���C���[�̓��͂��󂯎��
        playerHand = NONE;
        if (isTrigger(KEY_A)) {
            playerHand = ROCK;
        }
        else if (isTrigger(KEY_S)) {
            playerHand = SCISSORS;
        }
        else if (isTrigger(KEY_D)) {
            playerHand = PAPER;
        }

        //�v���C���[�̓��͂���������ȉ��̏�����
        if (playerHand != NONE) {
            Operation();
            determineWinner();
        }

        // ���j���[�ɖ߂�
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::determineWinner()
    {
        // �R���s���[�^�̎�������_���ɑI��
        computerHand = static_cast<Hand>(rand() % 3);

        // �v���C���[�̎�ƃR���s���[�^�̎��\��
        print("���Ȃ��̎�");
        if (playerHand == ROCK)
            print("�@�O�[");
        else if (playerHand == PAPER)
            print("�@�p�[");
        else
            print("�@�`���L");

        print("�R���s���[�^�̎�");
        if (computerHand == ROCK)
            print("�@�O�[");
        else if (computerHand == PAPER)
            print("�@�p�[");
        else
            print("�@�`���L");

        // ���s����ƌ��ʕ\��
        print("");
        if (playerHand == computerHand) {
            // ��������
            print("���������I");
        }
        else if ((playerHand == ROCK && computerHand == SCISSORS) ||
            (playerHand == SCISSORS && computerHand == PAPER) ||
            (playerHand == PAPER && computerHand == ROCK)) {
            // �v���C���[�̏���
            print("���Ȃ��̏����I");
        }
        else {
            // �v���C���[�̕���
            print("���Ȃ��̕����I");
        }

        print("");
        print("Enter�Ń��j���[�ɖ߂�");
    }

}; // namespace GAME13