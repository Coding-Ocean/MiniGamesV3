#include "../../libOne/inc/libOne.h"
#include "LEVEL.h"
#include "TRANSITION_EFFECT.h"
#include "MAIN.h"

MAIN::MAIN()
{
	window(1920, 1080, full);
	//�X�^�[�g���̃��x��������
	LevelFactory = new LEVEL_FACTORY(this);
	CurrentLevelId = NextLevelId = LEVEL_FACTORY::MENU_ID;
	Level = LevelFactory->create(CurrentLevelId);
	Level->create();
	//�؂�ւ����ʃI�u�W�F�N�g
	Transition = new TRANSITION_EFFECT;

	initDeltaTime();
}

MAIN::~MAIN()
{
	Level->destroy();
	delete Level;
	delete Transition;
}

void MAIN::run()
{
	//���C�����[�v
	while (notQuit) {

		setDeltaTime();
		Level->proc();
		Transition->proc();

		//Level->proc()���Ń��x����؂�ւ��Ă��Ȃ�
		if (CurrentLevelId == NextLevelId) {
			continue;
		}
		//Level->proc()���Ń��x����؂�ւ����������ɗ���
		Transition->outStart();
		//��ʐ؂�ւ����ʏI����ALevel�؂�ւ�
		if (Transition->outEndFlag()) {
			Level->destroy();
			delete Level;
			CurrentLevelId = NextLevelId;
			Level = LevelFactory->create(CurrentLevelId);
			Level->create();
			Transition->inStart();
		}
	}
}

void gmain()
{
	MAIN main;
	main.run();
}
