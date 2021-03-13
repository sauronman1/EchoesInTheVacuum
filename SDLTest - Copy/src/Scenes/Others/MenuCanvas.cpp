#include "MenuCanvas.h"
#include "../../Scripts/Common/PredefinedSceneHelper.h"


bool MenuCanvas::init()
{
	isClicked = false;
	return true;
}

void MenuCanvas::update(float deltaTime)
{

	if (SceneManager::get().getSceneState() == true) {
		return;
	}

	if (SDLEvent::get().getButtonDown(LEFT) == true && isClicked == false) {
		isClicked = true;
		if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1200 && SDLEvent::get().getMousePos().y > 350 && SDLEvent::get().getMousePos().y < 470) {
			std::cout << "Go to New Scene" << std::endl;
			SceneManager::get().setSceneState(true);
			Game::get().pauseGame();
			SceneManager::get().goToNextScene(1);
			return;

		}
		if (SDLEvent::get().getMousePos().x > 750 && SDLEvent::get().getMousePos().x < 1180 && SDLEvent::get().getMousePos().y > 550 && SDLEvent::get().getMousePos().y < 680) {
			std::cout << SDLEvent::get().getMousePos() << std::endl;
			SoundManager::Instance()->toggleMusic();
		}
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}
	
}


