# CircularLinkedList<T> - Detailed Description

This document provides a detailed description of the `CircularLinkedList<T>` container, including its methods and their time complexities.

## Class Overview
The `CircularLinkedList<T>` is a template-based circular linked list implementation. It maintains a `tail` pointer, which points to the last node in the list. The `tail->next` then points to the head of the list, forming a circular structure.

## Class Members

### Private Members
* `Node<T>* tail`: Pointer to the last node in the list. For an empty list, this is `nullptr`.
* `size_t size_`: Stores the current number of elements in the list.

### Public Methods

#### Constructors
* `CircularLinkedList()`
    * **Description**: Default constructor. Initializes an empty circular linked list.
    * **Time Complexity**: $O(1)$
* `CircularLinkedList(std::initializer_list<T> init)`
    * **Description**: Constructor that initializes the list with elements from an `std::initializer_list`.
    * **Time Complexity**: $O(N)$, where $N$ is the number of elements in the `initializer_list`. Each `push_back` operation takes $O(1)$ amortized time.
* `CircularLinkedList(const CircularLinkedList& other)`
    * **Description**: Copy constructor. Performs a deep copy of the `other` list.
    * **Time Complexity**: $O(N)$, where $N$ is the size of the `other` list. Each element is copied individually.

#### Destructor
* `~CircularLinkedList()`
    * **Description**: Destructor. Frees all dynamically allocated nodes in the list. Includes a check for corrupted node chains.
    * **Time Complexity**: $O(N)$, where $N$ is the number of elements in the list, due to calling `clear()`.

#### Assignment Operator
* `CircularLinkedList& operator=(const CircularLinkedList& other)`
    * **Description**: Assignment operator. Clears the current list and performs a deep copy of the `other` list.
    * **Time Complexity**: $O(N + M)$, where $N$ is the size of the current list (for `clear()`) and $M$ is the size of the `other` list (for copying).

#### Element Access
* `T& front() const`
    * **Description**: Returns a reference to the first element in the list (head). Throws `std::out_of_range` if the list is empty.
    * **Time Complexity**: $O(1)$
* `T& back() const`
    * **Description**: Returns a reference to the last element in the list (tail). Throws `std::out_of_range` if the list is empty.
    * **Time Complexity**: $O(1)$
* `T& at(int index)`
    * **Description**: Returns a reference to the element at the specified `index`. Throws `std::out_of_range` if the `index` is out of bounds.
    * **Time Complexity**: $O(k)$, where $k$ is the `index`. In the worst case, $O(N)$ for the last element.
* `T& operator[](size_t index)`
    * **Description**: Overloaded `[]` operator. Provides access to the element at the specified `index`. Does not perform bounds checking (unlike `at()`).
    * **Time Complexity**: $O(k)$, where $k$ is the `index`. In the worst case, $O(N)$ for the last element.

#### Modifiers
* `void push_front(const T& data)`
    * **Description**: Inserts a new element at the beginning of the list.
    * **Time Complexity**: $O(1)$
* `void push_back(const T& data)`
    * **Description**: Inserts a new element at the end of the list.
    * **Time Complexity**: $O(1)$
* `void pop_front()`
    * **Description**: Removes the first element from the list. Throws `std::out_of_range` if the list is empty.
    * **Time Complexity**: $O(1)$
* `void pop_back()`
    * **Description**: Removes the last element from the list. Throws `std::out_of_range` if the list is empty.
    * **Time Complexity**: $O(N)$, as it requires traversing to the second-to-last node.
* `void insert(int pos, const T& value)`
    * **Description**: Inserts `value` at the specified `pos`. Throws `std::out_of_range` if `pos` is invalid.
    * **Time Complexity**: $O(k)$, where $k$ is the `pos`. In the worst case, $O(N)$.
* `void erase(int pos)`
    * **Description**: Removes the element at the specified `pos`. Throws `std::out_of_range` if `pos` is invalid.
    * **Time Complexity**: $O(k)$, where $k$ is the `pos`. In the worst case, $O(N)$.
* `void remove(const T& value)`
    * **Description**: Removes the first occurrence of `value` from the list.
    * **Time Complexity**: $O(N)$, as it may require traversing the entire list.
* `void clear()`
    * **Description**: Removes all elements from the list, making it empty.
    * **Time Complexity**: $O(N)$, as it repeatedly calls `pop_front()`.
