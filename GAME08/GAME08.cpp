#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME08.h"
namespace GAME08
{
	int GAME::create()
	{ 
		//ここでは主に画像と音データを読み込む

		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。

		    d.TitleBackImg = loadImage("..\\main\\assets\\game08\\Title.png");


		//プレイヤー側
			d.player.img[0] = loadImage("..\\main\\assets\\game08\\playerGu.png");
			d.player.img[1] = loadImage("..\\main\\assets\\game08\\playerChoki.png");
			d.player.img[2] = loadImage("..\\main\\assets\\game08\\playerPa.png");

		//PC側
			d.pc.img[0] = loadImage("..\\main\\assets\\game08\\pcGu.png");
			d.pc.img[1] = loadImage("..\\main\\assets\\game08\\pcChoki.png");
			d.pc.img[2] = loadImage("..\\main\\assets\\game08\\pcPa.png");

		//アニマルライフ
			d.lifeImg[0] = loadImage("..\\main\\assets\\game08\\Araiguma.png"); 
			d.lifeImg[1] = loadImage("..\\main\\assets\\game08\\Coala.png");
			d.lifeImg[2] = loadImage("..\\main\\assets\\game08\\Inu.png");
			d.lifeImg[3] = loadImage("..\\main\\assets\\game08\\Kitsune.png");
			d.lifeImg[4] = loadImage("..\\main\\assets\\game08\\Kuma.png");
			d.lifeImg[5] = loadImage("..\\main\\assets\\game08\\Lion.png");
			d.lifeImg[6] = loadImage("..\\main\\assets\\game08\\Neko.png");
			d.lifeImg[7] = loadImage("..\\main\\assets\\game08\\Penguin.png");
			d.lifeImg[8] = loadImage("..\\main\\assets\\game08\\Risu.png");
			d.lifeImg[9] = loadImage("..\\main\\assets\\game08\\Usagi.png");
			d.lifeImg[10] = loadImage("..\\main\\assets\\game08\\Duck.png");
			d.lifeImg[11] = loadImage("..\\main\\assets\\game08\\Kirin.png");
			d.lifeImg[12] = loadImage("..\\main\\assets\\game08\\Uma.png");
			d.lifeImg[13] = loadImage("..\\main\\assets\\game08\\Hitsuji.png");
			d.lifeImg[14] = loadImage("..\\main\\assets\\game08\\Zou.png");

		//じゃんけん背景
			d.SbackImg = loadImage("..\\main\\assets\\game08\\BackColor.png"); 

		//背景
			d.RbackImg = loadImage("..\\main\\assets\\game08\\BackWa.png"); 

		//あなた（文字）
			d.PnameImg[0] = loadImage("..\\main\\assets\\game08\\Yokobou.png"); 
			d.PnameImg[1] = loadImage("..\\main\\assets\\game08\\A.png");
			d.PnameImg[2] = loadImage("..\\main\\assets\\game08\\Na.png");
			d.PnameImg[3] = loadImage("..\\main\\assets\\game08\\Ta.png");
			d.PnameImg[4] = loadImage("..\\main\\assets\\game08\\Yokobou.png");

		//あいて（文字）
			d.EnameImg[0] = loadImage("..\\main\\assets\\game08\\Yokobou.png"); 
			d.EnameImg[1] = loadImage("..\\main\\assets\\game08\\A.png");
			d.EnameImg[2] = loadImage("..\\main\\assets\\game08\\I.png");
			d.EnameImg[3] = loadImage("..\\main\\assets\\game08\\Te.png");
			d.EnameImg[4] = loadImage("..\\main\\assets\\game08\\Yokobou.png");

		//VS（文字）
			d.VersusImg[0] = loadImage("..\\main\\assets\\game08\\V.png"); 
			d.VersusImg[1] = loadImage("..\\main\\assets\\game08\\S.png");


		//ゲームクリア
			d.clearImg = loadImage("..\\main\\assets\\game08\\gameclear.png");

		//ゲームオーバー
			d.overImg = loadImage("..\\main\\assets\\game08\\gameover.png"); 


		//おみくじ
			d.OmikujiImg = loadImage("..\\main\\assets\\game08\\omikuji.png"); 
		//ランダムで3つ出す*7＝おみくじ
			d.OmikujiesImg[0] = loadImage("..\\main\\assets\\game08\\daikichi.png"); 
			d.OmikujiesImg[1] = loadImage("..\\main\\assets\\game08\\kichi.png");
			d.OmikujiesImg[2] = loadImage("..\\main\\assets\\game08\\chukichi.png");
			d.OmikujiesImg[3] = loadImage("..\\main\\assets\\game08\\shokichi.png");
			d.OmikujiesImg[4] = loadImage("..\\main\\assets\\game08\\suekichi.png");
			d.OmikujiesImg[5] = loadImage("..\\main\\assets\\game08\\kyo.png");
			d.OmikujiesImg[6] = loadImage("..\\main\\assets\\game08\\daikyo.png");


		//天気
			d.WeatherImg = loadImage("..\\main\\assets\\game08\\Weather.png"); 
		//ランダムで1つ出す*7＝天気
			d.WeathersImg[0] = loadImage("..\\main\\assets\\game08\\Kaisei.png"); 
			d.WeathersImg[1] = loadImage("..\\main\\assets\\game08\\Hare.png");
			d.WeathersImg[2] = loadImage("..\\main\\assets\\game08\\Kumori.png");
			d.WeathersImg[3] = loadImage("..\\main\\assets\\game08\\Yuyake.png");
			d.WeathersImg[4] = loadImage("..\\main\\assets\\game08\\Saiun.png");
			d.WeathersImg[5] = loadImage("..\\main\\assets\\game08\\Ame.png");
			d.WeathersImg[6] = loadImage("..\\main\\assets\\game08\\Yozora.png");


			//カラー
			d.ColorImg = loadImage("..\\main\\assets\\game08\\Color.png");
			//ランダムで1つ出す*9＝カラー
			d.ColorsImg[0] = loadImage("..\\main\\assets\\game08\\Red.png");
			d.ColorsImg[1] = loadImage("..\\main\\assets\\game08\\Orange.png");
			d.ColorsImg[2] = loadImage("..\\main\\assets\\game08\\Yellow.png");
			d.ColorsImg[3] = loadImage("..\\main\\assets\\game08\\Green.png");
			d.ColorsImg[4] = loadImage("..\\main\\assets\\game08\\Pink.png");
			d.ColorsImg[5] = loadImage("..\\main\\assets\\game08\\Blue.png");
			d.ColorsImg[6] = loadImage("..\\main\\assets\\game08\\Purple.png");
			d.ColorsImg[7] = loadImage("..\\main\\assets\\game08\\Brown.png");
			d.ColorsImg[8] = loadImage("..\\main\\assets\\game08\\White.png");


		return 0;

	}

//0にして②

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
	}

	void GAME::proc()
	{
		//ここはメインループから呼び出されている!!!!!

		if (d.state == d.TITLE) { title(); }
		else if (d.state == d.PLAY) { play(); }
		else if (d.state == d.RESULT) { result(); }
		else if (d.state == d.OMIKUJI) { omikuji(); }
		else if (d.state == d.COLOR) { color(); }
		else if (d.state == d.WEATHER) { weather(); }

		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();

		}
