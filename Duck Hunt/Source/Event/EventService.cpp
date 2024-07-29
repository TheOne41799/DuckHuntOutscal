#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Event 
{
	bool EventService::PressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;
	}

	bool EventService::PressedLeftMouseButton()
	{
		return LeftMouseButtonState == ButtonState::PRESSED;
	}

	bool EventService::PressedOneKey()
	{

		return sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1);
	}

	bool EventService::PressedTwoKey()
	{
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2);;
	}

	bool EventService::IsGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::GameWindowClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}

	bool EventService::HasQuitGame()
	{
		return (IsKeyboardEvent() && PressedEscapeKey());
	}

	void EventService::ProcessEvents()
	{
		if (IsGameWindowOpen()) 
		{
			while (gameWindow->pollEvent(gameEvent)) 
			{
				if (GameWindowClosed() || HasQuitGame()) 
				{
					gameWindow->close();
				}
			}
		}
	}

	void EventService::UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button button)
	{
		if (sf::Mouse::isButtonPressed(button)) {
			switch (currentButtonState)
			{
			case Event::ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			case Event::ButtonState::HELD:
				break;
			case Event::ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			default:
				break;
			}
		}
		else {
			currentButtonState = ButtonState::RELEASED;
		}
	}

	EventService::EventService()
	{
		gameWindow = nullptr;
	}

	EventService::~EventService()
	{

	}

	void EventService::Initialize()
	{
		gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	}

	void EventService::Update()
	{
		ProcessEvents();
		UpdateMouseButtonState(LeftMouseButtonState, sf::Mouse::Left);
	}

	bool EventService::IsKeyboardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}
}



