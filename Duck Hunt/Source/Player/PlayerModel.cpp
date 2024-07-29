#include "../../Header/Player/PlayerModel.h"


namespace Player 
{
	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::Initialize()
	{
		Reset();
	}

	void PlayerModel::Reset()
	{
		currentHealth = health;
		currentAmmoPerRound = 3;
		ammoPerRound = 3;
		currentRadiusAmmoPerRound = 1;
		score = 0;
	}

	void PlayerModel::ResetAmmoPerRound()
	{
		currentAmmoPerRound = ammoPerRound;
		currentRadiusAmmoPerRound = radiusAmmoRound;
	}

	int PlayerModel::GetHealth()
	{
		return currentHealth;
	}

	void PlayerModel::SetHealth(int newHealth)
	{
		currentHealth = newHealth;
	}

	int PlayerModel::GetAmmoPerRound()
	{
		return ammoPerRound;
	}

	void PlayerModel::SetAmmoPerRound(int newAmmo)
	{
		ammoPerRound = newAmmo;
	}

	int PlayerModel::GetCurrentAmmoPerRound()
	{
		return currentAmmoPerRound;
	}

	void PlayerModel::SetCurrentAmmoPerRound(int newAmmo)
	{
		currentAmmoPerRound = newAmmo;
	}

	int PlayerModel::GetRadiusAmmoPerRound()
	{
		return currentRadiusAmmoPerRound;
	}

	void PlayerModel::SetRadiusAmmoPerRound(int newAmmo)
	{
		currentRadiusAmmoPerRound = newAmmo;
	}

	int PlayerModel::GetScore()
	{
		return score;
	}

	void PlayerModel::SetScore(int newScore)
	{
		score = newScore;
	}
}






