#pragma once
#include "SFML/Graphics.hpp"
#include "../Global/ServiceLocator.h"


namespace Main 
{
	enum class GameState 
	{
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		GAMEPLAY
	};


	class GameService 
	{
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		void Initialize();
		void ShowSplashScreen();
		void Destroy();

		static GameState currentState;

	public:
		GameService();
		~GameService();

		void Ignite();
		void Update();
		void Render();
		bool IsRunning();

		static void SetGameState(GameState newState);

		static GameState GetGameState();
	};
}









