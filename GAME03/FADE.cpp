#include "../../libOne/inc/window.h"
#include "../../libOne/inc/graphic.h"
#include "FADE.h"
namespace GAME03
{
	FADE::FADE()
	{
		Alpha = 255;
		Red = 0;
		Green = 0;
		Blue = 0;
		//�t�F�[�h�A�E�g���J�n����t�F�[�h�C�����I���܂ł̎��ԁi�b�j
		float time = 1.0f;
		Speed = 255 / (time * 0.5f);
		State = IN_START;
	}

	FADE::~FADE()
	{
	}

	void FADE::setTime(float time)
	{
		Speed = 255 / (time * 0.5f);
	}

	void FADE::inStart()
	{
		if (State == OUT_END) {
			State = IN_START;
		}
	}

	bool FADE::inEndFlag()
	{
		return State == IN_START;
	}

	void FADE::outStart()
	{
		if (State == IN_END) {
			State = OUT_START;
		}
	}

	bool FADE::outEndFlag()
	{
		return State == OUT_END;
	}

	void FADE::proc()
	{
		//�t�F�[�h�C�����̓A�E�g���I�����Ă���Ƃ��͉������Ȃ�
		if (State == IN_END ||
			State == OUT_END) {
			return;
		}
		//�t�F�[�h�C���E�A�E�g���ʏ���
		noStroke();
		rectMode(CORNER);
		colorMode(RGB);
		fill(Red, Green, Blue, Alpha);
		//�t�F�[�h�C��
		if (State == IN_START) {
			rect(0, 0, width, height);
			Alpha -= Speed * delta;
			if (Alpha <= 0) {
				Alpha = 0;
				State = IN_END;
			}
			return;
		}
		//�t�F�[�h�A�E�g
		if (State == OUT_START) {
			rect(0, 0, width, height);
			Alpha += Speed * delta;
			if (Alpha >= 255) {
				Alpha = 255;
				State = OUT_END;
			}
		}
	}
}
