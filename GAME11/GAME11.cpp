#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME11.h"
namespace GAME11
{
	//�����~�������Q�[��
	int GAME::create()
	{
		State = TITLE;
		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���
		ObjectImg = loadImage("..\\main\\assets\\game11\\object.png");
		HaikeiImg = loadImage("..\\main\\assets\\game11\\haikei.png");
		KaoImg = loadImage("..\\main\\assets\\game11\\kao.png");
		LoseImg = loadImage("..\\main\\assets\\game11\\lose.png");
		
		GameSound = loadSound("..\\main\\assets\\game11\\game.wav");
		WinSound = loadSound("..\\main\\assets\\game11\\win.wav");
		LoseSound = loadSound("..\\main\\assets\\game11\\noroi.wav");
	    PerfectSound = loadSound("..\\main\\assets\\game11\\perfect.wav");
		FinalSound = loadSound("..\\main\\assets\\game11\\final.wav");


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
		//�����̓��C�����[�v����Ăяo����Ă���!!!!!
		if (State == TITLE)Title();
		if (State == PLAY)Play();
		if (State == CLEAR)Clear();
		if (State == OVER)Over();	
	} 
	void GAME::Title() {
		//�e�L�X�g���
		clear(200,255,200);
		fill(0);
		textSize(100);
		text("�E�C���X���瓦����!!!",450,580);
		print("�N���b�N�ŃX�^�[�g");
		print("������@�F�}�E�X�𓮂���");
		text("�@Enter�Ń��j���[�ɖ߂�", 0, height);
		//�؂�ւ�
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			if (Stagecount > 2)
				playSound(FinalSound);
			else
				playSound(GameSound);
			State = PLAY;
			return;
		}
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Init() {
		Px = MouseX;
		Py = MouseY;
		oPx = width / 2;
		oPy = height + oRadius;
		
		o2Px = width + oRadius;
		o2Py = height / 2;
		
		o3Px = width / 2;
		o3Py = 0 + oRadius;

		o4Px = 0 - oRadius;
		o4Py = height / 2;
		
		Vx = 15.0f;
		Vy = 8.0f;
		Radius = 70;
		oRadius = 100;

		Stagecount = 0;

		oCount = Stagecount;

		Countdown = 300;
	}
	void GAME::Play() {
		//�~
		rectMode(CENTER);
		//clear(128);
		strokeWeight(0);
		stroke(0);
		Px = MouseX;
		Py = MouseY;
		float a = oPx - Px;
		float b = oPy - Py;
		float a2 = o2Px - Px;
		float b2 = o2Py - Py;
		float a3 = o3Px - Px;
		float b3 = o3Py - Py; 
		float a4 = o4Px - Px;
		float b4 = o4Py - Py;
		float distance  = sqrt(a * a + b * b);
		float distance2 = sqrt(a2 * a2 + b2 * b2);
		float distance3 = sqrt(a3 * a3 + b3 * b3);
		float distance4 = sqrt(a4 * a4 + b4 * b4);
		//�����蔻��
		if (distance <= oRadius + Radius ||distance2 <= oRadius + Radius
			||distance3 <= oRadius + Radius || distance4 <= oRadius + Radius) {
			stopSound(GameSound);
			stopSound(FinalSound);
			playSound(LoseSound);
			State = OVER;
		}
		//�I�u�W�F�N�g�̓���
		oPy += Vy + Stagecount *1.5f;
		if (oPy > 1080 + Radius ) {
			oPy = 0 + Radius;
			oPx = random() % 1920;
		}
		o2Px += Vx + Stagecount * 2.0f;
		if (o2Px > 1920 + Radius) {
			o2Px = 0 + Radius;
			o2Py = random() % 1080;
		}
		o3Py -= Vy + (Stagecount * 1.5f);
		if (o3Py < 0 - Radius) {
			o3Py = 1080 - Radius;
			o3Px = random() % 1920;
		}
		o4Px -= Vx + (Stagecount * 2.0f);
		if (o4Px < 0 - Radius) {
			o4Px = 1920 - Radius;
			o4Py = random() % 1080;
		}
		//�N���A����
		fill(255);
		if (Countdown > 0) {
			fill(0);
			Countdown -= 1.0f;
		    image(HaikeiImg,width/2,height/2);
			text((let)Countdown, 1600, 120);
			text("STAGE", 1600, 200);
			if (Stagecount >= 3) {
				text("FINAL", 1750, 200);
			}
			else
			text((let)Stagecount, 1750, 200);
		}
		else {
			stopSound(GameSound);
			State = CLEAR;
			if (Stagecount < 3) {
				playSound(WinSound);
			}
			else
			    playSound(PerfectSound);
		}
		fill(255, 255, 255, 0);
		circle(Px, Py, Radius * 2.3f);
		circle(oPx, oPy, oRadius * 2);
		circle(o2Px, o2Py, oRadius * 2);
		circle(o3Px, o3Py, oRadius * 2);
		circle(o4Px, o4Py, oRadius * 2);
		image(KaoImg, Px, Py);
		image(ObjectImg, oPx,oPy);
		image(ObjectImg, o2Px, o2Py);
		image(ObjectImg, o3Px, o3Py);
		image(ObjectImg, o4Px, o4Py);
	}
	void GAME::Clear() {
		clear(255,244,80);
		fill(181,255,20);
		if (Stagecount < 3) {
			text("STAGE CLEAR!!", 800, 540);
			text("���N���b�N�ŁA���̃X�e�[�W��", 600, 640);
			text("ENTER�������āA�^�C�g���ɖ߂�", 600, 740);

			if (isTrigger(MOUSE_LBUTTON)) {
				oPy = height + oRadius;
				o2Px = width + oRadius;
				o3Py = 0 + oRadius;
				o4Px = 0 - oRadius;

				Stagecount++;
				Countdown = (Stagecount + 1 ) * 300;
				if (Stagecount > 2) {
					playSound(FinalSound);
				}
				else {
					playSound(GameSound);
				}
				stopSound(WinSound);
				State = PLAY;
			}
			if (isTrigger(MOUSE_RBUTTON)) {
				oPy = height + oRadius;
				o2Px = width + oRadius;
				o3Py = 0 + oRadius;
				o4Px = 0 - oRadius;

				Stagecount += 10;
				Countdown = (Stagecount + 1) * 300;
				if (Stagecount > 3) {
					playSound(FinalSound);
				}
				else {
					playSound(GameSound);
				}
					stopSound(WinSound);
				State = PLAY;
			}
			if (isTrigger(KEY_ENTER)) {
				stopSound(WinSound);
				State = TITLE;
			}
		}
		else {
			text("PERFECT!!", 800, 540);
			text("ENTER�������āA�^�C�g���ɖ߂�", 600, 690);
			if (isTrigger(KEY_ENTER)) {
			    Stagecount = 0;
				State = TITLE;
			}
		}
	}
	void GAME::Over() {
		clear(128);
		fill(0, 0, 128);
		image(LoseImg, 1920-400, 800);
		textSize(80);
     	text("GAME OVER",800,540);
		text("ENTER�������āA�^�C�g���ɖ߂�", 190, 640);
		if (isTrigger(KEY_ENTER)) {
				Stagecount = 0;
				State = TITLE;
		}
	}
}