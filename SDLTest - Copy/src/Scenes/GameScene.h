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
	ObjectPool<GameObject, 20> bulletPool;
	std::vector<GameObject> activeBullets;


	bool isClicked = false;
	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;
	float moveSpeed;
	float timer = 0;
	float coolDown = 1;
	int score = 0;
};

