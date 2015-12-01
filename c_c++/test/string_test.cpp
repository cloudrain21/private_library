#include <String.hpp>
#include <iostream>
#include <string>

int main()
{
  cr::String s;
 
  std::string s1 = s;
  std::wstring s2 = s;
  s = "hello";
  s = L"hello";
  s += ' ';
  s += 'a';
  s += L'a';
 
  cr::String s3("world");
  std::cout << s.toAnsiString() << " " << s3.toAnsiString() << std::endl;

  std::string sss("sssssss");
  std::cout  << sss << std::endl;

  return 0;
}
