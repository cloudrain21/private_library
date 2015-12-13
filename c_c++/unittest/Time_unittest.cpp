#include <Time.hpp>
#include <gtest/gtest.h>


/**
 * Default constructor
 */
TEST(StringTest, ConstructorDefault)
{
    cr::Time t = cr::seconds(0.1f);
    cr::Int32 milli = t.asMilliseconds();

    EXPECT_EQ( 100, milli );
}
