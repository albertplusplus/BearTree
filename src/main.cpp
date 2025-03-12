#include "rbtree.h"
#include "list.h"

int main() {
    auto rbtree = bear::RBTree<std::string,int>();
    rbtree.insert(std::string("Hello"),10);
    rbtree.insert(std::string("World"),20);
    rbtree.print_nodes();
   std::cout << "\n\n";
    auto lst = bear::list<int>();
    lst.push_front(45);
    lst.push_front(23);
    lst.push_back(64);
    lst.pop_back();
    lst.push_back(98);
    for (auto nodes : lst) {
        std::cout << nodes.item << "  ";
    }
    return 0;
}
