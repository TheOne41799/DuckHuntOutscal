#include "../../Header/Duck/Controller/DuckOneController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Duck
{
	namespace Controllers
	{
		DuckOneController::DuckOneController(DuckType type) : DuckController(type)
		{
			DuckController::score = duckOneScore;
			DuckController::verticalMovementSpeed = verticalMovementSpeed;
			DuckController::horizontalMovementSpeed = horizontalMovementSpeed;
		}

		DuckOneController::~DuckOneController()
		{

		}

		void DuckOneController::Initialize()
		{
			DuckController::Initialize();

		}

		bool DuckOneController::CheckIfColliding(sf::FloatRect bounds)
		{
			if (DuckController::CheckIfColliding(bounds)) {
				Global::ServiceLocator::GetInstance()->GetDuckService()
				->CheckIsDuckColliding(sf::FloatRect(duckModel->GetDuckPosition(), sf::Vector2f(150.f, 150.f)));
				return true;
			}

			return false;
		}
	}
}












