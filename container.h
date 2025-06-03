/*
    Egor Shastin st129457@student.spbu.ru

     The container.hpp file provides a CircularLinkedList<T> template container, 
    offering a complete iterator system compliant with standard STL concepts. 
     This implementation includes error handling, standard operator overloading, 
    and adheres to a clean code style using C++20. 
*/


#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <vector> 

// Template node for circular linked list
template <typename T>
class Node {
public:
    T data; // Data stored in node
    Node<T>* next; // Pointer to next node

    // Constructor initializes data and next pointer
    Node(const T& data) : data(data), next(nullptr) {}
};

// Template circular linked list container
template <typename T>
class CircularLinkedList {
private:
    Node<T>* tail; // Pointer to last node (tail->next = head)
    size_t size_; // Track number of elements

public:
    // Default constructor creates empty list
    CircularLinkedList() : tail(nullptr), size_(0) {}

    // Constructor from initializer list
    CircularLinkedList(std::initializer_list<T> init) : tail(nullptr), size_(0) {
        for (const auto& item : init) {
            push_back(item);
        }
    }

    // Copy constructor (deep copy)
    CircularLinkedList(const CircularLinkedList& other) : tail(nullptr), size_(0) {
        if (!other.isEmpty()) {
            Node<T>* current = other.tail->next; // Start from head
            do {
                push_back(current->data);
                current = current->next;
            } while (current != other.tail->next);
        }
    }
    
    bool is_list_correct() const {
        if (isEmpty()) return true;
        Node<T>* current = tail->next;
        size_t count = 0;
        do {
            if (!current) return false;
            current = current->next;
            ++count;
        } while (current != tail->next && count <= size_);
        return count == size_;
    }

    // Destructor frees all nodes
    ~CircularLinkedList() {
        if (tail && !is_list_correct()) {
            std::cerr << "Corrupted node chain detected!\n";
        }
        clear();
    }

