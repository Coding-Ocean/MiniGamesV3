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
		//フェードアウトを開始からフェードインが終了までの時間（秒）
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
		//フェードイン又はアウトが終了しているときは何もしない
		if (State == IN_END ||
			State == OUT_END) {
			return;
		}
		//フェードイン・アウト共通処理
		noStroke();
		rectMode(CORNER);
		colorMode(RGB);
		fill(Red, Green, Blue, Alpha);
		//フェードイン
		if (State == IN_START) {
			rect(0, 0, width, height);
			Alpha -= Speed * delta;
			if (Alpha <= 0) {
				Alpha = 0;
				State = IN_END;
			}
			return;
		}
		//フェードアウト
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
