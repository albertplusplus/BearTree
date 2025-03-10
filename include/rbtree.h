
#include <memory>

template <typename T1, typename T2>
class RBTree {
private:

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

public:

    RBTree() {}


}
