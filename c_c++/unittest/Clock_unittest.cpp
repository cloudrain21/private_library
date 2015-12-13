#include <Clock.hpp>
#include <gtest/gtest.h>


/**
 * constructor test
 */
TEST(ClockTest, constructorTest)
{
    Clock   c;
    Clock * c1 = new Clock();

    delete c1;
}
