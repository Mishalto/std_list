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

public:
    // Default constructor
    List() : head_(nullptr) {}

    // Constructor with parameters
    List(T obj) {
        head_ = new Node<T>(obj);
    }

    // Destructor
    // valgrind --leak-check=full ./list
    // no leak
    ~List() {
        Node<T>* curr = head_;
        while (curr != nullptr) {
            Node<T>* temp = curr->next_;
            delete curr;
            curr = temp;
        }
    }

    // Get first object
    T& front() {
        if (head_ != nullptr) {
            return head_->obj_;
        } else {
            throw std::out_of_range("Empty");
        }
    }

    // Get last object 
    T& back() {
        if (head_ == nullptr) {
            throw std::out_of_range("Empty");
        }

        Node<T> *back = head_;
        while (back->next_ != nullptr) {
            back = back->next_;
        }

        return back->obj_;
    }

    // Empty check
    bool is_empty() {
        return head_ == nullptr;
    }

    // Insert element at end
    void push_back(T obj) {
        if (head_ == nullptr) {
            head_ = new Node<T>(obj);
            return;
        } else {
            Node<T>* new_node = new Node<T>(obj);

            Node<T>* curr = head_;
            while (curr->next_ != nullptr)
            {
                curr = curr->next_;
            }
            curr->next_ = new_node;
            curr->next_->prev_ = curr;
        }
    }
};