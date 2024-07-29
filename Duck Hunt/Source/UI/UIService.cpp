#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"


namespace UI 
{
	using namespace Main;
	using namespace Interface;


	void UIService::CreateUIControllers()
	{
		splashScreenUIController = new SplashScreenUI::SplashScreenUIController();
		mainMenuUIController = new MainMenu::MainMenuUIController();
		gameplayUIController = new GameplayUI::GameplayUIController();
	}

	void UIService::InitializeControllers()
	{
		splashScreenUIController->Initialize();
		mainMenuUIController->Initialize();
		gameplayUIController->Initialize();
	}

	void UIService::Destroy()
	{
		delete(splashScreenUIController);
		delete(mainMenuUIController);
		delete(gameplayUIController);
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::GetGameState()) 
		{
		case GameState::SPLASH_SCREEN:
			return splashScreenUIController;
		case GameState::MAIN_MENU:
			return mainMenuUIController;
		case GameState::GAMEPLAY:
			return gameplayUIController;
		}
	}

	UIService::UIService()
	{
		CreateUIControllers();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::Initialize()
	{
		UIElement::TextView::InitializeTextView();
		InitializeControllers();
	}

	void UIService::Update()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->Update();
	}

	void UIService::Render()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->Render();
	}

	void UIService::ShowUI()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->Show();
	}
}







