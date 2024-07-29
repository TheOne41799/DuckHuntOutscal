#include "../../Header/Main/GameService.h"


namespace Main 
{
	using namespace Global;
	GameState GameService::currentState = GameState::BOOT;


	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
		ShowSplashScreen();
	}

	void GameService::ShowSplashScreen()
	{
		SetGameState(GameState::SPLASH_SCREEN);
		Global::ServiceLocator::GetInstance()->GetUIService()->ShowUI();
	}

	void GameService::Destroy()
	{

	}

	GameService::GameService()
	{
		serviceLocator = nullptr;
		gameWindow = nullptr;
	}

	GameService::~GameService()
	{

	}

	void GameService::Ignite()
	{
		serviceLocator = ServiceLocator::GetInstance();
		Initialize();
	}

	void GameService::Update()
	{
		serviceLocator->Update();
	}

	void GameService::Render()
	{
		gameWindow->clear(serviceLocator->GetGraphicService()->GetWindowColor());
		serviceLocator->Render();
		gameWindow->display();
	}

	bool GameService::IsRunning()
	{
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	}

	void GameService::SetGameState(GameState newState)
	{
		currentState = newState;
	}

	GameState GameService::GetGameState()
	{
		return currentState;
	}
}






