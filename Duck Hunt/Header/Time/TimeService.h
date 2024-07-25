#pragma once
#include <chrono>


namespace Time
{
	class TimeService
	{
	private:
		std::chrono::time_point<std::chrono::steady_clock> previousTime;
		float deltaTime;

		void UpdateDeltaTime();
		float CalculateDeltaTime();
		void UpdatePreviousTime();

	public:
		void Initialize();
		void Update();

		float GetDeltaTime();
	};
}
