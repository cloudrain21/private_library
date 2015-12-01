#ifndef __CRCR_THREAD_LOCAL_HPP__
#define __CRCR_THREAD_LOCAL_HPP__

#include <NonCopyable.hpp>
#include <cstdlib>

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 */
namespace cr
{

namespace priv
{
	class ThreadLocalImpl;
}

/**
 * \brief Defines variables with thread-local storage
 */
class ThreadLocal : NonCopyable
{
public:

	/**
	 * \brief Default constructor
	 *
	 * \param value Optional value to initialize the variable
	 */
	ThreadLocal(void * value = NULL);

	/**
	 * \brief Destructor
	 */
	~ThreadLocal();

	/**
	 * \brief Set the thread-specific value of the variable
	 *
	 * \param value Value of the variable for the current thread
	 */
	void setValue(void * value);

	/**
	 * \brief Retrieve the thread-specific value of the variable
	 *
	 * \return Value of the variable for the current thread
	 */
	void * getValue() const;

private:

	/**
	 * \brief Member data
	 */
	priv::ThreadLocalImpl * m_impl;
};

} // namespace cr

#endif // __CRCR_THREAD_LOCAL_HPP__
