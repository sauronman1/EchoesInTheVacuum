#include "SceneManager.h"
#include "../../../Scenes/MainScene.h"
#include "../../../Scenes/GameScene.h"
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

	if (sceneID == 0) {
		MainScene* mainScene = new MainScene(manager);
		currentScene = mainScene;
		setCurrentScene();
	}
	else if (sceneID == 1)
	{
		removeScene();
		GameScene* gameScene = new GameScene(manager);
		currentScene = gameScene;
		setCurrentScene();
	}
}
