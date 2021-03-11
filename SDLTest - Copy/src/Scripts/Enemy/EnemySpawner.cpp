#include "EnemySpawner.h"
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
        spawnEnemies({ 180,180 }, { 1700,0 }, {0,0});
        counter = 0;
    }

}


void EnemySpawner::initSpawnerWithDelay(GameObjectManager* gManager, bool isActive, int enCount)
{
    eCounts = enCount;
    isCreatingEnemies = isActive;
    manager = gManager;
}


std::string EnemySpawner::getRandomTexture()
{
    int iRandomEnemyName = rand() % eCounts + 1;
    return "enemy" + CommonFunctions::numToString(iRandomEnemyName);
}

void EnemySpawner::spawnEnemies(Vector2<int> rect, Vector2<float> position, Vector2<float> force)
{
    if (isCreatingEnemies) {
        position.y = rand() % edgeMaxYPosition + edgeMinYPosition;

       GameObject* gb = enemyPool.allocate();

        if (!gb->hasComponent<Rigibody2D>()) {
            gb->addComponent<Rigibody2D>(0);
            gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), rect.x, rect.y);
            gb->addComponent<Enemy>();
            gb->addComponent<Sprite>(Game::get().getRenderer(), getRandomTexture());
            gb->getComponent<Transform>().rotation = -90;
            gb->getComponent<Transform>().scale = 0.35f;

            manager->addGameObject(gb);
        }
        CommonFunctions::printConsoleMessage("Creating a enemy");
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
