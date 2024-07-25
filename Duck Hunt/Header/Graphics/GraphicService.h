#pragma once
#include <SFML/Graphics.hpp>


namespace Graphics
{
	class GraphicService
	{
	private:
		const sf::String gameWindowTitle = "Space Invaders";

		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		const sf::Color gameWindowColor = sf::Color::Blue;

		const int frameRate = 60;

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		void SetVideoMode();
		void OnDestroy();

	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* CreateGameWindow();

		void Initialize();
		void Update();
		void Render();

		bool IsGameWindowOpen();

		sf::RenderWindow* GetGameWindow();
		sf::Color GetGameWindowColor();

	};
}
