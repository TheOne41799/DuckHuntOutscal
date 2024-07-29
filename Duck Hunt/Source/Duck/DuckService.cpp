#include "../../Header/Duck/DuckService.h"
#include "../../Header/Duck/DuckController.h"
#include "../../Header/Duck/Controller/DuckOneController.h"
#include "../../Header/Duck/Controller/DuckTwoController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Duck 
{
	DuckController* DuckService::CreateDuck(DuckType duckType)
	{
		switch (duckType)
		{
		case Duck::DuckType::DUCK_TWO:
			return new Controllers::DuckOneController(duckType);
			break;
		case Duck::DuckType::DUCK_ONE:
			return new Controllers::DuckTwoController(duckType);
			break;
		default:
			return new Controllers::DuckTwoController(duckType);
			break;
		}
	}

	DuckType DuckService::GetRandomDuckType()
	{
		int randomDuckType = std::rand() % 2;
		return static_cast<DuckType>(randomDuckType);
	}

	void DuckService::Destroy() 
	{
		for (DuckController* duckController : duckList)
		{
			delete duckController;
		}

		duckList.clear();
	}

	void DuckService::Initialize()
	{

	}

	void DuckService::Update()
	{
		for (DuckController* duckController : duckList)
		{
			duckController->Update();
		}
	}

	void DuckService::Render()
	{
		for (DuckController* duckController : duckList)
		{
			duckController->Render();
		}
	}

	void DuckService::Reset()
	{
		Destroy();
	}

	void DuckService::CheckIsDuckColliding(sf::FloatRect bounds)
	{
		for (DuckController* duckController : duckList)
		{
			duckController->CheckIfColliding(bounds);
		}
	}

	int DuckService::GetNoOfDucksRemaning()
	{
		return duckList.size();
	}

	void DuckService::SpawnDuck()
	{
		DuckController* duckController = CreateDuck(GetRandomDuckType());
		duckController->Initialize();
		duckList.push_back(duckController);
	}

	void DuckService::SpawnNoOfDuck(int number)
	{
		for (int i = 0; i < number; i++) {
			SpawnDuck();
		}
	}

	void DuckService::DestroyDuck(DuckController* duckController)
	{
		duckList.erase(std::remove(duckList.begin(), duckList.end(), duckController), duckList.end());
		delete duckController;

		if (GetNoOfDucksRemaning() <= 0 && Global::ServiceLocator::GetInstance()->GetPlayerService()->GetHealth() > 0) 
		{
			Global::ServiceLocator::GetInstance()->GetGameplayService()->IncreaseWave();
		}
	}
}







