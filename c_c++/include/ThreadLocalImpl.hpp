#ifndef __CRCR_THREAD_LOCAL_IMPL_HPP__
#define __CRCR_THREAD_LOCAL_IMPL_HPP__

#include <NonCopyable.hpp>
#include <stddef.h>
#include <pthread.h>


namespace cr
{

namespace priv
{

/**
 * \brief Unix implementation of thread-local storage
 */
class ThreadLocalImpl : NonCopyable
{
public:

	/**
	 * \brief Default constructor -- allocate the storage
	 */
	ThreadLocalImpl();

	/**
	 * \brief Destructor -- free the storage
	 */
	~ThreadLocalImpl();

	/**
	 * \brief Set the thread-specific value of the variable
	 *
	 * \param value Value of the variable for this thread
	 */
	void setValue(void * value);

	/**
	 * \brief Retrieve the thread-specific value of the variable
	 *
	 * \return Value of the variable for this thread
	 */
	void * getValue() const;

private:

	/**
	 * \brief Member data
	 */
	pthread_key_t m_key; /**< Index of our thread-local storage slot */
};

} // namespace priv

} // namespace cr

#endif // __CRCR_THREAD_LOCAL_IMPL_HPP__
