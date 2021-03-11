#include "SceneManager.h"
#include "../../../Scenes/MainScene.h"
#include "../../../Scenes/GameScene.h"
#include "../../../Scenes/CreditsScene.h"
#include "../TextureManager.h"
SceneManager* SceneManager::sm_instance = nullptr;

void SceneManager::init(GameObjectManager* manager)
{
	this->manager = manager;
	goToNextScene(0);
}


void SceneManager::setCurrentScene()
{
	currentScene->init();
}

void SceneManager::removeScene()
{
	TextureManager::get().clean();
	manager->cleanGameObject();
	delete currentScene;
}

void SceneManager::goToNextScene(int sceneID)
{
	removeScene();

	if (sceneID == 0) {
		MainScene* mainScene = new MainScene(manager);
		currentScene = mainScene;
		setCurrentScene();
	}
	else if (sceneID == 1)
	{
		GameScene* gameScene = new GameScene(manager);
		currentScene = gameScene;
		setCurrentScene();
	}
	else if (sceneID == 2)
	{
		CreditsScene* creditsScene = new CreditsScene(manager);
		currentScene = creditsScene;
		setCurrentScene();
	}
}
