#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/IUIController.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/ImageView.h"
#include "../UIElement/TextView.h"


namespace UI 
{
	namespace MainMenu 
	{
		class MainMenuUIController : public Interface::IUIController 
		{
		private:
			const float buttonWidth = 400;
			const float buttonHeight = 150;

			const float playButtonYPosition = 500.f;
			const float quitButtonYPosition = 700.f;
			const float backgroundAlpha = 1.f;

			const float fontSize = 200.f;
			const sf::Vector2f duckHuntTextPosition = sf::Vector2f(580.f, 200.f);

			UIElement::ImageView* backgroundImage;
			UIElement::ButtonView* playButton;
			UIElement::ButtonView* quitButton;
			UIElement::TextView* duckHuntTextView;

			void CreateImage();
			void CreateButton();
			void CreateText();
			void InitializeBackgroundImage();

			void InitializeButtons();
			void InitializeText();
			void RegisterButtonCallback();

			void PlayButtonCallback();
			void QuitButtonCallback();

			void Destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}



