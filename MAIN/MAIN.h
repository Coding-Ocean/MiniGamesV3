#pragma once
#include "LEVEL_FACTORY.h"
class MAIN
{
public:
	MAIN();
	~MAIN();
	void run();
	void setNextLevelId(LEVEL_FACTORY::LEVEL_ID nextLevelId) { 
		NextLevelId = nextLevelId; 
	}
	void backToMenu() {
		NextLevelId = LEVEL_FACTORY::MENU_ID;
	}
private:
	//���x���̃V���v���t�@�N�g��
	class LEVEL_FACTORY* LevelFactory = nullptr;
	//���ݎ��s���̃��x��ID
	LEVEL_FACTORY::LEVEL_ID CurrentLevelId;
	//���Ɏ��s�\��̃��x��ID
	LEVEL_FACTORY::LEVEL_ID NextLevelId;
	//���s���̃��x��
	class LEVEL* Level = nullptr;
	//�؂�ւ�����
	class TRANSITION_EFFECT* Transition = nullptr;
};
