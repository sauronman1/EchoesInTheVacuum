#include "CreditsScene.h"
#include "../Scripts/Common/PredefinedSceneHelper.h"
#include "Others/CreditCanvas.h"



void CreditsScene::init() {
	Game::get().unPauseGame();  // Unpausing all the updates as the scene is init and previous memory scene has been cleaned
	GameObject* canvas = new GameObject(); // Adding Textures and Scounds that are gonna be used in this scene
	PredefinedSceneHelper::addCreditSceneAssets();
	PredefinedSceneHelper::addCreditSceneObjects(manager); // Adding all gameObjects , Mainly buttons for the canvas below . Organizing
	manager->addGameObject(canvas);
	canvas->addComponent<CreditCanvas>(); // Canvas Script handeling the Menu UI .
}
