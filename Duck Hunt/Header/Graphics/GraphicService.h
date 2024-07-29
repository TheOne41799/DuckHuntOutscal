#pragma once
#include <SFML/Graphics.hpp>


namespace Graphic 
{
	class GraphicService 
	{
	private:
		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		sf::Color windowColor = sf::Color::Black;

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		sf::RenderWindow* CreateGameWindow();
		void SetVideoMode();
		void Destroy();

		const int frameRate = 60;

	public:
		GraphicService();
		~GraphicService();

		void Initialize();
		void Update();
		void Render();

		bool IsGameWindowOpen();

		sf::RenderWindow* GetGameWindow();
		sf::Color GetWindowColor();
	};
}



