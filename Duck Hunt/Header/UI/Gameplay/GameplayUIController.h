#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/TextView.h"
#include "../../Header/Gameplay/GameplayModel.h"
#include "../../Header/Player/PlayerService.h"


namespace UI 
{
	namespace GameplayUI 
	{
		class GameplayUIController : public Interface::IUIController 
		{
		private:
			Player::PlayerService* playerService;
			Gameplay::GameplayModel* gameplayModel;
			UIElement::ImageView* backgroundImage;
			UIElement::TextView* healthTextView;
			UIElement::TextView* waveNoTextView;
			UIElement::TextView* waveTimeTextView;
			UIElement::TextView* waveStartTextView;
			UIElement::TextView* waveStartsInTextView;
			UIElement::TextView* scoreTextView;
			UIElement::ImageView* bulletImage;
			UIElement::ImageView* radiusBulletImage;

			const sf::Color textColor = sf::Color::White;
			const float mainfontSize = 40.f;
			const float smallFontSize = 30.f;

			const float waveStartfontSize = 60.f;
			const float waveStartInFontSize = 50.f;
			const sf::Vector2f healthTextPosition = sf::Vector2f(1750.f, 15.f);
			const sf::Vector2f scoreTextPosition = sf::Vector2f(1750.f, 50.f);

			const sf::Vector2f waveNoTextPosition = sf::Vector2f(900.f, 15.f);
			const sf::Vector2f waveTimeTextPosition = sf::Vector2f(970.f, 60.f);
			const sf::Vector2f waveStartTextPosition = sf::Vector2f(800.f, 400.f);
			const sf::Vector2f waveStartsInTextPosition = sf::Vector2f(950.f, 460.f);

			const sf::Vector2f bulletImagePosition = sf::Vector2f(30.f, 10.f);
			const float bulletSpacing = 20.f;
			const float bulletImageWidth = 20.f;
			const float bulletImageHeight = 30.f;

			const sf::Vector2f radiusBulletImagePosition = sf::Vector2f(30.f, 40.f);

			void CreateUIElements();
			void InitializeImage();
			void InitializeText();
			void Destroy();
			void UpdateHealthText();
			void UpdateScoreText();
			void UpdateWaveNOText();
			void UpdateWaveTimeText();
			void UpdateWaveStartText();
			void DrawBulletCount();
			void DrawRadiusBulletCount();

		public:
			GameplayUIController();
			virtual ~GameplayUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;

			void Show() override;
		};
	}
}