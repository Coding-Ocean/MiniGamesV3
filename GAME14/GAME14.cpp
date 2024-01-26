#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"BUILDING.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include "GAME14.h"
namespace GAME14
{

	int GAME::create()
	{
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���

		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
		//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
		Container = new CONTAINER();	
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[GAME_OVER_ID] = new GAME_OVER(this);
		
		Player = new PLAYER(this);
		Building = new BUILDING(this);

		Container->load();
		for (int i = 0; i < NUM_SCENES; i++) {
			Scenes[i]->create();
		}
		Player->create();
		Building->create();
		changeScene(TITLE_ID);

		return 0;
	}

	void GAME::init()
	{
	}

	void GAME::destroy()
	{
		//create()��new�����ꍇ�͂�����delete���邱��
		delete Building;
		delete Player;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		//�����̓��C�����[�v����Ăяo����Ă���!!!!!

		//�`��--------------------------------------------------
		Scenes[CurSceneId]->proc();
		//�e�L�X�g���
		fill(0);
		textSize(100);
		text("Enter�Ń��j���[�ɖ߂�", 0, height);
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
	}

}
