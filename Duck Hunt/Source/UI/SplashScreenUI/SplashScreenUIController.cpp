#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


namespace UI 
{
	namespace SplashScreenUI 
	{
		void SplashScreenUIController::InitializeBackgroundImage()
		{
			sf::RenderWindow* gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		}

		void SplashScreenUIController::InitializeOutscalLogo()
		{
			outscaleLogoView->Initialize(Global::Config::duckHuntLogoTexturePath, 
										 logoWidth, logoHeight, GetLogoPosition());
		}

		void SplashScreenUIController::FadeInAnimationCallback()
		{
			outscaleLogoView->PlayAnimation(UI::UIElement::AnimationType::FADE_OUT, 
											logoAnimationDuration, 
											std::bind(&SplashScreenUIController::FadeOutAnimationCallback, this));
		}

		void SplashScreenUIController::FadeOutAnimationCallback()
		{
			Global::ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
			Main::GameService::SetGameState(Main::GameState::MAIN_MENU);
		}

		sf::Vector2f SplashScreenUIController::GetLogoPosition()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			float xPosition = (game_window->getSize().x - logoWidth) / 2.0f;
			float yPosition = (game_window->getSize().y - logoHeight) / 2.0f;

			return sf::Vector2f(xPosition, yPosition);
		}

		SplashScreenUIController::SplashScreenUIController()
		{
			outscaleLogoView = new UIElement::AnimatedImageView();
		}

		SplashScreenUIController::~SplashScreenUIController()
		{
			delete(outscaleLogoView);
		}

		void SplashScreenUIController::Initialize()
		{
			InitializeBackgroundImage();
			InitializeOutscalLogo();
		}

		void SplashScreenUIController::Update()
		{
			outscaleLogoView->Update();
		}

		void SplashScreenUIController::Render()
		{
			outscaleLogoView->Render();
		}

		void SplashScreenUIController::Show()
		{
			outscaleLogoView->PlayAnimation(UI::UIElement::AnimationType::FADE_IN, 
											logoAnimationDuration, 
											std::bind(&SplashScreenUIController::FadeInAnimationCallback, this));
		}
	}
}












