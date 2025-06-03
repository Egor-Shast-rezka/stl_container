# CircularLinkedList<T> - Detailed Description

This document provides a detailed description of the `CircularLinkedList<T>` container, including its methods and their time complexities.

## Class Overview
The `CircularLinkedList<T>` is a template-based circular linked list implementation. It maintains a `tail` pointer, which points to the last node in the list. The `tail->next` points to the head of the list, forming a circular structure.

## Class Members

### Private Members
* `Node<T>* tail`: Pointer to the last node. `nullptr` if empty.
* `size_t size_`: Current number of elements in the list.

### Public Methods

#### Constructors
* `CircularLinkedList()`
  * **Description**: Default constructor. Initializes an empty list.
  * **Time Complexity**: $O(1)$
* `CircularLinkedList(std::initializer_list<T> init)`
  * **Description**: Initializes list with elements from `std::initializer_list`.
  * **Time Complexity**: $O(N)$ (N = elements in `init`)
* `CircularLinkedList(const CircularLinkedList& other)`
  * **Description**: Deep copy constructor.
  * **Time Complexity**: $O(N)$ (N = size of `other`)
* `CircularLinkedList(CircularLinkedList&& other) noexcept`
  * **Description**: Move constructor (**Bugged**: Uses undefined `head`/`listSize`).
  * **Time Complexity**: $O(1)$ (Intended)

#### Destructor
* `~CircularLinkedList()`
  * **Description**: Destroys all nodes. Checks for corrupted chains.
  * **Time Complexity**: $O(N)$ (calls `clear()`)

#### Assignment Operators
* `CircularLinkedList& operator=(const CircularLinkedList& other)`
  * **Description**: Deep copy assignment.
  * **Time Complexity**: $O(N + M)$ (N = current size, M = `other` size)
* `CircularLinkedList& operator+=(const CircularLinkedList& other)`
  * **Description**: Appends `other` to current list.
  * **Time Complexity**: $O(M)$ (M = size of `other`)

#### Element Access
* `T& front() const`
  * **Description**: Returns first element (head). Throws if empty.
  * **Time Complexity**: $O(1)$
* `T& back() const`
  * **Description**: Returns last element (tail). Throws if empty.
  * **Time Complexity**: $O(1)$
* `T& at(int index)`
  * **Description**: Returns element at `index`. Throws if out-of-range.
  * **Time Complexity**: $O(k)$ (k = index)
* `T& operator[](size_t index)`
  * **Description**: Accesses element at `index` (no bounds checking).
  * **Time Complexity**: $O(k)$ (k = index)

#### Modifiers
* `void push_front(const T& data)`
  * **Description**: Inserts element at beginning.
  * **Time Complexity**: $O(1)$
* `void push_back(const T& data)`
  * **Description**: Inserts element at end.
  * **Time Complexity**: $O(1)$
* `void pop_front()`
  * **Description**: Removes first element. Throws if empty.
  * **Time Complexity**: $O(1)$
* `void pop_back()`
  * **Description**: Removes last element. Throws if empty.
  * **Time Complexity**: $O(N)$ (traversal required)
* `void insert(int pos, const T& value)`
  * **Description**: Inserts `value` at `pos`. Throws if invalid position.
  * **Time Complexity**: $O(k)$ (k = pos)
* `void erase(int pos)`
  * **Description**: Removes element at `pos`. Throws if invalid position.
  * **Time Complexity**: $O(k)$ (k = pos)
* `void remove(const T& value)`
  * **Description**: Removes first occurrence of `value`.
  * **Time Complexity**: $O(N)$
* `void clear()`
  * **Description**: Removes all elements.
  * **Time Complexity**: $O(N)$
* `void swap(CircularLinkedList& other) noexcept`
  * **Description**: Swaps contents with `other`.
  * **Time Complexity**: $O(1)$
* `void merge(CircularLinkedList& other)`
  * **Description**: Merges `other` into current list
  * **Time Complexity**: $O(1)$ (Intended)
* `void reverse()`
  * **Description**: Reverses list in-place.
  * **Time Complexity**: $O(N)$
* `CircularLinkedList<T> split(int pos)`
  * **Description**: Splits list at `pos`, returns new list with elements from `pos` to end.
  * **Time Complexity**: $O(k)$ (k = pos)

#### Capacity
* `size_t size() const`
  * **Description**: Returns number of elements.
  * **Time Complexity**: $O(1)$
* `bool empty() const`
  * **Description**: Checks if list is empty.
  * **Time Complexity**: $O(1)$

#### Operations
* `int find(const T& value) const`
  * **Description**: Returns index of first `value` occurrence, or -1.
  * **Time Complexity**: $O(N)$
* `bool contains(const T& value) const`
  * **Description**: Checks if `value` exists in list.
  * **Time Complexity**: $O(N)$
* `std::vector<T> to_vector() const`
  * **Description**: Converts list to `std::vector`.
  * **Time Complexity**: $O(N)$
* `bool is_list_correct() const`
  * **Description**: Verifies circular linkage integrity.
  * **Time Complexity**: $O(N)$
* `Iterator operator++(int)`
  * **Description**: Post-increment operator
  * **Time Complexity**: $O(1)$ (Intended)

#### Operators
* `CircularLinkedList operator+(const CircularLinkedList& other) const`
  * **Description**: Returns new concatenated list (current + `other`).
  * **Time Complexity**: $O(N + M)$ (N = current size, M = `other` size)
* `friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList& cll)`
  * **Description**: Outputs list elements to stream.
  * **Time Complexity**: $O(N)$

## Iterator Class
Bidirectional iterator for traversing circular lists.

### Public Methods
* `Iterator(Node<T>* node, Node<T>* tail)`
  * **Description**: Constructs iterator from node and tail reference.
* `T& operator*() const`
  * **Description**: Dereferences to node data.
  * **Time Complexity**: $O(1)$
* `Iterator& operator++()`
  * **Description**: Pre-increment. Moves to next node.
  * **Time Complexity**: $O(1)$
* `Iterator operator++(int)`
  * **Description**: Post-increment.
  * **Time Complexity**: $O(1)$
* `bool operator==(const Iterator& other) const`
  * **Description**: Checks iterator equality.
  * **Time Complexity**: $O(1)$
* `bool operator!=(const Iterator& other) const`
  * **Description**: Checks iterator inequality.
  * **Time Complexity**: $O(1)$
* Comparison operators (`<`, `>`, `<=`, `>=`)
  * **Description**: Compare node pointers.
  * **Time Complexity**: $O(1)$

### Iterator Accessors
* `Iterator begin()`
  * **Description**: Returns iterator to first element.
  * **Time Complexity**: $O(1)$
* `Iterator end() const`
  * **Description**: Returns end iterator (`nullptr`).
  * **Time Complexity**: $O(1)$
* `Iterator cbegin() const`
  * **Description**: Const version of `begin()`.
  * **Time Complexity**: $O(1)$
* `Iterator cend() const`
  * **Description**: Const version of `end()`.
  * **Time Complexity**: $O(1)$
