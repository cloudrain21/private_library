#ifndef __CRCR_CLOCK_IMPL_HPP__
#define __CRCR_CLOCK_IMPL_HPP__

#include <Config.hpp>
#include <Time.hpp>
#include <cstddef>
#include <cstdlib>

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 */
namespace cr
{

namespace priv
{

class ClockImpl
{
public:
	static Time getCurrentTime();
};
	
}; // namespace priv
	
}; // namespace cr

#endif // __CRCR_CLOCK_IMPL_HPP__
