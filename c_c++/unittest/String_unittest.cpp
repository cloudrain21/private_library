#include <String.hpp>
#include <Utf.hpp>
#include <gtest/gtest.h>
#include <cstring>

#include <iostream>
#include <exception>


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
    const std::string org_str("This is a test string !@#$%^&*().");
    cr::String s(org_str);

    std::basic_string<cr::Uint16> str1;
    str1 = s.toUtf16();

    std::basic_string<cr::Uint16> str2;
    str2.reserve( s.getSize() );
    cr::Utf16::fromAnsi( org_str.begin(),
                         org_str.end(),
                         std::back_inserter(str2) );

    EXPECT_TRUE( !memcmp( str1.c_str(), str2.c_str(), s.getSize() * 2 ) );
}

/**
 * Converting function to Utf32
 */
TEST(StringTest, toUtf32)
{
    const std::string org_str("This is a test string !@#$%^&*().");
    cr::String s(org_str);

    std::basic_string<cr::Uint32> str1;
    str1 = s.toUtf32();

    std::basic_string<cr::Uint32> str2;
    str2.reserve( s.getSize() );
    cr::Utf32::fromAnsi( org_str.begin(),
                         org_str.end(),
                         std::back_inserter(str2) );

    EXPECT_TRUE( !memcmp( str1.c_str(), str2.c_str(), s.getSize() * 2 ) );
}

/**
 * operator equal(=) : assign operator
 */
TEST(StringTest, assignOperator)
{
    cr::String s1("This is a test string !@#$%^&*().");
    cr::String s2;

    s2 = s1;

    EXPECT_STREQ( s1.toAnsiString().c_str(), s2.toAnsiString().c_str() );
}

/**
 * operator plus equal(+=) : plus assign operator
 */
TEST(StringTest, plusAssignOperator)
{
    cr::String org("This is a test string !@#$%^&*().");
    cr::String s1("This is a test");
    cr::String s2(" string !@#$%^&*().");

    s1 += s2;

    EXPECT_STREQ( org.toAnsiString().c_str(), s1.toAnsiString().c_str() );
}

/**
 * operator [] const
 */
TEST(StringTest, indexConstOperator)
{
    const std::string s1 = "This is a test string !@#$%^&*().";
    const cr::String  s2 = "This is a test string !@#$%^&*().";

    for(int i=0; i<s2.getSize(); ++i)
    {
        EXPECT_TRUE( cr::Utf32::decodeAnsi(s1[i]) == s2[i] );
    }
}

/**
 * operator [] 
 */
TEST(StringTest, indexOperator)
{
    std::string s1 = "This is a test string !@#$%^&*().";
    cr::String  s2 = "This is a test string !@#$%^&*().";

    for(int i=0; i<s2.getSize(); ++i)
    {
        EXPECT_TRUE( cr::Utf32::decodeAnsi(s1[i]) == s2[i] );
    }
}

/**
 * clear
 */
TEST(StringTest, clear)
{
    std::string s1 = "This is a test string !@#$%^&*().";
    cr::String  s2 = "This is a test string !@#$%^&*().";

    EXPECT_EQ( s1.size(), s2.getSize() );

    s2.clear();

    EXPECT_EQ( 0, s2.getSize() );
}

/**
 * getSize, size
 */
TEST(StringTest, getSize)
{
    std::string s1 = "This is a test string !@#$%^&*().";
    cr::String  s2 = "This is a test string !@#$%^&*().";

    EXPECT_EQ( s1.size(), s2.getSize() );
    EXPECT_EQ( s1.size(), s2.getSize() );

    s2.clear();

    EXPECT_EQ( 0, s2.getSize() );
    EXPECT_EQ( 0, s2.size() );
}

/**
 * isEmpty
 */
TEST(StringTest, isEmpty)
{
    cr::String  s1 = "This is a test string !@#$%^&*().";
    cr::String  s2;

    EXPECT_TRUE( ! s1.isEmpty() );

    s1.clear();

    EXPECT_TRUE( s1.isEmpty() );
    EXPECT_TRUE( s2.isEmpty() );
}

/**
 * erase
 */
