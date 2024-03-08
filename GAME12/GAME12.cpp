#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME12.h"

namespace GAME12
{
	int GAME::create()
	{
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
		//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
		/*Px = width / 2;
		Py = height / 2;
		Radius = 200;*/
       
		return 0;
	}

	void GAME::destroy()
	{
		//create()��new�����ꍇ�͂�����delete���邱��
	}

    void GAME::proc()
    {

        //�V�[���؂�ւ�
        if (State == TITLE)title();
        else if (State == INIT)init();
        else if (State == PLAY)play();
        else if (State == OVER)over();
    }
    int bonus = 0;
    int Score = 0;
    //�u���b�N�p�^�[���I�t�Z�b�g
    int Offsets[7][3][2] = {
        //��������...0
        -1,0,   1,0,  2,0,
        //��
        //������....1
        -1,-1, -1,0,  1,0,
        //  �@��
        //������....2
        -1,0,   1,-1, 1,0,
        //����
        //�@����....3
        -1,0,   0,1,  1,1,
        //�@����
        //����  ....4
         1,0,   0,1, -1,1,
         //�@��
         //������....5
         -1,0,   0,-1, 1,0,
         //����
         //����......6
          1,0,   0,1,  1,1,
    };

   // HSB����RGB�ւ̕ϊ��֐�
   void GAME::hsbToRgb(float h, float s, float v, int& r, int& g, int& b) {
        if (s == 0) {
            r = g = b = static_cast<int>(v * 255);
        }
        else {
            float f = (h - static_cast<int>(h)) * 6.0f;
            float p = v * (1.0f - s);
            float q = v * (1.0f - s * f);
            float t = v * (1.0f - (s * (1.0f - f)));
            switch (static_cast<int>(h)) {
            case 0:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(t * 255);
                b = static_cast<int>(p * 255);
                break;
            case 1:
                r = static_cast<int>(q * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(p * 255);
                break;
            case 2:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(v * 255);
                b = static_cast<int>(t * 255);
                break;
            case 3:
                r = static_cast<int>(p * 255);
                g = static_cast<int>(q * 255);
                b = static_cast<int>(v * 255);
                break;
            case 4:
                r = static_cast<int>(t * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(v * 255);
                break;
            default:
                r = static_cast<int>(v * 255);
                g = static_cast<int>(p * 255);
                b = static_cast<int>(q * 255);
                break;
            }
        }
    }
    void GAME::title()
    {
        //�`��--------------------------------------------------
        clear(60, 60, 60);
        //�e�L�X�g���
        fill(0, 255, 0);
        textSize(100);
        text("�{�[�i�X�e�g���X", 600, 450);
        fill(0, 0, 0);
        textSize(40);
        text("�N���b�N�ŃQ�[���X�^�[�g", 750, 500);
        text("Enter�Ń��j���[�ɖ߂�", 750, 550);
        //�V�[���؂�ւ�-----------------------------------------
        if (isTrigger(MOUSE_LBUTTON)) {
            //���̃V�[�P���X
            State = INIT;
            return;
        }
        //���j���[�ɖ߂�-----------------------------------------
        if (isTrigger(KEY_ENTER)) {
            main()->backToMenu();
        }
    }
		//�����̓��C�����[�v����Ăяo����Ă���!!!!!
        void GAME::init() {
            clear(60, 60, 60);
            fill(0, 0, 0);
            textSize(60);
            text("�E�ւP�}�X:D", 750, 500);
            text("���ւP�}�X:A", 750, 550);
            text("��]:W", 750, 600);
            text("����:S", 750, 650);
            textSize(40);
            text("�s���N�̎l�p���u���b�N���o��������̓{�[�i�X�^�C���I", 750, 700);
            text("���̂��Ƃ̈�񂾂��_����10�{�I", 750, 750);
            text("�N���b�N�Ői��", 750, 900);
            //�ǂƔw�i�̐F�ԍ���Stage2�����z��ɃZ�b�g
            for (int y = 0; y < ROWS; y++) {
                Stage[y][0] = Stage[y][COLS - 1] = WALL;
                for (int x = 1; x < COLS - 1; x++) {
                    Stage[y][x] = BACK;
                    if (y == ROWS - 1) {
                        Stage[y][x] = WALL;
                    }
                }
            }
            //�u���b�N�����l
            X = 5;
            Y = 1;
            R = 0;
            PtnNo = random() % 7;
            setPtnPosition();
            if (isTrigger(MOUSE_LBUTTON)) {
                State = PLAY;
                return;
            }
        }
        void GAME::drawStage() {
            void complete();
            angleMode(DEGREES);
            colorMode(HSV);
            strokeWeight(20);
            rectMode(CENTER);
            for (int y = 0; y < ROWS; y++) {
                for (int x = 0; x < COLS; x++) {
                    int no = Stage[y][x];
                    //int r, g, b;
                    //hsbToRgb(Color[no].hue, Color[no].satu, Color[no].value, r, g, b);
                    stroke(Color[no].hue, Color[no].satu, Color[no].value);
                    //stroke(Color[no]);
                     
                    fill(0,0,100);
                    rect(Size / 2 + Size * x, Size / 2 + Size * y, Size / 2, Size / 2);
                    if (no == 6) {
                        bonus = 1;
                    }
                    if (bonus == 1) {
                        fill(255);
                        textSize(100);
                        text("�{�[�i�X�^�C���I" ,1000,100);
                    }
                }
            }
            // �X�R�A��\��
            fill(255);
            textSize(40);
            text((let)"Score:" + Score,0,100);
            //text("Score:",0,0);
            //text((let)Score,100,0);
        }
        void GAME::setPtnPosition() {
            //��u���b�N�ʒu
            Px[0] = X;
            Py[0] = Y;
            //��]��
            int r = R % 4;

            for (int i = 0; i < 3; i++) {
                //���݂̃u���b�N�p�^�[���̃I�t�Z�b�g�l���擾
                int ofsX = Offsets[PtnNo][i][0];
                int ofsY = Offsets[PtnNo][i][1];
                //��]���ɉ����ĂX�O�x����]������
                for (int j = 0; j < r; j++) {
                    int w = ofsX;
                    ofsX = -ofsY;
                    ofsY = w;
                }
                //�ʒu����
                Px[i + 1] = X + ofsX;
                Py[i + 1] = Y + ofsY;
            }
        }
        void GAME::setPtnNoToStage() {
            setPtnPosition();
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                Stage[y][x] = PtnNo;
            }
        }
        void GAME::delPtnNoFromStage() {
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                Stage[y][x] = BACK;
            }
        }
        int GAME::collision() {
            setPtnPosition();
            int flag = 0;
            for (int i = 0; i < 4; i++) {
                int x = Px[i];
                int y = Py[i];
                if (Stage[y][x] != BACK) {
                    flag = 1;
                }
            }
            return flag;
        }
        void GAME::complete() {
            for (int y = 1; y < ROWS - 1; y++) {
                int flag = 1;
                for (int x = 1; x < COLS - 1; x++) {
                    if (Stage[y][x] == BACK) {
                        flag = 0;
                    }
                }
                if (flag) {
                    if (bonus == 0) {
                        Score += 1000;
                    }
                    else if (bonus == 1) {
                        Score += 10000;
                        bonus = 0;
                    }
                    //��������̂ŃX���C�h
                    for (int upy = y - 1; upy >= 0; upy--) {
                        for (int x = 1; x < COLS - 1; x++) {
                            Stage[upy + 1][x] = Stage[upy][x];
                        }
                    }
                }
            }
        }
        void GAME::play() {
            //���݂̃p�^�[���ԍ��i�F�ԍ��j���X�e�[�W�������
            delPtnNoFromStage();
            //�ړ��A��]
            int dy = 0, dx = 0, dr = 0;;
            if ((++LoopCnt %= 15) == 0)dy = 1;
            if (isTrigger(KEY_D))dx = 1;
            if (isTrigger(KEY_A))dx = -1;
            if (isTrigger(KEY_W))dr = 1;
            if (isTrigger(KEY_S))FallFlag = 1;
            if (FallFlag)dy = 1;
            Y += dy;
            X += dx;
            R += dr;
            if (collision()) {
                //���̈ʒu�A��]�ɖ߂�
                Y -= dy;
                X -= dx;
                R -= dr;
                FallFlag = 0;
                if (dy == 1 && dx == 0 && dr == 0) {
                    //�ς��点��
                    setPtnNoToStage();
                    //�s��������Ă�����X���C�h������
                    complete();
                    //�V�����u���b�N�a��
                    X = 5;
                    Y = 1;
                    R = 0;
                    PtnNo = random() % 7;
                    if (collision()) {
                        State = OVER;
                    }
                }
            }
            //�p�^�[���ԍ��i�F�ԍ��j���X�e�[�W�ɃZ�b�g
            setPtnNoToStage();

            //�`��
            clear(0);
            drawStage();
        }

        void GAME::over() {
            clear(255,0,0);
            //�Q�[���I�[�o�[�e�L�X�g           
            fill(0, 0, 255);
            textSize(80);
            text("�f�������n������",650,450 );
            text("SPACE�L�[�Ń^�C�g���ɖ߂�", 500,550);
            if (isTrigger(KEY_SPACE)) {
                State = TITLE;
            }
        }

        void GAME::gmain() {
            window(Size * COLS*2, Size * ROWS,full);
        }

		/* //�`��--------------------------------------------------
		clear(255, 255, 255);

		//�e�L�X�g���
		fill(0);
		textSize(100);
		text("Enter�Ń��j���[�ɖ߂�", 0, height);
		print(12);
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}*/
	}



