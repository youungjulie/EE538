#include "q.h"

#include <iostream>
#include <vector>
#include <algorithm>

// Parameterized constructor
Student::Student(std::string name_1, int grade_1)
{
    name = name_1;
    grade = grade_1;
}

// Non-parameterized constructor. Sets the default value for name to "NO_NAME"
// and grade to INT_MIN.
Student::Student()
{
    name = "NO_NAME";
    grade = INT16_MIN;
}

// Copy constructor.
Student::Student(const Student &rhs)
{
    name = rhs.name;
    grade = rhs.grade;
}

// The following operators are overloaded. They only compare the grade part of
// the class with other objects.

// Returns true if grade is less than the grade of other Student objects and
// false otherwise.
bool Student::operator<(const Student &rhs) const
{
    return grade < rhs.grade;
}

// Returns true if grade is greater than the grade of other Student objects
// and false otherwise.
bool Student::operator>(const Student &rhs) const
{
    return grade > rhs.grade;
}

// Returns true if grade is equal to the grade of other Student objects and
// false otherwise.
bool Student::operator==(const Student &rhs) const
{
    return grade == rhs.grade;
}

// A Max Heap that contains objects of type Student.
// We compare the students only based on their grade, not their names. That
// means the student with the highest grade should always be at the top of the
// heap.


// Parameterized constructor: creates a max heap from the given input.
StudentMaxHeap::StudentMaxHeap(std::vector<Student> &input) {
    ConvertToHeap(input);
}

// Returns the parent of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetParent(int i) {
    int p_index = GetParentIndex(i);
    if ( p_index != INT16_MAX) {
        return data_[p_index];
    }
    else {
        return Student("NO_NAME", INT16_MIN);
    }

}

// Returns the left child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetLeft(int i) {
    int p_index = GetLeftIndex(i);
    if ( p_index != INT16_MAX) {
        return data_[p_index];
    }
    else {
        return Student("NO_NAME", INT16_MIN);
    }
}

// Returns the right child of a node given its index in the tree. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::GetRight(int i) {
    int p_index = GetRightIndex(i);
    if ( p_index != INT16_MAX) {
        return data_[p_index];
    }
    else {
        return Student("NO_NAME", INT16_MIN);
    }
}

// Returns the index of the parent of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetParentIndex(int i) {
    if (i == 0) {
        return INT16_MAX;
    }
    return (i - 1)/2;
}


// Returns the index of the left child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLeftIndex(int i) {
    int max_index = data_.size() - 1;
    if ((2*i + 1) > max_index) {
        return INT16_MAX;
    }
    return 2 * i + 1;
}

// Returns the index of the right child of a node given its index in the tree.
// Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetRightIndex(int i) {
    int max_index = data_.size() - 1;
    if ((2*i + 2) > max_index) {
        return INT16_MAX;
    }
    return 2 * i + 2;
}

// Returns the index of the largest child of a node given its index in the
// tree. Returns INT_MAX if unsuccessful.
int StudentMaxHeap::GetLargestChildIndex(int i) {
    int result;
    Student left = GetLeft(i);
    Student right = GetRight(i);
    if (left > right) {
        result = GetLeftIndex(i);
    }
    else {
        result = GetRightIndex(i);
    }
    return result;
}

// Returns the top of the heap. Returns
// Student("NO_NAME", INT_MIN) if unsuccessful.
Student StudentMaxHeap::top() {
    if (data_.size() == 0) {
        return Student("NO_NAME", INT16_MAX);
    }
    else{
        return data_[0];
    }
}

// Adds a new Student to the heap.
void StudentMaxHeap::push(const Student &student) {
    data_.push_back(student);
    TrickleUp(data_.size() - 1);
}

// Removes the top. Returns
// true if successful and false otherwise.
bool StudentMaxHeap::pop() {
    if (data_.size() == 0) {
        return false;
    }
    data_[0] = data_[data_.size() - 1];
    data_.pop_back();
    TrickleDown(0);
    return true;
}

// Performs trickle up. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleUp(int i) {
    while (i > 0 && GetParent(i) < data_[i]) {
        std::swap(data_[GetParentIndex(i)], data_[i]);
        i = GetParentIndex(i);
    }
}

// Performs trickle down. It should use the overloaded operators of the Student
// class.
void StudentMaxHeap::TrickleDown(int i) {
    if (GetLeftIndex(i) > data_.size() && GetRightIndex(i) > data_.size()) {
        return; 
    }

    int largest_child_index = GetLargestChildIndex(i);

    if (data_[i] < data_[largest_child_index]) {
        std::swap(data_[i], data_[largest_child_index]);
        TrickleDown(largest_child_index);
    }
}

// Converts the given input into a max heap and stores that into data_.
void StudentMaxHeap::ConvertToHeap(const std::vector<Student> &input) {
    data_ = input;
    for (int i = data_.size() / 2; i >= 0; i--) {
        TrickleDown(i);
    }
}

// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades.
void HeapSort(std::vector<Student> &input) {
    int n = input.size();
    for (int i = (n/2) - 1; i >= 0; i--) {
        Heapify(input, i, n);
    }
    
    for (int m = n-1; m>0; m--) {
        std::swap(input[m], input[0]);
        Heapify(input, 0, m);
    }

    std::reverse(input.begin(), input.end());

}

void Heapify(std::vector<Student>& input, int i, int n) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ((l < n) && (input[l] < input[smallest])) {
        smallest = l;
    }

    if ((r < n) && (input[r] < input[smallest])) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(input[smallest], input[i]);
        Heapify(input, smallest, n);
    }

    
}