#include "q.h"

#include <iostream>
#include <stack>
#include <vector>
#include <map>
// Implement each function of `q.h` here.

bool CPPLib::CheckValidExpression(const std::string& input) {
    std::stack<char> brackets_input;
    if(input.length() == 0) { return true; }
    if (input.length() == 1) { return false; }

    for (auto n : input) {
        if (n == ')' || n == ']' || n == '}') {
            if(brackets_input.size() == 0 ) return false;
            if(n == '}' && brackets_input.top() != '{') {return false;}
            if(n == ')' && brackets_input.top() != '(') {return false;}
            if(n == ']' && brackets_input.top() != '[') {return false;}
            brackets_input.pop();
        }
        else if (n != ')' && n != ']' && n != '}' && n != '(' && n != '[' && n != '{') {
            continue;
        }
        else { 
            brackets_input.push(n);
        }
    }
    if (brackets_input.size() == 0) {return true;}
    return false; 
}


  bool CPPLib::IsPalindrome(const std::string& input) {
      int half_length = input.size() / 2;
      for (int i = 0; i < half_length; i++) {
          if (input[i] != input[input.size() - i - 1]) {
              return false;
          } 
      }
      return true; 
  }


  int CPPLib::OddChar(const std::string& input) {
      int result = 0;
      for (int i = 0; i < input.size(); i++) {
          result = (result ^ input[i]);
          std::cout << result << std::endl; 
      }

      return result; 
  }
