#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include"CONTAINER.h"
#include "GAME14.h"
namespace GAME14
{

	int GAME::create()
	{
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
		//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
		
		return 0;
	}

	void GAME::init()
	{
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
		//�e�L�X�g���
		fill(0);
		textSize(100);
		text("Enter�Ń��j���[�ɖ߂�", 0, height);
		print(14);
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
void GAME::player(){}
void GAME::building(){}
void GAME::title(){}
void GAME::stage(){}
void GAME::game_crear(){}
void GAME::game_over(){}

}
