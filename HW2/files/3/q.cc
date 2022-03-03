#include "q.h"

Operation add = Operation::add;
Operation subtract = Operation::subtract;

// Given two integers, returns the result of the operation based on the given
// operator.
float CPPLib::Calculate(int a, int b, Operation operation) {
    switch (operation) {
        case Operation::add: 
            return a + b;
        case Operation::subtract:
            return a - b; 
        case Operation::multiplication:
            return a * b;   
        case Operation::division:
            return a / (float)b;
        case Operation::bitwise_AND:
            return a & b; 
        case Operation::bitwise_OR:
            return a | b; 
        case Operation::bitwise_XOR:
            return a ^ b; 
        case Operation::shift_left:
            return a << b;
        case Operation::shift_right:
            return a >> b;  
    }
    return 0;
}

