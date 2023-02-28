#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/sound.h"
#include "../../libOne/inc/window.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/rand.h"
#include "../MAIN/MAIN.h"
#include "GAME00.h"

int GAME00::create()
{
	State = TITLE;
	ExplosionImg = loadImage("..\\main\\assets\\game00\\explosion.png");
	ExplosionSnd = loadSound("..\\main\\assets\\game00\\bomb.wav");

	return 0;
}

void GAME00::destroy()
{
}

void GAME00::proc()
{
	//�V�[���؂�ւ�
	if      (State == TITLE)Title();
	else if (State == PLAY )Play();
	else if (State == CLEAR)Clear();
}

void GAME00::Title()
{
	//�`��--------------------------------------------------
	clear(60, 60, 60);
	//�e�L�X�g���
	fill(255, 255, 255);
	textSize(80);
	print("Title�F�����Ă���~���N���b�N����Q�[��");
	print("�@�N���b�N�ŃQ�[���X�^�[�g");
	print("  Enter�Ń��j���[�ɖ߂�");
	//�V�[���؂�ւ�-----------------------------------------
	if (isTrigger(MOUSE_LBUTTON)) {
		Init();
		State = PLAY;
		return;
	}
	//���j���[�ɖ߂�-----------------------------------------
	if (isTrigger(KEY_ENTER)) {
		main()->backToMenu();
	}
}

void GAME00::Init()
{
	CircleRadius = 50;
	CircleX = random() % 1000 + 500.0f;
	CircleY = -CircleRadius;
	CircleVy = 800;
}

void GAME00::Play()
{
	//�X�V--------------------------------------------------
	CircleY += CircleVy * delta;
	if (CircleY > height + CircleRadius) {
		CircleX = random() % 1000 + 500.0f;
		CircleY = -CircleRadius;
	}
	//�`��--------------------------------------------------
	clear(0, 60, 0);
	//�~
	fill(255);
	circle(CircleX, CircleY, CircleRadius * 2);
	//�e�L�X�g���
	fill(255, 255, 255);
	print("Play");
	print("�@�~���N���b�N�����Game Clear");
	//�V�[���؂�ւ�-----------------------------------------
	if (isTrigger(MOUSE_LBUTTON)) {
		float dx = CircleX - mouseX;
		float dy = CircleY - mouseY;
		if (dx * dx + dy * dy < CircleRadius * CircleRadius) {
			playSound(ExplosionSnd);
			State = CLEAR;
		}
	}
}

void GAME00::Clear()
{
	//�`��--------------------------------------------------
	clear(0,0, 255);
	//�����摜
	rectMode(CENTER);
	image(ExplosionImg, CircleX, CircleY);
	//�e�L�X�g���
	fill(255, 255, 255);
	print("Game Clear");
	print("�@�N���b�N�Ń^�C�g���ɖ߂�");
	//�V�[���؂�ւ�-----------------------------------------
	if (isTrigger(MOUSE_LBUTTON)) {
		State = TITLE;
	}
}
