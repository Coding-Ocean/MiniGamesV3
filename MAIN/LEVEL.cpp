#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include"LEVEL.h"
LEVEL::LEVEL(class MAIN* main) 
	:Main(main) 
{
	//�����t�@�C�����Đ�����B
	//��������Ă����Ȃ��ƂȂ����A�P���ڂ̍Đ����x������B
	playSound(loadSound("../main/assets/silence.wav"));
}
LEVEL::~LEVEL()
{
	refreshCntnr();
	releaseAllSound();
}