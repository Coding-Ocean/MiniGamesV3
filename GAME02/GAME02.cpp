#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME02.h"
namespace GAME02
{
	int GAME::create()
	{
		//ここでは主に画像と音データを読み込む

		pat[0] = loadImage("..\\main\\assets\\game02\\BB.png");
		pat[1] = loadImage("..\\main\\assets\\game02\\RB.png");
		pat[2] = loadImage("..\\main\\assets\\game02\\Replay.png");
		pat[3] = loadImage("..\\main\\assets\\game02\\Cherrie.png");
		pat[4] = loadImage("..\\main\\assets\\game02\\Orange.png");
		pat[5] = loadImage("..\\main\\assets\\game02\\Bell.png");
		pat[6] = loadImage("..\\main\\assets\\game02\\ドル箱.png");
		pat[7] = loadImage("..\\main\\assets\\game02\\gogoSDOT.png");
		pat[8] = loadImage("..\\main\\assets\\game02\\gogoSDOT R.png");

		sndpat[0] = loadSound("..\\main\\assets\\game02\\kaiten kaisi.wav");
		sndpat[1] = loadSound("..\\main\\assets\\game02\\kaiten teisi.wav");
		sndpat[2] = loadSound("..\\main\\assets\\game02\\haraidasi.wav");
		sndpat[3] = loadSound("..\\main\\assets\\game02\\BARharaidasi.wav");
		sndpat[4] = loadSound("..\\main\\assets\\game02\\BBharaidasi.wav");
		sndpat[5] = loadSound("..\\main\\assets\\game02\\GOD.wav");
		sndpat[6] = loadSound("..\\main\\assets\\game02\\BBkakutei.wav");
		sndpat[7] = loadSound("..\\main\\assets\\game02\\CRシンフォギア.wav");
		sndpat[8] = loadSound("..\\main\\assets\\game02\\ガコマシンガン.wav");
		sndpat[9] = loadSound("..\\main\\assets\\game02\\ガコッ.wav");
		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。

		return 0;
	}

	void GAME::Init() {
		initflag = 1;

		//リールの図柄
		//0 = 7図柄　1 = BAR　2 = Replay　3 = チェリー　4 = オレンジ　5 = ベル
		reel1.Reel[0] = 2;   reel2.Reel[0] = 4;   reel3.Reel[0] = 5;
		reel1.Reel[1] = 4;	 reel2.Reel[1] = 2;	  reel3.Reel[1] = 4;
		reel1.Reel[2] = 0;	 reel2.Reel[2] = 0;	  reel3.Reel[2] = 0;
		reel1.Reel[3] = 3;	 reel2.Reel[3] = 4;	  reel3.Reel[3] = 2;
		reel1.Reel[4] = 1;	 reel2.Reel[4] = 3;	  reel3.Reel[4] = 5;
		reel1.Reel[5] = 5;	 reel2.Reel[5] = 1;	  reel3.Reel[5] = 4;
		reel1.Reel[6] = 2;	 reel2.Reel[6] = 2;	  reel3.Reel[6] = 3;
		reel1.Reel[7] = 4;	 reel2.Reel[7] = 3;	  reel3.Reel[7] = 0;
		reel1.Reel[8] = 5;	 reel2.Reel[8] = 4;	  reel3.Reel[8] = 2;
		reel1.Reel[9] = 2;	 reel2.Reel[9] = 2;	  reel3.Reel[9] = 5;
	   reel1.Reel[10] = 4;	reel2.Reel[10] = 1;  reel3.Reel[10] = 4;
	   reel1.Reel[11] = 0;	reel2.Reel[11] = 4;  reel3.Reel[11] = 3;
	   reel1.Reel[12] = 3;	reel2.Reel[12] = 5;  reel3.Reel[12] = 2;
	   reel1.Reel[13] = 1;	reel2.Reel[13] = 0;  reel3.Reel[13] = 0;
	   reel1.Reel[14] = 5;	reel2.Reel[14] = 2;  reel3.Reel[14] = 5;
	   reel1.Reel[15] = 2;	reel2.Reel[15] = 1;  reel3.Reel[15] = 4;
	   reel1.Reel[16] = 4;	reel2.Reel[16] = 4;  reel3.Reel[16] = 3;
	   reel1.Reel[17] = 5;	reel2.Reel[17] = 5;  reel3.Reel[17] = 2;
	   reel1.Reel[18] = 1;	reel2.Reel[18] = 1;  reel3.Reel[18] = 1;
	   reel1.Reel[19] = 4;	reel2.Reel[19] = 2;  reel3.Reel[19] = 3;
	   reel1.Reel[20] = 5;	reel2.Reel[20] = 3;  reel3.Reel[20] = 2;

		//図柄のpx,py
		reel1.Px = width / 2 - 334;   reel2.Px = width / 2;   reel3.Px = width / 2 + 334;

		for (int i = 0; i < 21; i++) {
			reel1.Py[i] = (height / 2 - 1824) + i * 182.4f;
			reel2.Py[i] = (height / 2 - 1824) + i * 182.4f;
			reel3.Py[i] = (height / 2 - 1824) + i * 182.4f;
		}

		for (int i = 0; i < 3; i++) {
			reelC1.Py[i] = (height / 2 - 182.4f) + (i * 182.4f);
			reelC2.Py[i] = (height / 2 - 182.4f) + (i * 182.4f);
			reelC3.Py[i] = (height / 2 - 182.4f) + (i * 182.4f);
		}

		//回転の速さ
		ReelsSpeed = 45.6f;

		//リールが止まるべきところ
		StopPy = height / 2;

		//リールを回したあと、リールを止められるようになるまでの時間
		inputAcceptanceTime = 60;

		//メダルの枚数
		medal = 46;

		//設定
		optionSeed = random() % 6;
		if (optionSeed == 0)option = 127;
		if (optionSeed == 1)option = 128;
		if (optionSeed == 2)option = 142;
		if (optionSeed == 3)option = 148;
		if (optionSeed == 4)option = 161;
		if (optionSeed == 5)option = 168;
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
	}

