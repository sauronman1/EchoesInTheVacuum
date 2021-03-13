#include "CreditCanvas.h"
#include "../../Scripts/Common/PredefinedSceneHelper.h"

void CreditCanvas::update(float deltaTime)
{
	if (SceneManager::get().getSceneState() == true) {
		return;
	}

	if (SDLEvent::get().getButtonDown(LEFT) == true && isClicked == false) {
		isClicked = true;
		if (SDLEvent::get().getMousePos().x > 700 && SDLEvent::get().getMousePos().x < 854 && SDLEvent::get().getMousePos().y > 428 && SDLEvent::get().getMousePos().y < 469) {
			std::cout << SDLEvent::get().getMousePos() << std::endl;
			SceneManager::get().setSceneState(true);
			Game::get().pauseGame();
			SceneManager::get().goToNextScene(1);
			return;
		}
		if (SDLEvent::get().getMousePos().x > 1102 && SDLEvent::get().getMousePos().x < 1200 && SDLEvent::get().getMousePos().y > 428 && SDLEvent::get().getMousePos().y < 469) {
			Game::get().quit();
		}
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}
}

bool CreditCanvas::init()
{
	isClicked = false;
	return false;
}
