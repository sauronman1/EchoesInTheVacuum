#include "SceneManager.h"
#include "../../../Scenes/MainScene.h"
#include "../../../Scenes/GameScene.h"
#include "../TextureManager.h"
SceneManager* SceneManager::sm_instance = nullptr;

void SceneManager::init(GameObjectManager* manager, Scene* firstScene)
{
	this->manager = manager;
	setCurrentScene(firstScene);
	
}


void SceneManager::setCurrentScene(Scene* scene)
{
	removeScene();
	currentScene = scene;
	currentScene->init(manager);
}

void SceneManager::removeScene()
{
	TextureManager::get().clean();
	delete currentScene;
}

void SceneManager::goToNextScene(int sceneID)
{
	if (sceneID == 0) {
		removeScene();
		MainScene* mainScene = new MainScene();
		setCurrentScene(mainScene);
	}
	else if (sceneID == 1)
	{
		GameScene* gameScene = new GameScene();
		setCurrentScene(gameScene);
	}
}
