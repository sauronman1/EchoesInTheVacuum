#include "Enemy.h"
#include "../Player/Ship.h"
#include "../../Game Engine/Essentials/CommonFunctions.h"
Enemy::Enemy(ObjectPool* bPool, ObjectPool* ePool) {
	bulletPool = bPool;
	enemyPool = ePool;
}

void Enemy::onTriggerEnter2D(GameObject* other) {

	if (col.AABB(other->getComponent<BoxCollider2D>().getRect(), gameObject->getComponent<BoxCollider2D>().getRect()) && other->isActive()) {
		if (other->getComponent<BoxCollider2D>().getColisionTag() == "Bullet") {
			takeDamage(1);
			std::cout << "eyyy" << std::endl;
			bulletPool->returnGameObject(other);
		}
		if (other->getComponent<BoxCollider2D>().getColisionTag() == "Player" && !collided) {
			other->getComponent<Ship>().takeDamage(1);
			collided = true;
		}
	}
}

bool Enemy::init() {
	setHealth(2);
	return true;
	//stop enemy
	//enemypool --> returnGameObject(this)
}

void Enemy::update(float deltaTime) {
	if (gameObject->getComponent<Transform>().position.x < -250)
		enemyPool->returnGameObject(gameObject);

	for (auto& const bullet : bulletPool->returnActiveGameObjectsList()) {
		onTriggerEnter2D(bullet);
	}
}
