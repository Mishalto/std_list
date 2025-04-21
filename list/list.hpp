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

    // Return last element, complexity O(n)
    Node<T>* get_back() {
        Node<T>* back = head_;
        if (is_empty()) {
            throw std::out_of_range("Empty");
        } else {
            while (back->next_ != nullptr) {
                back = back->next_;
            }
        }

        return back;
    }

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
        if (head_ != nullptr) {
            return head_->obj_;
        } else {
            throw std::out_of_range("Empty");
        }
    }

    // Get last object
    // O(n)
    T& back() {
        Node<T>* back = get_back();

        return back->obj_;
    }

    // Empty check
    bool is_empty() {
        return head_ == nullptr;
    }

    // Insert element at end
    // O(n)
    void push_back(const T& obj) {
        if (is_empty()) {
            head_ = new Node<T>(obj);
        } else {
            Node<T>* new_node = new Node<T>(obj);

            Node<T>* back = get_back();
            back->next_ = new_node;
            back->next_->prev_ = back;
        }
    }
};