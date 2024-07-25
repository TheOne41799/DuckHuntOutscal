#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace Global;


	GameplayView::GameplayView()
	{
		gameWindow = nullptr;
	}

	GameplayView::~GameplayView()
	{

	}

	void GameplayView::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

		InitializeBackgroundSprite();
	}

	void GameplayView::InitializeBackgroundSprite()
	{
		if (backgroundTexture.loadFromFile(Config::duckHuntBackgroundTexturePath))
		{
			backgroundSprite.setTexture(backgroundTexture);
			ScaleBackgroundSprite();
		}
	}

	void GameplayView::ScaleBackgroundSprite()
	{
		backgroundSprite.setScale(
			static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
			static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
		);
	}

	void GameplayView::Update()
	{

	}

	void GameplayView::Render()
	{
		gameWindow->draw(backgroundSprite);
	}
}
