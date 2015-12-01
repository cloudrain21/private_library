#ifndef __CRCR_NON_COPYABLE_HPP__
#define __CRCR_NON_COPYABLE_HPP__

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 */
namespace cr
{

/**
 * \brief Non copyable class
 *
 * This class makes its instances non-copyable, by explicitly
 * disabling its copy constructor and its assignment operator.
 * To create a non-copyable class, simply inherit from
 * cr::NonCopyable.
 *
 * The type of inheritance (public or private) doesn't matter,
 * the copy constructor and assignment operator are declared private
 * in sf::NonCopyable so they will end up being inaccessible in both
 * cases. Thus you can use a shorter syntax for inheriting from it
 * (see example at the bottom).
 */
class NonCopyable
{
protected:
	NonCopyable() {}

private:
	NonCopyable(const NonCopyable&);
	NonCopyable& operator = (const NonCopyable&);
};
	
}; // namespace cr

#endif // __CRCR_NON_COPYABLE_HPP__


/**
 * \brief How to use
 *
 * \code
 * class MyNonCopyableClass : cr::NonCopyable
 * {
 *     ...
 * };
 * \endcode
 */
