#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Duck 
{
	void DuckController::Move()
	{
		switch (duckModel->GetMovementDirection())
		{
		case MovementDirection::LEFT_UP:
			MoveUp();
			MoveLeft();
			break;
		case MovementDirection::LEFT_DOWN:
			MoveDown();
			MoveLeft();
			break;
		case MovementDirection::RIGHT_UP:
			MoveRight();
			MoveUp();
			break;
		case MovementDirection::RIGHT_DOWN:
			MoveRight();
			MoveDown();
			break;
		default:
			break;
		}
	}

	void DuckController::MoveDown()
	{
		sf::Vector2f currentPosition = duckModel->GetDuckPosition();

		currentPosition.y += verticalMovementSpeed
							 * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.y >= duckModel->bottomMostPosition) 
		{
			if (duckModel->GetMovementDirection() == MovementDirection::LEFT_DOWN) 
			{
				duckView->SetRotation(-25);
				duckView->SetScale(-1);
				duckModel->SetMovementDirection(MovementDirection::LEFT_UP);
			}
			else {
				duckView->SetRotation(25);
				duckView->SetScale(1);
				duckModel->SetMovementDirection(MovementDirection::RIGHT_UP);
			}
		}
		else {
			duckModel->SetDuckPosition(currentPosition);
		}
	}

	void DuckController::MoveUp()
	{
		sf::Vector2f currentPosition = duckModel->GetDuckPosition();

		currentPosition.y -= verticalMovementSpeed
							 * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.y <= duckModel->topMostPosition) 
		{
			if (duckModel->GetMovementDirection() == MovementDirection::LEFT_UP) 
			{
				duckView->SetRotation(-50);
				duckView->SetScale(-1);
				duckModel->SetMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else 
			{
				duckView->SetRotation(50);
				duckView->SetScale(1);
				duckModel->SetMovementDirection(MovementDirection::RIGHT_DOWN);
			}
		}
		else 
		{
			duckModel->SetDuckPosition(currentPosition);
		}
	}

	void DuckController::MoveLeft()
	{
		sf::Vector2f currentPosition = duckModel->GetDuckPosition();

		currentPosition.x -= horizontalMovementSpeed
							 * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.x <= duckModel->leftMostPosition) 
		{
			if (duckModel->GetMovementDirection() == MovementDirection::LEFT_DOWN) {
				duckView->SetRotation(50);
				duckView->SetScale(1);
				duckModel->SetMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else 
			{
				duckView->SetRotation(25);
				duckView->SetScale(1);
				duckModel->SetMovementDirection(MovementDirection::RIGHT_UP);
			}
		}
		else 
		{
			duckModel->SetDuckPosition(currentPosition);
		}
	}

	void DuckController::MoveRight()
	{
		sf::Vector2f currentPosition = duckModel->GetDuckPosition();
		
		currentPosition.x += horizontalMovementSpeed
							 * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		
		if (currentPosition.x >= duckModel->rightMostPosition) 
		{
			if (duckModel->GetMovementDirection() == MovementDirection::RIGHT_DOWN) {
				duckView->SetRotation(-50);
				duckView->SetScale(-1);
				duckModel->SetMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else {
				duckView->SetRotation(-25);
				duckView->SetScale(-1);
				duckModel->SetMovementDirection(MovementDirection::LEFT_UP);
			}
		}
		else 
		{
			duckModel->SetDuckPosition(currentPosition);
		}
	}

	void DuckController::DeadMove()
	{
		sf::Vector2f currentPosition = duckModel->GetDuckPosition();
		currentPosition.y += deadMovementSpeed
							 * Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		duckModel->SetDuckPosition(currentPosition);
	}

	sf::Vector2f DuckController::GetRandomPosition()
	{
		float xPosition = duckModel->leftMostPosition 
						  + (std::rand() % static_cast<int>(duckModel->leftMostPosition - duckModel->rightMostPosition));
		float yPosition = duckModel->bottomMostPosition - (std::rand() % 50);

		return sf::Vector2f(xPosition, yPosition);
	}

	void DuckController::PlayDuckSound()
	{
		duckSoundElapsedTime += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (duckSoundElapsedTime >= duckSoundTime) 
		{
			Global::ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::DUCK_QUACK);
			duckSoundElapsedTime = 0.f;
		}
	}
	void DuckController::HandleOutOfBounds()
	{
		sf::Vector2f duckPosition = GetDuckPosition();

		sf::Vector2u windowSize = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (duckPosition.x < 0 || duckPosition.x > windowSize.x ||
			duckPosition.y < 0 || duckPosition.y > windowSize.y)
		{
			Global::ServiceLocator::GetInstance()->GetDuckService()->DestroyDuck(this);
		}
	}

	void DuckController::Destroy()
	{
		delete duckModel;
		delete duckView;
	}
	
	DuckController::DuckController(DuckType type)
	{
		duckModel = new DuckModel(type);
		duckView = new DuckView();
	}

	DuckController::~DuckController()
	{
		Destroy();
	}

	void DuckController::Initialize()
	{
		duckModel->SetReferencePosition(GetRandomPosition());
		duckModel->Initialize();
		duckView->Initialize(this);
	}

	void DuckController::Update()
	{
		duckView->Update();

		switch (duckModel->GetDuckState())
		{
		case DuckState::ALIVE:
			Move();
			PlayDuckSound();
			break;
		case DuckState::DEAD:
			DeadMove();
			HandleOutOfBounds();
			break;
		default:
			break;
		}
	}

	void DuckController::Render()
	{
		duckView->Render();
	}

	sf::Vector2f DuckController::GetDuckPosition()
	{
		return duckModel->GetDuckPosition();
	}

	DuckType DuckController::GetDuckType()
	{
		return duckModel->GetDuckType();
	}

	MovementDirection DuckController::GetMovementDirection()
	{
		return duckModel->GetMovementDirection();
	}

	DuckState DuckController::GetDuckState()
	{
		return duckModel->GetDuckState();
	}

	bool DuckController::CheckIfColliding(sf::FloatRect bounds)
	{
		if (duckModel->GetDuckState() == DuckState::ALIVE) 
		{
			if (GetDuckSprite().getGlobalBounds().intersects(bounds)) 
			{
				duckModel->SetDuckState(DuckState::DEAD);

				Global::ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::DuckDied);
				Global::ServiceLocator::GetInstance()->GetPlayerService()->IncreaseScore(score);;

				return true;
			}
		}

		return false;
	}

	const sf::Sprite& DuckController::GetDuckSprite()
	{
		if (duckModel->GetDuckState() == DuckState::ALIVE) 
		{
			return duckView->GetDuckSprite();
		}
		else 
		{
			return sf::Sprite();
		}

	}
}





