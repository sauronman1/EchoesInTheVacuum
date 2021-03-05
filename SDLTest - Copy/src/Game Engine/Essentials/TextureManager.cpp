#include "TextureManager.h"
#include <iostream>
#include "CommonFunctions.h"
#include "../../Game.h"

TextureManager* TextureManager::s_instance = nullptr;

void TextureManager::loadFont(std::string id, std::string path, int fontSize) {
	TTF_Font* newfont = TTF_OpenFont(path.c_str(), fontSize);
	if (newfont != nullptr) {
		fonts.emplace(id, newfont);
		CommonFunctions::printConsoleMessage(path + " ,Font is Available And Working");
	}
	else {
		CommonFunctions::printErrorMessage(TTF_GetError());
	}
}


TTF_Font* TextureManager::getFont(std::string id) {
	if (fonts.count(id) > 0) return fonts[id];
	return nullptr;
}


void TextureManager::loadTexture(std::string id, std::string path) {
	if (textures.count(id) <= 0) {
		SDL_Texture* texture = IMG_LoadTexture(Game::get().getRenderer(), path.c_str());
		if (texture) {
			textures[id] = texture;
			CommonFunctions::printConsoleMessage(path + " ,Texture is Available And Working");
		}
		else {
			CommonFunctions::printErrorMessage(TTF_GetError());
		}
	}
}


TextureManager::TextureManager() {
	if ((TTF_Init() != 0) || (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0))
		CommonFunctions::printErrorMessage(TTF_GetError());
}

SDL_Texture* TextureManager::getTexture(std::string id) {
	if (textures.count(id) > 0) return textures[id];
	return nullptr;
}
     
void TextureManager::clean() {

	for (auto it = textures.begin(); it != textures.end(); it++) {
		SDL_DestroyTexture(it->second);
	}

	textures.clear();

	for (auto it = fonts.begin(); it != fonts.end(); it++) {
		TTF_CloseFont(it->second);
	}

	fonts.clear();
	CommonFunctions::printConsoleMessage("Texture And Fonts Cleared");
}

