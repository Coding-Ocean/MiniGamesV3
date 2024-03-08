#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/sound.h"
#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME05.h"
namespace GAME05
{
	int GAME::create()
	{
		d = new DATA;
		b = new BULLET;
		c = new CHARA;
		i = new ITEM;

		/*
		�V���v���ȃQ�[���Ȃ玟�̂悤�ɁA�����ōs���Ă��悢�B
		px = width / 2;
		Py = height / 2;
		Radius = 200;
		*/
		State = TITLE;
		d->hitman.normalImg = loadImage("..\\main\\assets\\game05\\hitman0.png");
		d->hitman.damageImg = loadImage("..\\main\\assets\\game05\\hitman1.png");
		d->hitman.loseImg = loadImage("..\\main\\assets\\game05\\hitman2.png");
		d->hitman.winImg = loadImage("..\\main\\assets\\game05\\hitman3.png");
		d->hitman.pwinImg = loadImage("..\\main\\assets\\game05\\hitman4.png");
		d->hitman.healImg = loadImage("..\\main\\assets\\game05\\hitman5.png");

		d->oni.normalImg = loadImage("..\\main\\assets\\game05\\oni0.png");
		d->oni.damageImg = loadImage("..\\main\\assets\\game05\\oni1.png");
		d->oni.loseImg = loadImage("..\\main\\assets\\game05\\oni2.png");
		d->oni.winImg = loadImage("..\\main\\assets\\game05\\oni3.png");

		d->tama.img = loadImage("..\\main\\assets\\game05\\tama.png");

		d->fire.img = loadImage("..\\main\\assets\\game05\\fire.png");
		
		d->kaihukuyaku.img = loadImage("..\\main\\assets\\game05\\kaihukuyaku.png");

		d->misairu.img = loadImage("..\\main\\assets\\game05\\misairu.png");
		
		OnigasimaImg = loadImage("..\\main\\assets\\game05\\onigasima.png");

		ShootSnd = loadSound("..\\main\\assets\\game05\\shoot.wav");
		Shoot2Snd = loadSound("..\\main\\assets\\game05\\shoot2.wav");
		WinSnd = loadSound("..\\main\\assets\\game05\\win.wav");
		PclearSnd = loadSound("..\\main\\assets\\game05\\pclear.wav");
		LoseSnd = loadSound("..\\main\\assets\\game05\\lose.wav");
		ClickSnd = loadSound("..\\main\\assets\\game05\\click.wav");
		FinalFightSnd = loadSound("..\\main\\assets\\game05\\finalfight.wav");
		VoiceSnd = loadSound("..\\main\\assets\\game05\\human01.wav");
		ExplosionSnd = loadSound("..\\main\\assets\\game05\\explosion.wav");
		YouwinSnd = loadSound("..\\main\\assets\\game05\\youwin.wav");
		CancelSnd = loadSound("..\\main\\assets\\game05\\cancel.wav");
		HealSnd = loadSound("..\\main\\assets\\game05\\kaihuku.wav");
		return 0;

		//�����ł͎�ɉ摜�Ɖ��f�[�^��ǂݍ���
		//�����l�ݒ��Init()�֐��Ȃǂ�����Ă����ōs�����ق����ǂ�
	}
	//�C�[�W�[
	void GAME::init(struct DATA* d)
	{
		//�q�b�g�}���f�[�^
		d->hitman.img = d->hitman.normalImg;
		d->hitman.px = width / 2;
		d->hitman.py = 960.0f;
		d->hitman.vx = 6.0f;
		d->hitman.hp = 150.0f;
		d->hitman.Maxhp = d->hitman.hp;
		d->hitman.hpGaugeOfsY = -130; 
		d->hitman.bulletOfsY = -100;
		d->hitman.invincibleRestTime = 0;
		d->hitman.invincibleTime = 0.5f;

		//�S�f�[�^
		d->oni.img = d->oni.normalImg;
		d->oni.px = d->hitman.px;
		d->oni.py = 200.0f;
		d->oni.vx = 16.0f;
		d->oni.hp = 200.0f;
		d->oni.Maxhp = d->oni.hp;
		d->oni.hpGaugeOfsY = -150;
		d->oni.bulletOfsY = 150;
		d->oni.invincibleRestTime = 0;
		d->oni.invincibleTime = 0.5f;

		//�e�f�[�^
		d->tama.px = 0.0f;
		d->tama.py = 0.0f;
		d->tama.vy = -12.0f;
		d->tama.hp = 0;

		//�t�@�C���f�[�^
		d->fire.px = 0.0f;
		d->fire.py = 0.0f;
		d->fire.vy = 25.0f;
		d->fire.hp = 0; 
		
		//�񕜖�f�[�^
		d->kaihukuyaku.px = 0.0f;
		d->kaihukuyaku.py = 0.0f;
		d->kaihukuyaku.vy = 15.0f;
		d->kaihukuyaku.hp = 0;

		//�~�T�C���f�[�^
		d->misairu.px = 0.0f;
		d->misairu.py = 0.0f;
		d->misairu.vy = -12.0f;
		d->misairu.hp = 0;
		d->misairu.use = 0;

		//�����蔻��p
		d->hitman.halfW = 80;
		d->hitman.halfH = 80;
		d->oni.halfW = 150;
		d->oni.halfH = 90;
		d->tama.halfW = 25;
		d->tama.halfH = 25;
		d->fire.halfW = 60;
		d->fire.halfH = 60;
		d->misairu.halfW = 5;
		d->misairu.halfH = 5;
		d->kaihukuyaku.halfW = 25;
		d->kaihukuyaku.halfH = 25;

		//�g�p��
		useCnt = 3;
		Count = 0;

		//���ꉉ�o�pHP���l
		maxhp = 130;

		//HP�Q�[�W�̐F�ω�
		hpWarning = d->hitman.hp * 0.3f;
		hpDanger = d->hitman.hp * 0.1f;


		d->frameRestrictInput = 90;	
	}
	//�n�[�h
	void GAME::init2(struct DATA* d)
	{
		//�q�b�g�}���f�[�^
		d->hitman.img = d->hitman.normalImg;
		d->hitman.px = width / 2;
		d->hitman.py = 960.0f;
		d->hitman.vx = 4.0f;
		d->hitman.hp = 100.0f;
		d->hitman.Maxhp = d->hitman.hp;
		d->hitman.hpGaugeOfsY = -130;
		d->hitman.bulletOfsY = -100;
		d->hitman.invincibleRestTime = 0;
		d->hitman.invincibleTime = 0.2f;

		//�S�f�[�^
		d->oni.img = d->oni.normalImg;
		d->oni.px = d->hitman.px;
		d->oni.py = 200.0f;
		d->oni.vx = 20.0f;
		d->oni.hp = 250.0f;
		d->oni.Maxhp = d->oni.hp;
		d->oni.hpGaugeOfsY = -150;
		d->oni.bulletOfsY = 150;
		d->oni.invincibleRestTime = 0;
		d->oni.invincibleTime = 0.3f;

		//�e�f�[�^
		d->tama.px = 0.0f;
		d->tama.py = 0.0f;
		d->tama.vy = -10.0f;
		d->tama.hp = 0;

		//�t�@�C���f�[�^
		d->fire.px = 0.0f;
		d->fire.py = 0.0f;
		d->fire.vy = 25.0f;
		d->fire.hp = 0;

		//�񕜖�f�[�^
		d->kaihukuyaku.px = 0.0f;
		d->kaihukuyaku.py = 0.0f;
		d->kaihukuyaku.vy = 7.0f;
		d->kaihukuyaku.hp = 0;

		//�~�T�C���f�[�^
		d->misairu.px = 0.0f;
		d->misairu.py = 0.0f;
		d->misairu.vy = -10.0f;
		d->misairu.hp = 0;
		d->misairu.use = 0;

		//�����蔻��p
		d->hitman.halfW = 70;
		d->hitman.halfH = 80;
		d->oni.halfW = 150;
		d->oni.halfH = 100;
		d->tama.halfW = 25;
		d->tama.halfH = 25;
		d->fire.halfW = 60;
		d->fire.halfH = 60;
		d->misairu.halfW = 5;
		d->misairu.halfH = 5;
		d->kaihukuyaku.halfW = 25;
		d->kaihukuyaku.halfH = 25;

		//�~�T�C���g�p��(�n�[�h)
		useCnt = 3;
		Count = 0;

		//���ꉉ�o�pHP���l
		maxhp = 80;

		//HP�Q�[�W�̐F�ω�
		hpWarning = d->hitman.hp * 0.3f;
		hpDanger = d->hitman.hp * 0.1f;


		d->frameRestrictInput = 90;
	}
	void GAME::destroy()
	{
		delete i;// ITEM;
		delete c;// CHARA;
		delete b;// BULLET;
		delete d;//DATA;
		//create()��new�����ꍇ�͂�����delete���邱��
	}

