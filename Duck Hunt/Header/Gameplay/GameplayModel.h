#pragma once


namespace Gameplay 
{
	enum class GameplayState 
	{
		WAVE_STARTING,
		WAVE_STARTED
	};


	class GameplayModel 
	{
	private:
		GameplayState gameplayState = GameplayState::WAVE_STARTING;

		int waveNO = 1;
		int noOfDucksToSpawn = 3;
		int waveTime = 30.f;
		int waveStartTime = 3;
		int currentWaveTime = waveTime;
		float elapsedTime = 0.f;
		
		void UpdateWaveStartTime();
		void UpdateCurrentWaveTime();

	public:
		GameplayModel();
		~GameplayModel();

		void Initialize();
		void Update();

		int GetWaveNO();
		int GetNoOfDucksToSpawn();
		int GetWaveTime();
		int GetWaveStartTime();

		GameplayState GetGameplayState();

		void Reset();
		void IncreaseWave();
		void ResetWave();
		void SetWaveNo(int newWaveNO);
		void SetWaveTime(int newWaveTime);
		void SetGameplayState(GameplayState state);
		void SetNoOfDucksToSpawn(int number);
		void ResetWaveTime();
	};
}