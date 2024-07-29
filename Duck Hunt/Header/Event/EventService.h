#pragma once
#include <SFML\Graphics.hpp>


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

		ButtonState LeftMouseButtonState = ButtonState::RELEASED;

		bool IsGameWindowOpen();
		bool GameWindowClosed();
		bool HasQuitGame();

		void ProcessEvents();
		void UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button button);

	public:
		EventService();
		~EventService();
		void Initialize();
		void Update();

		bool IsKeyboardEvent();
		bool PressedEscapeKey();

		bool PressedLeftMouseButton();

		bool PressedOneKey();
		bool PressedTwoKey();
	};
}







