#pragma once
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/GameObject/GameObjectManager.h"
#include "../Game Engine/Essentials/SceneManagement/Scene.h"



class MainScene : public Scene
{
public:
	MainScene(GameObjectManager* managerT) {
		manager = managerT;
	};

	~MainScene() override {};
	void init() override final;

private:
	GameObject* toggleIndicator;
	GameObjectManager* manager;
};