	void GAME::reelCheck() {
		for (int x = 0; x < 21; x++) {
			for (int y = 0; y < 21; y++) {
				for (int z = 0; z < 21; z++) {
					//揃っているかどうかの判定
					if (reel1.Py[x] >= reelC1.Py[0] - 20 && reel1.Py[x] <= reelC1.Py[0] + 20 &&
						reel2.Py[y] >= reelC2.Py[0] - 20 && reel2.Py[y] <= reelC2.Py[0] + 20 &&
						reel3.Py[z] >= reelC3.Py[0] - 20 && reel3.Py[z] <= reelC3.Py[0] + 20 &&
						reel1.Reel[x] == reel2.Reel[y] && reel2.Reel[y] == reel3.Reel[z]) {
						if (reel1.Reel[x] == 0 && peka == 0)medalCnt += 480;
						else if (reel1.Reel[x] == 0)medalCnt += 240;
						if (reel1.Reel[x] == 1)medalCnt += 96;
						if (reel1.Reel[x] == 2)medalCnt += 3;
						if (reel1.Reel[x] == 4)medalCnt += 7;
						if (reel1.Reel[x] == 5)medalCnt += 14;
					}

					if (reel1.Py[x] >= reelC1.Py[1] - 20 && reel1.Py[x] <= reelC1.Py[1] + 20 &&
						reel2.Py[y] >= reelC2.Py[1] - 20 && reel2.Py[y] <= reelC2.Py[1] + 20 &&
						reel3.Py[z] >= reelC3.Py[1] - 20 && reel3.Py[z] <= reelC3.Py[1] + 20 &&
						reel1.Reel[x] == reel2.Reel[y] && reel2.Reel[y] == reel3.Reel[z]) {
						if (reel1.Reel[x] == 0 && peka == 0)medalCnt += 480;
						else if (reel1.Reel[x] == 0)medalCnt += 240;
						if (reel1.Reel[x] == 1)medalCnt += 96;
						if (reel1.Reel[x] == 2)medalCnt += 3;
						if (reel1.Reel[x] == 4)medalCnt += 7;
						if (reel1.Reel[x] == 5)medalCnt += 14;
					}

					if (reel1.Py[x] >= reelC1.Py[2] - 20 && reel1.Py[x] <= reelC1.Py[2] + 20 &&
						reel2.Py[y] >= reelC2.Py[2] - 20 && reel2.Py[y] <= reelC2.Py[2] + 20 &&
						reel3.Py[z] >= reelC3.Py[2] - 20 && reel3.Py[z] <= reelC3.Py[2] + 20 &&
						reel1.Reel[x] == reel2.Reel[y] && reel2.Reel[y] == reel3.Reel[z]) {
						if (reel1.Reel[x] == 0 && peka == 0)medalCnt += 480;
						else if (reel1.Reel[x] == 0)medalCnt += 240;
						if (reel1.Reel[x] == 1)medalCnt += 96;
						if (reel1.Reel[x] == 2)medalCnt += 3;
						if (reel1.Reel[x] == 4)medalCnt += 7;
						if (reel1.Reel[x] == 5)medalCnt += 14;
					}

					if (reel1.Py[x] >= reelC1.Py[0] - 20 && reel1.Py[x] <= reelC1.Py[0] + 20 &&
						reel2.Py[y] >= reelC2.Py[1] - 20 && reel2.Py[y] <= reelC2.Py[1] + 20 &&
						reel3.Py[z] >= reelC3.Py[2] - 20 && reel3.Py[z] <= reelC3.Py[2] + 20 &&
						reel1.Reel[x] == reel2.Reel[y] && reel2.Reel[y] == reel3.Reel[z]) {
						if (reel1.Reel[x] == 0 && peka == 0)medalCnt += 480;
						else if (reel1.Reel[x] == 0)medalCnt += 240;
						if (reel1.Reel[x] == 1)medalCnt += 96;
						if (reel1.Reel[x] == 2)medalCnt += 3;
						if (reel1.Reel[x] == 4)medalCnt += 7;
						if (reel1.Reel[x] == 5)medalCnt += 14;
					}

					if (reel1.Py[x] >= reelC1.Py[2] - 20 && reel1.Py[x] <= reelC1.Py[2] + 20 &&
						reel2.Py[y] >= reelC2.Py[1] - 20 && reel2.Py[y] <= reelC2.Py[1] + 20 &&
						reel3.Py[z] >= reelC3.Py[0] - 20 && reel3.Py[z] <= reelC3.Py[0] + 20 &&
						reel1.Reel[x] == reel2.Reel[y] && reel2.Reel[y] == reel3.Reel[z]) {
						if (reel1.Reel[x] == 0 && peka == 0)medalCnt += 480;
						else if (reel1.Reel[x] == 0)medalCnt += 240;
						if (reel1.Reel[x] == 1)medalCnt += 96;
						if (reel1.Reel[x] == 2)medalCnt += 3;
						if (reel1.Reel[x] == 4)medalCnt += 7;
						if (reel1.Reel[x] == 5)medalCnt += 14;
					}
					//チェリー判定
					if (reel1.Py[x] >= reelC1.Py[0] - 20 && reel1.Py[x] <= reelC1.Py[0] + 20 &&
						reel1.Py[y] >= reelC1.Py[1] - 20 && reel1.Py[y] <= reelC1.Py[1] + 20 &&
						reel1.Py[z] >= reelC1.Py[2] - 20 && reel1.Py[z] <= reelC1.Py[2] + 20) {
						if (reel1.Reel[x] == 3)medalCnt += 2;
						if (reel1.Reel[y] == 3)medalCnt += 2;
						if (reel1.Reel[z] == 3)medalCnt += 2;
					}
				}
			}
		}
	}

