#include "../../libOne/inc/libOne.h"
#include "LEVEL.h"
#include "TRANSITION_EFFECT.h"
#include "MAIN.h"

MAIN::MAIN()
{
	window(1920, 1080, full);
	//���x���t�@�N�g������
	LevelFactory = new LEVEL_FACTORY(this);
	//�X�^�[�g���̃��x��������
	CurrentLevelId = NextLevelId = LEVEL_FACTORY::MENU_ID;
	Level = LevelFactory->create(CurrentLevelId);
	Level->create();
	//�؂�ւ����ʃI�u�W�F�N�g
	Transition = new TRANSITION_EFFECT;
}

MAIN::~MAIN()
{
	delete LevelFactory;
	Level->destroy();
	delete Level;
	delete Transition;
}

void MAIN::run()
{
	initDeltaTime();
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
			//���݂̃��x�������
			Level->destroy();
			delete Level;
			//���̃��x���𐶐�
			CurrentLevelId = NextLevelId;
			Level = LevelFactory->create(CurrentLevelId);
			Level->create();
			//�؂�ւ����ʃX�^�[�g
			Transition->inStart();
		}
	}
}

void gmain()
{
	MAIN main;
	main.run();
}
