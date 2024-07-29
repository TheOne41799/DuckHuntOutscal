#include "../../Header/Duck/Controller/DuckTwoController.h"
#include "../../Header/Duck/DuckModel.h"
#include "../../Header/Duck/DuckView.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Duck 
{
	namespace Controllers 
	{
		DuckTwoController::DuckTwoController(DuckType type) : DuckController(type)
		{
			DuckController::score = score;
			DuckController::verticalMovementSpeed = verticalMovementSpeed;
			DuckController::horizontalMovementSpeed = horizontalMovementSpeed;
		}

		DuckTwoController::~DuckTwoController()
		{

		}

		void DuckTwoController::Initialize()
		{
			DuckController::Initialize();
		}
	}
}







