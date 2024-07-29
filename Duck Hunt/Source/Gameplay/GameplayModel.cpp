#include "../../Header/Gameplay/GameplayModel.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Gameplay 
{
    void GameplayModel::UpdateWaveStartTime()
    {
        elapsedTime += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

        if (elapsedTime >= 1.f) 
        {
            waveStartTime -= 1;
            elapsedTime = 0.f;
        
            if (waveStartTime <= 0) {
                Global::ServiceLocator::GetInstance()->GetPlayerService()->RestAmmoPerRound();
                Global::ServiceLocator::GetInstance()->GetGameplayService()->ResetWave();
                Global::ServiceLocator::GetInstance()->GetDuckService()->SpawnNoOfDuck(GetNoOfDucksToSpawn());

                gameplayState = GameplayState::WAVE_STARTED;
            }
        }
    }

    void GameplayModel::UpdateCurrentWaveTime()
    {
        elapsedTime += Global::ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

        if (elapsedTime >= 1.f) 
        {
            currentWaveTime -= 1;
            elapsedTime = 0.f;

            if (currentWaveTime <= 0) {
                Global::ServiceLocator::GetInstance()->GetPlayerService()->ReduceHealth();
                Global::ServiceLocator::GetInstance()->GetPlayerService()->RestAmmoPerRound();
                Global::ServiceLocator::GetInstance()->GetGameplayService()->ResetWave();
            }
        }
    }

    GameplayModel::GameplayModel()
    {

    }

    GameplayModel::~GameplayModel()
    {

    }

    void GameplayModel::Initialize()
    {

    }

    void GameplayModel::Update()
    {
        switch (gameplayState)
        {
        case Gameplay::GameplayState::WAVE_STARTING:
            UpdateWaveStartTime();
            break;
        case Gameplay::GameplayState::WAVE_STARTED:
            UpdateCurrentWaveTime();
            break;
        default:
            break;
        }
    }

    int GameplayModel::GetWaveNO()
    {
        return waveNO;
    }

    int GameplayModel::GetNoOfDucksToSpawn()
    {
        return noOfDucksToSpawn;
    }

    int GameplayModel::GetWaveTime()
    {
        return currentWaveTime;
    }

    int GameplayModel::GetWaveStartTime()
    {
        return waveStartTime;
    }

    GameplayState GameplayModel::GetGameplayState()
    {
        return gameplayState;
    }

    void GameplayModel::Reset()
    {
        noOfDucksToSpawn = 3;
        waveStartTime = 3;
        waveNO = 1;
        currentWaveTime = waveTime;
    }

    void GameplayModel::IncreaseWave()
    {
        noOfDucksToSpawn = noOfDucksToSpawn + waveNO / 2;
        waveNO += 1;
        ResetWave();
    }

    void GameplayModel::ResetWave()
    {
        waveStartTime = 3;
        currentWaveTime = waveTime;
    }

    void GameplayModel::SetWaveNo(int newWaveNO)
    {
        waveNO = newWaveNO;
    }

    void GameplayModel::SetWaveTime(int newWaveTime)
    {
        waveTime = newWaveTime;
        currentWaveTime = waveTime;
    }

    void GameplayModel::SetGameplayState(GameplayState state)
    {
        gameplayState = state;
    }

    void GameplayModel::SetNoOfDucksToSpawn(int number)
    {
        noOfDucksToSpawn = number;
    }

    void GameplayModel::ResetWaveTime()
    {
        waveStartTime = 3;
        currentWaveTime = waveTime;
    }
}







