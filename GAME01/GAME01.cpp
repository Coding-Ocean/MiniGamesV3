#include "../../libOne/inc/libOne.h"
#include "../MAIN/LEVEL_FACTORY.h"
#include "../MAIN/MAIN.h"
#include "GAME01.h"

void GAME01::create()
{
	//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

	//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
	//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
	Px = width / 2;
	Py = height / 2;
	Radius = 200;
}

void GAME01::destroy()
{
	//create()��new�����ꍇ�͂�����delete���邱��
}

void GAME01::proc()
{
	//�����̓��C�����[�v����Ăяo����Ă���!!!!!
	Hue += 1;
	//�`��--------------------------------------------------
	colorMode(HSV);
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
	//���j���[�ɖ߂�------------------------------------------
	if (isTrigger(KEY_ENTER)) {
		main()->backToMenu();
	}
}

