#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include"CONTAINER.h"
#include "GAME14.h"
namespace GAME14
{

	int GAME::create()
	{
		//ここでは主に画像と音データを読み込む

		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。
		
		return 0;
	}

	void GAME::init()
	{
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
	}

	void GAME::proc()
	{
		//ここはメインループから呼び出されている!!!!!

		//描画--------------------------------------------------
		clear(255, 255, 255);
		//円
		strokeWeight(50);
		stroke(0);
		fill(255, 0, 0);
		//テキスト情報
		fill(0);
		textSize(100);
		text("Enterでメニューに戻る", 0, height);
		print(14);
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
void GAME::player(){}
void GAME::building(){}
void GAME::title(){}
void GAME::stage(){}
void GAME::game_crear(){}
void GAME::game_over(){}

}
