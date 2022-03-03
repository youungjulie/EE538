#include <iostream>
#include <vector>

// Returns element at i index.
int ReturnElementI(std::vector<int>& input, int i) { 
  if (input.size() > i) {
    return input[i];
  }
  return -1;
}

// - What is wrong with each piece of code below?
// - For each case modify the code so that the issue is fixed:
int main() {
  // Question 1:
  {
    // Number of values to read from the input
    int number_of_items;
    std::cin >> number_of_items;
    std::vector<int> elements;

    // Reading elements from the input.
    for (int i = 0; i < number_of_items; i++) {
      int element;
      std::cin >> element;
      elements.push_back(element);
    }
  }

  // Cannot call elements[i], need to define length of vector at the beginning
  // The element variable cannot cin in this way. We need to use cin first to get the value of element, and then push it back to the vector elements

  // Question 2:
  {
    int* a = new int;
    std::cin >> (*a);
    (*a)++;
    std::cout << "(*a): " << (*a) << std::endl;
  }
  // we need to allocate memory to pointer a (new int)

  // Question 3:
  {
    int* a = new int;
    int* b = new int;
    std::cin >> (*a);
    std::cin >> (*b);

    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  }
  // Correct (remember to delete the memory)

  // Question 4:
  {
    int* a = new int;
    int* b = new int;
    std::cin >> (*a);
    std::cin >> (*b);
    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;

    (*a)++;  
    (*b)++;
    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;

    std::cin >> (*a);
    std::cin >> (*b);
    std::cout << "(*a) + (*b): " << (*a) + (*b) << std::endl;
  }
  // incorrect, this is an undefined behaviour

  // Question 5:
  {
    for (int i = 0; i < 10; i++) {
      std::cout << "i: " << i << std::endl;
      i = i + 1;
      std::cout << "i: " << i << std::endl;
    }
  }
// This is an infinite loop (i = i - 1)


  return 0;
}