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
        if (State == TITLE)Title();
        else if (State == PLAY)Play();
        else if (State == CLEAR)Clear();
        // �����̓��C�����[�v����Ăяo����Ă���
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
       

        // �V�[���؂�ւ�
        if (isTrigger(MOUSE_LBUTTON)) {
            Init();
            State = PLAY;
            return;
        }

        // ���j���[�ɖ߂�
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }

    void GAME::Init()
    {
        // �����������i����͓��ɉ������Ȃ��j
    }

    void GAME::Play()
    {
        // ��ʕ`��
        clear(255, 255, 255);

        // �e�L�X�g���
        fill(0);
        print("A�ŃO�[");
        print("S�Ń`���L");
        print("D�Ńp�[");
        print("�^�C�g���ɖ߂�");

        // �v���C���[�̓��͂��󂯎��
        if (isTrigger(KEY_A)) {
            playerHand = ROCK;
            determineWinner();
        }
        else if (isTrigger(KEY_S)) {
            playerHand = SCISSORS;
            determineWinner();
        }
        else if (isTrigger(KEY_D)) {
            playerHand = PAPER;
            determineWinner();
        }

        // �V�[���؂�ւ��i��F�N���A�t���O���������ꍇ�j
        if (ClearFlag) {
            State = CLEAR;
        }
    }

        


    void GAME::determineWinner()
    {
        // �R���s���[�^�̎�������_���ɑI��
        computerHand = static_cast<Hand>(rand() % 3);

        // �v���C���[�̎�ƃR���s���[�^�̎��\��
        print("���Ȃ��̎�: ");
        if (playerHand == ROCK)
            print("�O�[");
        else if (playerHand == PAPER)
            print("�p�[");
        else
            print("�`���L");

        print("�R���s���[�^�̎�: ");
        if (computerHand == ROCK)
            print("�O�[");
        else if (computerHand == PAPER)
            print("�p�[");
        else
            print("�`���L");

        // ���s����ƌ��ʕ\��
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
            State = CLEAR; // �������ꍇ�AClear() �֐��ɑJ�ڂ���
        }
    }

    void GAME::Clear()
    {
        // ��ʕ`��
        clear(0, 0, 255);

        // �e�L�X�g���
        fill(255, 255, 255);
        print("�N���b�N�Ń^�C�g���ɖ߂�");

        // �V�[���؂�ւ��i�}�E�X�N���b�N���������ꍇ�j
        if (isTrigger(MOUSE_LBUTTON)) {
            State = TITLE;
        }
    }

}; // namespace GAME13