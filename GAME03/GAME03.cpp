#include "../../libOne/inc/libOne.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"
#include "../../libOne/inc/sound.h"
#include "../MAIN/MAIN.h"
#include "../MAIN/GAME_BASE.h"
#include "FADE.h"
#include "GAME03.h"
namespace GAME03
{
	int GAME::create()
	{

		State = TITLE;
		Img1  = loadImage("..\\main\\assets\\game03\\desigh-1-4.png");
		Img2  = loadImage("..\\main\\assets\\game03\\desigh-1-5.png");
		Img3  = loadImage("..\\main\\assets\\game03\\desigh-1-6.png");
		Img4  = loadImage("..\\main\\assets\\game03\\desigh-1-7.png");
		Img5  = loadImage("..\\main\\assets\\game03\\settei.png");
		Img6  = loadImage("..\\main\\assets\\game03\\space.png");
		Img7  = loadImage("..\\main\\assets\\game03\\setumei.png");
		Img8  = loadImage("..\\main\\assets\\game03\\usoda.png");
		Snd0  = loadSound("..\\main\\assets\\game03\\BGM.wav");
		Snd0_1= loadSound("..\\main\\assets\\game03\\BGM2.wav");
		Snd1  = loadSound("..\\main\\assets\\game03\\maou_se_system23.wav");
		Snd2  = loadSound("..\\main\\assets\\game03\\間抜け7.wav");
		Snd3  = loadSound("..\\main\\assets\\game03\\歓声と拍手.wav");
		Snd4  = loadSound("..\\main\\assets\\game03\\get.wav");
		for (int i = 0; i < 19; i++) {
			char filename[128];
			sprintf_s(filename, "..\\main\\assets\\game03\\haikei_%d.png", i);
			imgs[i] = loadImage(filename);
		}
		//ここでは主に画像と音データを読み込む

		Fade = new FADE;
		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。

		return 0;

	}

	void GAME::destroy()
	{
		delete Fade;
		//create()でnewした場合はここでdeleteすること
	}

	void GAME::proc()
	{

		//シーン切り替え
		if      (State == TITLE)Title();
		else if (State == PLAY1)Play1();
		else if (State == PLAY2)Play2();
		else if (State == PLAY3)Play3();
		else if (State == PLAY4)Play4();
		else if (State == PLAY5)Play5();
		else if (State == CLEAR)Clear();
		else if (State == OVER) Over();

	}

	void GAME::Run()
	{
		initDeltaTime();
		setDeltaTime();
		Fade->proc();
		Fade->outStart();
		if (Fade->outEndFlag()) {
			destroy();
			Fade->inStart();
		}
	}

	void GAME::Title()
	{
		if (II % 3 == 0) {
			clear(0);
			image(Img1, 0, 0);
			image(Img4, 0, 0);
		}

		else if (II % 2 == 0) {
			clear(0);
			image(Img1, 0, 0);
			image(Img3, 0, 0);
		}

		else {
			clear(0);
			image(Img1, 0, 0);
			image(Img2, 0, 0);
		}

		fill(255, 255, 255);

		if (isTrigger(KEY_S)) {
			if (SS == 0) {
				SS += 1;
			}
			else {
				clear(0);
				image(Img1, 0, 0);
				SS = 0;
			}
		}

		if (loopBgm) {
			playLoopSound(Snd0);
			loopBgm = false;
		}
		cnt = 1; 
		font("UD デジタル 教科書体 N-R");
		textSize(40);

		if (SS == 1) {
			if (score < 101) {
				fill(114);
				text("最高記録：" + (let)score + "回", width / 2.3, height / 1.5);
			}
			else {
				fill(114);
				text("最高記録：--- 回", width / 2.3, height / 1.5);
			}
		}

		setVolume(Snd0,  -(100 - volume1) * (100 - volume1));
		setVolume(Snd0_1,-(100 - volume1) * (100 - volume1));
		setVolume(Snd1,  -(100 - volume2) * (100 - volume2));
		setVolume(Snd2,  -(100 - volume2) * (100 - volume2));
		setVolume(Snd3,  -(100 - volume2) * (100 - volume2));

		fill(114);
		text("Ｏキー:オプション", width / 20, height / 1.00625);
		text("Ｐキー:操作説明",   width /  4, height / 1.00625);

		if (isTrigger(KEY_Q)) {
			stopSound(Snd0);
			playSound(Snd1);
			Init();
			Run();
			State = PLAY1;
			return;
		}

		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

		if (isPress(KEY_SPACE) && isPress(KEY_C)) {
			stopSound(Snd0);
			playSound(Snd1);
			Init();
			State = PLAY2;
			return;
		}

		if (isTrigger(KEY_O)) {
			playSound(Snd1);
			Init();
			State = PLAY3;
			return;
		}
		if (isTrigger(KEY_P)) {
			playSound(Snd1);
			Init();
			State = PLAY4;
			return;
		}

		if (isPress(KEY_A)) {
			if (isPress(KEY_S)) {
				if (isPress(KEY_D)) {
					if (isPress(KEY_F)) {
						if (isPress(KEY_G)) {
							stopSound(Snd0);
							playSound(Snd1);
							Init();
							State = PLAY5;
							return;
						}
					}
				}
			}
		}

		if (TIME % 29 == 0) {
			II++;
		}

		TIME++;

		if (TIME >= 1000 || II >= 1000) {
			TIME = 0;
			II = 0;
		}
	}

