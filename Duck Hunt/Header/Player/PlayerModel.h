#pragma once


namespace Player 
{
	class PlayerModel 
	{
	private:
		const int health = 3;
		int ammoPerRound = 3;
		const int radiusAmmoRound = 1;

		int currentHealth;
		int currentAmmoPerRound;
		int currentRadiusAmmoPerRound;
		int score = 0;

	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();
		void Reset();
		void ResetAmmoPerRound();

		int GetHealth();
		void SetHealth(int newHealth);

		int GetAmmoPerRound();
		void SetAmmoPerRound(int newAmmo);

		int GetCurrentAmmoPerRound();
		void SetCurrentAmmoPerRound(int newAmmo);

		int GetRadiusAmmoPerRound();
		void SetRadiusAmmoPerRound(int newAmmo);

		int GetScore();
		void SetScore(int newScore);
	};
}






