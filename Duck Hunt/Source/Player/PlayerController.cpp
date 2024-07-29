#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Player 
{
	using namespace Global;


	void PlayerController::Create()
	{
		playerModel = new PlayerModel();
	}

	void PlayerController::Destroy()
	{
		delete playerModel;
	}

	void PlayerController::ProcessPlayerInput()
	{
		Event::EventService* eventService = Global::ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftMouseButton()) 
		{
			CheckIfDuckUnderCursor();
			ReduceAmmo();
			
			if (playerModel->GetCurrentAmmoPerRound() <= 0 && playerModel->GetRadiusAmmoPerRound() <= 0
				&& Global::ServiceLocator::GetInstance()->GetDuckService()->GetNoOfDucksRemaning() > 0) 
			{
				Global::ServiceLocator::GetInstance()->GetGameplayService()->ResetWave();
				ReduceHealth();
				RestAmmoPerRound();
			}
		}

		if (eventService->PressedOneKey()) 
		{
			if (playerModel->GetCurrentAmmoPerRound() > 0) 
			{
				SetBulletType(BulletType::Point);
			}
		}

		else if (eventService->PressedTwoKey()) 
		{
			if (playerModel->GetRadiusAmmoPerRound() > 0)
			{
				SetBulletType(BulletType::Area);
			}
		}
	}

	void PlayerController::ReduceAmmo()
	{
		switch (bulletType)
		{
		case Player::BulletType::Point:
			Global::ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::BULLET_FIRE);

			playerModel->SetCurrentAmmoPerRound(playerModel->GetCurrentAmmoPerRound() - 1);

			if (playerModel->GetCurrentAmmoPerRound() <= 0) 
			{
				SetBulletType(BulletType::Area);
			}
			break;
		case Player::BulletType::Area:
			Global::ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::RADIUS_BUllET_FIRE);

			playerModel->SetRadiusAmmoPerRound(playerModel->GetRadiusAmmoPerRound() - 1);

			if (playerModel->GetRadiusAmmoPerRound() <= 0) 
			{
				SetBulletType(BulletType::Point);
			}
			break;
		default:
			break;
		}
	}

	void PlayerController::CheckIfDuckUnderCursor()
	{
		sf::RenderWindow* gameWindow = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

		switch (bulletType)
		{
		case Player::BulletType::Point:
			Global::ServiceLocator::GetInstance()->GetDuckService()
									->CheckIsDuckColliding(
									sf::FloatRect(static_cast<sf::Vector2f>
									(gameWindow->mapPixelToCoords(static_cast<sf::Vector2i>(mousePosition))), 
									sf::Vector2f(2.f, 2.f)));
			break;
		case Player::BulletType::Area:
			Global::ServiceLocator::GetInstance()->GetDuckService()
									->CheckIsDuckColliding(
									sf::FloatRect(static_cast<sf::Vector2f>
									(gameWindow->mapPixelToCoords(static_cast<sf::Vector2i>(mousePosition))), 
									sf::Vector2f(300.f, 300.f)));
			break;
		default:
			break;
		}
	}

	void  PlayerController::ReduceHealth() 
	{
		playerModel->SetHealth(playerModel->GetHealth() - 1);

		if (playerModel->GetHealth() <= 0) 
		{
			ServiceLocator::GetInstance()->Reset();
		}
	}

	void PlayerController::RestAmmoPerRound()
	{
		SetBulletType(BulletType::Point);
		playerModel->ResetAmmoPerRound();
	}

	PlayerController::PlayerController()
	{
		Create();
	}

	PlayerController::~PlayerController()
	{
		Destroy();
	}

	void PlayerController::Initialize()
	{
		playerModel->Initialize();
	}

	void PlayerController::Update()
	{
		ProcessPlayerInput();
	}

	void PlayerController::Render()
	{

	}

	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	int PlayerController::GetHealth()
	{
		return playerModel->GetHealth();
	}

	int PlayerController::GetAmmoPerRound()
	{
		return playerModel->GetCurrentAmmoPerRound();
	}

	int PlayerController::GetRadiusAmmoPerRound()
	{
		return playerModel->GetRadiusAmmoPerRound();
	}

	int PlayerController::GetScore()
	{
		return playerModel->GetScore();;
	}

	void PlayerController::IncreaseScore(int increaseAmount)
	{
		playerModel->SetScore(GetScore() + increaseAmount);
	}

	void PlayerController::IncreaseAmmo()
	{
		playerModel->SetAmmoPerRound(Global::ServiceLocator::GetInstance()->GetGameplayService()->GetNoOfDucksToSpawn());
	}

	BulletType PlayerController::GetBulletType()
	{
		return bulletType;
	}

	void PlayerController::SetBulletType(BulletType type)
	{
		bulletType = type;
	}
}








