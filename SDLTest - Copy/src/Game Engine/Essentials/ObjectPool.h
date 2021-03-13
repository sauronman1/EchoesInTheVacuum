#pragma once

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

	void releaseObjts() {
		std::list<GameObject*>::iterator i = gameObjects.begin();
		while (i != gameObjects.end())
		{		
				gameObjects.erase(i++);  
		}

		i = activeGameObjects.begin();
		while (i != activeGameObjects.end())
		{
				activeGameObjects.erase(i++);  
		}
	}
	~ObjectPool() {
		releaseObjts();
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
			activeGameObjects.push_front(gameObject);
			gameObjects.pop_front();
			gameObject->SetEnabled(true);
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
		return activeGameObjects;
	}

private:
	int size = 10;
	std::list<GameObject*> gameObjects;
	std::list<GameObject*> activeGameObjects;
};
