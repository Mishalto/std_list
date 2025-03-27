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

    void get_info(Node<T>* nd) const {
        std::cout << "prev[" << (nd->prev_ != nullptr ? std::to_string(nd->prev_->obj_) : "nullptr") << "]\n";
        std::cout << "obj[" << nd->obj_ << "]\n";
        std::cout << "next[" << (nd->next_ != nullptr ? std::to_string(nd->next_->obj_) : "nullptr") << "]\n\n";
    }
};

template <typename T>
class List {
private:
    Node<T>* head_;

public:
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
            Node<T>* next = new Node<T>;
            next->obj_ = obj;
            curr->next_ = next;
            curr->next_->prev_ = curr;
        } else {
            head_ = new Node<T>;
            head_->obj_ = obj;
        }
    }
};