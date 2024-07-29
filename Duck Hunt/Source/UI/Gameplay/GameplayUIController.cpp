#include "../../Header/UI/Gameplay/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Gameplay/GameplayModel.h"
#include <string> 


namespace UI 
{
	namespace GameplayUI 
	{
		using namespace Global;


		void GameplayUIController::CreateUIElements()
		{
			backgroundImage = new UIElement::ImageView();
			bulletImage = new UIElement::ImageView();
			radiusBulletImage = new UIElement::ImageView();
			healthTextView = new UIElement::TextView();
			scoreTextView = new UIElement::TextView();
			waveNoTextView = new UIElement::TextView();
			waveTimeTextView = new UIElement::TextView();
			waveStartTextView = new UIElement::TextView();
			waveStartsInTextView = new UIElement::TextView();
		}

		void GameplayUIController::InitializeImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			backgroundImage->Initialize(Config::backgroundTexturePath, 
										gameWindow->getSize().x, gameWindow->getSize().y, 
										sf::Vector2f(0.f, 860.f));
			backgroundImage->SetTextureRect(sf::IntRect(0, 158, 393, 42));
			
			bulletImage->Initialize(Config::bulletTexturePath, 
									bulletImageWidth, bulletImageHeight, 
									bulletImagePosition);
			radiusBulletImage->Initialize(Config::bulletTexturePath, 
										  bulletImageWidth, bulletImageHeight, 
										  radiusBulletImagePosition);
			radiusBulletImage->SetColor(sf::Color::Red);
		}

		void GameplayUIController::InitializeText()
		{
			playerService = ServiceLocator::GetInstance()->GetPlayerService();
			sf::String healthString = "Health: " + std::to_string(playerService->GetHealth());
			healthTextView->Initialize(healthString, healthTextPosition,
				UIElement::FontType::MILKY_VANTAGE, mainfontSize, textColor);

			sf::String scoreString = "Score: " + std::to_string(playerService->GetScore());
			scoreTextView->Initialize(scoreString, scoreTextPosition,
				UIElement::FontType::MILKY_VANTAGE, mainfontSize, textColor);

			gameplayModel = ServiceLocator::GetInstance()->GetGameplayService()->GetGameplayModel();

			sf::String waveNoString = "Wave NO: " + std::to_string(gameplayModel->GetWaveNO());
			waveNoTextView->Initialize(waveNoString, waveNoTextPosition,
				UIElement::FontType::MILKY_VANTAGE, mainfontSize, textColor);

			sf::String waveTimeString = std::to_string(gameplayModel->GetWaveTime());
			waveTimeTextView->Initialize(waveTimeString, waveTimeTextPosition,
				UIElement::FontType::MILKY_VANTAGE, smallFontSize, textColor);

			waveStartTextView->Initialize("Wave Starts In", waveStartTextPosition,
				UIElement::FontType::MILKY_VANTAGE, waveStartfontSize, textColor);

			sf::String waveStartTimeString = std::to_string(gameplayModel->GetWaveStartTime());
			waveStartsInTextView->Initialize(waveStartTimeString, waveStartsInTextPosition,
				UIElement::FontType::MILKY_VANTAGE, waveStartInFontSize, textColor);
		}

		void GameplayUIController::Destroy()
		{
			delete backgroundImage;
			delete bulletImage;
			delete radiusBulletImage;
			delete healthTextView;
			delete scoreTextView;
			delete waveNoTextView;
			delete waveTimeTextView;
		}

		void GameplayUIController::UpdateHealthText()
		{
			sf::String healthString = "Health: " + std::to_string(playerService->GetHealth());
			healthTextView->SetText(healthString);
		}

		void GameplayUIController::UpdateScoreText()
		{
			sf::String scoreString = "Score: " + std::to_string(playerService->GetScore());
			scoreTextView->SetText(scoreString);
		}

		void GameplayUIController::UpdateWaveNOText()
		{
			sf::String waveNoString = "Wave NO: " + std::to_string(gameplayModel->GetWaveNO());
			waveNoTextView->SetText(waveNoString);
		}

		void GameplayUIController::UpdateWaveTimeText()
		{
			sf::String waveTimeString = std::to_string(gameplayModel->GetWaveTime());
			waveTimeTextView->SetText(waveTimeString);
		}

		void GameplayUIController::UpdateWaveStartText()
		{
			sf::String waveStartTimeString = std::to_string(gameplayModel->GetWaveStartTime());
			waveStartTextView->SetText("Wave Starts In");
			waveStartsInTextView->SetText(waveStartTimeString);
		}

		void GameplayUIController::DrawBulletCount()
		{
			for (int i = 0; i < playerService->GetAmmoPerRound(); i++)
			{
				bulletImage->SetPosition(sf::Vector2f(bulletImagePosition.x + (i * bulletSpacing), 
													  bulletImagePosition.y));
				bulletImage->Render();
			}
		}

		void GameplayUIController::DrawRadiusBulletCount()
		{
			for (int i = 0; i < playerService->GetRadiusAmmoPerRound(); i++)
			{
				radiusBulletImage->SetPosition(sf::Vector2f(radiusBulletImagePosition.x + (i * bulletSpacing), 
															radiusBulletImagePosition.y));
				radiusBulletImage->Render();
			}
		}

		GameplayUIController::GameplayUIController()
		{
			CreateUIElements();
		}

		GameplayUIController::~GameplayUIController()
		{
			Destroy();
		}

		void GameplayUIController::Initialize()
		{
			InitializeImage();
			InitializeText();
		}

		void GameplayUIController::Update()
		{
			switch (gameplayModel->GetGameplayState())
			{
			case GameplayState::WAVE_STARTING:
				UpdateWaveStartText();
				break;
			case GameplayState::WAVE_STARTED:
				UpdateHealthText();
				UpdateScoreText();
				UpdateWaveNOText();
				UpdateWaveTimeText();
				break;
			default:
				break;
			}
		}

		void GameplayUIController::Render()
		{
			backgroundImage->Render();
			healthTextView->Render();
			scoreTextView->Render();
			waveNoTextView->Render();
			waveTimeTextView->Render();

			if (gameplayModel->GetGameplayState() == GameplayState::WAVE_STARTING) {
				waveStartTextView->Render();
				waveStartsInTextView->Render();
			}

			DrawBulletCount();
			DrawRadiusBulletCount();
		}

		void GameplayUIController::Show()
		{
			backgroundImage->Show();
			healthTextView->Show();
			scoreTextView->Show();
			bulletImage->Show();
			waveStartTextView->Show();
			waveStartsInTextView->Show();
			radiusBulletImage->Show();
		}
	}
}