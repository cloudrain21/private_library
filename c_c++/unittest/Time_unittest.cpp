#include <Time.hpp>
#include <gtest/gtest.h>


/**
 * constructor test
 */
TEST(TimeTest, constructorTest)
{
    cr::Time t;
    EXPECT_TRUE( t == cr::Time::Zero );

    cr::Time t1 = cr::seconds(0);
    EXPECT_TRUE( t1 == cr::Time::Zero );

    t1 = cr::milliseconds(0);
    EXPECT_TRUE( t1 == cr::Time::Zero );

    t1 = cr::microseconds(0);
    EXPECT_TRUE( t1 == cr::Time::Zero );
}

/**
 * basic usage of Time class
 */
TEST(TimeTest, basicFunction)
{
    cr::Time t = cr::seconds(0.1f);
    cr::Int32 milli = t.asMilliseconds();

    EXPECT_EQ( 100, milli );

    t = cr::milliseconds(30);
    cr::Int64 micro = t.asMicroseconds();

    EXPECT_EQ( 30000, micro );

    t = cr::microseconds(800000);
    cr::Time t1 = cr::milliseconds(800);

    EXPECT_EQ( t.asSeconds(), t1.asSeconds() );
}

/**
 * operator for comparison
 */
TEST(TimeTest, operatorComparison)
{
    cr::Time t1 = cr::seconds(0.1f);
    cr::Time t2 = cr::milliseconds(100);

    EXPECT_TRUE( t1 == t2 );
    EXPECT_TRUE( t1 >= t2 );
    EXPECT_TRUE( t1 <= t2 );
    EXPECT_FALSE( t1 != t2 );
    EXPECT_FALSE( t1 > t2 );
    EXPECT_FALSE( t1 < t2 );

    t1 = cr::seconds(0.2f);
    t2 = cr::microseconds(100000);  /**< 0.1 sec */

    EXPECT_FALSE( t1 == t2 );
    EXPECT_TRUE( t1 >= t2 );
    EXPECT_FALSE( t1 <= t2 );
    EXPECT_TRUE( t1 != t2 );
    EXPECT_TRUE( t1 > t2 );
    EXPECT_FALSE( t1 < t2 );
}

/**
 * operator plus & minus
 */
TEST(TimeTest, operatorPlusMinus1)
{
    cr::Time t1 = cr::seconds(2);
    cr::Time t2 = cr::seconds(-2);

    EXPECT_TRUE( -t1 == t2 );
    EXPECT_TRUE( t1 == -t2 );

    EXPECT_TRUE( cr::Time::Zero == (t1 + t2) );
    EXPECT_TRUE( cr::Time::Zero == (t1 + t2) );
    EXPECT_EQ( cr::seconds(4), (t1 - t2) );

    t1 = cr::milliseconds(100);
    t2 = cr::milliseconds(200);

    EXPECT_TRUE( cr::milliseconds(300) == (t1 + t2) );
    EXPECT_TRUE( t1 == (t2 - t1) );

    t1 = cr::microseconds(100);
    t2 = cr::microseconds(200);

    EXPECT_TRUE( cr::microseconds(300) == (t1 + t2) );
}

/**
 * operator plus & minus
 */
TEST(TimeTest, operatorPlusMinus2)
{
    cr::Time t1 = cr::seconds(2);
    cr::Time t2 = cr::seconds(3);

    cr::Time t3;

    t3 += t1;
    EXPECT_EQ( 2, t3.asSeconds() );

    t3 += t2;
    EXPECT_EQ( 5, t3.asSeconds() );

    t3 -= t2;
    EXPECT_EQ( 2, t3.asSeconds() );

    t3 -= t1;
    EXPECT_EQ( 0, t3.asSeconds() );
}

/**
 * operator multiply & divide
 */
TEST(TimeTest, operatorMultiplyDivide)
{
    cr::Time t1 = cr::seconds(2);
    cr::Time t2;

    t2 = t1 * static_cast<cr::Int64>(3);
    EXPECT_EQ( 6, t2.asSeconds() );

    t2 = t1 * static_cast<float>(3);
    EXPECT_EQ( 6, t2.asSeconds() );

    t2 = 3.0f * t1;
    EXPECT_EQ( 6, t2.asSeconds() );

    t2 = static_cast<cr::Int64>(3) * t1;
    EXPECT_EQ( 6, t2.asSeconds() );

    t2 = cr::seconds(3);
    t2 *= 2.0f;
    EXPECT_EQ( 6, t2.asSeconds() );

    t2 = cr::seconds(3);
    t2 *= static_cast<cr::Int64>(2);
    EXPECT_EQ( 6, t2.asSeconds() );

    t1 = cr::seconds(10.0f);
    t2 = t1 / 2.0f;
    EXPECT_EQ( 5, t2.asSeconds() );

    t1 = cr::seconds(10.0f);
    t2 = t1 / static_cast<cr::Int64>(2);
    EXPECT_EQ( 5, t2.asSeconds() );

    t2 = cr::seconds(10.0f);
    t2 /= 2.0f;
    EXPECT_EQ( 5, t2.asSeconds() );

    t2 = cr::seconds(10.0f);
    t2 /= static_cast<cr::Int64>(2);
    EXPECT_EQ( 5, t2.asSeconds() );

    t1 = cr::seconds(10.0f);
    t2 = cr::seconds(2.0f);
    EXPECT_EQ( 5, t1 / t2 );
}

/**
 * operator modular
 */
TEST(TimeTest, operatorModular)
{
    cr::Time t1 = cr::seconds(10);
    cr::Time t2 = cr::seconds(2);
    cr::Time t3 = cr::seconds(3);
    cr::Time t4 = cr::seconds(10);

    EXPECT_EQ( 0, (t1 % t2).asSeconds() );
    EXPECT_EQ( 1, (t1 % t3).asSeconds() );
    EXPECT_EQ( (t1 % t2).asSeconds(), (t4 %= t2).asSeconds() );
}
