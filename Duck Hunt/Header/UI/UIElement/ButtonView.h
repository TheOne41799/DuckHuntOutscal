#pragma once
#include "../../../Header/UI/UIElement/ImageView.h"
#include <functional>


namespace UI 
{
	namespace UIElement 
	{
		class ButtonView : public ImageView 
		{
		private:
			using CallbackFunction = std::function<void()>;
			CallbackFunction callbackFunction = nullptr;

			void PrintButtonClicked();

		protected:
			sf::String buttonTitle;

			virtual void HandleButtonInteraction();
			virtual bool ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);

		public:
			ButtonView();
			~ButtonView();

			void Initialize(sf::String title, sf::String texturePath, float buttonWidth, float buttonHeight, 
							sf::Vector2f position);
			void Update();
			void Render();

			void RegisterCallbackFuntion(CallbackFunction buttonCallback);
		};
	}
}
