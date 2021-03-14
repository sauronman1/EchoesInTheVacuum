#include "EnemySpawner.h"
#include <sstream>
#include "../../Game Engine/GameObject/Components/Rigibody2D.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Scripts/Common/BackgroundEffect.h"
#include "Enemy.h"
#include "../Common/GameScore.h"



void EnemySpawner::update(float deltaTime)
{
    counter = counter + deltaTime;

    if (GameScore::get().getWaveNumber() < 8) {
        spawnDelay = rand() % (maxSpawnRateInSeconds) + (minSpawnRateInSeconds - GameScore::get().getWaveNumber());
    }
    else {
        spawnDelay = rand() % maxSpawnRateInSeconds + (minSpawnRateInSeconds - 7);
    }
    
    if (counter > spawnDelay /10) {
        counter = 0;
        spawnEnemies(offScreen, zeroForce);
        counter = 0;
    }

}


void EnemySpawner::initSpawnerWithDelay(GameObjectManager* gManager, ObjectPool* bPool, GameObject* player, bool isActive, int enCount)
{
    eCounts = enCount;
    isCreatingEnemies = isActive;
    manager = gManager;
    createAllEnemies(bPool, player);
}


std::string EnemySpawner::getRandomTexture()
{
    int iRandomEnemyName = rand() % eCounts + 1;
    return "enemy" + CommonFunctions::numToString(iRandomEnemyName);
}


void EnemySpawner::createAllEnemies(ObjectPool* bPool, GameObject* player)
{
    //Add player to the enemy constructor
    for (auto const& gb : enemyPool->returnAllGameObjectList()) {
            gb->getComponent<Transform>().setPosition(Vector2<float>(-5000,-5000));
            gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), rectDefault.x, rectDefault.y);
            gb->addComponent<Enemy>(bPool, enemyPool, player);
            gb->addComponent<Rigibody2D>(0, -3, 0);
            std::string sprite = getRandomTexture();
            int theNumber;
            int pos = sprite.find("y") + 1;
            std::string numberIs = sprite.substr(pos, pos + 1);
            std::stringstream geek(numberIs);
            geek >> theNumber;
            if (theNumber == 3 || theNumber == 4 || theNumber == 5 || theNumber == 7)
                gb->addComponent<BackgroundEffect>(6, 0, 0);
            gb->addComponent<Sprite>(Game::get().getRenderer(), sprite);
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
