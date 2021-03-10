#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
#include "../Game Engine/Essentials/ObjectPool.h"
#include "../Game Engine/Math/Vector2.h"

class GameScene : public Scene
{
public:
	GameScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	void init() override;
	void update(float deltaTime) override;
private:
	ObjectPool<GameObject, 100> enemyPool;
	ObjectPool<GameObject, 20> bulletPool;

	void spawnEnemy(Vector2<int> rect, Vector2<float> position, Vector2<float> force);
	std::string getRandomTexture();

	bool isClicked = false;
	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;
	float moveSpeed;
	float timer = 0;
	float coolDown = 1;
	int score = 0;
};

