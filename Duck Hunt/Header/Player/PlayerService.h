#pragma once
#include "PlayerController.h"


namespace Player 
{
	class PlayerService 
	{
	private:
		PlayerController* playerController;

		void CreateController();
		void InitializeController();
		void Destroy();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();
		void Reset();

		int GetHealth();
		int GetAmmoPerRound();
		int GetRadiusAmmoPerRound();
		int GetScore();

		void ReduceHealth();
		void IncreaseScore(int amount);
		void IncreaseAmmo();
		void RestAmmoPerRound();
	};
}