//ループする③	
	}
	void GAME::title() {
		rectMode(CENTER);
		image(d.TitleBackImg, width / 2, height / 2);
		//clear(240, 0, 0);
		if (isTrigger(KEY_SPACE)) {
			init();
		}
	}

	void GAME::init() {

		    //（あなた）
			d.player.hand = d.GU; 
			d.player.px = width/2 + 550;
			d.player.py = height/2 + 100;
			d.player.angle = 0;
			d.player.r = 255;
			d.player.g = 255;
			d.player.b = 255;
			d.player.life = 3;

			//（あいて）
			d.pc.hand = d.GU; 
			d.pc.px = width/2 - 550;
			d.pc.py = height/2 + 100;
			d.pc.angle = 0;
			d.pc.r = 255;
			d.pc.g = 255;
			d.pc.b = 255;
			d.pc.life = 3;

			//リザルト
			d.rpx = width / 2;
			d.rpy = height / 2 - 350;
			d.rsize = 1.2;

			//使用画像番号の設定(重複しないように＝ライフ)
			for (int x = 0; x < 6; x++) {
				d.lifeNumber[x] = random() % 15;
				for (int j = 0; j < x; j++) {
					if (d.lifeNumber[j] == d.lifeNumber[x]) {
						x--;
						break;
					}
				}
			}


			//ライフ
			d.lpx = width / 2 + 100 ;
			d.lpy = 180 ;
			d.lmx = 245;
			d.lsize = 1.5;

			//name(あなた）
			d.Ppx = width / 2 + width / 4 - 300 ;
			d.Ppy = height / 2 + 450;
			d.Pmx = 160;
			//name(あいて）
			d.Epx = width / 4 - 350 ;
			d.Epy = height / 2 + 450;
			d.Emx = 160;

			//VS
			d.Vpx = width / 2 - 50;
			d.Vpy = height / 2 ;
			d.Vmx = 160;


			d.state = d.PLAY;

			d.PushFlag = false;

			for (int i = 0; i < 8; i++) {
				d.born[i] = 10;
			}
			d.colorSum = 0;
			d.color = 0;
			d.colorKind = 0;

	}

	void GAME::play() {
		clear(0, 255, 0);
		draw();
		if (isTrigger(KEY_SPACE)) {
			d.state = d.RESULT;
		}
				if (!isTrigger(KEY_A) && !isTrigger(KEY_S) && !isTrigger(KEY_D)) {
					return;
				}
				//プレイヤーの手
				if (isTrigger(KEY_A))
				{ d.player.hand = d.GU; }
				if (isTrigger(KEY_S)) 
				{ d.player.hand = d.CHOKI; }
				if (isTrigger(KEY_D)) 
				{ d.player.hand = d.PA; }

				//PCの手
				d.pc.hand = random() % 3;

				//勝ち負け判定
				if (d.player.hand == d.pc.hand) {
					//あいこ
					d.player.r = 255; d.player.g = 255; d.player.b = 255;

					d.pc.r = 255; d.pc.g = 255; d.pc.b = 255;

				}
				else if ((d.player.hand + 1) % 3 == d.pc.hand) {
					//プレイヤーの勝ち
					d.pc.life--;
					d.player.r = 255; d.player.g = 255; d.player.b = 255;

					d.pc.r = 255; d.pc.g = 200; d.pc.b = 200;

				}
				else {
					//pcの勝ち
					d.player.life--;
					d.player.r = 255; d.player.g = 200; d.player.b = 200;

					d.pc.r = 255; d.pc.g = 255; d.pc.b = 255;

				}
				if (d.player.life == 0 || d.pc.life == 0) {
					d.state = d.RESULT;
				}

	}

	void GAME::draw() {

			clear(180);
			rectMode(CENTER);

			//image(d.TitleBackImg, width / 2, height / 2);

			imageColor(255);
			image(d.SbackImg, width / 2, height / 2);

			imageColor(d.player.r, d.player.g, d.player.b);
			image(d.player.img[d.player.hand],
				d.player.px, d.player.py, d.player.angle);

			imageColor(d.pc.r, d.pc.g, d.pc.b);
			image(d.pc.img[d.pc.hand],
				d.pc.px, d.pc.py, d.pc.angle);
			
			//あなたとあいての文字
			for(int i=0; i<5; i++){  
				imageColor(0,191,255);
				image(d.PnameImg[i], d.Ppx + d.Pmx * i, d.Ppy);
				image(d.EnameImg[i], d.Epx + d.Emx * i, d.Epy);
			}

			//VSの文字
			for (int i = 0; i < 2; i++) { 
				imageColor(0,0,255);
				image(d.VersusImg[i], d.Vpx + d.Vmx * i, d.Vpy);
			}


			if (d.player.life > 0 && d.pc.life > 0) {

				for (int i = 0; i < d.player.life; i++) {
					imageColor(255);
					image(d.lifeImg[d.lifeNumber[i + 3]], d.player.px + d.lmx * (i - 1), d.lpy, 0, d.lsize);
				}

				for (int i = 0; i < d.pc.life; i++) {
					imageColor(255);
					image(d.lifeImg[d.lifeNumber[i]], d.pc.px + d.lmx * (i - 1), d.lpy, 0, d.lsize);
				}

			}
			
			if (d.state == d.RESULT) {
				textSize(d.resultSize);
				imageColor(255);
				if (d.player.life > 0) {
					image(d.clearImg, d.rpx, d.rpy, 0, d.rsize);

				}
				else {
					image(d.overImg, d.rpx, d.rpy, 0, d.rsize);

				}
			}
			print(GetAsyncKeyState('1'));
	}

	void GAME::result() {
		clear(0, 0, 255);
		draw();
				if (d.player.life == 0) {
					d.player.py += 4.5;
					d.player.angle += 0.003f;
				}
				else {
					d.pc.py += 4.5;
					d.pc.angle += -0.003f;
				}

				if (isTrigger(KEY_SPACE)&&d.player.life == 0) {
					d.state = d.TITLE;
				}

				if (isTrigger(KEY_J)) {
					d.state = d.OMIKUJI;
				}

				if (isTrigger(KEY_K)) {
					d.state = d.COLOR;
				}

				if (isTrigger(KEY_L)) {
					d.state = d.WEATHER;
				}

				
	}

	void GAME::omikuji() {
		clear(255);
		if (isTrigger(KEY_SPACE) && d.PushFlag == false) {

			d.PushFlag = true;
			d.NowOmikuji = rand() % d.OmikujiKind;
		}
		if (d.NowOmikuji != d.OmikujiKind) {
			image(d.OmikujiesImg[d.NowOmikuji], width / 2, height / 2);
		}
		else {
			image(d.OmikujiImg, width / 2, height / 2);
		}
	}

	void GAME::color() {
		clear(255);
		if (d.pressFlag == false) {
			getDegit();
		}
		pressFlag();
		print(d.select);
		for (int i = 0; i < 8; i++) print(d.born[i]);
		if (isTrigger(MOUSE_LBUTTON)) {
			if (d.select != 0) {
				d.born[d.select] = 10;
				d.select--;
			}
			d.born[d.select] = 0; 
		}
		if (isTrigger(KEY_G) && d.born[7] != 10 && d.color == 0) {
			judgement();
		}
		if (d.changeFlag == false && d.color != 0) {
			image(d.ColorImg, width / 2, height / 2);
			if (isTrigger(KEY_SPACE)) {
				d.changeFlag = true;
			}
		}
		else if (d.color != 0 && d.changeFlag) {
			//色の表示
			switch (d.color) {
			case 1:
				image(d.ColorsImg[0], width / 2, height / 2);
				break;
			case 2:
				image(d.ColorsImg[1], width / 2, height / 2);
				break;
			case 3:
				image(d.ColorsImg[2], width / 2, height / 2);
				break;
			case 4:
				image(d.ColorsImg[3], width / 2, height / 2);
				break;
			case 5:
				image(d.ColorsImg[4], width / 2, height / 2);
				break;
			case 6:
				image(d.ColorsImg[5], width / 2, height / 2);
				break;
			case 7:
				image(d.ColorsImg[6], width / 2, height / 2);
				break;
			case 8:
				image(d.ColorsImg[7], width / 2, height / 2);
				break;
			case 9:
				image(d.ColorsImg[8], width / 2, height / 2);
				break;

			}
		}
	}

	void GAME::getDegit() {

		if (d.select < 8) {
			if (GetAsyncKeyState('0') != 0) {
				d.born[d.select] = 0;
				d.select++;
			}
			if (GetAsyncKeyState('1') != 0) {
				d.born[d.select] = 1;
				d.select++;
			}
			if (GetAsyncKeyState('2') != 0) {
				d.born[d.select] = 2;
				d.select++;
			}
			if (GetAsyncKeyState('3') != 0) {
				d.born[d.select] = 3;
				d.select++;
			}
			if (GetAsyncKeyState('4') != 0) {
				d.born[d.select] = 4;
				d.select++;
			}
			if (GetAsyncKeyState('5') != 0) {
				d.born[d.select] = 5;
				d.select++;
			}
			if (GetAsyncKeyState('6') != 0) {
				d.born[d.select] = 6;
				d.select++;
			}
			if (GetAsyncKeyState('7') != 0) {
				d.born[d.select] = 7;
				d.select++;
			}
			if (GetAsyncKeyState('8') != 0) {
				d.born[d.select] = 8;
				d.select++;
			}
			if (GetAsyncKeyState('9') != 0) {
				d.born[d.select] = 9;
				d.select++;
			}
		}
	}

	void GAME::pressFlag() {
		if (GetAsyncKeyState('0') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('1') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('2') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('3') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('4') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('5') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('6') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('7') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('8') != 0) {
			d.pressFlag = true;
		}
		else if (GetAsyncKeyState('9') != 0) {
			d.pressFlag = true;
		}
		else {
			d.pressFlag = false;
		}
	}

	void GAME::judgement() {
		for (int i = 0; i < 8; i++) {//足す
			d.colorKind += d.born[i];
		}
			if (d.colorKind >= 10) {
				d.sum[0] = d.colorKind / 10;
				d.sum[1] = d.colorKind % 10;

				d.colorSum = d.sum[0] + d.sum[1];
				while (d.colorSum >= 10) {
					d.sum[0] = d.colorSum / 10;
					d.sum[1] = d.colorSum % 10;

					d.colorSum = d.sum[0] + d.sum[1];
				}
			}
			else {
				d.sum[0] = d.colorKind;
				d.sum[1] = 0;
			}
			for (int i = 0; i < 2; i++) {
				d.color += d.sum[i];
			}
	}

	void GAME::weather() {
		clear(0, 0, 255);
		if (isTrigger(KEY_SPACE) && d.PushFlag == false) {
			d.PushFlag = true;
			d.NowWeather = rand() % d.WeatherKind;
		}
		if (d.NowWeather != d.WeatherKind) {
			image(d.WeathersImg[d.NowWeather], width / 2, height / 2);
		}
		else {
			image(d.WeatherImg, width / 2, height / 2);
		}
	}


}


