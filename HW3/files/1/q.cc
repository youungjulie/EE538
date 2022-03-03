#include "q.h"

#include <iostream>
#include <vector>

// Implement each function of `q.h` here.

// Creates an empty vector.
MyVector::MyVector() {
    size_ = 0;
    data_ = nullptr;
    error_ = ErrorCode::kNoError;
}
    
MyVector::MyVector(int size) {
    size_ = size;
    data_ = new int[size_];
    error_ = ErrorCode::kNoError;
}

 // Copy constructor.
MyVector::MyVector(const MyVector& rhs) {
    size_ = rhs.size();
    data_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        data_[i] = rhs.get_number(i);
    }
    error_ = ErrorCode::kNoError;
  }

// Destructor.
MyVector::~MyVector() {
    delete [] data_;
    error_ = ErrorCode::kNoError;
  }

// Get number
int MyVector::get_number(int index) const{
    return data_[index];
}

// Inserts the given value at the back of the vector.
void MyVector::push_back(int value) {

    // Expand the vector size by one. 
    int* new_data = new int[size_ + 1];
    for (int i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    delete [] data_;
    data_ = new_data;
    data_[size_] = value;
    size_ += 1;
    error_ = ErrorCode::kNoError;
    return;
  }

 // Removes and returns a value from the backs of the vector.
int MyVector::pop_back() {
    if (size_ == 0) {
      std::cout << "The vector is empty! Nothing to pop. " << std::endl;
      error_ = ErrorCode::kPopFromEmptyVector;
      return INT8_MAX;
    }

    else {
        int* new_data = new int[size_ - 1];
        for (int i = 0; i < size_ - 1; i++) {
            new_data[i] = data_[i];
        }
        int result = data_[size_ - 1]; 
        delete [] data_;
        data_ = new_data;
        size_ -= 1;
        error_ = ErrorCode::kNoError;
        return result;
    }
    
};


// Inserts the given value at the front of the vector.
void MyVector::push_front(int value) {
    int* new_data = new int[size_ + 1];
    new_data[0] = value;
    for (int i = 0; i < size_; i++) {
        new_data[i + 1] = data_[i];
    }
    delete [] data_;
    data_ = new_data;
    size_ += 1;
    error_ = ErrorCode::kNoError;
    return;
}

// Removes and returns a value from the front of the vector.
int MyVector::pop_front() {
    if (size_ == 0) {
      std::cout << "The vector is empty! Nothing to pop. " << std::endl;
      error_ = ErrorCode::kPopFromEmptyVector;
      return INT8_MAX;
    }

    int* new_data = new int[size_ - 1];
    for (int i = 1; i < size_; i++) {
        new_data[i - 1] = data_[i];
    }

    int result = data_[0]; 
    delete [] data_;
    data_ = new_data;
    size_ -= 1;
    error_ = ErrorCode::kNoError;
    return result;
}

// Inserts the given value after the given index.
void MyVector::insert(int value, int index) {
    if (index > size_ - 1|| index < 0) {
        error_ = ErrorCode::kIndexError;
        return;
    }
    else {
        int* new_data = new int[size_ + 1];
        for (int i = 0; i <= index; i++) {
            new_data[i] = data_ [i];
        }
        new_data[index + 1] = value;
        for (int i = index + 2; i < size_ + 1; i++) {
            new_data[i] = data_ [i - 1];
        }
        delete [] data_;
        data_ = new_data;
        size_ += 1;
        error_ = ErrorCode::kNoError;
        return;
    }
}

// Returns item at the given index.
int MyVector::at(int index) {
    if (index < 0 || index >= size_) {
        error_ = ErrorCode::kIndexError;
        return -1;
    }
    return data_[index];
}

// Returns the first index of the given item in the vector. Returns -1 if not
// found.
int MyVector::find(int item) {
    for (int i = 0; i < size_; i++) {
        if (data_[i] == item) {
            return i;
        }
    }
    error_ = ErrorCode::kNotFound;
    return -1;
}

// Returns the value of error_
ErrorCode MyVector::get_error() const {
    return error_;
}

// Returns the value of size_
int MyVector::size() const {
    return size_;
}

// Convert to std::vector. Used for testing.
std::vector<int> MyVector::ConvertToStdVector() {
    std::vector<int> vec(0);
    for (int i = 0; i < size_; i++) {
        vec.push_back(data_[i]);
    }
    return vec;
}