#include "MainScene.h"
#include "../Game Engine/GameObject/Components/UILabel.h"
#include "../Scripts/Common/PredefinedSceneHelper.h"
#include "Others/MenuCanvas.h"

void MainScene::init()
{	
	Game::get().unPauseGame(); // Unpausing all the updates as the scene is init and previous memory scene has been cleaned
	PredefinedSceneHelper::addMainSceneAssets(); // Adding Textures and Scounds that are gonna be used in this scene
	GameObject* canvas = new GameObject(); // 
	PredefinedSceneHelper::addMainSceneObjects(manager); // Adding all gameObjects , Mainly buttons for the canvas
	manager->addGameObject(canvas); 
	canvas->addComponent<MenuCanvas>(toggleIndicator); // Canvas Script handeling the Menu UI .
}


