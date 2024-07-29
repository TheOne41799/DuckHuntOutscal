#pragma once
#include <vector>
#include "DuckConfig.h"
#include <SFML/Graphics.hpp>


namespace Duck 
{
	class DuckController;
	class DuckService {


	private:
		std::vector<DuckController*> duckList;

		DuckController* CreateDuck(DuckType duckType);
		DuckType GetRandomDuckType();

		void Destroy();

	public:
		void Initialize();
		void Update();
		void Render();

		void Reset();

		void CheckIsDuckColliding(sf::FloatRect bounds);

		int GetNoOfDucksRemaning();
		
		void SpawnDuck();
		void SpawnNoOfDuck(int number);

		void DestroyDuck(DuckController* duckController);
	};
}






