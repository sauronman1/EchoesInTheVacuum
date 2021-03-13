#include "MainScene.h"
#include "../Scripts/Common/PredefinedSceneHelper.h"
#include "Others/MenuCanvas.h"

void MainScene::init()
{
	Game::get().unPauseGame(); // Unpausing all the updates as the scene is init and previous memory scene has been cleaned
	PredefinedSceneHelper::addMainSceneAssets(); // Adding Textures and Scounds that are gonna be used in this scene
	GameObject* canvas = new GameObject(); // 
	PredefinedSceneHelper::addMainSceneObjects(manager); // Adding all gameObjects , Mainly buttons for the canvas
	manager->addGameObject(canvas);
	
	canvas->addComponent<MenuCanvas>(); // Canvas Script handeling the Menu UI .
}

// No need for an update Function for this Scene . 
/* In SceneManager we will
	1- pause all game update functions
	2- delete all the GameObjects via the GameObject Manager that has all the unique ptrs for all objects
	3-delete all the Textures created
	4-Clean the scene and call the destructor
	*Note : When deleting the gameObjects from the manager smart pointers for all added components will be deleted too.
*/
