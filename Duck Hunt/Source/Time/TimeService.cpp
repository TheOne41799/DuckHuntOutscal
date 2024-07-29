#include "../../Header/Time/TimeService.h"


namespace Time 
{
    void TimeService::UpdateDeltaTime()
    {
        deltaTime = CalculateDeltaTime();
        UpdatePreviousTime();
    }

    float TimeService::CalculateDeltaTime()
    {
        int delta = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>
                                    (std::chrono::steady_clock::now() - previousTime).count());

        return static_cast<float>(delta) / 1000000.f;
    }

    void TimeService::UpdatePreviousTime()
    {
        previousTime = std::chrono::steady_clock::now();
    }

    TimeService::TimeService()
    {

    }

    TimeService::~TimeService()
    {

    }

    void TimeService::Initialize()
    {
        previousTime = std::chrono::steady_clock::now();
        deltaTime = 0;
    }

    void TimeService::Update()
    {
        UpdateDeltaTime();
    }

    float TimeService::GetDeltaTime()
    {
        return deltaTime;
    }
}








