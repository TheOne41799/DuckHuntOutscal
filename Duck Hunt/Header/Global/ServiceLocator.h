#pragma once
#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../UI/UIService.h"
#include "../Time/TimeService.h"
#include "../Gameplay/GameplayService.h"
#include "../Sound/SoundService.h"


namespace Global
{
	class ServiceLocator
	{
	private:

		Event::EventService* eventService;
		Graphics::GraphicService* graphicService;
		UI::UIService* uiService;
		Time::TimeService* timeService;
		Gameplay::GameplayService* gameplayService;
		Sound::SoundService* soundService;

		ServiceLocator();
		~ServiceLocator();

		void CreateServices();
		void ClearAllServices();

	public:
		static ServiceLocator* GetInstance();

		void Initialize();
		void Update();
		void Render();

		Event::EventService* GetEventService();
		Graphics::GraphicService* GetGraphicService();
		UI::UIService* GetUIService();
		Time::TimeService* GetTimeService();
		Gameplay::GameplayService* GetGameplayService();
		Sound::SoundService* GetSoundService();
	};
}

