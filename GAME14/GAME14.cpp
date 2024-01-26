#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"BUILDING.h"
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include "GAME14.h"
namespace GAME14
{

	int GAME::create()
	{
		//ここでは主に画像と音データを読み込む

		//初期値設定はInit()関数などを作ってそこで行ったほうが良い。
		//シンプルなゲームなら次のように、ここで行ってもよい。
		Container = new CONTAINER();	
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[STAGE_ID] = new STAGE(this);
		Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
		Scenes[GAME_OVER_ID] = new GAME_OVER(this);
		
		Player = new PLAYER(this);
		Building = new BUILDING(this);

		Container->load();
		for (int i = 0; i < NUM_SCENES; i++) {
			Scenes[i]->create();
		}
		Player->create();
		Building->create();
		changeScene(TITLE_ID);

		return 0;
	}

	void GAME::init()
	{
	}

	void GAME::destroy()
	{
		//create()でnewした場合はここでdeleteすること
		delete Building;
		delete Player;
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		//ここはメインループから呼び出されている!!!!!

		//描画--------------------------------------------------
		Scenes[CurSceneId]->proc();
		//テキスト情報
		fill(0);
		textSize(100);
		text("Enterでメニューに戻る", 0, height);
		//メニューに戻る------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}
	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
	}

}