	void GAME::Init()
	{
		ClearFlag = false;
		onlyOnce  = true;
		select    = true;
	}

	void GAME::run()
	{
		loopBgm  = true;
		loopBgm2 = true;
		hcnt     = 0;
	}

	void GAME::Play1()
	{
		clear(0);
		if (loopBgm2) {
			playLoopSound(Snd0_1);
			loopBgm2 = false;
		}

		++counter %= 19 * interval;
		int no = counter / interval;
		image(imgs[no], 0, 0);
		noStroke();
		fill(0, 0, 0, 125);
		rect(0, 0, 1920, 1080);

		fill(255);
		textSize(100 + (cnt / static_cast<float>(2)));
		text((let)cnt + "回目", width / 8 - (cnt / static_cast<float>(2)), height / 1.9);
		if (isTrigger(KEY_A)) {
			a = 0; s = 0; d = 0; f = 0; g = 0;
			a = 1;
			if (isTrigger(KEY_S)) {
				s = 1;
				if (isTrigger(KEY_D)) {
					d = 1;
					if (isTrigger(KEY_F)) {
						f = 1;
						if (isTrigger(KEY_G)) {
							g = 1;
							ClearFlag = true;
							
						}
					}
				}
			}
			cnt++;
		}
		if (a == 1) {
			text("A", width / 2.7, height / 1.9);
			if (s == 1) {
				text("S", width / 2.2, height / 1.9);
				if (d == 1) {
					text("D", width / 1.8, height / 1.9);
					if (f == 1) {
						text("F", width / 1.5, height / 1.9);
						if (g == 1) {
							text("G", width / 1.2, height / 1.9);
						}
					}
				}
			}
		}

		if (isTrigger(KEY_ENTER)) {
			stopSound(Snd0_1);
			run();
			State = TITLE;
			a = 0;
			s = 0;
			d = 0;
			f = 0;
			g = 0;
		}
		if (cnt >= 101) {
			stopSound(Snd0_1);
			run();
			State = OVER;
			a = 0;
			s = 0;
			d = 0;
			f = 0;
			g = 0;
		}
		fill(255);
		if (ClearFlag) {
			stopSound(Snd0_1);
			run();
			State = CLEAR;
			a = 0;
			s = 0;
			d = 0;
			f = 0;
			g = 0;
		}
	}

	void GAME::Play2()
	{
		clear(0);
		if (loopBgm2) {
			playLoopSound(Snd0_1);
			loopBgm2 = false;
		}
		fill(255);
		textSize(100);
		text((let)cnt + "回目", width / 8, height / 2);
		if (isTrigger(KEY_A)) {
			a = 0; s = 0;
			a = 1;
			if (isTrigger(KEY_S)) {
				s = 1;
				ClearFlag = true;

			}
			cnt++;
		}
		if (a == 1) {
			text("A", width / 2.7, height / 1.9);
			if (s == 1) {
				text("S", width / 2.2, height / 1.9);
			}
		}
		if (cnt >= 101) {
			stopSound(Snd0_1);
			run();
			State = OVER;
			a = 0;
			s = 0;
		}
		fill(255);
		if (ClearFlag) {
			stopSound(Snd0_1);
			run();
			State = CLEAR;
			a = 0;
			s = 0;
		} 
	}

