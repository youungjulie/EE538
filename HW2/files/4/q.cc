#include <string>

#include "q.h"

// A function that capitalize the first letter of a string.
// If it was possible, returns true, otherwise false.
bool CPPLib::CapitalizeFirstLetter(std::string &input) {
    for (long unsigned int i = 0; i < input.length(); i++) {
        if (isalpha(input[i])) {
            input[i] = toupper(input[i]);
            return true;
        }
    }
    return false;
}
