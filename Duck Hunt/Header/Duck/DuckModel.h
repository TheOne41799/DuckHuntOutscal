#pragma once
#include <SFML/System/Vector2.hpp>
#include "DuckConfig.h"


namespace Duck 
{
	class DuckController;


	class DuckModel
	{
	private:
		sf::Vector2f duckPosition;
		sf::Vector2f referencePosition = sf::Vector2f(900.f, 1000.f);

		DuckType duckType;
		DuckState duckState = DuckState::ALIVE;
		MovementDirection movementDirection = MovementDirection::LEFT_UP;

	public:
		DuckModel(DuckType type);
		~DuckModel();

		void Initialize();

		const float leftMostPosition = 0.f;
		const float rightMostPosition = 1840.f;
		const float topMostPosition = 100.f;
		const float bottomMostPosition = 900.f;
		const float deadMovmentSpeed = 600.f;

		sf::Vector2f GetDuckPosition();
		void SetDuckPosition(sf::Vector2f position);

		sf::Vector2f GetReferencePosition();
		void SetReferencePosition(sf::Vector2f position);

		DuckType GetDuckType();
		void SetDuckType(DuckType type);

		DuckState GetDuckState();
		void SetDuckState(DuckState state);

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection direction);
	};
}










