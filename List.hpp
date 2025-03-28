#pragma once

#include <iostream>
#include <string>

template <typename T>
struct Node
{
    Node* prev_;
    Node* next_;

    T obj_;

    Node() : prev_(nullptr), next_(nullptr) {}
    Node(T obj) : prev_(nullptr), next_(nullptr), obj_(obj) {}
};

template <typename T>
class List {
private:
    Node<T>* head_;

    void get_info(Node<T>* nd) const {
        std::cout << "prev[" << (nd->prev_ != nullptr ? std::to_string(nd->prev_->obj_) : "nullptr") << "]\n";
        std::cout << "obj[" << nd->obj_ << "]\n";
        std::cout << "next[" << (nd->next_ != nullptr ? std::to_string(nd->next_->obj_) : "nullptr") << "]\n\n";
    }

public:
    List() {}

    List(T obj) {
        head_ = new Node<T>(obj);
    }

    void print_all_elem() const {
        Node<T>* curr = head_;
        while (curr != nullptr) {
            std::cout << curr->obj_ << " ";
            curr = curr->next_;
        }
    }

    void push_back(T obj) {
        if (head_ != nullptr) {
            Node<T>* curr = head_;
            while (curr->next_ != nullptr) {
                curr = curr->next_;
            }
            Node<T>* next = new Node<T>(obj);
            next->prev_ = curr;
            curr->next_ = next;
        } else {
            head_ = new Node<T>(obj);
            get_info(head_);
        }
    }
};