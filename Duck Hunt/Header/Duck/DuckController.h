#pragma once
#include <SFML/Graphics.hpp>
#include "DuckConfig.h"


namespace Duck 
{
	class DuckModel;
	class DuckView;


	class DuckController 
	{
	protected:
		DuckModel* duckModel;
		DuckView* duckView;

		float verticalMovementSpeed = 200.f;
		float horizontalMovementSpeed = 200.f;

		float deadMovementSpeed = 400.f;

		int score = 1;

		const float duckSoundTime = 1.5f;
		float duckSoundElapsedTime = 0.f;

		virtual void Move();
		virtual void MoveLeft();
		virtual void MoveRight();
		virtual void MoveDown();
		virtual void MoveUp();
		void DeadMove();

		sf::Vector2f GetRandomPosition();
		void PlayDuckSound();
		void HandleOutOfBounds();
		void Destroy();

	public:
		DuckController(DuckType type);
		~DuckController();

		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetDuckPosition();
		DuckType GetDuckType();
		MovementDirection GetMovementDirection();
		DuckState GetDuckState();

		virtual bool CheckIfColliding(sf::FloatRect bounds);

		const sf::Sprite& GetDuckSprite();
	};
}









