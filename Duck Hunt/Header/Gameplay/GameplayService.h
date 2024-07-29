#pragma once
#include "GameplayController.h"


namespace Gameplay 
{
	class GameplayService 
	{
	private:
		GameplayController* gameplayController;

	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();
		
		void IncreaseWave();
		void ResetWave();
		
		int GetNoOfDucksToSpawn();
		void Reset();

		GameplayModel* GetGameplayModel();
	};
}







