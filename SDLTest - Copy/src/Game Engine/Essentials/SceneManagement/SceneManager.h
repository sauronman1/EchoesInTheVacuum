#pragma once
#include <map>
#include <string>
#include "Scene.h"
#include "../../GameObject/GameObjectManager.h"
#include "../CommonFunctions.h"
class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() = default;

	inline static SceneManager& get() {
		if (sm_instance == nullptr) {
			sm_instance = new SceneManager();
		}
		return *sm_instance;
	}
	void init(GameObjectManager* manager, Scene* firstScene);
	void setCurrentScene(Scene* scene);
	Scene* getCurrentScene() { return currentScene;}
	void removeScene();
	void goToNextScene(int sceneID);
	void update(float deltaTime) { currentScene->update(deltaTime); }

private:
	static SceneManager* sm_instance;
	Scene* currentScene;
	GameObjectManager* manager;


};

