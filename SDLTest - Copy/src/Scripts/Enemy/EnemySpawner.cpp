#include "EnemySpawner.h"
#include <list>
#include <iostream>
#include "../../Game Engine/Essentials/CommonFunctions.h"
#include "../../Game Engine/GameObject/Components/BoxCollider2D.h"
#include "../../Game Engine/GameObject/Components/Rigibody2D.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Game Engine/GameObject/Components/Transform.h"
#include "Enemy.h"

bool isCreatingEnemies = false;
int eCounts = 0;
float spawnDelay = 999;
int edgeMinYPosition = 0;
int edgeMaxYPosition = 850;
float counter = 0;
Vector2<int> rectDefault = {180,180};
Vector2<float> offScreen = { 1700,0 };
Vector2<float> zeroForce = {0,0};

 int maxSpawnRateInSeconds = 5;
 int minSpawnRateInSeconds = 1;

void EnemySpawner::ScheduleNextEnemySpawn()
{
}

void EnemySpawner::update(float deltaTime)
{
    counter = counter + deltaTime;
    spawnDelay = rand() % maxSpawnRateInSeconds + minSpawnRateInSeconds;

    if (counter > spawnDelay) {
        counter = 0;
        spawnEnemies(offScreen, zeroForce);
        counter = 0;
    }

}


void EnemySpawner::initSpawnerWithDelay(GameObjectManager* gManager, ObjectPool* bPool, bool isActive, int enCount)
{
    eCounts = enCount;
    isCreatingEnemies = isActive;
    manager = gManager;
    createAllEnemies(bPool);
}


std::string EnemySpawner::getRandomTexture()
{
    int iRandomEnemyName = rand() % eCounts + 1;
    return "enemy" + CommonFunctions::numToString(iRandomEnemyName);
}


void EnemySpawner::createAllEnemies(ObjectPool* bPool)
{
    //Add player to the enemy constructor
    for (auto const& gb : enemyPool->returnAllGameObjectList()) {
            gb->getComponent<Transform>().setPosition(Vector2<float>(-5000,-5000));
            gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), rectDefault.x, rectDefault.y);
            gb->addComponent<Enemy>(bPool, enemyPool);
            gb->addComponent<Rigibody2D>(0, -3, 0);
            gb->addComponent<Sprite>(Game::get().getRenderer(), getRandomTexture());
            gb->getComponent<Transform>().rotation = -90;
            gb->getComponent<Transform>().scale = 0.35f;

            manager->addGameObject(gb);
    }
 
}

void EnemySpawner::spawnEnemies(Vector2<float> position, Vector2<float> force)
{
    if (isCreatingEnemies) {
        position.y = rand() % edgeMaxYPosition + edgeMinYPosition;
        GameObject* gb = enemyPool->getGameObject();
        gb->getComponent<Transform>().setPosition(position);
    }

}

void EnemySpawner::activate()
{
    isCreatingEnemies = true;
}

void EnemySpawner::deActivate()
{
    isCreatingEnemies = false;

}