	void GAME::proc()
	{
		if (State == TITLE)Title();
		else if (State == PLAY)Play();
		//メニューに戻る------------------------------------------
		textSize(50);
		text("Enterでメニューに戻る", 0, height);
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::Title() {
		clear(128,128,128);
		if (isTrigger(KEY_P)) {
			State = PLAY;
		}
		fill(0, 0, 0);
		textSize(200);
		text("SDOT", width / 2 - 220, height / 2);
		textSize(100);
		text("Pキーでプレイ", width / 2 - 330, height / 2 + 200);
	}

	void GAME::Play() {

		if (initflag == 0) {
			Init();
		}

		if (reelCheckflag == 0) {
			reelCheck();
			reelCheckflag = 1;
		}

		rectMode(CENTER);
		clear(128, 128, 128);

		for (int i = 0; i < 21; i++) {
			image(reel1.Reel[i], reel1.Px, reel1.Py[i], 1, 0.3f);
			image(reel2.Reel[i], reel2.Px, reel2.Py[i], 1, 0.3f);
			image(reel3.Reel[i], reel3.Px, reel3.Py[i], 1, 0.3f);

			if (reel1.Py[i] >= 2538)reel1.Py[i] = height / 2 - 1824;
			if (reel2.Py[i] >= 2538)reel2.Py[i] = height / 2 - 1824;
			if (reel3.Py[i] >= 2538)reel3.Py[i] = height / 2 - 1824;

			if (reel1.reelRotateFlag == 1)reel1.Py[i] += ReelsSpeed;
			if (reel2.reelRotateFlag == 1)reel2.Py[i] += ReelsSpeed;
			if (reel3.reelRotateFlag == 1)reel3.Py[i] += ReelsSpeed;
		}

		if (reel1.reelRotateFlag == 0 && reel2.reelRotateFlag == 0 && reel3.reelRotateFlag == 0) {
			if (isTrigger(KEY_R) && medalCnt <= 0) {
				playSound(sndpat[0]);
				reel1.reelRotateFlag = 1;
				reel2.reelRotateFlag = 1;
				reel3.reelRotateFlag = 1;
				gameCnt++;
				haraidasiflag = 0;
				medal -= 3;
			}
		}
		else
		{
			inputAcceptanceTime--;
		}

		if (inputAcceptanceTime < 0) {
			for (int i = 0; i < 21; i++) {
				if (isPress(KEY_G) && reel1.reelRotateFlag == 1) {
					if (reel1.Py[i] <= StopPy && reel1.Py[i] >= StopPy - 182.4f) {
						reel1.reelStopTime = (StopPy - reel1.Py[i]) / 45.6f;
						for (float j = 0; j <= reel1.reelStopTime; j++) {
							reel1.reelStopTime--;
							if (reel1.reelStopTime < 0) {
								reel1.reelRotateFlag = 0;
								if (reel1.reelRotateFlag == 0 && reel2.reelRotateFlag == 0 && reel3.reelRotateFlag == 0) {
									reelCheckflag = 0;
									inputAcceptanceTime = 60;
									if (peka != 0)peka = random() % option;
								}
								playSound(sndpat[1]);
							}
						}
					}
				}

				else if (isPress(KEY_H) && reel2.reelRotateFlag == 1) {
					if (reel2.Py[i] <= StopPy && reel2.Py[i] >= StopPy - 182.4f) {
						reel2.reelStopTime = (StopPy - reel2.Py[i]) / 45.6f;
						for (float j = 0; j <= reel2.reelStopTime; j++) {
							reel2.reelStopTime--;
							if (reel2.reelStopTime < 0) {
								reel2.reelRotateFlag = 0;
								if (reel1.reelRotateFlag == 0 && reel2.reelRotateFlag == 0 && reel3.reelRotateFlag == 0) {
									reelCheckflag = 0;
									inputAcceptanceTime = 60;
									if (peka != 0)peka = random() % option;
								}
								playSound(sndpat[1]);
							}
						}
					}
				}

				else if (isPress(KEY_J) && reel3.reelRotateFlag == 1) {
					if (reel3.Py[i] <= StopPy && reel3.Py[i] >= StopPy - 364.8f) {
						reel3.reelStopTime = (StopPy - reel3.Py[i]) / 45.6f;
						for (float j = 0; j <= reel3.reelStopTime; j++) {
							reel3.reelStopTime--;
							if (reel3.reelStopTime < 0) {
								reel3.reelRotateFlag = 0;
								if (reel1.reelRotateFlag == 0 && reel2.reelRotateFlag == 0 && reel3.reelRotateFlag == 0) {
									reelCheckflag = 0;
									inputAcceptanceTime = 60;
									if(peka != 0)peka = random() % option;
								}
								playSound(sndpat[1]);
							}
						}
					}
				}
			}
		}

		if (medalCnt > 0) {
			randomBB = random() % 3;
			if (haraidasiflag == 0 && medalCnt < 96) {
				playSound(sndpat[2]);
				haraidasiflag = 1;
			}
			if (haraidasiflag == 0 && medalCnt >= 96 && medalCnt < 240) {
				playSound(sndpat[3]);
				haraidasiflag = 1;
			}
			if (haraidasiflag == 0 && medalCnt >= 240) {
				if (randomBB == 0)playSound(sndpat[5]);
				if (randomBB == 1)playSound(sndpat[6]);
				if (randomBB == 2)playSound(sndpat[7]);
				if (randomBB == 3)playSound(sndpat[8]);
				haraidasiflag = 1;
				peka = 1;
			}
			medal++;
			medalCnt--;
		}

		fill(128, 128, 128);

		rect(width / 2, height / 2 - 547.2f, width, height / 2);
		rect(width / 2, height / 2 + 547.2f, width, height / 2);

		if (medal / 500 >= 1) {
			for (int i = 0; i > -(medal / 500); i--) {
				image(pat[6], width - 100, height - 55.2f + (i * 50), 1, 0.3f);
			}
		}

		if (peka == 0 && pressflag == 0) {
			image(pat[8], 300, height - 200, 1, 0.5f);
		}
		else {
			playSound(sndpat[9]);
			image(pat[7], 300, height - 200, 1, 0.5f);
		}
		fill(0);
		//テキスト情報
		if (isPress(KEY_Z) && isPress(KEY_O)) {
			if (optionSeed == 0)text("設定６", 100, 100);
			if (optionSeed == 1)text("設定５", 100, 100);
			if (optionSeed == 2)text("設定４", 100, 100);
			if (optionSeed == 3)text("設定３", 100, 100);
			if (optionSeed == 4)text("設定２", 100, 100);
			if (optionSeed == 5)text("設定１", 100, 100);
		}
		fill(0);
		textSize(50);
		text("Rで回転", 200, height / 2);
		text("G", reel1.Px, height - 200);
		text("H", reel2.Px, height - 200);
		text("J", reel3.Px, height - 200);
		text((let)"回転数" + gameCnt, 200, height / 2 - 200);
		text((let)"メダル" + medal, 100, height / 2 + 200);
		//print(2);
	}
}