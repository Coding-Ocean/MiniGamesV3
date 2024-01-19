#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "SELECT.h"
#include "FADE.h"

namespace GAME09
{

	int GAME::create()
	{
		//new
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[SELECT_ID] = new SELECT(this);
		Fade = new FADE(this);

		//load
		Container->load();

		//create
		Scenes[TITLE_ID]->create();
		Fade->create();

		//init
		CurSceneId = TITLE_ID;

		return 0;
	}

	void GAME::destroy()
	{
		for (int i = 0; i < NUM_SCENES; i++) {
			delete Scenes[i];
		}
		delete Container;
	}

	void GAME::proc()
	{
		Scenes[CurSceneId]->proc();
		Fade->proc();

		//ƒƒjƒ…[‚É–ß‚é------------------------------------------
		if (isTrigger(KEY_ENTER)) {
			main()->backToMenu();
		}
	}

	void GAME::changeScene(SCENE_ID sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
		Fade->inStart();
	}
}