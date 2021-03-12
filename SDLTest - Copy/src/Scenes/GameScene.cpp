#include "GameScene.h"
#include "../Game.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"
#include "../Game Engine/GameObject/Components/Projectile.h"
#include "../Game Engine/Essentials/Collision/Collision2D.h"
#include "../Scripts/Common/BackgroundEffect.h"
#include "../Game Engine/GameObject/Components/UILabel.h"
#include "../Scripts/Player/Ship.h"
#include "../Scripts/Common/GameScore.h"


int enemyCount = 14;
int spawnSpeed = 2;


void loadTextures() {
	for (int i = 1;i <= enemyCount;i++) {
		TextureManager::get().loadTexture("enemy" + CommonFunctions::numToString(i), "assets/_Art/Enemies/enemy" + CommonFunctions::numToString(i) + ".png");
	}

	TextureManager::get().loadTexture("player", "assets/Ship.png");
	TextureManager::get().loadTexture("bullet", "assets/bullet_blaster_small_single.png");
	TextureManager::get().loadFont("score", "assets/fonts/neuropol.ttf", 30);

}


void GameScene::update(float deltaTime)
{
	if (playerObj->getComponent<Ship>().getHealth()<=0) {
		Game::get().pauseGame();
		SceneManager::get().goToNextScene(2);
	}

	if (currentScore != GameScore::getGameScore()) {
		currentScore = GameScore::getGameScore();
		scoreLabel->getComponent<UILabel>().setText("score: " + std::to_string(GameScore::getGameScore()));

	}
}

void GameScene::createAllBullets()
{
	for (auto const& gb : bulletPool->returnAllGameObjectList()) {
		gb->getComponent<Transform>().setPosition(Vector2<float>(-5000, -5000));
		gb->addComponent<Projectile>(bulletPool);
		gb->addComponent<Rigibody2D>(0, 6, 0);
		gb->addComponent<BoxCollider2D>(Game::get().getRenderer(), 50, 50, "Bullet");
		gb->addComponent<Sprite>(Game::get().getRenderer(), "bullet");
		gb->getComponent<Transform>().rotation = 90;

		manager->addGameObject(gb);
	}
}

void GameScene::init()
{
	srand(time(NULL));

	Game::get().unPauseGame();

	loadTextures();
	createAllBullets();
	GameScore::initScore();
	playerObj = new GameObject();
	scoreLabel = new GameObject();
	playerObj->addComponent<Ship>(bulletPool);
	scoreLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 440, "score");
	scoreLabel->getComponent<UILabel>().setFontColor({ 0,128,0 });
	scoreLabel->getComponent<UILabel>().setText("score: " + std::to_string(GameScore::getGameScore()));
	GameObject* enemySpawner = new GameObject();
	enemySpawner->addComponent<EnemySpawner>().initSpawnerWithDelay(manager, bulletPool, playerObj, true, enemyCount);
	
	manager->addGameObject(scoreLabel);
	manager->addGameObject(enemySpawner);
	manager->addGameObject(playerObj);


//	Game::get().pauseGame();
//	SceneManager::get().goToNextScene(2);

}
/*
Game::get().unPauseGame();

GameObject* gb = new GameObject();
playerObj = new GameObject();
enemyObj = new GameObject();
scoreLabel = new GameObject();
moveSpeed = 4;

TextureManager::get().loadTexture("nebula", "assets/background_02_static.png");
TextureManager::get().loadTexture("player", "assets/DKO-api-X1.png");
TextureManager::get().loadFont("ScoreLabel", "assets/fonts/neuropol.ttf", 30);
TextureManager::get().loadTexture("nebula", "assets/space.png");

//GameObject* background = new GameObject();
//background->addComponent<Sprite>(Game::get().getRenderer(), "nebula");

gb->addComponent<Sprite>(Game::get().getRenderer(), "nebula");
playerObj->addComponent<Sprite>(Game::get().getRenderer(), "player");
playerObj->getComponent<Transform>().rotation = 90;
playerObj->addComponent<BoxCollider2D>(Game::get().getRenderer(), 180, 180);
enemyObj->addComponent<Sprite>(Game::get().getRenderer(), "player");
enemyObj->getComponent<Transform>().position = Vector2<float>(1700, 500);
enemyObj->addComponent<BoxCollider2D>(Game::get().getRenderer(), 180, 180);
enemyObj->addComponent<BackgroundEffect>(true, true, 20, 4);
scoreLabel->addComponent<UILabel>(Game::get().getRenderer(), "", 880, 60, "ScoreLabel");
scoreLabel->getComponent<UILabel>().setFontColor({ 0,128,0 });
scoreLabel->getComponent<UILabel>().setText("Score: " + std::to_string(score));

//manager->addGameObject(background);
manager->addGameObject(gb);
manager->addGameObject(playerObj);
manager->addGameObject(enemyObj);
manager->addGameObject(scoreLabel);

}




	/*
	Collision2D col;

	timer += deltaTime;

	if (SDLEvent::get().getKeyValue(SDLK_a) == 1 && playerObj->getComponent<Transform>().position.x > 0) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(-moveSpeed * 100, 0) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_d) == 1 && playerObj->getComponent<Transform>().position.x < 1600) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(moveSpeed * 100, 0) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_w) == 1 && playerObj->getComponent<Transform>().position.y > 0) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(0, -moveSpeed * 100) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_s) == 1 && playerObj->getComponent<Transform>().position.y < 850) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(0, moveSpeed * 100) * deltaTime);
	}

	if (col.AABB(playerObj->getComponent<BoxCollider2D>(), enemyObj->getComponent<BoxCollider2D>())) {
		std::cout << "hit" << std::endl;
		score++;
		scoreLabel->getComponent<UILabel>().setText("Score: " + std::to_string(score));

	}

	if (timer > coolDown && (SDLEvent::get().getButtonDown(LEFT) == true || SDLEvent::get().getKeyValue(SDLK_SPACE) == 1) && isClicked == false) {
		isClicked = true;
		std::cout << SDLEvent::get().getMousePos() << std::endl;
		GameObject* shot = new GameObject();
		Vector2<float> playerPos = playerObj->getComponent<Transform>().position;
		shot->getComponent<Transform>().position = Vector2<float>(playerPos.x + 180, playerPos.y +55);
		TextureManager::get().loadTexture("bullet", "assets/bullet_blaster_small_single.png");
		shot->addComponent<Sprite>(Game::get().getRenderer(), "bullet");
		shot->addComponent<Projectile>(shot, 10);
		shot->addComponent<BoxCollider2D>(Game::get().getRenderer(), 50, 50);
		shot->getComponent<Transform>().rotation = 90;

		manager->addGameObject(shot);
		timer = 0;
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}
	*/


