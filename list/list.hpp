#pragma once

#include <iostream> // for throw

template <typename T>
struct Node {
    Node* prev_;
    Node* next_;

    T obj_;

    Node() : prev_(nullptr), next_(nullptr) {};
    Node(const T& obj) : prev_(nullptr), next_(nullptr), obj_(obj) {}
};

template <typename T>
class List {
private:
    Node<T>* head_;
    Node<T>* tail_;

public:
    // Default constructor
    List() : head_(nullptr), tail_(nullptr) {}

    // Constructor with parameters
    List(const T& obj) {
        head_ = new Node<T>(obj);
        tail_ = head_;
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
    // O(1)
    T& front() {
        if (is_empty()) {
            throw std::out_of_range("Empty");
        }
            return head_->obj_;
    }

    // Get last object
    // O(1)
    T& back() {;
        if (is_empty()) {
            throw std::out_of_range("Empty");
        }
        return tail_->obj_;
    }

    // Empty check
    bool is_empty() {
        return head_ == nullptr;
    }

    // Insert element at end
    // O(1)
    void push_back(const T& obj) {
        if (is_empty()) {
            head_ = new Node<T>(obj);
            tail_ = head_;
        } else if (head_ == tail_) {
            tail_ = new Node<T>(obj);
            head_->next_ = tail_;
            tail_->prev_ = head_;
        } else {
            Node<T>* new_node = new Node<T>(obj);
            new_node->prev_ = tail_;
            tail_->next_ = new_node;
            tail_ = new_node;
        }
    }
};