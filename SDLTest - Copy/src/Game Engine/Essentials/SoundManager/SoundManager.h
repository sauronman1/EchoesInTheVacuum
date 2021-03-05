#pragma once
#include <map>
#include <string>
#include <iostream>
#include <SDL_mixer.h>

#define FREQ 44100
#define CHUNK_SIZE 2048

using EffectClips = std::map<std::string, Mix_Chunk*>;
using MusicClips = std::map<std::string, Mix_Music*>;

class SoundManager
{
public:
	inline static SoundManager* Instance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new SoundManager();
	}

	void toggleMusic();
	void loadMusic(std::string id , std::string source);
	void playEffect(std::string id);
	void loadEffect(std::string id, std::string source);
	void cleanSounds();
	void playMusic(std::string id);
	// Volume from 0 to 128 as per documentation 
	void setVolume(int volume);

private:
	SoundManager();
	MusicClips musicClips;
	EffectClips effectClips;
	static SoundManager* s_Instance;
	void printMixError(std::string error);



};

