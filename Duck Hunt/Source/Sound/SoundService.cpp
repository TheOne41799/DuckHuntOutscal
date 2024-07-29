#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"


namespace Sound 
{
	using namespace Global;


	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath)) {
			printf("Error loading background music file");
		}
	}

	void SoundService::LoadSoundFromFile()
	{
		if (!bufferButtonClick.loadFromFile(Config::buttonClickSoundPath)) {
			printf("Error loading button click file");
		}
		if (!bufferBulletFire.loadFromFile(Config::bulletSoundPath)) {
			printf("Error loading bullet fire file");
		}
		if (!bufferRadiusBulletFire.loadFromFile(Config::radiusBulletSoundPath)) {
			printf("Error loading radius bullet fire file");
		}
		if (!bufferDuckQuackBuffer.loadFromFile(Config::duckQuackSoundPath)) {
			printf("Error loading duck quck file");
		}
		if (!bufferDuckDeadBuffer.loadFromFile(Config::deadDuckSoundPath)) {
			printf("Error loading dead duck file");
		}
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		soundEffect.setVolume(15);
		duckSoundEffect.setVolume(15);
		bulletSoundEffect.setVolume(15);

		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			soundEffect.play();
			break;
		case SoundType::BULLET_FIRE:
			bulletSoundEffect.setBuffer(bufferBulletFire);
			bulletSoundEffect.play();
			break;
		case SoundType::RADIUS_BUllET_FIRE:
			bulletSoundEffect.setBuffer(bufferRadiusBulletFire);
			bulletSoundEffect.play();
			break;
		case SoundType::DUCK_QUACK:
			duckSoundEffect.setBuffer(bufferDuckQuackBuffer);
			duckSoundEffect.play();
			break;
		case SoundType::DuckDied:
			duckSoundEffect.setBuffer(bufferDuckDeadBuffer);
			duckSoundEffect.play();
			break;
		default:
			printf("Invalid Source Type");
			break;
		}
	}

	void SoundService::PlayBackgroundMusic()
	{
		backgroundMusic.setVolume(volume);
		backgroundMusic.setLoop(true);
		backgroundMusic.play();
	}

	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}
}







