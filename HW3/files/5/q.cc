#include "q.h"

#include <iostream>
#include <vector>
#include <map>
// Implement each function of `q.h` here.

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v) {
    if (v.size() == 0) {
        head_ = nullptr;
        size_ = 0;
    }

    else {
        head_ = new ListNode(v[0]);
        size_ = 1;
        ListNode* current_node = head_;
        for (long unsigned int i = 1; i < v.size(); i++) {
            current_node->next =  new ListNode(v[i]);
            current_node = current_node->next;
            size_ ++;
        }
    }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs) {
    if (rhs.head_ != nullptr) {
        size_ = 1;
        ListNode* p1 = rhs.head_;
        ListNode* p2;
        ListNode* node = new ListNode(p1->val);
        head_ = node;
        p2 = head_;

        while (p1->next != nullptr) {
            p1 = p1->next;
            ListNode* node = new ListNode(p1->val);
            p2->next = node;
            p2 = node;
            size_ ++;
        }
    }
}

bool SinglyLinkedList::empty() {
    if (head_ == nullptr) {
        return true;
    }

    else {return false; }
}

int SinglyLinkedList::size() {
    return size_; 

    // int count = 0;
    // if (head_ == nullptr) {
    //     return count;
    // }
    // else {
    //     ListNode* p = head_;
    //     while (p != nullptr) {
    //         p = p->next;
    //         count ++;
    //     }
    //     return count;
    // }
}

ListNode* SinglyLinkedList::head() {
    return head_;
}

void SinglyLinkedList::push_back(int i) {
    if (head_ == nullptr) {
        head_ =  new ListNode(i);
        size_ = 1;
        return;
    }

    ListNode* p = head_;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next =  new ListNode(i);
    size_ ++;
    return;
}

bool SinglyLinkedList::pop_back() {
    if (head_ == nullptr) {
        return false;
    }

    else if (size_ == 1) {
        head_ = nullptr;
        size_ -= 1;
        return true;
    }

    ListNode* last = nullptr;
    ListNode* current = head_;
    while (current->next != nullptr) {
        last = current;
        current = current->next;
    }

    last->next = nullptr;
    delete [] current;
    size_ -= 1;
    return true;
}

int SinglyLinkedList::back() {
    if (head_ == nullptr) {
        return -1;
    }

    ListNode* node = nullptr;
    ListNode* current = head_;
    while (current != nullptr) {
        node = current;
        current = current->next;
    }
    return node->val;
}

ListNode* SinglyLinkedList::GetBackPointer() {
    if (head_ == nullptr) {
        return nullptr;
    }

    ListNode* node = nullptr;
    ListNode* current = head_;
    while (current != nullptr) {
        node = current;
        current = current->next;
    }
    return node;
}

int SinglyLinkedList::GetPointerValue(ListNode* node) {
    return node->val;
}


ListNode* SinglyLinkedList::GetIthPointer(int i) {
    if (head_ == nullptr) {
        return nullptr;
    }

    int count = 0;
    ListNode* current = head_;
    while (count < i && current->next != nullptr) {
        current = current->next;
        count ++;
    }
    return current; //when i is greater than the length, return nullptr
}

int& SinglyLinkedList::operator[](int i) {
    minus_1_ = -1;
    if (head_ == nullptr) {
        return minus_1_;
    }

    int count = 0;
    ListNode* current = head_;
    while (count < i && current->next != nullptr) {
        current = current->next;
        count ++;
    }

    if (count < i) {
        return minus_1_;
    }
    else {
        return current->val; 
    }
}

void SinglyLinkedList::print() {
    ListNode* current = head_;
    while (current != nullptr) {
        std::cout << current->val << "->";
        current = current->next;
    }
}

std::vector<int> SinglyLinkedList::convert_to_vector() {
    std::vector<int> vec;
    ListNode* current = head_;
    while (current != nullptr) {
        vec.push_back(current->val);
        current = current->next;
    }
    return vec;
}

ListNode* SinglyLinkedList::erase(int i) {
    if (i == 0) {
        head_ = head_->next;
        size_ -= 1;
        return nullptr;
    }


    ListNode* last_node = nullptr;
    ListNode* current = head_;
    ListNode* next_node = nullptr;
    int count = 0;
    while (count < i && current->next != nullptr) {
        last_node = current;
        current = current->next;
        next_node = current->next;
        count ++;
    }

    if (count == i) {
        last_node->next = next_node;
        delete [] current;
        size_ --;
        return last_node;
    }

    else {return nullptr; }
}

void SinglyLinkedList::remove_duplicates() {
    std::map<int, bool> value_map;
    ListNode* last = nullptr;
    ListNode* current = head_;
    ListNode* garbage = nullptr;

    while (current != nullptr) {
        auto it = value_map.find(current->val);
        if (it == value_map.end()) {
            value_map[current->val] = true;
            last = current;
            current = current->next;
        }
        else if (it->second == true) {
            last->next = current->next;
            garbage = current; 
            current = last->next;
            delete [] garbage;
            size_ -= 1; 
            (*this).print();
            std::cout << std::endl;
        }
    }
    return;
}
