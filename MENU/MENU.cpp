#include "../../libOne/inc/graphic.h"
#include "../../libOne/inc/input.h"
#include "../../libOne/inc/mathUtil.h"
#include "../MAIN/LEVEL_FACTORY.h"
#include "../MAIN/MAIN.h"
#include "MENU.h"

void MENU::create()
{
	Rows = 2;//�s
	Cols = 2;//��
	TileW = 160*4;
	TileH = 90*4;
	OfstX = (width - TileW * Cols) / 2;
	OfstY = (height - TileH * Rows) / 2;
	DivHue = 360.0f / (Cols * Rows);
}

void MENU::destroy()
{
}

void MENU::proc()
{
	//�X�V--------------------------------------------------
	//�}�E�X������Ă���^�C����selectIndex������
	int selectIndex = -1;//�S�Ẵ^�C���̊O���ɂ���Ƃ��́[�P
	if (mouseX > OfstX && mouseX<OfstX+TileW * Cols &&
		mouseY>OfstY && mouseY < OfstY+TileH * Rows) {
		int mouseCol = int((mouseX - OfstX) / TileW);
		int mouseRow = int((mouseY - OfstY) / TileH);
		selectIndex = Cols * mouseRow + mouseCol;
	}
	//�`��--------------------------------------------------
	//�J���[���[�h�A�g�̐F�A�g�̕�
	colorMode(HSV);
	angleMode(DEGREES);
	stroke(0, 0, 0);
	strokeWeight(5);
	clear(0,0,0);
	//Menu����
	float size = 40;
	textSize(size);
	fill(0, 0, 255);
	text("Menu", OfstX, OfstY);
	//�^�C��
	for (int r = 0; r < Rows; r++) {
		for (int c = 0; c < Cols; c++) {
			//�^�C���̐F������
			int index = Cols * r + c;
			float hue = DivHue * index;
			float saturation = 200;
			//�}�E�X����ɂ���^�C���͖��邭
			if (index == selectIndex) {
				saturation = 0;
			}
			fill(hue, saturation, 200);
			//�^�C���̕\���ʒu�����߂ĕ`��
			float px = TileW * c + OfstX;
			float py = TileH * r + OfstY;
			rect(px, py, TileW, TileH);
			//�C���f�b�N�X�\��
			fill(0);
			text(index, px + 10, py + size + 10);
		}
	}

	if (selectIndex >= 0 &&
		isTrigger(MOUSE_LBUTTON)) {
		main()->setNextLevelId((LEVEL_FACTORY::LEVEL_ID)selectIndex);
	}
}


