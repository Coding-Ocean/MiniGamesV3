#include <fstream>
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "../MAIN/LEVEL_FACTORY.h"
#include "../MAIN/MAIN.h"
#include "MENU.h"

int MENU::create()
{
	//�e�ϐ�������
	Rows = 2;//�s
	Cols = 3;//��
	TileW = 160 * 3;
	TileH = 90 * 3;
	OfstX = (width - TileW * Cols) / 2;
	OfstY = (height - TileH * Rows) / 2;
	DivHue = 360.0f / (Cols * Rows);
	SizeText = 40;
	IndexMouseHolding = -1;

	LoadIndices();
	LoadTitleNames();

	return 0;
}

void MENU::LoadIndices()
{
	//���j���[�ɕ��ׂ郌�x���̃C���f�b�N�X�ԍ��̔z��m��
	NumIndices = Rows * Cols;
	Indices = new char[NumIndices] {};
	//���j���[�ɕ��ׂ郌�x���̃C���f�b�N�X�ԍ��t�@�C����Indices�z��ɓǂݍ���
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ifstream ifs(fileName, std::ios::binary);
	if (ifs) {
		//��C�ɓǂݍ��ށB�������̃G���[�����͂��Ă��Ȃ��B
		ifs.read(Indices, NumIndices);
		ifs.close();
	}
	else {
		//�t�@�C����������ΘA�Ԃ�ݒ�
		for (int i = 0; i < NumIndices; i++) {
			Indices[i] = i;
		}
	}
}

void MENU::LoadTitleNames()
{
	//�^�C���ɕ\�����郌�x���^�C�g���̃e�L�X�g��ǂݍ��ޔz��m��
	Titles = new std::string[NumIndices];
	//�^�C���ɕ\�����郌�x���^�C�g���̃e�L�X�g���t�@�C������ǂݍ���
	std::ifstream ifs;
	char buf[128];
	for (int i = 0; i < NumIndices; i++) {
		sprintf_s(buf, "../MAIN/assets/game%02d/title.txt", i);
		ifs.open(buf);
		std::getline(ifs, Titles[i]);
		ifs.close();
	}
}

void MENU::destroy()
{
	//���݂̃C���f�b�N�X�̕��т��t�@�C���ɏ�������
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ofstream ofs(fileName, std::ios::binary);
	ofs.write(Indices, NumIndices);

	delete[] Titles;
	delete[] Indices;
}


void MENU::proc()
{
	//�X�V--------------------------------------------------
	ChangePosition();
	//�`��--------------------------------------------------
	Draw();
	//�E�N���b�N�őI���������x���ɐ؂�ւ�-----------------------
	if (isTrigger(MOUSE_LBUTTON)) {
		if (IndexMouseOver >= 0) {
			int index = Indices[IndexMouseOver];
			main()->setNextLevelId((LEVEL_FACTORY::LEVEL_ID)index);
		}
	}
}

void MENU::ChangePosition()
{
	//���N���b�N�ɂ��h���b�O�A���h�h���b�v�Ń��x���̏�������ѕς���

	//�}�E�X������Ă���^�C���̃C���f�b�N�X�B�Ƃ肠��������(-1)
	IndexMouseOver = -1;
	//�}�E�X�����j���[�i�S�^�C���j�͈̔͂ɂ���Ȃ�
	if (mouseX > OfstX && mouseX < OfstX + TileW * Cols &&
		mouseY > OfstY && mouseY < OfstY + TileH * Rows)
	{
		//�}�E�X�̈ʒu�����ԍ��ƍs�ԍ��ɕϊ�
		int mouseCol = int((mouseX - OfstX) / TileW);
		int mouseRow = int((mouseY - OfstY) / TileH);
		//�P�����z��Indices[]�̃C���f�b�N�X�ɕϊ�
		IndexMouseOver = Cols * mouseRow + mouseCol;
		//�u�͂ށI�v�N���b�N���ꂽ���̃C���f�b�N�X������Ă���
		if (isTrigger(MOUSE_RBUTTON))
		{
			IndexMouseHolding = IndexMouseOver;
		}
		//�u�����I�v�}�E�X�{�^���𗣂����ʒu�ɂƂ��Ă������C���f�b�N�X��}��
		if (IndexMouseHolding != -1 &&
			isRelease(MOUSE_RBUTTON))
		{
			//�N���b�N���ꂽ�^�C���̃C���f�b�N�X������Ă���
			int workIndex = Indices[IndexMouseHolding];
			//���̃C���f�b�N�X��O�Ɏ����Ă��������A���ɂ��炷
			if (IndexMouseOver < IndexMouseHolding)
			{
				for (int i = IndexMouseHolding; i > IndexMouseOver; i--)
				{
					Indices[i] = Indices[i - 1];
				}
			}
			//�O�̃C���f�b�N�X�����Ɏ����Ă��������A�O�ɂ��炷
			else if (IndexMouseOver > IndexMouseHolding)
			{
				for (int i = IndexMouseHolding; i < IndexMouseOver; i++)
				{
					Indices[i] = Indices[i + 1];
				}
			}
			//��ł��炷���Ƃɂ��}���ꏊ���ł����̂œ����
			Indices[IndexMouseOver] = workIndex;
			//�����ɂ���
			IndexMouseHolding = -1;
		}
	}
	else {
		//�S�^�C���̊O�ɏo���̂ŁA�͂�ł���C���f�b�N�X�𖳌��ɂ���
		IndexMouseHolding = -1;
	}
}

void MENU::Draw()
{
	//�J���[���[�h�A�g�̐F�A�g�̕�
	colorMode(HSV);
	angleMode(DEGREES);
	stroke(0, 0, 0);
	strokeWeight(5);
	clear(0, 0, 0);
	//Menu�����`��
	textMode(BOTTOM);
	textSize(SizeText);
	fill(0, 0, 255);
	text("Menu", OfstX, OfstY);
	//�^�C���`��
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			//�^�C���̐F������
			int index = Cols * r + c;
			float hue = DivHue * index;
			float saturation = 255;
			float value = 160;
			//�}�E�X����ɂ���^�C���͖��邭
			if (index == IndexMouseOver) {
				saturation = 128;
				value = 255;
			}
			fill(hue, saturation, value);
			//�^�C���̈ʒu
			float px = TileW * c + OfstX;
			float py = TileH * r + OfstY;
			rect(px, py, TileW, TileH);
			//�^�C�g������
			textSize(SizeText);
			fill(0);
			textMode(BOTTOM);
			text(Titles[Indices[index]].c_str(), px + 10, py + 10 + SizeText);
		}
	}
	//�ړ����̃^�C�g��������`��
	if (IndexMouseHolding >= 0) {
		fill(128);
		textMode(BCENTER);
		text(Titles[Indices[IndexMouseHolding]].c_str(), mouseX, mouseY);
	}
}