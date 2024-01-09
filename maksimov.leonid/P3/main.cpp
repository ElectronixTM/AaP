#include <iostream>
#include "comparison.hpp"
#include "delvow.hpp"
#include "newarr.hpp"

int main()
{
  char* str = 0;
  try
  {
    str = newarr(std::cin);
  }
  catch (const std::exception& ex)
  {
    std::cerr << "Could not read an element of the string\n";
    return 1;
  }
  for (size_t i = 0; i < strlen(str) + 1; i++)
  {
    std::cout << str[i] << '\t' << int(str[i]) << '\t' << i << '\n';
  }
  std::cout << "[HAS-SAM]: " << arr::comparison(str, strlen(str), "abc") << '\n';
  arr::delVow(str, strlen(str));
  std::cout << "[RMV-VOW]: ";
  for (size_t i = 0; i < strlen(str); i++)
  {
    std::cout << str[i];
  }
  delete[] str;
  return 0;
}
