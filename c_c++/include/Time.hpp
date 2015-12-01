#ifndef __CRCR_TIME_HPP__
#define __CRCR_TIME_HPP__

#include <Config.hpp>

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 */
namespace cr
{

/**
 * \brief Represents a time value
 *
 * sf::Time encapsulates a time value in a flexible way.
 * It allows to define a time value either as a number of
 * seconds, milliseconds or microseconds. It also works the
 * other way round: you can read a time value as either
 * a number of seconds, milliseconds or microseconds.
 *
 * By using such a flexible interface, the API doesn't
 * impose any fixed type or resolution for time values,
 * and let the user choose its own favorite representation.
 *
 * Time values support the usual mathematical operations:
 * you can add or subtract two times, multiply or divide
 * a time by a number, compare two times, etc.
 *
 * Since they represent a time span and not an absolute time
 * value, times can also be negative.
 */
class Time
{
public:
	/**
	 * \brief Default constructor
	 *
	 * Set the time value to zero.
	 */
	Time();

	/**
	 * \brief Return the time value as a number of seconds
	 *
	 * \return Time in seconds
	 *
	 * \see asMilliseconds, asMicroseconds
	 */
	float asSeconds() const;

	/**
	 * \brief Return the time value as a number of milliseconds
	 *
	 * \return Time in milliseconds
	 *
	 * \see asSeconds, asMicroseconds
	 */
	Int32 asMilliseconds() const;

	/**
	 * \brief Return the time value as a number of microseconds
	 *
	 * \return Time in microseconds
	 *
	 * \see asSeconds, asMilliseconds
	 */
	Int64 asMicroseconds() const;

	/**
	 * \brief Static member data
	 *
	 * Predefined "zero" time value
	 */
	static const Time Zero;

private:
	friend Time seconds(float);
	friend Time milliseconds(Int32);
	friend Time microseconds(Int64);

	/**
	 * \brief Construct from a number of microseconds
	 *
	 * This function is internal. To construct time values,
	 * use cr::seconds, cr::milliseconds or cr::microseconds instead.
	 *
	 * \param microseconds Number of microseconds
	 */
	explicit Time(Int64 microseconds);

private:

	/**
	 * \brief Member data
	 *
	 * Time value stored as microseconds
	 */
	Int64 m_microseconds;
};


/**
 * \relates Time
 * \brief Construct a time value from a number of seconds
 *
 * \param amount Number of seconds
 *
 * \return Time value constructed from the amount of seconds
 *
 * \see milliseconds, microseconds
 */
Time seconds(float amount);

/**
 * \relates Time
 * \brief Construct a time value from a number of milliseconds
 *
 * \param amount Number of milliseconds
 *
 * \return Time value constructed from the amount of milliseconds
 *
 * \see seconds, microseconds
 */
Time milliseconds(Int32 amount);

/**
 * \relates Time
 * \brief Construct a time value from a number of microseconds
 *
 * \param amount Number of microseconds
 *
 * \return Time value constructed from the amount of microseconds
 *
 * \see seconds, milliseconds
 */
Time microseconds(Int64 amount);

/**
 * \relates Time
 * \brief Overload of == operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if both time values are equal
 */
bool operator == (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of != operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if both time values are different
 */
bool operator != (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of < operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if \a left is lesser than \a right
 */
bool operator < (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of > operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if \a left is greater than \a right
 */
bool operator > (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of <= operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if \a left is lesser or equal than \a right
 */
bool operator <= (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of >= operator to compare two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return True if \a left is greater or equal than \a right
 */
bool operator >= (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of unary - operator to negate a time value
 *
 * \param right Right operand (a time)
 *
 * \return Opposite of the time value
 */
Time operator - (Time right);

/**
 * \relates Time
 * \brief Overload of binary + operator to add two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return Sum of the two times values
 */
Time operator + (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of binary += operator to add/assign two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return Sum of the two times values
 */
Time& operator += (Time& left, Time right);

/**
 * \relates Time
 * \brief Overload of binary - operator to substract two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return Difference of the two times values
 */
Time operator - (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of binary -= operator to substract/assign two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return Difference of the two times values
 */
Time& operator -= (Time& left, Time right);

/**
 * \relates Time
 * \brief Overload of binary * operator to scale a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left multiplied by \a right
 */
Time operator * (Time left, float right);

/**
 * \relates Time
 * \brief Overload of binary * operator to scale a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left multiplied by \a right
 */
Time operator * (Time left, Int64 right);

/**
 * \relates Time
 * \brief Overload of binary * operator to scale a time value
 *
 * \param left  Left operand (a number)
 * \param right Right operand (a time)
 *
 * \return \a left multiplied by \a right
 */
Time operator * (float left, Time right);

/**
 * \relates Time
 * \brief Overload of binary * operator to scale a time value
 *
 * \param left  Left operand (a number)
 * \param right Right operand (a time)
 *
 * \return \a left multiplied by \a right
 */
Time operator * (Int64 left, Time right);

/**
 * \relates Time
 * \brief Overload of binary *= operator to scale/assign a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left multiplied by \a right
 */
Time& operator *= (Time& left, float right);

/**
 * \relates Time
 * \brief Overload of binary *= operator to scale/assign a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left multiplied by \a right
 */
Time& operator *= (Time& left, Int64 right);

/**
 * \relates Time
 * \brief Overload of binary / operator to scale a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left devided by \a right
 */
Time operator / (Time left, float right);

/**
 * \relates Time
 * \brief Overload of binary / operator to scale a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left devided by \a right
 */
Time operator / (Time left, Int64 right);

/**
 * \relates Time
 * \brief Overload of binary /= operator to scale/assign a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left devided by \a right
 */
Time& operator /= (Time& left, float right);

/**
 * \relates Time
 * \brief Overload of binary /= operator to scale/assign a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a number)
 *
 * \return \a left devided by \a right
 */
Time& operator /= (Time& left, Int64 right);

/**
 * \relates Time
 * \brief Overload of binary / operator to compute the ratio of two time values
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return \a left devided by \a right
 */
float operator / (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of binary % operator to compute remainder of a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return \a left modulo \a right
 */
Time operator % (Time left, Time right);

/**
 * \relates Time
 * \brief Overload of binary %= operator to compute/assign remainder of a time value
 *
 * \param left  Left operand (a time)
 * \param right Right operand (a time)
 *
 * \return \a left modulo \a right
 */
Time& operator %= (Time& left, Time right);
	
}; // namespace cr

#endif // __CRCR_TIME_HPP__


/**
 * \brief How to Use
 *
 * \code
 * cr::Time t1 = cr::seconds(0.1f);
 * Int32 milli = t1.asMilliseconds(); // 100
 *
 * cr::Time t2 = cr::milliseconds(30);
 * Int64 micro = t2.asMicroseconds(); // 30000
 *
 * cr::Time t3 = cr::microseconds(-800000);
 * float sec = t3.asSeconds(); // -0.8
 * \endcode
 *
 * \code
 * void update(cr::Time elapsed)
 * {
 *    position += speed * elapsed.asSeconds();
 * }
 *
 * update(cr::milliseconds(100));
 * \endcode
 *
 * \see cr::Clock
 */
