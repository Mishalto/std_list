#pragma once

#include <stdexcept> // for throw

template <typename T>
struct Node {
    Node* prev_;
    Node* next_;

    T obj_;

    Node() : prev_(nullptr), next_(nullptr) {}
    Node(const T& obj) : prev_(nullptr), next_(nullptr), obj_(obj) {}
};

template <typename T>
class List {
private:
    Node<T>* head_;
    Node<T>* tail_;

    size_t size_;
public:
    // Default constructor
    List() : head_(nullptr), tail_(nullptr), size_(0) {}

    // Constructor with parameters
    List(const T& obj) : size_(1) {
        head_ = new Node<T>(obj);
        tail_ = head_;
    }

    // Destructor, no leak
    // valgrind --leak-check=full ./list    ulimit -n 65536(descriptor error)
    // Best: O(1), Overrall O(n)
    ~List() {
        Node<T> *curr = head_;
        while (curr != nullptr) {
            Node<T> *temp = curr->next_;
            delete curr;
            curr = temp;
        }
    }

    // Destruct list
    void clear() {
        Node<T>* curr = head_;
        while (curr != nullptr) {
            Node<T>* temp = curr->next_;
            delete curr;
            curr = temp;
        }

        head_->next_ = nullptr;
        head_ = nullptr;
        size_ = 0;
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
    T& back() {
        if (is_empty()) {
            throw std::out_of_range("Empty");
        }
        return tail_->obj_;
    }

    // Empty check
    bool is_empty() {
        return size_ == 0;
    }

    // Return list size
    size_t size() {
        return size_;
    }

    // Insert element at end
    // O(1)
    void push_back(const T& obj) {
        Node<T>* new_node = new Node<T>(obj);
        if (is_empty()) {
            head_ = new_node;
            tail_ = head_;
        } else {
            new_node->prev_ = tail_;
            tail_->next_ = new_node;
            tail_ = new_node;
        }
        size_ += 1;
    }

    // Delete last element
    // O(1)
    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Try to pop_back on empty_list");
        }

        if (size_ > 2) {
            Node<T>* temp = tail_->prev_;
            delete tail_;
            tail_ = temp;
            tail_->next_ = nullptr;
        } else if (size_ == 2) {
            delete tail_;
            head_->next_ = nullptr;
            head_->prev_ = nullptr;
            tail_ = head_;
        } else if (size_ == 1) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
        }
        size_-= 1;
    }

    // Push element to head
    // 0(1)
    void push_front(const T& obj) {
        Node<T>* new_node = new Node<T>(obj);
        if (is_empty()) {
            head_ = new_node;
            tail_ = head_;
        } else {
            new_node->next_ = head_;
            head_->prev_ = new_node;
            head_ = new_node;
        }
        size_ += 1;
    }

    // Delete first element
    // O(1)
    void pop_front() {
        if (is_empty()) {
            throw std::out_of_range("Empty");
        }

        if (size_ == 1) {
            delete head_;
            head_ = nullptr;
            tail_ = nullptr;
        } else if (size_ == 2) {
            tail_->prev_ = nullptr;
            delete head_;
            head_ = tail_;
        } else {
            Node<T>* temp = head_->next_;
            delete head_;
            head_ = temp;
            head_->prev_ = nullptr;
        }
        size_ -= 1;
    }
};