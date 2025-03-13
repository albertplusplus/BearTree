
#include "queue.h"
#include <iostream>

int main() {
    auto Q = bear::queue<int>();
    Q.enqueue(5);
    Q.enqueue(10);
    Q.enqueue(24);
    for (auto q : Q) {
        std::cout << q << " - ";
    }
    std::cout << "\n";

    return 0;
}