    // Assignment operator
    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) {
            clear();
            if (!other.isEmpty()) {
                Node<T>* current = other.tail->next;
                do {
                    insertEnd(current->data);
                    current = current->next;
                } while (current != other.tail->next);
            }
        }
        return *this;
    }

    // Check if list is empty
    bool isEmpty() const {
        return tail == nullptr;
    }

    // Insert element at beginning of list
    void push_front(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            tail = newNode;
            tail->next = tail;  // Single node points to itself
        }
        else {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode; // Tail points to new head
        }
        size_++; // Update size
    }

    // Insert element at end of list
    void push_back(const T& data) {
        if (isEmpty()) {
            push_front(data);
        }
        else {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = tail->next; // New node points to head
            tail->next = newNode; // Old tail points to new node
            tail = newNode; // Update tail to new node
            size_++; // Update size
        }
    }

    // Remove first element
    void pop_front() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }

        Node<T>* head = tail->next;
        if (head == tail) {
            // Single element case
            delete tail;
            tail = nullptr;
        }
        else {
            tail->next = head->next; // Bypass head
            delete head;
        }
        size_--; // Update size
    }

    // Remove element by value (first occurrence)
    void remove(const T& value) {
        if (isEmpty()) return;

        Node<T>* current = tail->next; // Start at head
        Node<T>* prev = tail; // Previous node

        do {
            if (current->data == value) {
                if (current == tail) {
                    // Special case: removing tail
                    pop_front(); // Use pop_front for head removal
                    tail = prev; // Update tail pointer
                    return;
                }
                prev->next = current->next;
                if (current == tail->next) {
                    // Update head reference if removing head
                    tail->next = current->next;
                }
                delete current;
                size_--; // Update size
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next); // Loop until back to start
    }

    // Access first element (head)
    T& front() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->next->data;
    }

    // Access last element (tail)
    T& back() const {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    // Access element at specific index
    T& at(int index) {
        if (index < 0 || static_cast<size_t>(index) >= size_) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* current = tail->next; // Start at head
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Clear entire list
    void clear() {
        while (!isEmpty()) {
            pop_front(); // Changed to pop_front
        }
        size_ = 0;
    }

    // Swap contents with another list
    void swap(CircularLinkedList& other) noexcept {
        std::swap(tail, other.tail);
        std::swap(size_, other.size_);
    }

    // Merge with another list (transfer ownership)
    void merge(CircularLinkedList& other) {
        if (this == &other || other.isEmpty()) return;

        if (isEmpty()) {
            // Simple takeover if current list is empty
            tail = other.tail;
            size_ = other.size_;
        }
        else {
            Node<T>* thisHead = tail->next;
            Node<T>* otherHead = other.tail->next;

            // Connect lists
            tail->next = otherHead; // Current tail → other head
            other.tail->next = thisHead; // Other tail → current head

            // Update tail to other's tail
            tail = other.tail;
            size_ += other.size_;
        }
        // Leave other in valid empty state
        other.tail = nullptr;
        other.size_ = 0;
    }

    // Iterator class for range-based loops
    class Iterator {
    private:
        Node<T>* current; // Current node pointer
        Node<T>* tailNode; // Original tail reference

    public:
        Iterator(Node<T>* node, Node<T>* tail)
            : current(node), tailNode(tail) {}

        // Dereference operator
        T& operator*() const {
            return current->data;
        }

        // Pre-increment operator
        Iterator& operator++() {
            if (current == tailNode) {
                current = nullptr; // End of cycle
            }
            else {
                current = current->next;
            }
            return *this;
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Begin iterator (start of list)
    Iterator begin() {
        if (isEmpty()) return end();
        return Iterator(tail->next, tail);
    }

    // End iterator (post-cycle state)
    Iterator end() const {
        return Iterator(nullptr, nullptr);
    }

    // Concatenation operator (creates new list)
    CircularLinkedList operator+(const CircularLinkedList& other) const {
        CircularLinkedList result(*this); // Copy current list
        if (!other.isEmpty()) {
            Node<T>* current = other.tail->next;
            do {
                result.push_back(current->data);
                current = current->next;
            } while (current != other.tail->next);
        }
        return result;
    }

    // Compound concatenation operator
    CircularLinkedList& operator+=(const CircularLinkedList& other) {
        if (!other.isEmpty()) {
            Node<T>* current = other.tail->next;
            do {
                push_back(current->data);
                current = current->next;
            } while (current != other.tail->next);
        }
        return *this;
    }

    // Output operator for printing
    friend std::ostream& operator<<(std::ostream& os,
        const CircularLinkedList& cll) {
        if (cll.isEmpty()) {
            os << "[EMPTY]";
            return os;
        }

        Node<T>* current = cll.tail->next; // Start at head
        do {
            os << current->data;
            current = current->next;
            if (current != cll.tail->next) os << " → ";
        } while (current != cll.tail->next); // Loop until head

        return os;
    }

    // Remove last element
    void pop_back() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        if (tail->next == tail) {
            // Single element case
            delete tail;
            tail = nullptr;
            size_ = 0;
        }
        else {
            // Traverse to second last node
            Node<T>* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }
            // Update links and delete tail
            current->next = tail->next; // Bypass current tail
            delete tail;
            tail = current; // Update tail pointer
            size_--;
        }
    }

    // Insert element at specified position
    void insert(int pos, const T& value) {
        if (pos < 0 || static_cast<size_t>(pos) > size_) {
            throw std::out_of_range("Invalid position");
        }

        if (pos == 0) {
            push_front(value);
            return;
        }

        if (static_cast<size_t>(pos) == size_) {
            push_back(value);
            return;
        }

        // Find node at position-1
        Node<T>* prev = tail->next; // Start at head
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }

        // Insert new node after previous
        Node<T>* newNode = new Node<T>(value);
        newNode->next = prev->next;
        prev->next = newNode;
        size_++;
    }

    // Remove element at specified position
    void erase(int pos) {
        if (pos < 0 || static_cast<size_t>(pos) > size_) {
            throw std::out_of_range("Invalid position");
        }

        if (pos == 0) {
            pop_front();
            return;
        }

        // Find node before target
        Node<T>* prev = tail->next; // Start at head
        for (int i = 0; i < pos - 1; ++i) {
            prev = prev->next;
        }

        Node<T>* toDelete = prev->next;
        if (toDelete == tail) {
            // Update tail if deleting last element
            tail = prev;
        }
        prev->next = toDelete->next; // Bypass target node
        delete toDelete;
        size_--;
    }

    // Return number of elements in list
    size_t size() const {
        return size_;
    }

    // Check if list is empty
    bool empty() const {
        return size_ == 0;
    }

    // Find first occurrence of value, return index or -1
    int find(const T& value) const {
        if (empty()) return -1;

        Node<T>* current = tail->next; // Start at head
        int index = 0;
        do {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        } while (current != tail->next); // Full cycle

        return -1;
    }

    // Check if value exists in list
    bool contains(const T& value) const {
        return find(value) != -1;
    }

    // Convert list to std::vector
    std::vector<T> to_vector() const {
        std::vector<T> result;
        if (empty()) return result;

        Node<T>* current = tail->next; // Start at head
        do {
            result.push_back(current->data);
            current = current->next;
        } while (current != tail->next); // Until back to start

        return result;
    }

    // Reverse list in-place
    void reverse() {
        if (size_ <= 1) return;

        Node<T>* prev = tail;
        Node<T>* current = tail->next;
        Node<T>* next = nullptr;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (prev != tail);

        // Update tail to point to new head
        tail = current;
    }

    // Split list at position
    CircularLinkedList<T> split(int pos) {
        if (pos < 0 || static_cast<size_t>(pos) > size_) {
            throw std::out_of_range("Invalid position");
        }

        CircularLinkedList<T> newList;
        if (pos == 0) {
            // Move entire list to newList
            newList.tail = tail;
            newList.size_ = size_;
            tail = nullptr;
            size_ = 0;
            return newList;
        }

        if (static_cast<size_t>(pos) == size_) {
            // Return empty list, original remains unchanged
            return newList;
        }

        // Traverse to split point
        Node<T>* current = tail->next;
        for (int i = 0; i < pos - 1; ++i) {
            current = current->next;
        }

        // Set up new list
        newList.tail = tail;
        newList.tail->next = current->next; // New head for second list
        newList.size_ = size_ - pos;

        // Update current list
        tail = current;
        tail->next = newList.tail->next; // Maintain circularity
        size_ = pos;

        return newList;
    }
    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    T& operator[](size_t index) {
        return at(index);
    }
};


#endif
