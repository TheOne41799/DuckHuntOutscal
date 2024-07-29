#include "../../Header/UI/UIElement/UIView.h"
#include "../../../Header/Global/ServiceLocator.h"


namespace UI 
{
	namespace UIElement 
	{
		UIView::UIView()
		{

		}
		UIView::~UIView()
		{

		}

		void UIView::Initialize()
		{
			gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			Show();
		}

		void UIView::Update()
		{

		}

		void UIView::Render()
		{

		}

		void UIView::Show()
		{
			uiState = UIState::VISIBLE;
		}

		void UIView::Hide()
		{
			uiState = UIState::HIDDEN;
		}
	}
}









