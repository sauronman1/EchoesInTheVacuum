#include "Ship.h"
#include "../../Game Engine/Essentials/TextureManager.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Game Engine/GameObject/Components/BoxCollider2D.h"
#include "../../Game Engine/SDL Events/SDLEvent.h"
#include "../../Game Engine/Essentials/SceneManagement/SceneManager.h"

Ship::Ship(ObjectPool* bPool) {
	bulletPool = bPool;
}

bool Ship::init(){
	TextureManager::get().loadTexture("player", "assets/DKO-api-X1.png");
	gameObject->addComponent<Sprite>(Game::get().getRenderer(), "player");
	gameObject->getComponent<Transform>().rotation = 90;
	gameObject->addComponent<BoxCollider2D>(Game::get().getRenderer(), 180, 180, "Player");
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
		isClicked = true;
		std::cout << SDLEvent::get().getMousePos() << std::endl;
		Vector2<float> playerPos = gameObject->getComponent<Transform>().position;
		bulletPool->getGameObject()->getComponent<Transform>().position = Vector2<float>(playerPos.x + 180, playerPos.y + 55);
		timer = 0;
	}
	else if (SDLEvent::get().getButtonDown(LEFT) == false && isClicked == true) {
		isClicked = false;
	}
}