#pragma once


namespace Player 
{
	enum class BulletType 
	{
		Point,
		Area
	};

	class PlayerModel;
	class PlayerView;


	class PlayerController 
	{
	private:
		PlayerModel* playerModel;

		BulletType bulletType = BulletType::Point;

		void Create();
		void Destroy();
		void ProcessPlayerInput();
		void ReduceAmmo();
		void CheckIfDuckUnderCursor();

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void ReduceHealth();
		int GetHealth();

		void RestAmmoPerRound();
		int GetAmmoPerRound();
		int GetRadiusAmmoPerRound();

		int GetScore();
		void IncreaseScore(int increaseAmount);
		void IncreaseAmmo();

		BulletType GetBulletType();
		void SetBulletType(BulletType type);
	};
}





