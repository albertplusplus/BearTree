#ifndef RB_TREE_H
#define RB_TREE_H


#include <memory>
#include <iostream>

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

    RBTree() = default;
    ~RBTree() = default;
        void push_front(T1 add_key, T2 add_value) {
            if (root == nullptr) {
                root = std::make_unique<Node>(add_key, add_value, RED, 1);
            } else {
                root = rec_add(std::move(root), add_key, add_value);
            }
        }

        std::unique_ptr<Node> rec_add(std::unique_ptr<Node> head, T1 add_key, T2 add_value) {
            if (!head) return std::make_unique<Node>(add_key, add_value, RED, 1);
            if (head->key > add_key) {
                head->left = rec_add(std::move(head->left), add_key, add_value);
            } else if (head->key < add_key) {
                head->right = rec_add(std::move(head->right), add_key, add_value);
            }
            return head;
        }

        void print_nodes() const  {
            _print_nodes(root.get());
        }

        void _print_nodes(Node* head) const {
            if (!head) return;
            _print_nodes(head->left.get());
            std::cout << head->key << " : " << head->value << "\n";
            _print_nodes(head->right.get());
        }

};
#endif // RB_TREE_H
