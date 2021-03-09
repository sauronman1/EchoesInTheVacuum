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

void GameScene::init()
{
	this->manager->cleanGameObject();
	GameObject* gb = new GameObject();
	playerObj = new GameObject();
	enemyObj = new GameObject();
	moveSpeed = 4;

	TextureManager::get().loadTexture("nebula", "assets/background_02_static.png");
	TextureManager::get().loadTexture("player", "assets/DKO-api-X1.png");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "nebula");
	playerObj->addComponent<Sprite>(Game::get().getRenderer(), "player");
	enemyObj->addComponent<Sprite>(Game::get().getRenderer(), "player");
	playerObj->getComponent<Transform>().rotation = 90;

	this->manager = manager;
	manager->addGameObject(gb);
	manager->addGameObject(playerObj);
	manager->addGameObject(enemyObj);
	playerObj->addComponent<BoxCollider2D>(Game::get().getRenderer(), 200, 200);
	enemyObj->getComponent<Transform>().position = Vector2<float>(1700, 500) ;
	enemyObj->addComponent<BoxCollider2D>(Game::get().getRenderer(), 200, 200);

}


void GameScene::update(float deltaTime)
{
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

}
