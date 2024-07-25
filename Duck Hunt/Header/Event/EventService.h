#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


namespace Event
{
	enum class ButtonState
	{

		PRESSED,
		HELD,
		RELEASED,
	};


	class EventService
	{
	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		ButtonState leftArrowButtonState;
		ButtonState rightArrowButtonState;

		ButtonState A_ButtonState;
		ButtonState D_ButtonState;

		ButtonState leftMouseButtonState;
		ButtonState rightMouseButtonState;

		bool IsGameWindowOpen();
		bool GameWindowWasClosed();
		bool HasQuitGame();

		void UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
		void UpdateKeyboardButtonState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);

	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents();
		bool IsKeyboardEvent();
		bool PressedEscapeKey();

		bool PressedLeftKey();
		bool PressedRightKey();

		bool PressedAKey();
		bool PressedDKey();

		bool PressedLeftMouseButton();
		bool PressedRightMouseButton();
	};
}