#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"


namespace Event
{
	using namespace Global;


	EventService::EventService()
	{
		gameWindow = nullptr;
	}

	EventService::~EventService() = default;

	void EventService::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	}

	void EventService::Update()
	{
		ProcessEvents();
		UpdateMouseButtonsState(leftMouseButtonState, sf::Mouse::Left);
		UpdateMouseButtonsState(rightMouseButtonState, sf::Mouse::Right);
		UpdateKeyboardButtonState(leftArrowButtonState, sf::Keyboard::Left);
		UpdateKeyboardButtonState(rightArrowButtonState, sf::Keyboard::Right);
		UpdateKeyboardButtonState(A_ButtonState, sf::Keyboard::A);
		UpdateKeyboardButtonState(D_ButtonState, sf::Keyboard::D);
	}

	void EventService::ProcessEvents()
	{
		if (IsGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (GameWindowWasClosed() || HasQuitGame())
				{
					gameWindow->close();
				}
			}
		}
	}

	bool EventService::IsGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::GameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}

	bool EventService::HasQuitGame()
	{
		return IsKeyboardEvent() && PressedEscapeKey();
	}

	bool EventService::IsKeyboardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}

	bool EventService::PressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;
	}

	void EventService::UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			switch (currentButtonState)
			{
			case ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = ButtonState::RELEASED;
		}
	}

	void EventService::UpdateKeyboardButtonState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton)
	{
		if (sf::Keyboard::isKeyPressed(keyboardButton))
		{
			switch (currentButtonState)
			{
			case ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = ButtonState::RELEASED;
		}
	}

	bool EventService::PressedLeftKey()
	{
		return leftArrowButtonState == ButtonState::HELD;
	}

	bool EventService::PressedRightKey()
	{
		return rightArrowButtonState == ButtonState::HELD;
	}

	bool EventService::PressedAKey()
	{
		return A_ButtonState == ButtonState::HELD;
	}

	bool EventService::PressedDKey()
	{
		return D_ButtonState == ButtonState::HELD;
	}

	bool EventService::PressedLeftMouseButton()
	{
		return leftMouseButtonState == ButtonState::PRESSED;
	}

	bool EventService::PressedRightMouseButton()
	{
		return rightMouseButtonState == ButtonState::PRESSED;
	}
}
