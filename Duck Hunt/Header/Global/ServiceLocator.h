#pragma once
#include "../../Header/Event/EventService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Gameplay/GameplayService.h"	
#include "../../Header/Time/TimeService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Duck/DuckService.h"


namespace Global 
{
	using namespace Graphic;
	using namespace Event;
	using namespace Player;
	using namespace Gameplay;
	using namespace Duck;
	using namespace Time;
	using namespace Sound;
	using namespace UI;


	class ServiceLocator 
	{
	private:
		GraphicService* graphicServie;
		EventService* eventService;
		GameplayService* gameplayService;
		DuckService* duckService;
		PlayerService* playerService;
		TimeService* timeService;
		SoundService* soundService;
		UIService* uiService;

		ServiceLocator();
		~ServiceLocator();

		void CreateServices();
		void ClearServices();

	public:
		static ServiceLocator* GetInstance();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		GraphicService* GetGraphicService();
		EventService* GetEventService();
		GameplayService* GetGameplayService();
		DuckService* GetDuckService();
		PlayerService* GetPlayerService();
		TimeService* GetTimeService();
		SoundService* GetSoundService();
		UIService* GetUIService();
	};
}







