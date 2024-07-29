#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Gameplay {
	void GameplayView::CreateUIElements()
	{
		backgroundImage = new UI::UIElement::ImageView();
	}

	void GameplayView::InitializeImage()
	{
		sf::RenderWindow* gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		backgroundImage->Initialize(Global::Config::backgroundTexturePath, 
									gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
	}

	void GameplayView::Destroy()
	{
		delete(backgroundImage);
	}

	GameplayView::GameplayView()
	{
		CreateUIElements();
	}

	GameplayView::~GameplayView()
	{
		Destroy();
	}

	void GameplayView::Initialize()
	{
		InitializeImage();
	}

	void GameplayView::Update()
	{

	}

	void GameplayView::Render()
	{
		backgroundImage->Render();
	}
}









