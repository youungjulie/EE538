#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Student, Test1) {
    Student LY("Longhao Yang", 99);
    Student WW("William Wang", 96);
    Student KK("KK lul", 80);
    Student Think("Thinking C++", 99);

    EXPECT_EQ(LY > WW, true);
    EXPECT_EQ(LY < WW, false);
    EXPECT_EQ(Think == LY, true);
}

TEST(StudentMaxHeap, Test2) {
    Student LY("Longhao Yang", 99);
    Student WW("William Wang", 96);
    Student KK("KK lul", 80);
    Student Think("Thinking C++", 100);
    Student WW_2("William Wang 2", 150);


    std::vector<Student> students;
    students.push_back(LY);
    students.push_back(WW);
    students.push_back(KK);
    students.push_back(Think);
    students.push_back(WW_2);


    StudentMaxHeap stu_max_heap(students);

    // size()
    EXPECT_EQ(stu_max_heap.size(), 5);
    // top()
    EXPECT_EQ(stu_max_heap.top(), WW_2);
    // pop()
    EXPECT_EQ(stu_max_heap.pop(), true);
    EXPECT_EQ(stu_max_heap.top(), Think);
    EXPECT_EQ(stu_max_heap.size(), 4);


    // push()
    Student Youngjulie("Youngjulie", 200);
    stu_max_heap.push(Youngjulie);
    EXPECT_EQ(stu_max_heap.size(), 5);
    EXPECT_EQ(stu_max_heap.top(), Youngjulie);

}


TEST(HeapSort, Test1) {
    Student LY("Longhao Yang", 99);
    Student WW("William Wang", 96);
    Student KK("KK lul", 80);
    Student Think("Thinking C++", 100);
    Student WW_2("William Wang 2", 150);


    std::vector<Student> students;
    students.push_back(LY);
    students.push_back(WW);
    students.push_back(KK);
    students.push_back(Think);
    students.push_back(WW_2);

    // HeapSort()
    HeapSort(students);
    std::vector<Student> expect = {KK, WW, LY, Think, WW_2};
    EXPECT_EQ(students, expect);

}