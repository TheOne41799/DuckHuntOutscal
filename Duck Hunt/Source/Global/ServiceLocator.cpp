#include "../../Header/Main/GameService.h"


namespace Global
{
	using namespace Graphics;
	using namespace Time;
	using namespace Event;
	using namespace UI;
	using namespace Gameplay;
	using namespace Sound;
	using namespace Main;


	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		timeService = nullptr;
		eventService = nullptr;
		gameplayService = nullptr;
		uiService = nullptr;
		soundService = nullptr;

		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}

	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
		timeService = new TimeService();
		eventService = new EventService();
		gameplayService = new GameplayService();
		uiService = new UIService();
		soundService = new SoundService();
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
		timeService->Initialize();
		eventService->Initialize();
		gameplayService->Initialize();
		uiService->Initialize();
		soundService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicService->Update();
		timeService->Update();
		eventService->Update();

		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Update();
		}

		uiService->Update();
	}

	void ServiceLocator::Render()
	{
		graphicService->Render();

		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Render();
		}

		uiService->Render();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(timeService);
		delete(eventService);
		delete(uiService);
		delete(gameplayService);
		delete(soundService);
	}

	EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}

	GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}

	TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}

	UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}

	GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}

	SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}
}