	void GAME::proc()
	{
		if (State == TITLE)Title(d);
		else if (State == EASY)Easy(d);
		else if (State == HARD)Hard(d);
		else if (State == OPERATION)Operation(d);
		else if (State == OPERATION2)Operation2(d);
		else if (State == EXPLAIN)Explain(d);
		else if (State == EXPLAIN2)Explain2(d);
		else if (State == PLAY)Play(d);
		else if (State == RESULT)Result(d);
	}
	void GAME::Title(struct DATA* d) 
	{
		clear();
		fill(255);
		textSize(300);
		fill(255, 0, 0);
		text("�S�ގ�", 530, 400);
		fill(255);
		textSize(100);
		text("���N���b�N�ŃC�[�W�[���[�h", 300, 600);
		text("�E�N���b�N�Ńn�[�h���[�h", 300, 800);
		printSize(100);
		if (isTrigger(MOUSE_LBUTTON)) {
			//playSound(ClickSnd);
			State = EASY;
			return;
		}
		else if (isTrigger(MOUSE_RBUTTON)) {
			//playSound(ClickSnd);
			State = HARD;
			return;
		}
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::Easy(struct DATA* d) {
		clear();
		ShowCursor(0);
		printSize(100);
		print("�C�[�W�[���[�h");
		print("Push W");
		if (isTrigger(KEY_W)) {
			playSound(ClickSnd);
			State = OPERATION;
			return;
		}
		else if(isTrigger(KEY_T)){
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	void GAME::Hard(struct DATA* d) {
		clear();
		ShowCursor(0);
		printSize(100);
		print("�n�[�h���[�h");
		print("Push Z");
		if (isTrigger(KEY_Z)) {
			playSound(ClickSnd);
			State = OPERATION2;
			return;
		}
		else if (isTrigger(KEY_T)) {
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	void GAME::Operation(struct DATA* d) {
		clear();
		fill(255);
		printSize(80);
		print("�`��������`");
		print("�EA�L�[:���ړ�");
		print("�ED�L�[:�E�ړ�");
		print("�ESpace�L�[:�e����");
		print("�EB�L�[�Ń^�C�g���ɖ߂�");
		print("�EPUSH E");
		if (isTrigger(KEY_E)) {
			playSound(ClickSnd);
			State = EXPLAIN;
			return;
		}
		else if (isTrigger(KEY_T)) {
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	void GAME::Operation2(struct DATA* d) {
		clear();
		fill(255);
		printSize(80);
		print("�`��������`");
		print("�EA�L�[:���ړ�");
		print("�ED�L�[:�E�ړ�");
		print("�ESpace�L�[:�e����");
		print("�EB�L�[�Ń^�C�g���ɖ߂�");
		print("�EPUSH H");
		if (isTrigger(KEY_H)) {
			playSound(ClickSnd);
			State = EXPLAIN2;
			return;
		}
		else if (isTrigger(KEY_T)) {
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	//�C�[�W�[���[�h
	void GAME::Explain(struct DATA* d) {
		clear();
		fill(255);
		printSize(80);
		print("�`�����`");
		print("�E�G��HP:200");
		print("�E������HP:150");
		print("�E�����܂��͋S��HP�̐F�����F�ɂȂ�����");
		print("�@H�L�[�Ń~�T�C�����ˉ\(3��܂�)");
		print("�E������HP�̐F�����F�ɂȂ�����");
		print("�@�񕜖򂪗����Ă���");
		print("�ES�L�[�Ő퓬�J�n");
		if (isTrigger(KEY_S)) {
			init(d);
			playSound(ClickSnd);
			playSound(FinalFightSnd);
			playLoopSound(FinalFightSnd);
			State = PLAY;
			return;
		}
		else if (isTrigger(KEY_B)) {
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	//�n�[�h���[�h
	void GAME::Explain2(struct DATA* d) {
		clear();
		fill(255);
		printSize(80);
		print("�`�����`"); 
		print("�E�G��HP��+50���ꂽ��ԂŃX�^�[�g");
		print("�E������HP��-50���ꂽ��ԂŃX�^�[�g");
		print("�E�G�̃X�s�[�h���A�b�v");
		print("�E�����̃X�s�[�h���_�E��");
		print("�E�����̒e�̑��x���_�E��");
		print("�E�����܂��͋S��HP�̐F�����F�ɂȂ�����");
		print("�@H�L�[�Ń~�T�C�����ˉ\(3��܂�)");
		print("�E������HP�̐F�����F�ɂȂ�����");
		print("�@�񕜖򂪗����Ă���");
		print("�E�񕜖򂪗����Ă��鑬�x���_�E��");
		print("�ES�L�[�Ő퓬�J�n");
		if (isTrigger(KEY_S)) {
			init2(d);
			playSound(ClickSnd);
			playSound(FinalFightSnd);
			playLoopSound(FinalFightSnd);
			State = PLAY;
			return;
		}
		else if (isTrigger(KEY_B)) {
			playSound(CancelSnd);
			State = TITLE;
			return;
		}
	}
	//�C�[�W�[���[�h
	void GAME::Play(struct DATA* d)
	{
		//�q�b�g�}���𓮂���
		if (isPress(KEY_D)) { d->hitman.px += d->hitman.vx; }
		if (isPress(KEY_A)) { d->hitman.px += -d->hitman.vx; }
		//�q�b�g�}���̈ړ��͈�
		if (d->hitman.px < d->hitman.halfW) {
			d->hitman.px = d->hitman.halfW;
		}
		if (d->hitman.px > width - d->hitman.halfW) {
			d->hitman.px = width - d->hitman.halfW;
		}

		//�e����
		if (d->tama.hp == 0 && isPress(KEY_SPACE)) {
			playSound(ShootSnd);
			//���ˈʒu
			d->tama.px = d->hitman.px;
			d->tama.py = d->hitman.py + d->hitman.bulletOfsY;
			d->tama.hp = 1;
		}
		//�e�𓮂���
		if (d->tama.hp > 0) {
			d->tama.py += d->tama.vy;
			//��ʊO�ɍs����
			if (d->tama.py < -d->tama.halfH) {
				d->tama.hp = 0;
			}
		}
		//�~�T�C������
		if(d->misairu.hp == 0 && d->hitman.hp <= hpWarning && isTrigger(KEY_H) && d->misairu.use < useCnt
			|| d->misairu.hp == 0 && d->oni.hp <= hpWarning && isTrigger(KEY_H) && d->misairu.use < useCnt){
			playSound(Shoot2Snd);
			//���ˈʒu
			d->misairu.px = d->hitman.px;
			d->misairu.py = d->hitman.py + d->hitman.bulletOfsY;
			//�~�T�C����łĂ�񐔐�������
			d->misairu.hp = 1;
			d->misairu.use++;
		}
		//�~�T�C�����łĂȂ��Ȃ鏈��
		else if(d->misairu.use > useCnt){
			d->misairu.hp = 0;
			d->tama.hp = 1;
		}
		
		//�~�T�C���𓮂���
		if (d->misairu.hp > 0) {
			d->misairu.py += d->misairu.vy;
			//��ʊO�ɍs����
			if (d->misairu.py < -d->misairu.halfH) {
				d->misairu.hp = 0;
			}
		}

		//�񕜖򂪗����Ă���ʒu
		if (d->kaihukuyaku.hp == 0) {
			//�ʒu
			d->kaihukuyaku.py = 0;
			d->kaihukuyaku.hp = 1;
		}
		//�񕜖򗎉�
		if (d->kaihukuyaku.hp > 0 && d->hitman.hp < hpWarning) {
			d->kaihukuyaku.py += d->kaihukuyaku.vy;
			//��ʊO�ɍs����
			if (d->kaihukuyaku.py > height + d->kaihukuyaku.halfH) {
				d->kaihukuyaku.px = random() % 1000;
				d->kaihukuyaku.py = 0;
			}
		}

		//�S�𓮂���
		d->oni.px += d->oni.vx;
		if (d->oni.px < d->oni.halfW ||
			d->oni.px > width - d->oni.halfW) {
			//�ړ��������]
			d->oni.vx = -d->oni.vx;
		}
		
		//�t�@�C���[����
		if (d->fire.hp == 0) {
			playSound(ShootSnd);
			//���ˈʒu
			d->fire.px = d->oni.px;
			d->fire.py = d->oni.py + d->oni.bulletOfsY;
			d->fire.hp = 1;
		}
		//�t�@�C���[�𓮂���
		if (d->fire.hp > 0) {
			d->fire.py += d->fire.vy;
			//��ʊO�ɍs����
			if (d->fire.py > height + d->fire.halfH) {
				d->fire.hp = 0;
			}
		}

		//�����蔻�� �q�b�g�}���ƃt�@�C���[
		if (collision(&d->hitman, &d->fire) && d->hitman.invincibleRestTime <= 0) {
			playSound(ExplosionSnd);
			d->hitman.img = d->hitman.damageImg;
			d->hitman.hp -= 3;
			//���G
			d->hitman.invincibleRestTime = d->hitman.invincibleTime;
		}
		else if (d->hitman.invincibleRestTime > 0) {
			d->hitman.invincibleRestTime -= delta;
		}
		else {
			d->hitman.img = d->hitman.normalImg;
		}


		//�����蔻�� �S�ƒe
		if (collision(&d->oni, &d->tama) && d->oni.invincibleRestTime <= 0) {
			playSound(ExplosionSnd);
			d->oni.img = d->oni.damageImg;
			d->oni.hp -= 2;
			d->oni.invincibleRestTime = d->oni.invincibleTime;
		}
		//�����蔻��@�S�ƃ~�T�C��
		else if (collision(&d->oni, &d->misairu)) {
			playSound(ExplosionSnd);
			d->oni.img = d->oni.damageImg;
			d->oni.hp -= 5;
			//���G
			d->oni.invincibleRestTime = d->oni.invincibleTime;
		}
		else if (d->oni.invincibleRestTime > 0) {
			d->oni.invincibleRestTime -= delta;
		}
		else {
			d->oni.img = d->oni.normalImg;
		}

		//�����蔻�� �q�b�g�}���Ɖ񕜖�
		if (collision2(&d->hitman, &d->kaihukuyaku) && d->hitman.hp < hpWarning) {
			playSound(HealSnd);
			d->hitman.img = d->hitman.healImg;
			d->hitman.hp = d->hitman.Maxhp;
			if (d->hitman.hp == d->hitman.Maxhp) {
				d->kaihukuyaku.hp = 0;
			}
		}
		//����������
		if (d->hitman.hp <= 0 || d->oni.hp <= 0 || d->hitman.hp >= maxhp && d->oni.hp <= 0) {
			//�摜�ؑ�
			if(d->hitman.hp <= 0) {//�S�̏���
				d->oni.img = d->oni.winImg;
				d->hitman.img = d->hitman.loseImg;
				playSound(LoseSnd);
				playSound(VoiceSnd);
				stopSound(FinalFightSnd);
				stopSound(ExplosionSnd);
			}
			else if(d->oni.hp <= 0 && d->hitman.hp < maxhp){//�q�b�g�}���̏���
				d->hitman.img = d->hitman.winImg;
				d->oni.img = d->oni.loseImg;
				playSound(WinSnd);
				playSound(YouwinSnd);
				stopSound(FinalFightSnd);
				stopSound(ExplosionSnd);
			}
			else if(d->hitman.hp >= maxhp && d->oni.hp <= 0){//HP��130�ȏ�c������ԂŃq�b�g�}���̏���
				d->hitman.img = d->hitman.pwinImg;
				d->oni.img = d->oni.loseImg;
				playSound(PclearSnd);
				stopSound(FinalFightSnd);
				stopSound(ExplosionSnd);
			}
			//�X�e�[�g�؂�ւ�
			d->frameCnt = d->frameRestrictInput;
			State = RESULT;
		}
		//���j���[�ɖ߂�------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

		//�����̓��C�����[�v����Ăяo����Ă���!!!!!

		//�`��--------------------------------------------------
		draw(d);
	}
	int GAME::collision(struct CHARA* c, struct BULLET* b)
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
				//�G��ĂȂ�
				return 0;
			}
			else {
				//�G��Ă���
				return 1;

			}
		}
		return 0;
	}
	int GAME::collision2(struct CHARA* c, struct ITEM* i) {
		if (i->hp > 0) {
			float cRight = c->px + c->halfW;
			float cLeft = c->px - c->halfW;
			float cTop = c->py - c->halfH;
			float cBottom = c->py + c->halfH;
			float iRight = i->px + i->halfW;
			float iLeft = i->px - i->halfW;
			float iTop = i->py - i->halfH;
			float iBottom = i->py + i->halfH;
			if (cRight < iLeft || iRight < cLeft ||
				iBottom < cTop || cBottom < iTop) {
				//�G��ĂȂ�
				return 0;
			}
			else {
				//�G��Ă���
				return 1;
			}
		}
		return 0;
	}
	void GAME::draw(struct DATA* d) {
		clear();
		//�w�i
		rectMode(CORNER);
		image(OnigasimaImg, 0, 0);
		//�L����
		rectMode(CENTER);
		image(d->hitman.img, d->hitman.px, d->hitman.py);
		image(d->oni.img, d->oni.px, d->oni.py);
		//�e
		if (d->tama.hp > 0) {
			image(d->tama.img, d->tama.px, d->tama.py);
		}

		if (d->fire.hp > 0) {
			image(d->fire.img, d->fire.px, d->fire.py);
		}

		if (d->misairu.hp > 0) {
			image(d->misairu.img, d->misairu.px, d->misairu.py);
		}
		if (d->kaihukuyaku.hp > 0) {
			image(d->kaihukuyaku.img, d->kaihukuyaku.px, d->kaihukuyaku.py);
		}
		//HP�Q�[�W
		hpGauge(&d->hitman);
		hpGauge(&d->oni);

		/*
		//�����蔻��G���A
		fill(255, 255, 255, 128);
		rect(d->hitman.px, d->hitman.py, d->hitman.halfW * 2, d->hitman.halfH * 2);
		rect(d->tama.px, d->tama.py, d->tama.halfW * 2, d->tama.halfH * 2);
		rect(d->misairu.px, d->misairu.py, d->misairu.halfW * 2, d->misairu.halfH * 2);
		rect(d->oni.px, d->oni.py, d->oni.halfW * 2, d->oni.halfH * 2);
		rect(d->fire.px, d->fire.py, d->fire.halfW * 2, d->fire.halfH * 2);
		rect(d->kaihukuyaku.px, d->kaihukuyaku.py, d->kaihukuyaku.halfW * 2, d->kaihukuyaku.halfH * 2);	
		*/
	}
	void GAME::hpGauge(struct CHARA* c)
	{
		strokeWeight(0);
		fill(128);
		rect(c->px, c->py + c->hpGaugeOfsY, c->Maxhp, 15);
		if (c->hp > hpWarning) {
			fill(0, 255, 0);
		}
		else if(c->hp > hpDanger){
			fill(255, 255, 0);
		}
		else {
			fill(255, 0, 50);
		}
		rect(c->px, c->py + c->hpGaugeOfsY, c->hp, 15);
	}
	
	void GAME::Result(struct DATA* d)
	{
		//���ƃt�@�C���[�ƃ~�T�C������ʊO�܂ňړ�
		if (d->tama.hp > 0) {
			d->tama.py += d->tama.vy;
			if (d->tama.py < -d->tama.halfH) {
				d->tama.hp = 0;
			}
		}
		if (d->fire.hp > 0) {
			d->fire.py += d->fire.vy;
			if (d->fire.py < -d->fire.halfH) {
				d->fire.hp = 0;
			}
		}
		if (d->misairu.hp > 0) {
			d->misairu.py += d->misairu.vy;
			if (d->misairu.py > height + d->misairu.halfH) {
				d->misairu.hp = 0;
			}
		}
		//�`��
		draw(d);

		//���U���g
		if(d->hitman.hp < maxhp && d->oni.hp <= 0){//����
			clear(255, 0, 50);
			image(d->hitman.img, d->hitman.px = width / 2, d->hitman.py = height / 2);
			fill(255);
			textSize(180);
			text("Game Clear!!!", 450, 200);
			textSize(100);
			text("Space�Ń^�C�g���ɖ߂�܂�", 20, height);
			if (isTrigger(KEY_SPACE)) {
				stopSound(WinSnd);
				playSound(ClickSnd);
				State = TITLE;
			}
		}
		else if (d->hitman.hp >= maxhp && d->oni.hp <= 0) {//HP��130, �܂���80�ȏ�c���ď���
			clear(180, 190, 0);
			image(d->hitman.pwinImg, d->hitman.px = width / 2, d->hitman.py = height / 2);
			fill(255, 0 , 0);
			textSize(150);
			text("Perfect Game!!!!!", 400, 200);
			textSize(100);
			text("Space�Ń^�C�g���ɖ߂�܂�", 20, height);
			if (isTrigger(KEY_SPACE)) {
				stopSound(PclearSnd);
				playSound(ClickSnd);
				State = TITLE;
			}
		}
		else {//����
			clear(0);
			image(d->hitman.img, d->hitman.px = width / 2, d->hitman.py = height / 2);
			fill(0, 0, 255);
			textSize(180);
			text("Game Over...", 450, 200);
			fill(255);
			textSize(100);
			text("Space�Ń^�C�g���ɖ߂�܂�", 25, height);
			if (isTrigger(KEY_SPACE)) {
				stopSound(LoseSnd);
				playSound(ClickSnd);
				State = TITLE;
			}
		}
	}
}