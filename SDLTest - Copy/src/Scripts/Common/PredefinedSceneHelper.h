#pragma once
#include "../../Game.h"
#include "../../Game Engine/GameObject/GameObject.h"
#include "../../Game Engine/Essentials/TextureManager.h"
#include "../../Game Engine/GameObject/Components/Sprite.h"
#include "../../Game Engine/Essentials/SceneManagement/SceneManager.h"
#include "../../Game Engine/SDL Events/SDLEvent.h"
#include "../../Game Engine/Essentials/SoundManager/SoundManager.h"
#include "../../Game Engine/GameObject/Components/UILabel.h"
#include "../../Game Engine/GameObject/Components/Projectile.h"
#include "../../Game Engine/GameObject/Components/BoxCollider2D.h"
#include "../../Scripts/Player/Ship.h"
#include "../../Scripts/Common/GameScore.h"




class PredefinedSceneHelper {
	// Would have split the helper into 3 , each for every scene but this game is very small no need for that . 

public:

	// Menu Scene
	static void addMainSceneAssets();
	static void addMainSceneObjects(GameObjectManager* manager);
	// Game Scene
	static void addGameSceneAssets(int enemyCount);
	static void addGameSceneObjects(GameObjectManager* manager, ObjectPool* bulletPool, GameObject* playerObj, GameObject* scoreLabel);
	// Credit Scene
	static void addCreditSceneAssets();
	static void addCreditSceneObjects(GameObjectManager* manager);
};
