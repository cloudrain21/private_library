#include <String.hpp>
#include <Utf.hpp>
#include <cstring>
#include <gtest/gtest.h>


TEST(StringTest, ConstructorDefault)
{
    const cr::String s;
    EXPECT_EQ(0, s.getSize());
}

TEST(StringTest, ConstructorAnsiChar)
{
    const char * ansiChar = "A";
    cr::String s(*ansiChar);

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( ansiChar, s.toAnsiString().c_str() );

    std::string locstr = "ko_KR.UTF-8";
    std::locale loc(locstr);
    cr::String s1(*ansiChar, loc);

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( ansiChar, s1.toAnsiString().c_str() );
    EXPECT_STREQ( loc.name().c_str(), locstr.c_str() );
}

