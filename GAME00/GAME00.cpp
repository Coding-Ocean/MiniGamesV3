#include "../../libOne/inc/libOne.h"
#include "../../libOne/inc/sound.h"
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"
#include "../MAIN/MAIN.h"
#include "GAME00.h"
namespace GAME00
{
	
	int GAME::create()
	{
		
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���
		ningenImg = loadImage("..\\main\\assets\\game00\\ningen.png");

		sakanaImg = loadImage("..\\main\\assets\\game00\\sakana.png");

		sasimiImg = loadImage("..\\main\\assets\\game00\\sasimi.png");

		umiImg = loadImage("..\\main\\assets\\game00\\umi.jpg");
		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ��B
		//�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B

		return 0;
	}

	void GAME::destroy()
	{
		//create()��new�����ꍇ�͂�����delete���邱��
	}
	void GAME::proc()
	{
		//�V�[���؂�ւ�
		if (State == TITLE)Title();
		else if (State == PLAY)Play();
		else if (State == CLEAR)Clear();
	}

	void GAME::Title()
	{
		
		clear(0, 0, 128);

		fill(255, 255, 255);
		textSize(80);
		print("Title:�}�O����؂�Q�[��");
		print(" �N���b�N�ŃQ�[���X�^�[�g");
		print(" Enter�Ń��j���[�ɖ߂�");

		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
		}
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Init()
	{
		
		ex = 1920;
		ey = 540;
		ew = 450;
	    eh = 220;

		px = 100;
		py = 540;
		pw = 150;
		ph = 200;
		vx = 45;

		cx = 650;
		cy = 400;
		SakanaLife = 1;
		NingenLife = 250;
		ClearFlag = false;
	}
	void GAME::Play()
	{
		
		ex += -vx;
		if (ex < -360) {
			ex = 1920;
			ey = random() % 750 + 200.0f;
			NingenLife += -20;
		}
		
		
		if (NingenLife < 0) {
			State = CLEAR;
		}
			
		float limA = 900;
		float limB = 0;
		if (isPress(KEY_W)) {
			if (py > limB) {
				py += -20;
			}
		}
		else if (isPress(KEY_S)) {
			if (py < limA) {
				py += 20;
			}
		}
		
		if (collision()) {
			ex = 1920;
			ey = random() % 750 + 200.0f;
		}

		Draw();
		fill(255, 255, 255);
		print("�}�O����؂�");
		print("w�ŏ�Ɉړ�");
		print("s�ŉ��Ɉړ�");
	}
	int GAME::collision() {
		if (SakanaLife > 0) {
			float SakanaLeft = ex;
			float SakanaRight = ex + ew;
			float SakanaTop = ey;
			float SakanaBottom = ey + eh;
			float SamuraiLeft = px;
			float SamuraiRight = px + pw;
			float SamuraiTop = py;
			float SamuraiBottom = py + ph;
			if (SamuraiRight < SakanaLeft ||
				SakanaRight < SamuraiLeft ||
				SamuraiBottom < SakanaTop ||
				SakanaBottom < SamuraiTop) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return 0;
	}
	void GAME::Draw()
	{
		clear(0, 0, 128);
		rectMode(CORNER);
		image(umiImg, 0, 0);
		fill(128, 128, 128);
		rect(ex, ey, ew, eh);
		rect(px, py, pw, ph);
		
		image(sakanaImg, ex, ey);
		image(ningenImg, px, py);
		
		LifeGauge();
	}
	void GAME::LifeGauge()
	{
		strokeWeight(0);
		if (NingenLife > 40) {
			fill(0, 255, 0);
		}
		else {
			fill(255, 0, 0);
		}
		rect(px, py - 60, NingenLife, 5);
	}
	void GAME::Clear()
	{ 
		
		clear(0, 0, 128);

		image(sasimiImg, cx, cy);

		fill(255, 255, 255);
		print("Game Over");
		print(" �N���b�N�Ń^�C�g���ɖ߂�");
		if (isTrigger(MOUSE_LBUTTON)) {
			State = TITLE;
		}
	}
	
}
