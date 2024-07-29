#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


namespace Global 
{
	using namespace Main;
	using namespace Event;
	using namespace Graphic;


	ServiceLocator::ServiceLocator()
	{
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearServices();
	}

	void ServiceLocator::CreateServices()
	{
		graphicServie = new GraphicService();
		eventService = new EventService();
		duckService = new DuckService();
		gameplayService = new GameplayService();
		playerService = new PlayerService();
		timeService = new TimeService();
		soundService = new SoundService();
		uiService = new UIService();
	}

	void ServiceLocator::ClearServices()
	{
		delete graphicServie;
		delete eventService;
		delete gameplayService;
		delete duckService;
		delete playerService;
		delete timeService;
		delete soundService;
		delete uiService;
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator serviceLocator;
		return &serviceLocator;
	}

	void ServiceLocator::Initialize()
	{
		graphicServie->Initialize();
		eventService->Initialize();
		duckService->Initialize();
		gameplayService->Initialize();
		playerService->Initialize();
		timeService->Initialize();
		soundService->Initialize();
		uiService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicServie->Update();
		eventService->Update();

		switch (GameService::GetGameState())
		{
		case GameState::GAMEPLAY:
			gameplayService->Update();
			duckService->Update();
			playerService->Update();
		default:
			break;
		}

		timeService->Update();
		uiService->Update();
	}

	void ServiceLocator::Render()
	{
		graphicServie->Render();

		switch (GameService::GetGameState())
		{
		//case GameState::SPLASH_SCREEN:
		//	break;
		//case GameState::MAIN_MENU:

		case GameState::GAMEPLAY:
			gameplayService->Render();
			duckService->Render();
		default:
			break;
		}
		uiService->Render();
	}

	void ServiceLocator::Reset()
	{
		duckService->Reset();
		playerService->Reset();
		gameplayService->Reset();
	}

	GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicServie;
	}

	EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}
	GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}
	DuckService* ServiceLocator::GetDuckService()
	{
		return duckService;
	}
	PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}
	TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}
	SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}
	UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}
}

