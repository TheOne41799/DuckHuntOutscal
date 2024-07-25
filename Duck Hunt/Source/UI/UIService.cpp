#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/MainMenuUIController/MainMenuUIController.h"


namespace UI
{
	using namespace Main;
	using namespace MainMenu;


	UIService::UIService()
	{
		mainMenuUIController = nullptr;

		CreateUIControllers();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::CreateUIControllers()
	{
		mainMenuUIController = new MainMenuUIController();
	}

	void UIService::Initialize()
	{
		InitializeControllers();
	}

	void UIService::InitializeControllers()
	{
		mainMenuUIController->Initialize();
	}

	void UIService::Update()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			mainMenuUIController->Update();
			break;
		}
	}

	void UIService::Render()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			mainMenuUIController->Render();
			break;
		}
	}

	void UIService::Destroy()
	{
		delete(mainMenuUIController);
	}
}
