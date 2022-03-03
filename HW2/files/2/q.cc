#include "q.h"

#include <iostream>
#include <string>

// Returns the index of the fist space character in a string.
int CPPLib::IndexOfFirstSpace(std::string& input) {
    int length = input.size(); 
    for (int i=0; i < length; i++) {
        if (input[i] == ' ') {
            return i;
        }
    }
    return -1;  // If there is no space in the string, we return -1
}

// Given the full_name, it returns the first_name and last_name.
// Note: you should use IndexOfFirstSpace function and cannot use any other
// std:: functions.
void CPPLib::SeparateFirstAndLastNames(std::string& full_name,
                                       std::string& first_name,
                                       std::string& last_name) {
    CPPLib s;
    int length = full_name.length(); 
    int index = s.IndexOfFirstSpace(full_name);
    for (int i = 0; i < index;i++) {
        first_name.push_back(full_name[i]);
    }
    for (int j = index + 1; j < length; j++) {
        last_name.push_back(full_name[j]);
    }

    return;
    
                                       }

// Returns the number of vowles (a, e, i, o, u) in a string.
int CPPLib::NumberOfVowels(std::string& input) {
    int count = 0;
    std::string dic = "aeiou"; 
    for (auto n : input) {
        if (isalpha(n)) {
            for (auto letter : dic) {
                if (tolower(n) == letter) {
                    count += 1; 
                }
            }
        }
    }
    return count; 
}

// Returns the number of consonants (letters that are not a, e, i, o, u) in a
// string.
int CPPLib::NumberOfConsonants(std::string& input) {
    int count = 0;
    std::string dic = "aeiou"; 
    for (auto n : input) {
        int vowel = 0; 
        if (isalpha(n)) {
            for (auto letter : dic) {
                if (tolower(n) == letter) {vowel += 1; }
            }
            if (vowel == 0) {
                count += 1;
            }
        }
    }
    return count; 
}

// Returns the reverse of a string.
// Example input: 'ted', output: 'det'.
// Note: You cannot use any std:: functions.
int CPPLib::Reverse(std::string& input) {
    int half_length = input.size()/2;
    int length = input.size(); 
    for (int i = 0; i <= half_length; i++) {
        if (i == half_length) {continue; }
        char temp = input[i];
        input[i] = input[length - i - 1]; 
        input[length - i - 1] = temp; 
    }

    return 0; 
}

