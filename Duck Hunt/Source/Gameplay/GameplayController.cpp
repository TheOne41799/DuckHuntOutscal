#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Gameplay 
{
	GameplayController::GameplayController()
	{
		gameplayModel = new GameplayModel();
		gameplayView = new GameplayView();
	}

	GameplayController::~GameplayController()
	{
		delete gameplayModel;
		delete gameplayView;
	}

	void GameplayController::Initialize()
	{
		gameplayModel->Initialize();
		gameplayView->Initialize();
	}

	void GameplayController::Update()
	{
		gameplayModel->Update();
		gameplayView->Update();
	}

	void GameplayController::Render()
	{
		gameplayView->Render();
	}

	void GameplayController::IncreaseWave()
	{
		gameplayModel->SetGameplayState(GameplayState::WAVE_STARTING);
		gameplayModel->IncreaseWave();

		Global::ServiceLocator::GetInstance()->GetDuckService()->Reset();
		Global::ServiceLocator::GetInstance()->GetPlayerService()->IncreaseAmmo();
		Global::ServiceLocator::GetInstance()->GetPlayerService()->RestAmmoPerRound();
	}

	void GameplayController::ResetWave()
	{
		gameplayModel->SetGameplayState(GameplayState::WAVE_STARTING);
		gameplayModel->ResetWave();
		Global::ServiceLocator::GetInstance()->GetDuckService()->Reset();
	}

	void GameplayController::Reset()
	{
		gameplayModel->Reset();
		ResetWave();
	}

	GameplayModel* GameplayController::GetGameplayModel()
	{
		return gameplayModel;
	}
}











