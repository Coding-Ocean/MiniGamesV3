#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME04.h"
namespace GAME04
{
	int GAME::create()
	{
		d = new DATA;
		c = new CHARA;
		b = new BULLET;
		//ここでは主に画像と音データを読み込む
		
		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。
		State = TITLE;
		d->Player.normalImg = loadImage("..\\main\\assets\\game04\\player1.png");
		d->Player.damageImg = loadImage("..\\main\\assets\\game04\\player2.png");
		d->Player.loseImg = loadImage("..\\main\\assets\\game04\\player4.png");
		d->Player.winImg = loadImage("..\\main\\assets\\game04\\player3.png");

		d->NPC.normalImg = loadImage("..\\main\\assets\\game04\\NPC1.png");
		d->NPC.damageImg = loadImage("..\\main\\assets\\game04\\NPC2.png");
		d->NPC.loseImg = loadImage("..\\main\\assets\\game04\\NPC4.png");
		d->NPC.winImg = loadImage("..\\main\\assets\\game04\\NPC3.png");
				
		d->PBullet.img = loadImage("..\\main\\assets\\game04\\PBullet.png");
				
		d->NBullet.img = loadImage("..\\main\\assets\\game04\\NBullet.png");
		

		d->titleImg = loadImage("..\\main\\assets\\game04\\title.png");

		d->backImg = loadImage("..\\main\\assets\\game04\\back.png");
		
		FireSoundP = loadSound("..\\main\\assets\\game04\\PBsnd.wav");
		FireSoundN = loadSound("..\\main\\assets\\game04\\NBsnd.wav");

		DamageSndP = loadSound("..\\main\\assets\\game04\\Damage P.wav");
		DamageSndN = loadSound("..\\main\\assets\\game04\\Damage N.wav");

		GAMECSound = loadSound("..\\main\\assets\\game04\\GAME C.wav");
		GAMEOSound = loadSound("..\\main\\assets\\game04\\GAME O.wav");

		BgmSound = loadSound("..\\main\\assets\\game04\\BGM.wav");
		
		return 0;
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
		delete new DATA;
		delete new CHARA; 
		delete new BULLET;
	}

	


