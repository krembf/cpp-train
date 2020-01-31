// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include "vector-train.hpp"
#include "lambda-train.hpp"
#include "inheritance-train.hpp"
#include "template-train.hpp"
#include "variadic-template-train.hpp"
#include "tuple-train.hpp"

//! auto-generated include (using cmake)
#include "mainConfig.h"

int main(int argc, char *argv[])
{
  std::cout << "Hello World" << std::endl;

  if (argc < 2)
  {
    // report version
    std::string maj(cpp_train_VERSION_MAJOR);
    std::string min(cpp_train_VERSION_MINOR);
    std::cout << argv[0] << " Version " << maj << "." << min << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;

  lambdatrain::Ex0_abssort_using_lambda();
  lambdatrain::Ex1_using_various_capture_ways();
  lambdatrain::Ex2();
  lambdatrain::Ex3_higher_order_lambda();

  inheritancetrain::Ex0_VirtualFunctions();

  templatetrain::Ex0_TemplateWithDefaultArguments();
  templatetrain::Ex1_TemplateWithNonTypeArguments();

  variadictemplatetrain::Ex0_FuncWithVariousArgs();
  variadictemplatetrain::Ex1_CreateClassesViaFactory();

  tupletrain::Ex0_TupleWithTemplate();

  std::cout << "Press any key to exit ...";
  std::getchar();

  return 0;
}