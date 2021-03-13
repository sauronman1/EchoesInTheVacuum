#include "CreditsScene.h"
#include "../Scripts/Common/PredefinedSceneHelper.h"
#include "Others/CreditCanvas.h"



void CreditsScene::init() {
	isClicked = false;
	CommonFunctions::printConsoleMessage("Final Scene Loaded");
	Game::get().unPauseGame();
	GameObject* canvas = new GameObject();
	PredefinedSceneHelper::addCreditSceneAssets();
	PredefinedSceneHelper::addCreditSceneObjects(manager);
	manager->addGameObject(canvas);
	canvas->addComponent<CreditCanvas>(); // Canvas Script handeling the Menu UI .
}
