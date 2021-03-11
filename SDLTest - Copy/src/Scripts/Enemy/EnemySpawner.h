#pragma once
#include "../../Game Engine/Math/Vector2.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/GameObject/GameObjectManager.h"
#include "../../Game Engine/Essentials/ObjectPool.h"
#include <iostream>
class EnemySpawner : public Component
{
private: 
	std::vector<GameObject> activeEnemies;
	ObjectPool <GameObject, 200> enemyPool;

	void ScheduleNextEnemySpawn();
	void update(float deltaTime) override final;
	std::string getRandomTexture();
	GameObjectManager* manager;

public :

	void initSpawnerWithDelay(GameObjectManager* gManager,  bool isActive, int enCount);
	void spawnEnemies(Vector2<int> rect, Vector2<float> position, Vector2<float> force);
	void activate();
	void deActivate();
	auto getActiveEnemies() { return &activeEnemies; }



};

