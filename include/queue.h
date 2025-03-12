#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"


namespace bear {
    template <typename T>
    class queue {
    private:
        list<T> _list;
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
    };
}

#endif // QUEUE_H
