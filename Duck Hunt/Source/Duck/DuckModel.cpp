#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckController.h"
#include <vector>


namespace Duck
{
	DuckModel::DuckModel(DuckType type)
	{
		duckType = type;
	}

	DuckModel::~DuckModel()
	{

	}

	void DuckModel::Initialize()
	{
		duckPosition = referencePosition;

		switch (std::rand() % 2) 
		{
		case 0:
			SetMovementDirection(MovementDirection::LEFT_UP);
			break;
		case 1:
			SetMovementDirection(MovementDirection::RIGHT_UP);
			break;
		}
	}

	sf::Vector2f DuckModel::GetDuckPosition()
	{
		return duckPosition;
	}

	void DuckModel::SetDuckPosition(sf::Vector2f position)
	{
		duckPosition = position;
	}

	sf::Vector2f DuckModel::GetReferencePosition()
	{
		return referencePosition;
	}

	void DuckModel::SetReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}

	DuckType DuckModel::GetDuckType()
	{
		return duckType;
	}

	void DuckModel::SetDuckType(DuckType type)
	{
		duckType = type;
	}

	DuckState DuckModel::GetDuckState()
	{
		return duckState;
	}

	void DuckModel::SetDuckState(DuckState state)
	{
		duckState = state;
	}

	MovementDirection DuckModel::GetMovementDirection()
	{
		return movementDirection;
	}

	void DuckModel::SetMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}
}




