#include "SoundManager.h"
#include "../../Essentials/CommonFunctions.h"

SoundManager* SoundManager::s_Instance = nullptr;

SoundManager::SoundManager() {

	if (Mix_OpenAudio(FREQ, MIX_DEFAULT_FORMAT, 2, CHUNK_SIZE < 0))
	{
		printMixError(Mix_GetError());
	}
}

void SoundManager::printMixError(std::string error)
{
	CommonFunctions::printErrorMessage(error);
}


	void SoundManager::playMusic(std::string id)
	{
		if(Mix_PlayMusic(musicClips[id], -1) == -1)
			printMixError(Mix_GetError());
	}


	void SoundManager::setVolume(int volume)
	{
		Mix_VolumeMusic(volume);
	}


	void SoundManager::toggleMusic()
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}

	void SoundManager::loadMusic(std::string id, std::string source)
	{
		Mix_Music* music = Mix_LoadMUS(source.c_str());
		if (music != nullptr) {
			musicClips[id] = music;
		}
		else {
			printMixError(Mix_GetError());

		}
	}
	void SoundManager::playEffect(std::string id)
	{
		if(Mix_PlayChannel(-1,effectClips[id], 0) == -1)
			printMixError(Mix_GetError());
	}
	void SoundManager::loadEffect(std::string id, std::string source)
	{
		Mix_Chunk* effect = Mix_LoadWAV(source.c_str());
		if (effect != nullptr)
			effectClips[id] = effect;
		else
			printMixError(Mix_GetError());
	}

	void SoundManager::cleanSounds()
	{
		for (MusicClips::iterator it = musicClips.begin();it != musicClips.end();it++) {
			Mix_FreeMusic(it->second);
		}

		for (EffectClips::iterator it = effectClips.begin();it != effectClips.end();it++) {
			Mix_FreeChunk(it->second);
		}
		musicClips.clear();
		effectClips.clear();
		CommonFunctions::printConsoleMessage("Sound System is Cleaned");

	}


