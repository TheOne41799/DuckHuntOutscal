#pragma once
#include "../UI/UIElement/ImageView.h"


namespace Gameplay 
{
	class GameplayView 
	{
	private:
		UI::UIElement::ImageView* backgroundImage;

		void CreateUIElements();
		void InitializeImage();
		void Destroy();

	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();
	};
}