	void GAME::proc()
	{
		//ここはメインループから呼び出されている!!!!!
		if (State == TITLE)Title(d);
		else if (State == PLAY)Play(d);
		else if (State == RESULT)Result(d);
		//描画--------------------------------------------------
		
	}
	void GAME04::GAME::Title(DATA* d)
	{
		playSound(BgmSound);

		rectMode(CORNER);
		clear();
		imageColor(255, 255, 255);
		image(d->titleImg, 0, 0);
		if (isTrigger(KEY_SPACE)) {
			Init(d);
			//ステート切り替え
			clear(0,180,0);
			State = PLAY;
			return;
		}
		//テキスト情報
		fill(0);
		textSize(100);
		text("Enterでメニューに戻る", 0, height);
		print(4);
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}						
	}
	void GAME04::GAME::Init(struct DATA* d)
	{
		d->Player.img = d->Player.normalImg;
		d->Player.px = 960.0f;
		d->Player.py = 970.0f;
		d->Player.vx = 15.0f;
		d->Player.hp = 25;
		d->Player.bulletOfsY = -70;
		d->Player.hpGaugeOfsY = -60;

		d->NPC.img = d->NPC.normalImg;
		d->NPC.px = 960.0f;
		d->NPC.py = 150.0f;
		d->NPC.vx = 25.0f;
		d->NPC.bulletOfsY = 55;
		d->NPC.hp = 35;
		d->NPC.hpGaugeOfsY = -62;

		d->NBullet.px = 0.0f;
		d->NBullet.py = 0.0;
		d->NBullet.vy = 35.0f;
		d->NBullet.hp = 0;

		d->PBullet.px = 0.0f;
		d->PBullet.py = 0.0f;
		d->PBullet.vy = -20.0f;
		d->PBullet.hp = 0;

		//当たり判定用データ
		d->Player.halfW = 60;
		d->Player.halfH = 80;
		d->NPC.halfW = 60;
		d->NPC.halfH = 80;
		d->NBullet.halfW = 25;
		d->NBullet.halfH = 26;
		d->PBullet.halfW = 25;
		d->PBullet.halfH = 26;

		d->frameRestrictInput = 90;

	}
	void GAME::Play(DATA* d)
	{
		
		//プレイヤーを動かす
		if (isPress(KEY_A)) { d->Player.px += -d->Player.vx; }
		if (isPress(KEY_D)) { d->Player.px += d->Player.vx; }
		//プレイヤーの移動範囲制限
		if (d->Player.px < d->Player.halfW) {
			d->Player.px = d->Player.halfW;
		}
		if (d->Player.px > width - d->Player.halfW) {
			d->Player.px = width - d->Player.halfW;
		}
		//弾発射
		if (d->PBullet.hp == 0 && isTrigger(KEY_SPACE)) {
			playSound(FireSoundP);
			//発射位置
			d->PBullet.px = d->Player.px;
			d->PBullet.py = d->Player.py + d->Player.bulletOfsY;
			d->PBullet.hp = 1;
		}
		//弾を動かす
		if (d->PBullet.hp > 0) {
			d->PBullet.py += d->PBullet.vy;
			//ウィンドウの外に出た
			if (d->PBullet.py < -d->PBullet.halfH) {
				d->PBullet.hp = 0;
			}
		}

		//NPCを動かす
		d->NPC.px += d->NPC.vx;
		if (d->NPC.px < d->NPC.halfW ||
			d->NPC.px > width - d->NPC.halfW) {
			//移動方向反転
			d->NPC.vx = -d->NPC.vx;
		}
		//弾発射
		if (d->NBullet.hp == 0) {
			playSound(FireSoundN);
			//発射位置
			d->NBullet.px = d->NPC.px;
			d->NBullet.py = d->NPC.py + d->NPC.bulletOfsY;
			d->NBullet.hp = 1;
		}
		
		//弾を動かす
		if (d->NBullet.hp > 0) {
			d->NBullet.py += d->NBullet.vy;
			//ウィンドウの外に出た
			if (d->NBullet.py > height + d->NBullet.halfH) {
			    d->NBullet.hp = 0;
			}
		}
				
		//当たり判定・プレイヤーとN弾
		if (Collision(&d->Player, &d->NBullet)){
			playSound(DamageSndP);
			d->Player.img = d->Player.damageImg;
			d->Player.hp--;
		}
		else {
			d->Player.img = d->Player.normalImg;
		}
		//当たり判定・NPCとP弾
		if (Collision(&d->NPC, &d->PBullet)) {
			playSound(DamageSndN);
			d->NPC.img = d->NPC.damageImg;
			d->NPC.hp--;
		}
		else {
			d->NPC.img = d->NPC.normalImg;
		}
		//勝負がついた
		if (d->Player.hp <= 0 || d->NPC.hp <= 0) {
			//勝ち負け画像の切り替え
			if (d->NPC.hp > 0) {//NPCが勝った
				d->NPC.img = d->NPC.winImg;
				d->Player.img = d->Player.loseImg;
				playSound(GAMEOSound);

			}
			else {//プレイヤーが勝った
				d->Player.img = d->Player.winImg;
				d->NPC.img = d->NPC.loseImg;
			    playSound(GAMECSound);
			}
			//ステート切り替え
			stopSound(BgmSound);
			d->frameCnt = d->frameRestrictInput;
			State = RESULT;
		}
		Draw(d);
	}
	void GAME::Result(DATA* d)
	{
		//P弾とN弾を画面外まで移動
		if (d->PBullet.hp > 0) {
			d->PBullet.py += d->PBullet.vy;
			if (d->PBullet.py < -d->PBullet.halfH) {
				d->PBullet.hp = 0;
			}
		}
		if (d->NBullet.hp > 0) {
			d->NBullet.py += d->NBullet.vy;
			if (d->NBullet.py > height + d->NBullet.halfH) {
				d->NBullet.hp = 0;
			}
		}
		Draw(d);

		//リスタート(数フレームループしないとスペースキーを押せない)
		if (d->frameCnt > 0) {
			d->frameCnt--;
		}
		else if(d->Player.hp > 0)
		{
			fill(255,255,0);
			printSize(150);
			print("GameClear!");
			fill(0);
			text("SPACEでタイトルに戻る", 25, height);
			if (isTrigger(KEY_SPACE)) {
				State = TITLE;
			}
		}
		else {
			fill(255,0,0);
			printSize(150);
			print("GameOver");
			fill(0);
			text("SPACEでタイトルに戻る", 25, height);
			if (isTrigger(KEY_SPACE)) {
				State = TITLE;
			}
		}
	}
	int  GAME::Collision(CHARA* c, BULLET* b)
	{
		if (b->hp > 0) {
			float cRight = c->px + c->halfW;
			float cLeft = c->px - c->halfW;
			float cTop = c->py - c->halfH;
			float cBottom = c->py + c->halfH;
			float bRight = b->px + b->halfW;
			float bLeft = b->px - b->halfW;
			float bTop = b->py - b->halfH;
			float bBottom = b->py + b->halfH;
			if (cRight < bLeft || bRight < cLeft ||
				bBottom < cTop || cBottom < bTop) {
				//触れていない
				return 0;
			}
			else {
				//触れている
				return 1;
			}
		}
		return 0;
	}
	void GAME::Draw(DATA* d)
	{
		
		clear();
		//キャラ
		rectMode(CORNER);
		image(d->backImg, 0, 0);
		rectMode(CENTER);
		image(d->Player.img, d->Player.px, d->Player.py);
		image(d->NPC.img, d->NPC.px, d->NPC.py);
		//弾
		if (d->PBullet.hp > 0) {
			image(d->PBullet.img, d->PBullet.px, d->PBullet.py);
		}
		if (d->NBullet.hp > 0) {
			image(d->NBullet.img, d->NBullet.px, d->NBullet.py);
		}
		//HPゲージ
		HpGauge(&d->NPC);
		HpGauge(&d->Player);

#if _DEBUG
		//当たり判定表示エリア
		fill(255, 255, 255, 128);
		rect(d->Player.px, d->Player.py, d->Player.halfW * 2, d->Player.halfH * 2);
		rect(d->NPC.px, d->NPC.py, d->NPC.halfW * 2, d->NPC.halfH * 2);
		rect(d->PBullet.px, d->PBullet.py, d->PBullet.halfW * 2, d->PBullet.halfH * 2);
		rect(d->NBullet.px, d->NBullet.py, d->NBullet.halfW * 2, d->NBullet.halfH * 2);
#endif

	}
	void GAME::HpGauge(CHARA* c)
	{
		strokeWeight(0);
		if (c->hp > 15) {
			fill(0, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(c->px, c->py + c->hpGaugeOfsY, c->hpGaugeOfsY, 5);
	}
}
