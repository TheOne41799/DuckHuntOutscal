#pragma once
#include<SFML/Audio.hpp>


namespace Sound 
{
	enum class SoundType 
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		RADIUS_BUllET_FIRE,
		DUCK_QUACK,
		DuckDied,
	};


	class SoundService 
	{
	private:
		const int volume = 2;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::Sound duckSoundEffect;
		sf::Sound bulletSoundEffect;

		sf::SoundBuffer bufferButtonClick;

		sf::SoundBuffer bufferBulletFire;
		sf::SoundBuffer bufferRadiusBulletFire;
		sf::SoundBuffer bufferDuckQuackBuffer;
		sf::SoundBuffer bufferDuckDeadBuffer;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void PlaySound(SoundType);
		void PlayBackgroundMusic();

		void Initialize();
	};
}









