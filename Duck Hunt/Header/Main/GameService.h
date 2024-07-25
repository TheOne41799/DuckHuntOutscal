#pragma once
#include "../Global/ServiceLocator.h"


namespace Main
{
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};


	class GameService
	{
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		static GameState currentState;

		void Initialize();
		void InitializeVariables();
		void Destroy();

		void ShowMainMenu();

	public:
		GameService();
		~GameService();

		void Ignite();
		void Update();
		void Render();

		bool IsRunning();

		static GameState GetGameState();
		static void SetGameState(GameState state);
	};
}
