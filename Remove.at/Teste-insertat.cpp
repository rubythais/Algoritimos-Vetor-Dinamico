#include <iostream>
#include <chrono>
#include "arraydinamico.hpp"

int main() {
    arraydinamico l1; 
    int n; 
    std::cin >> n;

    auto beg = std::chrono::high_resolution_clock::now(); 

    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x; 
        l1.push_front(x); 
    }

    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = end - beg;

    
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n"; 
        exit(1); 
    }

    
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;

    return 0; 
}
