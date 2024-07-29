#include "../../Header/Duck/DuckView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/DuckAnimationConfigData.h"
#include "../../Header/Global/Config.h"


namespace Duck 
{
	using namespace Global;


	void DuckView::CreateUIElemetns()
	{
		duckImage = new UI::UIElement::ImageView();
	}

	void DuckView::InitializeImage()
	{
		duckImage->Initialize(GetDuckTexturePath(), 0, 0, duckController->GetDuckPosition());
		duckImage->SetTextureRect(sf::IntRect(0, 0, duckAnimationConfig.tileWidth, duckAnimationConfig.tileHeight));

		switch (duckController->GetMovementDirection())
		{
		case MovementDirection::LEFT_UP:
			duckImage->SetRotation(-25);
			SetScale(-1);
			break;
		case MovementDirection::RIGHT_UP:
			duckImage->SetRotation(25);
			SetScale(1);
			break;
		default:
			duckImage->SetRotation(-25);
			SetScale(-1);
			break;
		}
	}

	sf::String DuckView::GetDuckTexturePath()
	{
		switch (duckController->GetDuckType()) 
		{
		case DuckType::DUCK_TWO:
			return Config::duckOneTexturePath;
			break;
		case DuckType::DUCK_ONE:
			return Config::duckTwoTexturePath;
			break;
		default:
			return Config::duckTwoTexturePath;
			break;
		}
	}

	void DuckView::Destroy()
	{
		delete duckImage;
	}

	DuckView::DuckView()
	{
		CreateUIElemetns();
	}
	
	DuckView::~DuckView()
	{
		Destroy();
	}

	void DuckView::Initialize(DuckController* controller)
	{
		duckController = controller;
		currentFrame = 0;
		InitializeImage();
	}

	void DuckView::Update()
	{
		elapsedTime += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		duckImage->SetPosition(duckController->GetDuckPosition());

		if (duckController->GetDuckState() == DuckState::ALIVE) {

			UpdateAnimation(duckAnimationConfig);
		}
		else 
		{
			duckImage->SetRotation(0);

			if (!deadAniamtionFinished) {
				ShowDeadAnimation(duckdeadAnimationConfig);
			}
			else 
			{
				UpdateAnimation(duckRotatingAnimationConfig);
			}
		}
	}

	void DuckView::Render()
	{
		duckImage->Render();
	}

	void DuckView::UpdateAnimation(DuckAnimationConfig animationConfig)
	{
		if (elapsedTime >= animationConfig.frameDuration) 
		{
			if (currentFrame + 1 >= animationConfig.numberOfAnimationFrame) {
				currentFrame = 0;
			}
			else 
			{
				currentFrame = (currentFrame + 1) % animationConfig.numberOfAnimationFrame;
			}

			duckImage->SetTextureRect(sf::IntRect(
				animationConfig.tileStart + (currentFrame * animationConfig.tileWidth),
				0,
				animationConfig.tileWidth,
				animationConfig.tileHeight
			));

			elapsedTime = 0.f;
			duckImage->Update();
		}
	}
	void DuckView::ShowDeadAnimation(DuckAnimationConfig animationConfig)
	{
		duckImage->SetTextureRect(sf::IntRect(
			animationConfig.tileStart,
			0,
			animationConfig.tileWidth,
			animationConfig.tileHeight
		));

		if (elapsedTime >= animationConfig.frameDuration) {

			currentFrame = 0;
			elapsedTime = 0.f;
			deadAniamtionFinished = true;
		}
		duckImage->Update();
	}

	const sf::Sprite& DuckView::GetDuckSprite()
	{
		return duckImage->GetSprite();
	}

	void DuckView::SetRotation(float angle)
	{
		duckImage->SetRotation(angle);
	}

	void DuckView::SetScale(int flip)
	{
		duckImage->SetScale(duckWidth, duckHeight, flip * duckAnimationConfig.tileWidth, duckAnimationConfig.tileHeight);
	}
}







