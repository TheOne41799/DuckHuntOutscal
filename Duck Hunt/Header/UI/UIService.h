#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/UI/MainMenuUI/MainMenuUIController.h"
#include "../../Header/UI/Gameplay/GameplayUIController.h"


namespace UI 
{

	class UIService 
	{
	private:
		SplashScreenUI::SplashScreenUIController* splashScreenUIController;
		MainMenu::MainMenuUIController* mainMenuUIController;
		GameplayUI::GameplayUIController* gameplayUIController;

		void CreateUIControllers();
		void InitializeControllers();
		void Destroy();

		Interface::IUIController* getCurrentUIController();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();

		void ShowUI();
	};
}





