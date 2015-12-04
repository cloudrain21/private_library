#include <String.hpp>
#include <Utf.hpp>
#include <gtest/gtest.h>
#include <cstring>


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
    const char * str = "This is a constructor from ansi string !@#$.%^&*()";
    cr::String s(str);

    EXPECT_EQ( strlen(str), s.getSize() );
    EXPECT_STREQ( str, s.toAnsiString().c_str() );
}

/**
 * Construct from std::string 
 */
TEST(StringTest, ConstructorFromStdString)
{
    std::string str("This is a constructor from standard string !@#$.%^&*()");
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
    const char    * astr =  "This is a constructor from wide string !@#$.%^&*()";
    const wchar_t * wstr = L"This is a constructor from wide string !@#$.%^&*()";

    cr::String s(wstr);

    EXPECT_EQ( wcslen(wstr), s.getSize() );
    EXPECT_STREQ( astr, s.toAnsiString().c_str() );
}

/**
 * Construct from std::wstring reference
 */
TEST(StringTest, ConstructorFromStdWideStringRef)
{
    std::string str("This is a constructor from standard wide string !@#$.%^&*()");
    std::wstring wstr(L"This is a constructor from standard wide string !@#$.%^&*()");

    cr::String s(wstr);

    EXPECT_EQ( wstr.length(), s.getSize() );
    EXPECT_STREQ( str.c_str(), s.toAnsiString().c_str() );
}

/**
 * Construct from utf32 string
 */
TEST(StringTest, ConstructorFromUtf32String)
{
    std::string a("This is a test string !@#$.%^&*()");
    std::basic_string<cr::Uint32> str;

    cr::Utf32::fromAnsi( a.begin(),
                         a.end(),
                         std::back_inserter(str),
                         std::locale() );

    const cr::Uint32 * u = str.data(); 

    cr::String s(u);

    EXPECT_EQ( a.length(), s.getSize() );
    EXPECT_STREQ( a.c_str(), s.toAnsiString().c_str() );
}

/**
 * Construct from utf32 basic string reference
 */
TEST(StringTest, ConstructorFromUtf32BasicStringRef)
{
    std::string a("This is a test string !@#$.%^&*()");
    std::basic_string<cr::Uint32> str;

    cr::Utf32::fromAnsi( a.begin(),
                         a.end(),
                         std::back_inserter(str),
                         std::locale() );

    cr::String s(str);

    EXPECT_EQ( a.length(), s.getSize() );
    EXPECT_STREQ( a.c_str(), s.toAnsiString().c_str() );
}

/**
 * Copy constructor
 */
TEST(StringTest, CopyConstructor)
{
    cr::String s1("This is test string !@#$.%^&*()");
    cr::String s2(s1);

    EXPECT_EQ( s1.getSize(), s2.getSize() );
    EXPECT_STREQ( s1.toAnsiString().c_str(), s2.toAnsiString().c_str() );
}

/**
 * Implicit conversion operator to std::string
 */
TEST(StringTest, ImplicitConversionOperatorToStdString)
{
    cr::String s("This is a test !@#$%^&*().");
    std::string ss = s;  /* implicit conversion */

    EXPECT_EQ( ss.size(), s.getSize() );
    EXPECT_STREQ( ss.c_str(), s.toAnsiString().c_str() );
}

/**
 * Converting function to Ansi string
 */
TEST(StringTest, toAnsiString)
{
    std::string sstr("This is a test string !@#$%^&*().");
    std::wstring wstr(L"This is a test string !@#$%^&*().");
    cr::String s(wstr);
    std::string ss = s.toAnsiString();

    EXPECT_TRUE( s.toAnsiString().c_str() != nullptr );
    EXPECT_EQ( sstr.size(), ss.size() );
    EXPECT_STREQ( sstr.c_str(), ss.c_str() );
}

/**
 * Converting function to Wide string
 */
TEST(StringTest, toWideString)
{
    std::wstring s1(L"This is a test string !@#$%^&*().");
    cr::String s2(L"This is a test string !@#$%^&*().");

    EXPECT_TRUE( s1 == s2.toWideString() );
}

/**
 * Converting function to Utf16
 */
TEST(StringTest, toUtf16)
{
    const std::string org_str = "This is a test string !@#$%^&*().";
    std::basic_string<cr::Uint16> str16;
    std::basic_string<cr::Uint32> str32;

    cr::Utf32::toUtf16( org_str.begin(),
                        org_str.end(),
                        str16.begin() );

    cr::Utf16::toUtf32( str16.begin(),
                        str16.end(),
                        str32.begin() );

    cr::String s(str32);

    //std::cout << str32 << std::endl;

    //EXPECT_TRUE( str16 == s.toUtf16() );
    EXPECT_STREQ( org_str.c_str(), s.toAnsiString().c_str() );
}

/**
 * Converting function to Utf32
 */
TEST(StringTest, toUtf32)
{
    cr::String s1("This is a test string !@#$%^&*().");
    cr::String s2("This is a test string !@#$%^&*().");

    EXPECT_TRUE( s1.toUtf32() == s2.toUtf32() );
}
