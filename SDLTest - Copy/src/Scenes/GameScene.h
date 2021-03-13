#pragma once
#include "../Game Engine/Essentials/SceneManagement/Scene.h"
#include "../Game Engine/Math/Vector2.h"
#include "../Scripts/Enemy/EnemySpawner.h"
//#include "../Game Engine/GameObject/GameObject.h"

class GameScene : public Scene
{
public:
	GameScene(GameObjectManager* manager) {
		this->manager = manager;
	};
	~GameScene() override {
		delete bulletPool;
	}
	void init() override;
	void update(float deltaTime) override;

private:
	ObjectPool* bulletPool = new ObjectPool(100);
	
	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;

	int enemyCount;
	int currentScore;
};

