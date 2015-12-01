#ifndef __CRCR_CLOCK_HPP__
#define __CRCR_CLOCK_HPP__

#include <Time.hpp>
#include <ClockImpl.hpp>

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 */
namespace cr
{

/**
 * \brief Utility class that measures the elapsed time
 *
 * Its provides the most precise time that the underlying
 * OS can achieve (generally microseconds or nanoseconds).
 * It also ensures monotonicity, which means that the returned
 * time can never go backward, even if the system time is
 * changed.
 */
class Clock
{
public:

	/**
	 * \brief Default constructor
	 *
	 * The clock starts automatically after being constructed.
	 */
	Clock();

	/**
	 * \brief Get the elapsed time
	 *
	 * This function returns the time elapsed since the last call
	 * to restart() (or the construction of the instance if restart()
	 * has not been called).
	 *
	 * \return Time elapsed
	 */
	Time getElapsedTime() const;

	/**
	 * \brief Restart the clock
	 *
	 * This function puts the time counter back to zero.
	 * It also returns the time elapsed since the clock was started.
	 *
	 * \return Time elapsed
	 */
	Time restart();

private:

	/**
	 * Member data
	 */
	Time m_startTime;
};
	
}; // namespace cr

#endif // __CRCR_CLOCK_HPP__


/**
 * \brief How to Use
 *
 * \code
 * cr::Clock clock;
 * ...
 * Time time1 = clock.getElapsedTime();
 * ...
 * Time time2 = clock.restart();
 * \endcode
 *
 * The cr::Time value returned by the clock can then be
 * converted to a number of seconds, milliseconds or even
 * microseconds.
 *
 * \see cr::Time
 */
