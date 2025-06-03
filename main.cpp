/*
    Egor Shastin st129457@student.spbu.ru
    
     The main function demonstrates various container functionalities such as creation, 
    element insertion and deletion, iterator usage, searching, 
    and operations like merging, swapping, and reversing.
    
*/


// ================= main ===================

#include <iostream>
#include "container.h"

int main() {
    CircularLinkedList<int> c1 = {10, 5, 20, 15, 25};

    std::cout << "Initial list:\n" << c1 << "\n";

    c1.push_back(12);
    std::cout << "\nAfter push_back(12):\n" << c1 << "\n";

    std::cout << "\nContains 15? " << (c1.contains(15) ? "Yes" : "No") << "\n";
    std::cout << "Contains 100? " << (c1.contains(100) ? "Yes" : "No") << "\n";

    c1.remove(10);
    std::cout << "\nAfter removing 10:\n" << c1 << "\n";

    std::cout << "\nIterating through list:\n";
    for (auto it = c1.begin(); it != c1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "\nElement at index 2: " << c1.at(2) << "\n";

    c1.insert(2, 99);
    std::cout << "\nAfter inserting 99 at index 2:\n" << c1 << "\n";

    c1.erase(1);
    std::cout << "\nAfter erasing index 1:\n" << c1 << "\n";

    std::cout << "\nFront: " << c1.front() << ", Back: " << c1.back() << "\n";

    std::cout << "\nList size: " << c1.size() << "\n";


    return 0;
}

