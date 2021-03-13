#include "GameScene.h"
#include "../Scripts/Common/PredefinedSceneHelper.h"
#include "../Game Engine/Essentials/Collision/Collision2D.h"
#include "../Scripts/Common/BackgroundEffect.h"

void GameScene::init()
{
	enemyCount = 14;
	currentScore = 0;
	currentHealth = 100;
	healthTemp = currentHealth;

	Game::get().unPauseGame(); // Unpausing all the updates as the scene is init and previous memory scene has been cleaned
	GameScore::get().initScore(); // Set Score to Zero as its a new Game
	PredefinedSceneHelper::addGameSceneAssets(enemyCount); // Adding Textures and Scounds that are gonna be used in this scene

	playerObj = new GameObject(); // The Ship controlled byPlayer , Will add <Ship> script to it.
	scoreLabel = new GameObject(); // Score lable to update the score
	healthLabel = new GameObject();
	GameObject* enemySpawner = new GameObject(); // GameObject will be outside the screen where enemies will Spawn .
	enemySpawner->addComponent<EnemySpawner>().initSpawnerWithDelay(manager, bulletPool, playerObj, true, enemyCount);
	manager->addGameObject(enemySpawner);

	PredefinedSceneHelper::addGameSceneObjects(manager, bulletPool, playerObj, scoreLabel, healthLabel);	// Add Scene GameObjects

}


void GameScene::update(float deltaTime)
{
	if (sceneFinished == true) { return; }
	// If player Health is 0 end game and go to next Scene.
	healthTemp = playerObj->getComponent<Ship>().getHealth();

	if (healthTemp <= 0) {
		sceneFinished = true;
		Game::get().pauseGame();
		SceneManager::get().goToNextScene(2);
		return;
	}

	// if Score Changed then update UI
	if (currentScore != GameScore::get().getGameScore()) {
		currentScore = GameScore::get().getGameScore();
		scoreLabel->getComponent<UILabel>().setText(CommonFunctions::numToString(GameScore::get().getGameScore()));
	}

	// if Health Changed then update UI
	if (currentHealth != healthTemp) {
		currentHealth = healthTemp;
		healthLabel->getComponent<UILabel>().setText(CommonFunctions::numToString(currentHealth) + "%");
	}

}