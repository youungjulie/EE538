#include <iostream>
#include "src/lib/cpplib.h"

int main() {
  // Print Hello world!
  CPPLib s;
  std::vector<int> arr_1 = {};

  std::cout << s.PrintIntro() << std::endl;
  std::cout << s.FindAverage(arr_1) << std::endl; 
  
  return 0;
}