#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME04.h"
namespace GAME04
{
	int GAME::create()
	{
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
		//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
		Px = width / 2;
		Py = height / 2;
		Radius = 200;

		return 0;
	}

	void GAME::destroy()
	{
		//create()��new�����ꍇ�͂�����delete���邱��
	}

	void GAME::proc()
	{
		//�����̓��C�����[�v����Ăяo����Ă���!!!!!

		//�`��--------------------------------------------------
		clear(255, 255, 255);
		//�~
		strokeWeight(50);
		stroke(0);
		fill(255, 0, 0);
		circle(Px, Py, Radius * 2);
		//�e�L�X�g���
		fill(0);
		textSize(100);
		text("Enter�Ń��j���[�ɖ߂�", 0, height);
		print(4);
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
}
