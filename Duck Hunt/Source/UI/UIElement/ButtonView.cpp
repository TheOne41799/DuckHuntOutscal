#include "../../../Header/UI/UIElement/ButtonView.h"
#include "../../../Header/Event/EventService.h"
#include "../../../Header/Global/ServiceLocator.h"


namespace UI 
{
	namespace UIElement 
	{
		using namespace Event;
	
		
		void ButtonView::PrintButtonClicked()
		{
			printf("Clicked%s\n", buttonTitle.toAnsiString().c_str());
		}

		void ButtonView::HandleButtonInteraction()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*UIView::gameWindow));

			if (ClickedButton(&sprite, mousePosition)) 
			{
				if (callbackFunction) callbackFunction();
			}

		}

		bool ButtonView::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
		{
			EventService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();
			return eventService->PressedLeftMouseButton() 
				   && sprite.getGlobalBounds().contains(
					   UIView::gameWindow->mapPixelToCoords(static_cast<sf::Vector2i> (mousePosition)));

		}

		ButtonView::ButtonView()
		{

		}

		ButtonView::~ButtonView()
		{

		}

		void ButtonView::Initialize(sf::String title, sf::String texturePath, 
									float buttonWidth, float buttonHeight, sf::Vector2f position)
		{
			ImageView::Initialize(texturePath, buttonWidth, buttonHeight, position);
			buttonTitle = title;
		}

		void ButtonView::Update()
		{
			ImageView::Update();

			if (uiState == UIState::VISIBLE) 
			{
				HandleButtonInteraction();
			}
		}

		void ButtonView::Render()
		{
			ImageView::Render();
		}

		void ButtonView::RegisterCallbackFuntion(CallbackFunction buttonCallback)
		{
			callbackFunction = buttonCallback;
		}
	}
}












