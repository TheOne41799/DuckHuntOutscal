#include "../../Header/Player/PlayerService.h"


namespace Player 
{
	void PlayerService::CreateController()
	{
		playerController = new PlayerController();
	}

	void PlayerService::InitializeController()
	{
		playerController->Initialize();
	}

	void PlayerService::Destroy()
	{
		delete playerController;
	}

	PlayerService::PlayerService()
	{
		CreateController();
	}

	PlayerService::~PlayerService()
	{
		Destroy();
	}
	void PlayerService::Initialize()
	{
		InitializeController();
	}

	void PlayerService::Update()
	{
		playerController->Update();
	}

	void PlayerService::Render()
	{
		playerController->Render();
	}

	void PlayerService::Reset()
	{
		playerController->Reset();
	}

	int PlayerService::GetHealth()
	{
		return playerController->GetHealth();
	}

	int PlayerService::GetAmmoPerRound()
	{
		return playerController->GetAmmoPerRound();
	}

	int PlayerService::GetRadiusAmmoPerRound()
	{
		return playerController->GetRadiusAmmoPerRound();
	}

	int PlayerService::GetScore()
	{
		return playerController->GetScore();;
	}

	void PlayerService::ReduceHealth()
	{
		playerController->ReduceHealth();
	}

	void PlayerService::IncreaseScore(int amount)
	{
		playerController->IncreaseScore(amount);
	}

	void PlayerService::IncreaseAmmo()
	{
		playerController->IncreaseAmmo();
	}

	void PlayerService::RestAmmoPerRound()
	{
		playerController->RestAmmoPerRound();
	}
}



















