#pragma once
#include "../DuckController.h"


namespace Duck 
{
	namespace Controllers 
	{
		class DuckOneController : public DuckController 
		{
		protected:
			int duckOneScore = 2;
			float verticalMovementSpeed = 450.f;
			float horizontalMovementSpeed = 700.f;

		public:
			DuckOneController(DuckType type);
			virtual ~DuckOneController();

			void Initialize();
			virtual bool CheckIfColliding(sf::FloatRect bounds) override;

		};
	}
}










