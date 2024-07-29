#pragma once
#include "../DuckController.h"


namespace Duck 
{
	namespace Controllers 
	{
		class DuckTwoController : public DuckController 
		{
		protected:
			int score = 1;
			float verticalMovementSpeed = 300.f;
			float horizontalMovementSpeed = 600.f;

		public:
			DuckTwoController(DuckType type);
			virtual ~DuckTwoController();

			void Initialize();
		};
	}
}
















