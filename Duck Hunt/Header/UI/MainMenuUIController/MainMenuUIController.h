#pragma once
#include <SFML/Graphics.hpp>


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const float buttonWidth = 400;
			const float buttonHeight = 140;

			sf::RenderWindow* gameWindow;

			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;

			void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale);
			void PositionButtons();

			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePos);

		public:
			MainMenuUIController();

			void Initialize();
			void Update();
			void Render();
		};
	}
}

