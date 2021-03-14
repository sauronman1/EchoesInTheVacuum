#pragma once
#include "../../Game Engine/Math/Vector2.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/GameObject/GameObjectManager.h"
#include "../../Game Engine/Essentials/ObjectPool.h"
#include <iostream>
class EnemySpawner : public Component
{
private: 
	ObjectPool *enemyPool = new ObjectPool(300);
	void createAllEnemies(ObjectPool* bPool, GameObject* player);
	void update(float deltaTime) override final;
	std::string getRandomTexture();
	GameObjectManager* manager;

	bool isCreatingEnemies = false;
	int eCounts = 0;
	float spawnDelay = 999;
	int edgeMinYPosition = 0;
	int edgeMaxYPosition = 850;
	float counter = 0;
	Vector2<int> rectDefault = { 180,180 };
	Vector2<float> offScreen = { 1900,0 };
	Vector2<float> zeroForce = { 0,0 };

	int maxSpawnRateInSeconds = 10;
	int minSpawnRateInSeconds = 8;

public :

	EnemySpawner() = default;
	~EnemySpawner() { delete enemyPool; };

	void initSpawnerWithDelay(GameObjectManager* gManager, ObjectPool* bPool, GameObject* player, bool isActive, int enCount);
	void spawnEnemies(Vector2<float> position, Vector2<float> force);
	void activate();
	void deActivate();
};

