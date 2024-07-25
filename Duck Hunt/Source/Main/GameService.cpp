#include "../../Header/Main/GameService.h"


namespace Main
{
	using namespace Global;

	GameState GameService::currentState = GameState::BOOT;


	GameService::GameService()
	{
		serviceLocator = nullptr;
		gameWindow = nullptr;
	}

	GameService::~GameService()
	{
		Destroy();
	}

	void GameService::Ignite()
	{
		serviceLocator = ServiceLocator::GetInstance();
		Initialize();
	}

	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		InitializeVariables();
		ShowMainMenu();
	}

	void GameService::InitializeVariables()
	{
		gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
	}

	void GameService::Update()
	{
		//serviceLocator->GetEventService()->ProcessEvents();
		serviceLocator->Update();
	}

	void GameService::Render()
	{
		gameWindow->clear(serviceLocator->GetGraphicService()->GetGameWindowColor());
		serviceLocator->Render();
		gameWindow->display();
	}

	bool GameService::IsRunning()
	{
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	}

	void GameService::Destroy()
	{
	}

	GameState GameService::GetGameState()
	{
		return currentState;
	}

	void GameService::SetGameState(GameState state)
	{
		currentState = state;
	}

	void GameService::ShowMainMenu()
	{
		SetGameState(GameState::MAIN_MENU);
	}
}
