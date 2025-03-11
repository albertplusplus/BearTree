#ifndef LIST_H
#define LIST_h
#include <memory>
#include <iostream>
#include <stdexcept>

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

    public:
    list() : head{nullptr}, tail{nullptr}, _size{0} {}
        ~list() {}

        void push_front(T _item) {
            if (empty()) {
                head = std::make_shared<Node>(_item);
                tail = head;
                return;
            }
            auto curr = std::make_shared<Node>(_item);
            curr->next = head;
            head->prev = curr;
            head = curr;
        }

        void push_back(T _item) {
            if (empty()) {
                push_front(_item);
            }
            auto curr = std::make_shared<Node>(_item);
            curr->prev = tail;
            tail->next = curr;
            tail = curr;
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

        size_t size() { return _size; }
    };
}

#endif // LIST_H
