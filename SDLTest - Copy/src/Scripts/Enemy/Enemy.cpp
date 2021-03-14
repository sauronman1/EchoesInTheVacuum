#include "Enemy.h"
#include "../Player/Ship.h"
#include "../../Game Engine/Essentials/CommonFunctions.h"
#include "../../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../../Game Engine/GameObject/Components/UILabel.h"
#include "../../Scripts/Common/GameScore.h"
#include"../../Game Engine/GameObject/Components/Rigibody2D.h"

Enemy::Enemy(ObjectPool* bPool, ObjectPool* ePool, GameObject* player) {
	bulletPool = bPool;
	enemyPool = ePool;
	playerTarget = player;
}

void Enemy::onTriggerEnter2D(GameObject* other) {

	if (col.AABB(other->getComponent<BoxCollider2D>().getRect(), gameObject->getComponent<BoxCollider2D>().getRect()) && other->isActive()) {
		GameScore::get().incrementGameScore(23);
		enemyPool->returnGameObject(gameObject);

		if (other->getComponent<BoxCollider2D>().getColisionTag() == "Bullet") {
			bulletPool->returnGameObject(other);

		}
		if (other->getComponent<BoxCollider2D>().getColisionTag() == "Player" && !collided) {
			other->getComponent<Ship>().takeDamage(25);
			collided = true;
		}
	}
}

bool Enemy::init() {
	setHealth(2);
	return true;

}

void Enemy::update(float deltaTime) {
	if (gameObject->getComponent<Transform>().position.x < -250)
		enemyPool->returnGameObject(gameObject);

	for (auto& const bullet : bulletPool->returnActiveGameObjectsList()) {
		onTriggerEnter2D(bullet);
	}
	onTriggerEnter2D(playerTarget);


	gameObject->getComponent<Rigibody2D>().addFoceXBy(GameScore::get().getWaveNumber());
	
}
