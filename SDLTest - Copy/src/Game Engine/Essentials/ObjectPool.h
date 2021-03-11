#include <iostream>
#include <memory>
#include <list>
#include "../GameObject/GameObject.h"
class ObjectPool
{
public:

	ObjectPool() {
		initPool();
	};
	ObjectPool(int poolSize) {
		size = poolSize;
		initPool();
	}
	~ObjectPool() {
		// free memory
		while (activeGameObjects.size())
		{
			gameObjects.push_front(activeGameObjects.front());
			activeGameObjects.pop_front();
		}
		while (gameObjects.size())
		{
			GameObject* obj = gameObjects.front();
			gameObjects.pop_front();
			delete obj;
		}
	}
	GameObject* getGameObject()
	{
		if (gameObjects.empty())
		{
			returnGameObject(activeGameObjects.back());
			activeGameObjects.pop_back();
			return new GameObject;
		}

			GameObject* gameObject = gameObjects.front();
			gameObjects.pop_front();
			gameObject->SetEnabled(true);
			activeGameObjects.push_front(gameObject);
			return gameObject;
		
	}
	


	void  initPool() {
		for (int i = 0;i < size;i++) {
			GameObject *newGameObject = new GameObject();
			newGameObject->SetEnabled(false);
			gameObjects.push_front(newGameObject);
		}

	}

	void returnGameObject(GameObject* gameObject)
	{
		gameObject->SetEnabled(false);
		gameObjects.push_back(gameObject);
	}

	int getAllGameObjectsCount() {
		return gameObjects.size();
	}

	int getActiveGameObjectsCount() {
		return activeGameObjects.size();
	}

	auto  returnAllGameObjectList() {
		return gameObjects;
	}

	auto  returnActiveGameObjectsList() {
		return gameObjects;
	}

private:
	int size = 10;
	std::list<GameObject*> gameObjects;
	std::list<GameObject*> activeGameObjects;
};