TEST(StringTest, erase)
{
    std::string s1 = "This is a test string !@#$%^&*().";
    cr::String  s2 = "This is a test string !@#$%^&*().";

    s1.erase(0,4);
    s2.erase(0,4);
    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.erase(3);
    s2.erase(3);
    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.erase(0,100);
    s2.erase(0,100);
    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.clear();
    s2.clear();

    s1 = "This is a test string !@#$%^&*().";
    s2 = "This is a test string !@#$%^&*().";

    s1.erase(4,7);
    s2.erase(4,7);
    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.erase(5,100);
    s2.erase(5,100);
    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.clear();
    s2.clear();

    s1 = "This is a test string !@#$%^&*().";
    s2 = "This is a test string !@#$%^&*().";

    s1.erase(s1.begin(), s1.begin()+5);
    s2.erase(s2.begin(), s2.begin()+5);

    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.clear();
    s2.clear();

    s1 = "This is a test string !@#$%^&*().";
    s2 = "This is a test string !@#$%^&*().";

    s1.erase(s1.begin());
    s2.erase(s2.begin());

    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );

    s1.erase(s1.begin(), s1.end());
    s2.erase(s2.begin(), s2.end());

    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );
    EXPECT_TRUE( 0 == s1.size() );
    EXPECT_TRUE( 0 == s2.size() );

    s1.clear();
    s2.clear();

    s1 = "This is a test string !@#$%^&*().";
    s2 = "This is a test string !@#$%^&*().";

    /**< erase special characters */
    s1.erase(s1.end()-12, s1.end());
    s2.erase(s2.end()-12, s2.end());

    EXPECT_STREQ( s1.c_str(), s2.toAnsiString().c_str() );
}

/**
 * insert
 */
TEST(StringTest, insert)
{
    cr::String  s = "This is a test string !@#$%^&*().";
    cr::String  s1 = "This is !@#$%^&*().";
    cr::String  s2 = "a test string ";

    s1.insert(8, s2);

    EXPECT_TRUE( s.getSize() == s1.getSize() );
    EXPECT_STREQ( s.toAnsiString().c_str(), s1.toAnsiString().c_str() );

    s = "This is a test string.";
    s1 = "This is";
    s2 = " a test string.";

    s1.insert( s1.getSize(), s2 );

    EXPECT_TRUE( s.getSize() == s1.getSize() );
    EXPECT_STREQ( s.toAnsiString().c_str(), s1.toAnsiString().c_str() );

    s = "This is a test string.";
    s1 = L"This is";     /**< wide character */
    s2 = " a test string.";

    s1.insert( s1.getSize(), s2 );

    EXPECT_TRUE( s.getSize() == s1.getSize() );
    EXPECT_STREQ( s.toAnsiString().c_str(), s1.toAnsiString().c_str() );

    s = "This is a test string.";
    s1 = L"This is";         /**< wide character */
    s2 = L" a test string."; /**< wide character */

    s2.insert( 0, s1 );

    EXPECT_TRUE( s.getSize() == s2.getSize() );
    EXPECT_STREQ( s.toAnsiString().c_str(), s2.toAnsiString().c_str() );
}

/**
 * find
 */
TEST(StringTest, find)
{
    std::string s1 = "This is a test string !@#$%^&*().";
    cr::String  s2 = "This is a test string !@#$%^&*().";
    cr::String  find_str = "test";

    std::size_t pos1 = s1.find( find_str, 0 );
    std::size_t pos2 = s2.find( "test", 0 );

    EXPECT_EQ( pos1, pos2 );

    pos1 = s1.find( find_str, 4 );
    pos2 = s2.find( "test", 4 );

    EXPECT_EQ( pos1, pos2 );

    pos1 = s1.find( find_str );
    pos2 = s2.find( "test" );

    EXPECT_EQ( pos1, pos2 );
}

/**
 * replace a substring with another string
 */
TEST(StringTest, replace1)
{
    cr::String  s = "This is a test string !@#$%^&*().";
    cr::String  rr = "This is a replace string !@#$%^&*().";
    cr::String  r = "replace";
    cr::String  f;

    s.replace( 0, cr::String::InvalidPos, r );

    EXPECT_STREQ( s.toAnsiString().c_str(), r.toAnsiString().c_str() );

    s = "This is a test string !@#$%^&*().";
    r = "replace";

    s.replace( 10, 4, r );

    EXPECT_STREQ( s.toAnsiString().c_str(), rr.toAnsiString().c_str() );

    s = "This is a test string !@#$%^&*().";
    f = "test";
    r = "replace";

    std::size_t pos = s.find(f);

    s.replace( pos, 4, r );

    EXPECT_STREQ( s.toAnsiString().c_str(), rr.toAnsiString().c_str() );
}

/**
 * replace all occurrences of a substring with a replacement string
 */
TEST(StringTest, replace2)
{
}
