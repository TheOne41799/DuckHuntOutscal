#include "../../../Header/UI/MainMenuUIController/MainMenuUIController.h"
#include "../../../Header/Main/GameService.h"
#include "../../../Header/Global/Config.h"=


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Event;
		using namespace Sound;


		MainMenuUIController::MainMenuUIController()
		{
			gameWindow = nullptr;
		}

		void MainMenuUIController::Initialize()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			InitializeBackgroundImage();
			InitializeButtons();
		}

		void MainMenuUIController::InitializeBackgroundImage()
		{
			if (backgroundTexture.loadFromFile(Config::duckHuntBackgroundTexturePath))
			{
				backgroundSprite.setTexture(backgroundTexture);
			}

			ScaleBackgroundImage();
		}

		void MainMenuUIController::ScaleBackgroundImage()
		{
			backgroundSprite.setScale(
				static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
				static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
			);
		}

		void MainMenuUIController::InitializeButtons()
		{
			if (LoadButtonTexturesFromFile())
			{
				SetButtonSprites();
				ScaleAllButtons();
				PositionButtons();
			}
		}

		bool MainMenuUIController::LoadButtonTexturesFromFile()
		{
			return
				playButtonTexture.loadFromFile(Config::playButtonTexturePath)
				&& instructionsButtonTexture.loadFromFile(Config::instructionsButtonTexturePath)
				&& quitButtonTexture.loadFromFile(Config::quitButtonTexturePath);
		}

		void MainMenuUIController::SetButtonSprites()
		{
			playButtonSprite.setTexture(playButtonTexture);
			instructionsButtonSprite.setTexture(instructionsButtonTexture);
			quitButtonSprite.setTexture(quitButtonTexture);
		}

		void MainMenuUIController::ScaleAllButtons()
		{
			ScaleButton(&playButtonSprite);
			ScaleButton(&instructionsButtonSprite);
			ScaleButton(&quitButtonSprite);
		}

		void MainMenuUIController::ScaleButton(sf::Sprite* buttonToScale)
		{
			buttonToScale->setScale(
				buttonWidth / buttonToScale->getTexture()->getSize().x,
				buttonHeight / buttonToScale->getTexture()->getSize().y
			);
		}

		void MainMenuUIController::PositionButtons()
		{
			float xPosition = static_cast<float>(gameWindow->getSize().x / 2) - buttonWidth / 2;

			playButtonSprite.setPosition(xPosition, 350.0f);
			instructionsButtonSprite.setPosition(xPosition, 500.0f);
			quitButtonSprite.setPosition(xPosition, 650.0f);
		}

		void MainMenuUIController::Update()
		{
			ProcessButtonInteractions();
		}

		void MainMenuUIController::ProcessButtonInteractions()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

			if (ClickedButton(&playButtonSprite, mousePosition))
			{
				GameService::SetGameState(GameState::GAMEPLAY);
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
				ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
			}

			if (ClickedButton(&instructionsButtonSprite, mousePosition))
			{
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
				printf("Clicked instruction button\n");
			}

			if (ClickedButton(&quitButtonSprite, mousePosition))
			{
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
				gameWindow->close();
			}
		}

		bool MainMenuUIController::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePos)
		{
			EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
			return eventService->PressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(mousePos);
		}

		void MainMenuUIController::Render()
		{
			gameWindow->draw(backgroundSprite);
			gameWindow->draw(playButtonSprite);
			gameWindow->draw(instructionsButtonSprite);
			gameWindow->draw(quitButtonSprite);
		}
	}
}
