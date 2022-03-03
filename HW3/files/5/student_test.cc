#include <iostream>
#include <string>


#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, Copy_vector) {
    std::vector<int> vec_1 = {1, 2, 3, 4};
    SinglyLinkedList sll  = vec_1;
    sll.print();
    std::cout << std::endl;

    // check size
    EXPECT_EQ(sll.size(), 4);
}

TEST(SinglyLinkedList, Copy_constructor) {
    // Check push_back
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);

    SinglyLinkedList sll  = sll_1;
    sll.print();
    std::cout << std::endl;
    sll_1.print();
    std::cout << std::endl;


    std::vector<int> v1 = sll_1.convert_to_vector();
    std::vector<int> v = sll.convert_to_vector();

    // Check size()
    EXPECT_EQ(sll.size(), 5);
    // Check convert_to_vector()
    EXPECT_EQ(v1, v);

}

TEST(SinglyLinkedList, Empty) {
    SinglyLinkedList sll_1; 
    EXPECT_EQ(sll_1.empty(), true);

    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    EXPECT_EQ(sll_1.empty(), false);

}

TEST(SinglyLinkedList, Pushback) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    EXPECT_EQ(sll_1.size(), 5);

}

TEST(SinglyLinkedList, Popback) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    while (sll_1.size() > 0) {
        bool pop = sll_1.pop_back();
        sll_1.print();
        std::cout << std::endl;
        EXPECT_EQ(pop, true);
    }

    bool pop_error = sll_1.pop_back();
    EXPECT_EQ(pop_error, false);

    EXPECT_EQ(sll_1.size(), 0);

}


TEST(SinglyLinkedList, back) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    EXPECT_EQ(sll_1.back(), 1);

}

TEST(SinglyLinkedList, Get_back_pointer) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    ListNode* last_node = sll_1.GetBackPointer();
    int last_node_val = sll_1.GetPointerValue(last_node);
    EXPECT_EQ(last_node_val, sll_1.back());
}

TEST(SinglyLinkedList, Get_ith_pointer) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    ListNode* last_node = sll_1.GetIthPointer(3);
    int last_node_val = sll_1.GetPointerValue(last_node);
    EXPECT_EQ(last_node_val, 2);
}

TEST(SinglyLinkedList, Operator) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    sll_1.print();
    std::cout << std::endl;

    int& val = sll_1[3];
    EXPECT_EQ(val, 2);
}

TEST(SinglyLinkedList, Erase) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(3);
    sll_1.push_back(2);
    sll_1.push_back(1);
    std::vector<int> v_origin = sll_1.convert_to_vector();

    sll_1.print();
    std::cout << std::endl;

    sll_1.erase(2);
    sll_1.print();
    std::cout << std::endl;

    std::vector<int> v_erase = sll_1.convert_to_vector();
    std::vector<int> test = {5, 4, 2, 1};
    EXPECT_EQ(v_erase, test);

    sll_1.erase(0);
    sll_1.print();
    std::cout << std::endl;

    std::vector<int> v_erase_2 = sll_1.convert_to_vector();
    std::vector<int> test2 = {4, 2, 1};
    EXPECT_EQ(v_erase_2, test2);
}


TEST(SinglyLinkedList, Remove_duplicates) {
    SinglyLinkedList sll_1; 
    sll_1.push_back(5);
    sll_1.push_back(4);
    sll_1.push_back(4);
    sll_1.push_back(2);
    sll_1.push_back(5);
    sll_1.print();
    std::cout << std::endl;

    sll_1.remove_duplicates();
    std::vector<int> remove_dup = sll_1.convert_to_vector();
    std::vector<int> test3 = {5, 4, 2};

    EXPECT_EQ(remove_dup, test3);
}