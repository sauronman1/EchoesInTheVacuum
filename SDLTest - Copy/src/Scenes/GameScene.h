#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
#include "../Game Engine/Math/Vector2.h"
#include "../Scripts/Enemy/EnemySpawner.h"

class GameScene : public Scene
{
public:
	GameScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	void init() override;
	void update(float deltaTime) override;
private:

	ObjectPool* bulletPool = new ObjectPool(100);

	void createAllBullets();
	bool isClicked = false;
	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;
	float moveSpeed;
	float timer = 0;
	float coolDown = 1;
	int score = 0;
};

