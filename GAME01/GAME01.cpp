#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"

int GAME01::create()
{
	//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

	//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
	//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
	Px = width / 2;
	Py = height / 2;
	Radius = 200;

	Hue = 0;
	SpeedChangeHue = 60;

	return 0;
}

void GAME01::destroy()
{
	//create()��new�����ꍇ�͂�����delete���邱��
}

void GAME01::proc()
{
	//�����̓��C�����[�v����Ăяo����Ă���!!!!!

	//�X�V--------------------------------------------------
	Hue += SpeedChangeHue * delta;
	//�`��--------------------------------------------------
	colorMode(HSV);
	angleMode(DEGREES);//for HUE
	clear(255, 0, 255);
	//�~
	strokeWeight(50);
	stroke(0);
	fill(Hue, 255, 255);
	circle(Px, Py, Radius * 2);
	//�e�L�X�g���
	fill(0);
	textSize(100);
	text("Enter�Ń��j���[�ɖ߂�", 0, height);
	print(1);
	//���j���[�ɖ߂�------------------------------------------
	if (isTrigger(KEY_ENTER)) {
		main()->backToMenu();
	}
}

