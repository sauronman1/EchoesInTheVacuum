#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
class GameScene : public Scene
{
public:
	GameScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	void init() override;
	void update(float deltaTime) override;
private:
	bool isClicked = false;
	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;
	float moveSpeed;
	float timer = 0;
	float coolDown = 1;
	int score = 0;
};

