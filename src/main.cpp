#include "rbtree.h"

int main() {
    auto rbtree = RBTree<std::string,int>();
    rbtree.push_front(std::string("Hello"),10);
    rbtree.push_front(std::string("World"),20);
    rbtree.print_nodes();
    return 0;
}
