#include "TITLE_BUTTON.h"
#include"CONTAINER.h"
#include"GAME14.h"
namespace GAME14 {
	TITLE_BUTTON::TITLE_BUTTON(class GAME* game):
		BUTTON(game){}
	TITLE_BUTTON::~TITLE_BUTTON(){}
	void TITLE_BUTTON::create(int* serectId){
		Button = game()->container()->data().title_button;
		Button.serectId = serectId;
	}
}