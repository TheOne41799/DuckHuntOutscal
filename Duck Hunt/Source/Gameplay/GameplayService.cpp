#include "../../Header/Gameplay/GameplayService.h"


namespace Gameplay 
{
    GameplayService::GameplayService()
    {
        gameplayController = new GameplayController();
    }

    GameplayService::~GameplayService()
    {
        delete gameplayController;
    }

    void GameplayService::Initialize()
    {
        gameplayController->Initialize();
    }

    void GameplayService::Update()
    {
        gameplayController->Update();
    }

    void GameplayService::Render()
    {
        gameplayController->Render();
    }

    void GameplayService::IncreaseWave()
    {
        gameplayController->IncreaseWave();
    }

    void GameplayService::ResetWave()
    {
        gameplayController->ResetWave();
    }

    int GameplayService::GetNoOfDucksToSpawn()
    {
        return GetGameplayModel()->GetNoOfDucksToSpawn();
    }

    void GameplayService::Reset()
    {
        gameplayController->Reset();
    }

    GameplayModel* GameplayService::GetGameplayModel()
    {
        return gameplayController->GetGameplayModel();
    }

}











