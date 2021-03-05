#include "GameScene.h"
#include "../Game.h"
#include "../Game Engine/GameObject/GameObject.h"
#include "../Game Engine/Essentials/TextureManager.h"
#include "../Game Engine/GameObject/Components/Sprite.h"
#include "../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../Game Engine/SDL Events/SDLEvent.h"
#include "../Game Engine/GameObject/Components/Projectile.h"

void GameScene::init(GameObjectManager* manager)
{
	GameObject* gb = new GameObject();
	playerObj = new GameObject();
	moveSpeed = 4;

	TextureManager::get().loadTexture("nebula", "assets/background_02_static.png");
	TextureManager::get().loadTexture("player", "assets/DKO-api-X1.png");

	gb->addComponent<Sprite>(Game::get().getRenderer(), "nebula");
	playerObj->addComponent<Sprite>(Game::get().getRenderer(), "player");

	//playerObj->getComponent<Transform>().rotation = 180.0f;

	manager->addGameObject(gb);
	manager->addGameObject(playerObj);
}

void GameScene::sceneClean() {

}

void GameScene::update(float deltaTime)
{

	if (SDLEvent::get().getKeyValue(SDLK_a) == 1 && playerObj->getComponent<Transform>().position.x > 0) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(-moveSpeed, 0));
	}
	if (SDLEvent::get().getKeyValue(SDLK_d) == 1 && playerObj->getComponent<Transform>().position.x < 1600) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(moveSpeed, 0));
	}
	if (SDLEvent::get().getKeyValue(SDLK_w) == 1 && playerObj->getComponent<Transform>().position.y > 0) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(0, -moveSpeed));
	}
	if (SDLEvent::get().getKeyValue(SDLK_s) == 1 && playerObj->getComponent<Transform>().position.y < 850) {
		playerObj->getComponent<Transform>().translate(Vector2<float>(0, moveSpeed));
	}

	if (SDLEvent::get().getButtonDown(LEFT) == true && isClicked == false) {
		std::cout << SDLEvent::get().getMousePos() << std::endl;
		GameObject* shot = new GameObject();
		TextureManager::get().loadTexture("bullet", "assets/game_logo_small.png");
		shot->addComponent<Sprite>(Game::get().getRenderer(), "bullet");
		//shot->addComponent<Projectile>(shot, 1);
		manager->addGameObject(shot);
		isClicked = true;
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}

}
