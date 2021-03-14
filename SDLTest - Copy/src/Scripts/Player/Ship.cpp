#include "Ship.h"
#include "../../Game Engine/Essentials/TextureManager.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Game Engine/GameObject/Components/BoxCollider2D.h"
#include "../../Game Engine/GameObject/Components/Rigibody2D.h"

#include "../../Game Engine/SDL Events/SDLEvent.h"
#include "../../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../../Game Engine/Essentials/SoundManager/SoundManager.h"
#include "../Common/GameScore.h"

Ship::Ship(ObjectPool* bPool) {
	bulletPool = bPool;
	health = 100;
}

bool Ship::init(){
	timer = 0;
	coolDown = 0.3;
	moveSpeed = 5;
	isClicked = false;

	TextureManager::get().loadTexture("player", "assets/DKO-api-X1.png");
	gameObject->addComponent<Sprite>(Game::get().getRenderer(), "player");
	gameObject->getComponent<Transform>().rotation = 90;
	gameObject->addComponent<BoxCollider2D>(Game::get().getRenderer(), 120, 150, "Player");
	return true;
}

void Ship::update(float deltaTime) {
	timer += deltaTime;

	if (SDLEvent::get().getKeyValue(SDLK_a) == 1 && gameObject->getComponent<Transform>().position.x > 0) {
		gameObject->getComponent<Transform>().translate(Vector2<float>(-moveSpeed * 100, 0) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_d) == 1 && gameObject->getComponent<Transform>().position.x < 1600) {
		gameObject->getComponent<Transform>().translate(Vector2<float>(moveSpeed * 100, 0) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_w) == 1 && gameObject->getComponent<Transform>().position.y > 0) {
		gameObject->getComponent<Transform>().translate(Vector2<float>(0, -moveSpeed * 100) * deltaTime);
	}
	if (SDLEvent::get().getKeyValue(SDLK_s) == 1 && gameObject->getComponent<Transform>().position.y < 850) {
		gameObject->getComponent<Transform>().translate(Vector2<float>(0, moveSpeed * 100) * deltaTime);
	}



	if (timer > coolDown && (SDLEvent::get().getButtonDown(LEFT) == true || SDLEvent::get().getKeyValue(SDLK_SPACE) == 1) && isClicked == false) {
		SoundManager::Instance()->playEffect("shootSound");
		isClicked = true;
		std::cout << SDLEvent::get().getMousePos() << std::endl;
		Vector2<float> playerPos = gameObject->getComponent<Transform>().position;
		GameObject* gb = bulletPool->getGameObject();
		gb->getComponent<Transform>().position = Vector2<float>(playerPos.x + 160, playerPos.y + 55);
		if(GameScore::get().getWaveNumber() >1)
		gb->getComponent<Rigibody2D>().addFoceXBy(2);
		timer = 0;
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}


}