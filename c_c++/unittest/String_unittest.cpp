#include <String.hpp>
#include <Utf.hpp>
#include <cstring>
#include <gtest/gtest.h>


/**
 * Default constructor
 */
TEST(StringTest, ConstructorDefault)
{
    const cr::String s;
    EXPECT_EQ(0, s.getSize());
}

/**
 * Construct from ANSI Character
 */
TEST(StringTest, ConstructorFromAnsiChar)
{
    const char * ansiChar = "A";
    cr::String s(*ansiChar);

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( ansiChar, s.toAnsiString().c_str() );

    //std::string locstr = "ko_KR.UTF-8";
    //std::locale loc(locstr);
    std::locale loc = std::locale();
    cr::String s1(*ansiChar, loc);

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( ansiChar, s1.toAnsiString().c_str() );
}

/**
 * Construct from Wide Character
 */
TEST(StringTest, ConstructorFromWideChar)
{
    wchar_t w = L'A';
    cr::String s(w);

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( "A", s.toAnsiString().c_str() );
}

/**
 * Construct from Utf32 Character
 */
TEST(StringTest, ConstructorFromUtf32Char)
{
    using cr::Utf32;
    using cr::String;

    const char ansiChar = 'A';
    String s( Utf32::decodeAnsi(ansiChar, std::locale()) );

    EXPECT_EQ( 1, s.getSize() );
    EXPECT_STREQ( "A", s.toAnsiString().c_str() );
}

/**
 * Construct from ANSI string
 */
TEST(StringTest, ConstructorFromAnsiString)
{
    const char * str = "This is a constructor from ansi string !!!";
    cr::String s(str);

    EXPECT_EQ( strlen(str), s.getSize() );
    EXPECT_STREQ( str, s.toAnsiString().c_str() );
}

/**
 * Construct from std::string 
 */
TEST(StringTest, ConstructorFromStdString)
{
    std::string str("This is a constructor from ansi string !!!");
    std::locale loc = std::locale();
    cr::String s(str, loc);

    EXPECT_EQ( str.length(), s.getSize() );
    EXPECT_STREQ( str.c_str(), s.toAnsiString().c_str() );
}

/**
 * Construct from Wide string
 */
TEST(StringTest, ConstructorFromWideString)
{
    const char    * astr =  "This is a constructor from ansi string !!!";
    const wchar_t * wstr = L"This is a constructor from ansi string !!!";

    cr::String s(wstr);

    EXPECT_EQ( wcslen(wstr), s.getSize() );
    EXPECT_STREQ( astr, s.toAnsiString().c_str() );
}
