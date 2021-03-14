#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include "../../GameObject/GameObjectManager.h"
#include "../CommonFunctions.h"
class SceneManager
{
public:
	~SceneManager() = default;

	inline static SceneManager& get() {
		if (sm_instance == nullptr) {
			sm_instance = new SceneManager();
		}
		return *sm_instance;
	}
	void init(GameObjectManager* manager);
	void setCurrentScene();
	Scene* getCurrentScene() { return currentScene;}
	void removeScene();
	void goToNextScene(int sceneID);
	void update(float deltaTime) { 
			currentScene->update(deltaTime);
	}
	bool getSceneState() {
		return currentScene->sceneFinished;
	}
	void setSceneState(bool enabled) {
		currentScene->sceneFinished = enabled;
	}
private:
	static SceneManager* sm_instance;
	Scene* currentScene;

	GameObjectManager* manager;


};