* `void swap(CircularLinkedList& other) noexcept`
    * **Description**: Swaps the contents of the current list with `other`.
    * **Time Complexity**: $O(1)$
* `void merge(CircularLinkedList& other)`
    * **Description**: Merges the `other` list into the current list, transferring ownership of nodes from `other`. The `other` list becomes empty.
    * **Time Complexity**: $O(1)$, as it only involves pointer reassignments.
* `void reverse()`
    * **Description**: Reverses the order of elements in the list in-place.
    * **Time Complexity**: $O(N)$, as it iterates through all nodes to reverse their pointers.
* `CircularLinkedList<T> split(int pos)`
    * **Description**: Splits the current list into two at the specified `pos`. Elements from `pos` to the end are moved to a new `CircularLinkedList` object, which is returned. Throws `std::out_of_range` if `pos` is invalid.
    * **Time Complexity**: $O(k)$, where $k$ is `pos`. In the worst case, $O(N)$.

#### Capacity
* `size_t size() const`
    * **Description**: Returns the number of elements in the list.
    * **Time Complexity**: $O(1)$
* `bool empty() const`
    * **Description**: Checks if the list is empty.
    * **Time Complexity**: $O(1)$
* `bool isEmpty() const`
    * **Description**: Alias for `empty()`. Checks if the list is empty.
    * **Time Complexity**: $O(1)$

#### Operations
* `int find(const T& value) const`
    * **Description**: Finds the first occurrence of `value` in the list and returns its index. Returns `-1` if `value` is not found.
    * **Time Complexity**: $O(N)$, as it may require traversing the entire list.
* `bool contains(const T& value) const`
    * **Description**: Checks if `value` exists in the list.
    * **Time Complexity**: $O(N)$, as it calls `find()`.
* `std::vector<T> to_vector() const`
    * **Description**: Converts the elements of the list into a `std::vector`.
    * **Time Complexity**: $O(N)$, as it iterates through all elements.
* `bool is_list_correct() const`
    * **Description**: Internal helper function to check the integrity of the circular linkage.
    * **Time Complexity**: $O(N)$

#### Operators
* `CircularLinkedList operator+(const CircularLinkedList& other) const`
    * **Description**: Concatenation operator. Creates a new list by appending `other` to a copy of the current list.
    * **Time Complexity**: $O(N + M)$, where $N$ is the size of the current list and $M$ is the size of the `other` list.
* `CircularLinkedList& operator+=(const CircularLinkedList& other)`
    * **Description**: Compound concatenation operator. Appends `other` to the current list.
    * **Time Complexity**: $O(M)$, where $M$ is the size of the `other` list.
* `friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList& cll)`
    * **Description**: Overloaded output operator for printing the list elements.
    * **Time Complexity**: $O(N)$, as it iterates through all elements to print them.

## Iterator Class

The `CircularLinkedList` provides an `Iterator` class to support range-based for loops and standard iterator operations.

### Iterator Members
* `Node<T>* current`: Pointer to the current node in the iteration.
* `Node<T>* tailNode`: A reference to the original `tail` of the list, used to determine the end of the circular iteration.

### Iterator Methods
* `Iterator(Node<T>* node, Node<T>* tail)`
    * **Description**: Constructor for the iterator.
* `T& operator*() const`
    * **Description**: Dereference operator. Returns a reference to the data of the `current` node.
    * **Time Complexity**: $O(1)$
* `Iterator& operator++()`
    * **Description**: Pre-increment operator. Moves the iterator to the next node. If the `current` node is the `tailNode`, it sets `current` to `nullptr` to signal the end of iteration.
    * **Time Complexity**: $O(1)$
* `Iterator operator++(int)`
    * **Description**: Post-increment operator.
    * **Time Complexity**: $O(1)$
* `bool operator!=(const Iterator& other) const`
    * **Description**: Inequality operator. Compares two iterators.
    * **Time Complexity**: $O(1)$
* `bool operator==(const Iterator& other) const`
    * **Description**: Equality operator. Compares two iterators.
    * **Time Complexity**: $O(1)$

### Iterator Accessors
* `Iterator begin()`
    * **Description**: Returns an iterator pointing to the first element (head) of the list.
    * **Time Complexity**: $O(1)$
* `Iterator end() const`
    * **Description**: Returns an iterator representing the past-the-end state of the list. This is typically a null pointer to signal the end of iteration in a circular list context.
    * **Time Complexity**: $O(1)$
