#include "../../libOne/inc/libOne.h"
#include "../MAIN/MAIN.h"
#include "GAME09.h"
#include "CONTAINER.h"
#include "TITLE.h"
#include "SELECT.h"
#include "FADE.h"
#include "MESSAGE.h"
#include "AROUNDJAPAN.h"
#include "BINGO.h"
#include "BACKBUTTON.h"
#include "BACKGROUND.h"

namespace GAME09
{

	int GAME::create()
	{
		//new
		Container = new CONTAINER;
		Scenes[TITLE_ID] = new TITLE(this);
		Scenes[SELECT_ID] = new SELECT(this);
		Scenes[NUM_SCENES + AroundJapan] = new AROUNDJAPAN(this);
		Scenes[NUM_SCENES + Bingo] = new BINGO(this);
		Scenes[NUM_SCENES + Enpty1] = nullptr;
		Scenes[NUM_SCENES + Enpty2] = nullptr;
		Scenes[NUM_SCENES + Enpty3] = nullptr;
		Scenes[NUM_SCENES + Enpty4] = nullptr;
		Fade = new FADE(this);
		Message = new MESSAGE(this);
		Back = new BACKBUTTON(this);
		BackG = new BACKGROUND(this);

		//load
		Container->load();

		//create
		for (int i = 0; i < NUM_SCENES + NUM_GAMES; i++) {
			if (Scenes[i] != nullptr) {
				Scenes[i]->create();
			}
		}
		Fade->create();
		Message->create();
		Back->create();
		BackG->create();

		//init
		CurSceneId = TITLE_ID;

		return 0;
	}

	void GAME::destroy()
	{
		delete BackG;
		delete Back;
		delete Message;
		delete Fade;
		for (int i = 0; i < NUM_SCENES + NUM_GAMES; i++) {
			if (Scenes[i] != nullptr) {
				delete Scenes[i];
			}
		}
		delete Container;
	}

	void GAME::proc()
	{
		clear();
		BackG->proc();
		Scenes[CurSceneId]->proc();
		Message->proc();
		Back->proc();
		Fade->proc();
	}

	void GAME::changeScene(int sceneId) {
		CurSceneId = sceneId;
		Scenes[CurSceneId]->init();
		Fade->inStart();
		Message->resetMessage();
	}

	void GAME::backToMenu() {
		main()->backToMenu();
	}

	void GAME::launchGame(GAME_ID gameId) {
		int sceneId = NUM_SCENES + gameId;
		if (Scenes[sceneId] == nullptr) {
			Message->upperMessage("ƒQ[ƒ€‚ª‚ ‚è‚Ü‚¹‚ñ");
		}
		else {
			Fade->outStart();
		}
	}
}