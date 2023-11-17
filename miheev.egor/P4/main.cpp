// #include "functions.hpp"
#include "structs.hpp"
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
  try
  {
    // checking params
    using namespace miheev;
    if (argc != 4)
    {
      throw std::invalid_argument("wrong arguments. Programm takes 3 positional");
    }
    //initing params
    long long num = 0;
    try
    {
      num = std::stoll(argv[1]);
    }
    catch(const std::invalid_argument& e)
    {
      std::cerr << "can't interpret first argument as integer\n";
      return 1;
    }

    size_t cols = 0, rows = 0;

    // reading matrix from file
    std::ifstream inputFile(argv[2]);
    inputFile >> rows >> cols;
    if (!inputFile)
    {
      std::cerr << "Can't read input\n";
      return 2;
    }
    Matrix* matrix = new Matrix(rows, cols, num);
    try
    {
      (*matrix).initWithIfstream(inputFile);
    }
    catch(const std::runtime_error& e)
    {
      delete matrix;
      std::cerr << e.what();
      return 2;
    }
    catch(...)
    {
      std::cerr << "unexpected error occured\n";
      delete matrix;
      return 2;
    }
    inputFile.close();

    (*matrix).increasePeriphery();

    std::ofstream outFile(argv[3]);
    if (outFile.is_open())
    {
      outFile << std::to_string((*matrix).getNRows()) + ' ' + std::to_string((*matrix).getNCols()) + ' ' + (*matrix).getMatrixInline();
    }

    delete matrix;

    return 0;
  }
  catch(const std::logic_error& logic_e)
  {
    std::cerr << logic_e.what();
    return 1;
  }
  catch(const std::runtime_error& e)
  {
    std::cout << e.what();
    return 2;
  }
}