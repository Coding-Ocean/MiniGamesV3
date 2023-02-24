#include <fstream>
#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "../MAIN/LEVEL_FACTORY.h"
#include "../MAIN/MAIN.h"
#include "MENU.h"

void MENU::create()
{
	Rows = 2;//�s
	Cols = 3;//��
	TileW = 160*3;
	TileH = 90*3;
	OfstX = (width - TileW * Cols) / 2;
	OfstY = (height - TileH * Rows) / 2;
	DivHue = 360.0f / (Cols * Rows);
	SizeText = 40;

	//
	NumIndices = Rows * Cols;
	Indices = new char[NumIndices];
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ifstream ifs(fileName, std::ios::binary);
	if (ifs) {
		ifs.read(Indices, NumIndices);
		for (int i = 0; i < NumIndices; i++) {
			if (Indices[i] == -51) {
				Indices[i] = i;
			}
		}
	}
	else {
		for (int i = 0; i < NumIndices; i++) {
			Indices[i] = i;
		}
	}
	ifs.close();

	//�^�C���ɕ\������^�C�g���e�L�X�g
	Titles = new std::string[NumIndices];
	char buf[128];
	for (int i = 0; i < NumIndices; i++) {
		sprintf_s(buf,"../MAIN/assets/game%02d/title.txt",i);
		ifs.open(buf);
		std::getline(ifs,Titles[i]);
		ifs.close();
	}

	IndexMouseHolding = -1;
}

void MENU::destroy()
{
	const char* fileName = "../MAIN/assets/menu/indices.bin";
	std::ofstream ofs(fileName, std::ios::binary);
	ofs.write(Indices, NumIndices);
	
	delete[] Titles;
	delete[] Indices;
}

void MENU::proc()
{
	//�X�V--------------------------------------------------
	//�}�E�X������Ă���^�C����selectIndex������
		//�}�E�X������^�C���̃C���f�b�N�X
	int indexMouseOver = -1;
	//�}�E�X�����j���[�i�S�^�C���j�͈̔͂ɂ���
	if (mouseX > OfstX && mouseX < OfstX + TileW * Cols &&
		mouseY > OfstY && mouseY < OfstY + TileH * Rows)
	{
		//�}�E�X�̈ʒu�����ԍ��ƍs�ԍ��ɕϊ�
		int mouseCol = int((mouseX - OfstX) / TileW);
		int mouseRow = int((mouseY - OfstY) / TileH);
		//�P�����z��Indices[]�̃C���f�b�N�X�ɕϊ�
		indexMouseOver = Cols * mouseRow + mouseCol;
		//�N���b�N���ꂽ���̃C���f�b�N�X������Ă���
		if (isTrigger(MOUSE_RBUTTON))
		{
			IndexMouseHolding = indexMouseOver;
		}
		//�}�E�X�{�^���𗣂����ʒu�ɂƂ��Ă������C���f�b�N�X��}��
		if (IndexMouseHolding != -1 &&
			isRelease(MOUSE_RBUTTON))
		{
			//�N���b�N���ꂽ�^�C���̃C���f�b�N�X������Ă���
			int workIndex = Indices[IndexMouseHolding];
			//���̃C���f�b�N�X��O�Ɏ����Ă��������A���ɂ��炷
			if (indexMouseOver < IndexMouseHolding)
			{
				for (int i = IndexMouseHolding; i > indexMouseOver; i--)
				{
					Indices[i] = Indices[i - 1];
				}
			}
			//�O�̃C���f�b�N�X�����Ɏ����Ă��������A�O�ɂ��炷
			else if (indexMouseOver > IndexMouseHolding)
			{
				for (int i = IndexMouseHolding; i < indexMouseOver; i++)
				{
					Indices[i] = Indices[i + 1];
				}
			}
			//��ł��炷���Ƃɂ��}���ꏊ���ł����̂œ����
			Indices[indexMouseOver] = workIndex;
			//�����ɂ���
			IndexMouseHolding = -1;
		}
	}
	else {
		//�����ɂ���
		IndexMouseHolding = -1;
	}
	//�`��--------------------------------------------------
	//�J���[���[�h�A�g�̐F�A�g�̕�
	colorMode(HSV);
	angleMode(DEGREES);
	stroke(0, 0, 0);
	strokeWeight(5);
	clear(0,0,0);
	//Menu����
	textMode(BOTTOM);
	textSize(SizeText);
	fill(0, 0, 255);
	text("Menu", OfstX, OfstY);
	//�^�C��
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
			if (index == indexMouseOver) {
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
			text(Titles[Indices[index]].c_str(), px+10, py +10+ SizeText);
		}
	}
	if (IndexMouseHolding >= 0) {
		fill(128);
		textMode(BCENTER);
		text(Titles[Indices[IndexMouseHolding]].c_str(), mouseX, mouseY);
	}
	//for (int r = 0; r < Rows; r++) {
	//	for (int c = 0; c < Cols; c++) {
	//		//�^�C���̐F������
	//		int index = Cols * r + c;
	//		float hue = DivHue * index;
	//		float saturation = 200;
	//		//�}�E�X����ɂ���^�C���͖��邭
	//		if (index == selectIndex) {
	//			saturation = 0;
	//		}
	//		fill(hue, saturation, 200);
	//		//�^�C���̕\���ʒu�����߂ĕ`��
	//		float px = TileW * c + OfstX;
	//		float py = TileH * r + OfstY;
	//		rect(px, py, TileW, TileH);
	//		//�C���f�b�N�X�\��
	//		fill(0);
	//		text(index, px + 10, py + size + 10);
	//	}
	//}

	if (Indices[indexMouseOver] >= 0 &&
		isTrigger(MOUSE_LBUTTON)) {
		main()->setNextLevelId(
			(LEVEL_FACTORY::LEVEL_ID)Indices[indexMouseOver]);
	}
}


