#ifndef RB_TREE_H
#define RB_TREE_H


#include <memory>
#include <iostream>
#include <cassert>


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

        std::unique_ptr<Node> rec_add(std::unique_ptr<Node> head, T1 add_key, T2 add_value) {
            if (!head) return std::make_unique<Node>(add_key, add_value, RED, 1);
            if (head->key > add_key) {
                head->left = rec_add(std::move(head->left), add_key, add_value);
            } else if (head->key < add_key) {
                head->right = rec_add(std::move(head->right), add_key, add_value);
            }

            if (is_red(head->right) && !is_red(head->left)) head = rotate_left(std::move(head));
            if (is_red(head->left) && is_red(head->left->left)) head = rotate_right(std::move(head));
            if (is_red(head->left) && is_red(head->right)) flip_colors(head);

            return head;
        }

        void _print_nodes(Node* head) const {
            if (!head) return;
            _print_nodes(head->left.get());
            std::cout << head->key << " : " << head->value << "\n";
            _print_nodes(head->right.get());
        }

        std::unique_ptr<Node> rotate_left(std::unique_ptr<Node> h) {
            assert(is_red(h));
            auto x = std::move(h->right);
            h->right = std::move(x->left);

            auto h_color = h->color;
            x->left = std::move(h);
            x->color = h_color;
            x->left->color = RED;
            return x;
        }

        std::unique_ptr<Node> rotate_right(std::unique_ptr<Node> h) {
            assert(is_red(h->left));
            auto x = std::move(h->left);
            h->left = std::move(x->right);

            auto h_color = h->color;
            x->right = std::move(h);
            x->color = h_color;
            x->right->color = RED;
            return x;
        }

        void flip_colors(std::unique_ptr<Node>& h) {
            assert(!is_red(h));
            assert(is_red(h->left));
            assert(is_red(h->right));

            h->color = RED;
            h->left->color = BLACK;
            h->right->color = BLACK;
        }

public:

    RBTree() = default;
    ~RBTree() = default;

    void push(T1 add_key, T2 add_value) {
       if (root == nullptr) {
           root = std::make_unique<Node>(add_key, add_value, RED, 1);
       } else {
           root = rec_add(std::move(root), add_key, add_value);
       }
    }

   void print_nodes() const  {
       _print_nodes(root.get());
    }


};
#endif // RB_TREE_H
