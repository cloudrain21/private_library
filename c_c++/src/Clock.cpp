#include <Clock.hpp>

namespace cr
{
    Clock::Clock() :
    m_startTime(priv::ClockImpl::getCurrentTime())
    {
    }

    Time Clock::getElapsedTime() const
    {
        return priv::ClockImpl::getCurrentTime() - m_startTime;
    }

    Time Clock::restart()
    {
        Time now = priv::ClockImpl::getCurrentTime();
        Time elapsed = now - m_startTime;
        m_startTime = now;

        return elapsed;
    }
    
};
