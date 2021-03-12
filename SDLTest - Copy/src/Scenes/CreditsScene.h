#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"

class CreditsScene : public Scene
{
public:
	CreditsScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	void init();
	void update(float deltaTime) override;
private:
	GameObject* titleLable;
	GameObject* highscoreLable;
	GameObject* RetryObj;
	GameObject* quitObj;
};

