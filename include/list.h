#ifndef LIST_H
#define LIST_h
#include <memory>
#include <iostream>
#include <stdexcept>
#include <iterator>

namespace bear {

    template <typename T>
    class list {
    private:
        struct Node {
            T item;
            std::shared_ptr<Node> prev, next;

        Node(T _item) : item{_item}, prev{nullptr}, next{nullptr} {}
        };

        size_t _size;
        std::shared_ptr<Node> head, tail;
        T _min;
        T _max;

    public:
    list() : head{nullptr}, tail{nullptr}, _size{0} {}
    ~list() {}

        void push_front(T _item) {
            if (empty()) {
                head = std::make_shared<Node>(_item);
                tail = head;
                _min = _max =  _item;
                ++_size;
                return;
            }
            auto curr = std::make_shared<Node>(_item);
            curr->next = head;
            head->prev = curr;
            head = curr;
            if (head->item < _min) _min = head->item;
            if (head->item > _max) _max = head->item;
            ++_size;
        }

        void push_back(T _item) {
            if (empty()) {
                push_front(_item);
                return;
            }
            auto curr = std::make_shared<Node>(_item);
            curr->prev = tail;
            tail->next = curr;
            tail = curr;
            ++_size;
        }

        T peek_front() {
            if (!head) return nullptr;
            return head->item;
        }

        T peek_back() {
            if (!tail) return nullptr;
            return tail->item;
        }

        T pop_front() {
            if (!head) throw std::runtime_error("Tried popping empty list");
            auto ret = head->item;
            if (!(head->next)) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            if (ret == _min) update_min();
            if (ret == _max) update_max();
            _size -= 1;
            return ret;
        }

        T pop_back() {
            if (!tail) throw std::runtime_error("Tried popping empty list");
            auto ret = tail->item;

            if (!(tail->prev)) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            if (ret == _min) update_min();
            if (ret == _max) update_max();
            _size -= 1;
            return ret;
        }

        bool empty() {
            return !head && !tail;
        }

        void print_nodes() {
            auto curr = head.get();
            while (curr != nullptr) {
                std::cout << curr->item << "  ";
                curr = curr->next.get();
            }
        }

        T min() {
            if (empty()) return std::runtime_error("List is empty");
            return _min;
        }

        T max() {
            if (empty()) return std::runtime_error("List is empty");
            return _max;
        }

        size_t size() { return _size; }

        struct iterator {
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using pointer = T*;
            using reference = T&;
            using difference_type = std::ptrdiff_t;

            iterator(Node* ptr) : _node{ptr} {}
            reference operator*() const {
                return _node->item;
            }
            pointer operator->() {
                return *(_node->item);
            }
            iterator& operator++() {
                _node = _node->next.get();
                return *this;
            }
            iterator operator++(int) {
                iterator tmp = *this;
                _node = _node->next.get();
                return tmp;
            }
            bool operator==(const iterator& other) const {
                return _node == other._node;
            }

            bool operator!=(const iterator& other) const {
                return _node != other._node;
            }
            Node* _node;
        };

        iterator begin() { return iterator(head.get()); }
        iterator end()   { return iterator(nullptr); }
    private:

        T update_min() {
            auto curr = head.get();
            while (curr != nullptr) {
                if (curr->item < _min) {
                    _min = curr->item;
                }
                curr = curr->next.get();
            }
        }

        T update_max() {
            auto curr = head.get();
            while (curr != nullptr) {
                if (curr->item > _max) {
                    _max = curr->item;
                }
                curr = curr->next.get();
            }
        }


    };
}

#endif // LIST_H
