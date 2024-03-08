#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME07.h"
#include <time.h>
namespace GAME07
{

	int GAME::create()
	{
		//ここでは主に画像と音データを読み込む
		State = TITLE;
		//背景
		TitleImg = loadImage("..\\main\\assets\\game07\\Image\\title.jpg");
		PlayImg = loadImage("..\\main\\assets\\game07\\Image\\play.jpg");
		ResultImg = loadImage("..\\main\\assets\\game07\\Image\\result.jpg");
		//トランプ
		c[0] = loadImage("..\\main\\assets\\game07\\Image\\back_card.png");

		H[1] = loadImage("..\\main\\assets\\game07\\Image\\heart\\1.png");
		H[2] = loadImage("..\\main\\assets\\game07\\Image\\heart\\2.png");
		H[3] = loadImage("..\\main\\assets\\game07\\Image\\heart\\3.png");
		H[4] = loadImage("..\\main\\assets\\game07\\Image\\heart\\4.png");
		H[5] = loadImage("..\\main\\assets\\game07\\Image\\heart\\5.png");
		H[6] = loadImage("..\\main\\assets\\game07\\Image\\heart\\6.png");
		H[7] = loadImage("..\\main\\assets\\game07\\Image\\heart\\7.png");
		H[8] = loadImage("..\\main\\assets\\game07\\Image\\heart\\8.png");
		H[9] = loadImage("..\\main\\assets\\game07\\Image\\heart\\9.png");
		H[10] = loadImage("..\\main\\assets\\game07\\Image\\heart\\10.png");
		H[11] = loadImage("..\\main\\assets\\game07\\Image\\heart\\11.png");
		H[12] = loadImage("..\\main\\assets\\game07\\Image\\heart\\12.png");
		H[13] = loadImage("..\\main\\assets\\game07\\Image\\heart\\13.png");

		D[1] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\1.png");
		D[2] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\2.png");
		D[3] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\3.png");
		D[4] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\4.png");
		D[5] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\5.png");
		D[6] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\6.png");
		D[7] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\7.png");
		D[8] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\8.png");
		D[9] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\9.png");
		D[10] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\10.png");
		D[11] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\11.png");
		D[12] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\12.png");
		D[13] = loadImage("..\\main\\assets\\game07\\Image\\diamond\\13.png");

		S[1] = loadImage("..\\main\\assets\\game07\\Image\\spade\\1.png");
		S[2] = loadImage("..\\main\\assets\\game07\\Image\\spade\\2.png");
		S[3] = loadImage("..\\main\\assets\\game07\\Image\\spade\\3.png");
		S[4] = loadImage("..\\main\\assets\\game07\\Image\\spade\\4.png");
		S[5] = loadImage("..\\main\\assets\\game07\\Image\\spade\\5.png");
		S[6] = loadImage("..\\main\\assets\\game07\\Image\\spade\\6.png");
		S[7] = loadImage("..\\main\\assets\\game07\\Image\\spade\\7.png");
		S[8] = loadImage("..\\main\\assets\\game07\\Image\\spade\\8.png");
		S[9] = loadImage("..\\main\\assets\\game07\\Image\\spade\\9.png");
		S[10] = loadImage("..\\main\\assets\\game07\\Image\\spade\\10.png");
		S[11] = loadImage("..\\main\\assets\\game07\\Image\\spade\\11.png");
		S[12] = loadImage("..\\main\\assets\\game07\\Image\\spade\\12.png");
		S[13] = loadImage("..\\main\\assets\\game07\\Image\\spade\\13.png");

		C[1] = loadImage("..\\main\\assets\\game07\\Image\\club\\1.png");
		C[2] = loadImage("..\\main\\assets\\game07\\Image\\club\\2.png");
		C[3] = loadImage("..\\main\\assets\\game07\\Image\\club\\3.png");
		C[4] = loadImage("..\\main\\assets\\game07\\Image\\club\\4.png");
		C[5] = loadImage("..\\main\\assets\\game07\\Image\\club\\5.png");
		C[6] = loadImage("..\\main\\assets\\game07\\Image\\club\\6.png");
		C[7] = loadImage("..\\main\\assets\\game07\\Image\\club\\7.png");
		C[8] = loadImage("..\\main\\assets\\game07\\Image\\club\\8.png");
		C[9] = loadImage("..\\main\\assets\\game07\\Image\\club\\9.png");
		C[10] = loadImage("..\\main\\assets\\game07\\Image\\club\\10.png");
		C[11] = loadImage("..\\main\\assets\\game07\\Image\\club\\11.png");
		C[12] = loadImage("..\\main\\assets\\game07\\Image\\club\\12.png");
		C[13] = loadImage("..\\main\\assets\\game07\\Image\\club\\13.png");

		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。

		return 0;
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
	}

	void GAME::proc()
	{
		//シーン切り替え
		if (State == TITLE)Title();
		else if (State == PLAY)Play();
		else if (State == CLEAR)Clear();
	}

	void GAME::Title(){
		//ここはメインループから呼び出されている!!!!!

		//描画--------------------------------------------------
		clear(0);
		//テキスト情報
		image(TitleImg, 0, 0, full);
		fill(255);
		textSize(150);
		text("BLACKJACK", 640, 400);
		textSize(75);
		text("クリックでゲームスタート", 520, 900);
		text("enterでメニューに戻る", 580, 1000);
		//シーン切り替え-----------------------------------------
		if (isTrigger(MOUSE_LBUTTON)) {
			Init();
			State = PLAY;
			return;
		}
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::Init()
	{
		//ボタン
		Bx = 355;
		By = 895;
		BWidth = 250;
		BHeight = 100;
		//トランプ
		Tx = 680;
		Ty = 100;
		TRate = 0.3;
		TDx = 350;
		TDy = 570;

		//配列cにトランプ情報を格納する

		int j = 1;

		for (int i = 1; i < SUM; i++) {
			if (i % CARD_NUMBER == 0) {
				j = 1;
			}

			if (i / CARD_NUMBER == 3) {
				c[i] = C[j];
			}
			else if (i / CARD_NUMBER == 2) {
				c[i] = S[j];
			}
			else if (i / CARD_NUMBER == 1) {
				c[i] = D[j];
			}
			else {
				c[i] = H[j];
			}
			j++;
		}

		//配列をシャッフルする
		int k = 0;
		int l = 0;
		int tmp = 0;
		//配列の末尾
		k = SUM;

		while (k > 0) {
			//シャッフル対象をランダムに決定
			srand(time(NULL));
			l = random() % k;
			//ランダムに決めた位置と末尾を交換
			if (l == 0) {
				c[l] = c[l];
			}
			else {
				tmp = c[l];
				c[l] = c[k];
				c[k] = tmp;
			}
			k--;
		}
	}

	void GAME::Play()
	{
		image(PlayImg, 0, 0);

		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 0) {
				j = 0;
			}
			if (i == 0) {
				TRate = 0.42;
			}
			image(c[i], Tx + TDx * j, Ty + TDy * (i / 2), TAngle, TRate);

			TRate = 0.3;
			j++;
		}
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}

	}

	void GAME::Clear() {

	}
}