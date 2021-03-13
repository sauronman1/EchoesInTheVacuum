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
	if (currentScene == nullptr) return;
	currentScene->sceneFinished = true;
	TextureManager::get().clean();
	manager->cleanGameObject();
	delete currentScene;
}

void SceneManager::goToNextScene(int sceneID)
{
	removeScene();

	if (sceneID == 0) {
		currentScene  = new MainScene(manager);
		setCurrentScene();
	}
	else if (sceneID == 1)
	{
		currentScene = new GameScene(manager);
		setCurrentScene();
	}
	else if (sceneID == 2)
	{
		currentScene = new CreditsScene(manager);
		setCurrentScene();
	}
}
