#ifndef RB_TREE_H
#define RB_TREE_H


#include <memory>

template <typename T1, typename T2>
class RBTree {
private:
    // Class Variables and Data Structures

    bool RED = true;
    bool BLACK = false;

    struct Node {
        T1 key;
        T2 value;
        std::unique_ptr<Node> left, right;
        bool color;
        int size;

    Node(T1 _key, T2 _value, bool _color, int _size) :
        key{_key}, value{_value}, color{_color}, size{_size}, left{nullptr}, right{nullptr} {}
    };

    std::unique_ptr<Node> root;


    private:
        bool is_red(const std::unique_ptr<Node>& x) {
            if (x == nullptr) return false;
            return x->color == RED;
        }
public:

    RBTree() {}
        ~RBTree() {}


};

#endif // RB_TREE_H
