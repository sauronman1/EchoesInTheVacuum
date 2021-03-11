#include "Enemy.h"
#include "../Player/Ship.h"

Enemy::Enemy(ObjectPool* bPool) {
	bulletPool = bPool;
}

void Enemy::onTriggerEnter2D(GameObject* other) {
	if (col.AABB(other->getComponent<BoxCollider2D>(), gameObject->getComponent<BoxCollider2D>()) && other->isActive()) {
		if (other->getComponent<BoxCollider2D>().getColisionTag() == "Bullet") {
			takeDamage(1);
			other->SetEnabled(false);
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
	//gameobject setenabled false
	//enemypool --> returnGameObject(this)
}

void Enemy::update(float deltaTime) {

}
