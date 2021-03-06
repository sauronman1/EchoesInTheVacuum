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


void SceneManager::setCurrentScene(Scene* scene)
{
	removeScene();
	currentScene = scene;
	isPaused = false;
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
	isPaused = true;

	if (sceneID == 0) {
		MainScene* mainScene = new MainScene(manager);
		setCurrentScene(mainScene);
	}
	else if (sceneID == 1)
	{
		GameScene* gameScene = new GameScene(manager);
		setCurrentScene(gameScene);
	}
}
