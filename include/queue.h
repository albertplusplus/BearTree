#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"


namespace bear {
    template <typename T>
    class queue {
    private:
        list<T> _list;
    public:
        queue() : _list{} {}
        ~queue() {}

        void enqueue(const T item) {
            _list.push_front(item);
        }

        T dequeue() {
            try {
                _list.pop_front();
            } catch (const std::runtime_error& e) {
                std::cerr << "Tried to dequeue an empty list.\n";
            }
        }

        bool empty() const {
            return _list.empty();
        }

        int size() {
            return _list.size();
        }

        using iterator = typename list<T>::iterator;

        iterator begin() {
            return _list.begin();
        }

        iterator end() {
            return _list.begin();
        }

    };
}

#endif // QUEUE_H
