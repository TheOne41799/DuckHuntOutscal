#pragma once
#include "GameplayModel.h"
#include "GameplayView.h"


namespace Gameplay 
{
	class GameplayController 
	{
	private:
		GameplayModel* gameplayModel;
		GameplayView* gameplayView;

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void IncreaseWave();
		void ResetWave();

		void Reset();

		GameplayModel* GetGameplayModel();
	};
}









