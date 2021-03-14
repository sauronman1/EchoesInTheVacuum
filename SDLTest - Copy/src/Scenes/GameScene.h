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
	~GameScene() override {
		delete bulletPool;
	}
	void init() override final;
	void update(float deltaTime) override;

private:
	ObjectPool* bulletPool = new ObjectPool(100);

	GameObject* playerObj;
	GameObject* enemyObj;
	GameObject* scoreLabel;
	GameObject* healthLabel;
	GameObject* waveLabel;
	GameObject* coolDownLabel;



	int enemyCount;
	int currentScore;
	int currentHealth;
	int currentWave;

	int healthTemp;
	int cooldown;
	float counter;
};