	void GAME::Play3()
	{
		clear(0);
		image(Img5, 0, 0);
		image(Img6, 0, 0);
		fill(0);
		textSize(50);
		text("ＢＧＭ", width / 5.0, height / 3.0);
		text("ＳＥ",   width / 4.5, height / 1.6);

		if (isTrigger(KEY_W)) {
			select = true;
			scnt = 0;
		}
		if (isTrigger(KEY_S)) {
			select = false;
			scnt = 0;
		}

		strokeWeight(5.0);
		stroke(100);
		fill(255);
		line(width / 3.5, height / 3.15, width / 3.5 + 800, height / 3.15);
		line(width / 3.5, height / 1.65, width / 3.5 + 800, height / 1.65);
		circle(width / 3.5 + volume1 * 8.0, height / 3.15, 25);
		circle(width / 3.5 + volume2 * 8.0, height / 1.65, 25);

		fill(0);
		text((let)volume1, width / 1.4, height / 3.0);
		text((let)volume2, width / 1.4, height / 1.6);
		if (select == true) {
			scnt++;
			if (scnt % 3 == 0) {
				if (volume1 >= 0 && volume1 <= 100) {
					if (isPress(KEY_A)) {
						volume1--;
						if (volume1 < 0) {
							volume1 = 0;
						}
					}
					if (isPress(KEY_D)) {
						volume1++;
						if (volume1 > 100) {
							volume1 = 100;
						}

					}
				}
				scnt = 0;
			}
			fill(255, 0, 0);
			circle(width / 3.5 + volume1 * 8.0, height / 3.15, 25);
		}

		if (select == false) {
			scnt++;
			if (scnt % 3 == 0) {
				if (volume2 >= 0 && volume2 <= 100) {
					if (isPress(KEY_A)) {
						volume2--;
						if (volume2 < 0) {
							volume2 = 0;
						}
					}
					if (isPress(KEY_D)) {
						volume2++;
						if (volume2 > 100) {
							volume2 = 100;
						}
					}
				}
				scnt = 0;
			}
			fill(255, 0, 0);
			circle(width / 3.5 + volume2 * 8.0, height / 1.65, 25);
		}
		setVolume(Snd0,   -(100 - volume1) * (100 - volume1));
		setVolume(Snd0_1, -(100 - volume1) * (100 - volume1));
		setVolume(Snd1,   -(100 - volume2) * (100 - volume2));
		setVolume(Snd2,   -(100 - volume2) * (100 - volume2));
		setVolume(Snd3,   -(100 - volume2) * (100 - volume2));

		if (isTrigger(KEY_Q)) {
			playSound(Snd1);
		}
		fill(255);
		text("初期設定", width / 2.2, height / 1.1);
		if (isPress(KEY_SPACE)) {
			fill(255, 0, 0);
			text("初期設定", width / 2.2, height / 1.1);
			volume1 = 80;
			volume2 = 80;
		}
		fill(0);
		textSize(40);
		text("Enterキーでタイトルに戻る", width / 1.5, height / 1.00625);
		text("Ｑキー：音を鳴らす",width / 1.5, height / 1.05625);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}

	void GAME::Play4() {
		clear(0);
		image(Img7, 0, 0);
		text("Enterキーでタイトルに戻る", width / 1.5, height / 1.00625);
		if (isTrigger(KEY_ENTER)) {
			State = TITLE;
		}
	}

	void GAME::Play5() {
		clear(0);
		if (onlyOnce) {
			playSound(Snd4);
			onlyOnce = false;
		}
		if (isTrigger(KEY_Q)) {
			playSound(Snd4);
		}
		image(Img8, 0, 0);
		fill(255, 0, 0);
		textSize(100);
		text("ｳｿﾞﾀﾞﾄﾞﾝﾄﾞｺﾄﾞｰﾝ!", width / 4, height / 2);
		if (isTrigger(KEY_ENTER)) {
			run();
			State = TITLE;
		}
	}

	void GAME::Clear()
	{
		if (onlyOnce) {
			::Sleep(1000);
			playSound(Snd3);
			cnt--;
			onlyOnce = false;
		}
		hcnt++;
		clear(0, 0, 0);
		fill(255, 255, 255);
		textSize(100);
		text("Game Clear", width / 8, height / 2);
		text("結果：" + (let)cnt + "回", width / 8, height / 1.5);
		if (hcnt > 500) {
			textSize(50);
			text("スペースキーでタイトルに戻る", width / 2, height / 1.00625);
		}
		if (score > cnt) {
			score = cnt;
		}
		if (isTrigger(KEY_SPACE) && hcnt > 500) {
			stopSound(Snd0_1);
			run();
			::Sleep(1000);
			State = TITLE;
		}
	}

	void GAME::Over() 
	{
		if (onlyOnce){
			::Sleep(1000);
			playSound(Snd2); 
			onlyOnce = false;
		}
		hcnt++;
		clear(0, 0, 0);
		fill(255, 255, 255);
		textSize(100);
		text("Game Over", width / 8, height / 2);
		if (hcnt > 500) {
			textSize(50);
			text("スペースキーでタイトルに戻る", width / 2, height / 1.00625);
		}
		if (isTrigger(KEY_SPACE) && hcnt > 500) {
			stopSound(Snd0_1);
			run();
			::Sleep(1000);
			State = TITLE;
		}
	}

}
