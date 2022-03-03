#include <iostream>
#include <string>

class CPPLib {
 public:
  // Returns the index of the first space character in a string.
  int IndexOfFirstSpace(std::string& input);

  // Given the full_name, it returns the first_name and last_name.
  // Note: you should use IndexOfFirstSpace function and cannot use any other
  // std:: functions.
  void SeparateFirstAndLastNames(std::string& full_name,
                                 std::string& first_name,
                                 std::string& last_name);

  // Returns the number of vowles (a, e, i, o, u) in a string.
  int NumberOfVowels(std::string& input);

  // Returns the number of consonants (letters that are not a, e, i, o, u) in a
  // string.
  int NumberOfConsonants(std::string& input);

  // Returns the reverse of a string.
  // Example input: 'ted', output: 'det'.
  // Note: You cannot use any std:: functions.
  int Reverse(std::string& input);
};
