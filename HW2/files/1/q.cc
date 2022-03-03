#include <iostream>
#include <list>
#include <set>
#include <vector>

// Given two separate strings for first and last names, prints the full name.
void PrintFullName(std::string& first_name, std::string& last_name) {
  std::cout << "This is your full name, correct? " << std::endl; 
  std::cout << first_name << ' ' << last_name << std::endl;
  return; 
}

// Reads the first and last names from the input and stores them in fist_name
// and last_name.
void GetFullName(std::string& first_name, std::string& last_name) {
  std::cout << "Please enter your first name: " << std::endl;
  std::cin >> first_name;
  std::cout << "Please enter your last name: " << std::endl;
  std::cin >> last_name;
  return; 
}

int main() {
  std::string first_name, last_name;
  GetFullName(first_name, last_name);
  PrintFullName(first_name, last_name);
  return 0;
}