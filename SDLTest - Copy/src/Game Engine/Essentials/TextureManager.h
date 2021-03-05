#pragma once

#include <map>
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>

class TextureManager {

public:

	TextureManager();
	~TextureManager() = default;

	inline static TextureManager& get() {
		if (s_instance == nullptr) {
			s_instance = new TextureManager();
		}
		return *s_instance;
	}

	void loadTexture(std::string id, std::string path);
	SDL_Texture* getTexture(std::string id);

	TTF_Font* getFont(std::string id);
	void loadFont(std::string id, std::string path, int fontSize);

	void clean();


private:
	static TextureManager* s_instance;
	std::map<std::string, TTF_Font*> fonts;
	std::map<std::string, SDL_Texture*> textures;
};
