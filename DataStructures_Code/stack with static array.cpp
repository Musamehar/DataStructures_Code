#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T, size_t MAX = 100>
class StaticStack {
private:
    T data[MAX];
    int top_index;

public:
    StaticStack() : top_index(-1) {}
    bool empty() const { return top_index == -1; }
    bool full() const { return top_index == static_cast<int>(MAX) - 1; }
    int size() const { return top_index + 1; }

    void push(const T& n) {
        if (full()) throw overflow_error("Stack overflow: Cannot push, stack is full.");
        data[++top_index] = n;
    }

    T pop() {
        if (empty()) throw out_of_range("Pop on empty stack");
        return data[top_index--];
    }

    T top() const {
        if (empty()) throw out_of_range("Top on empty stack");
        return data[top_index];
    }

    void display() const {
        if (empty()) return;
        cout << "TOP -> ";
        for (int i = top_index; i >= 0; --i) cout << data[i] << (i > 0 ? " -> " : "");
        cout << " -> BOTTOM\n";
    }
};

int main() {
    StaticStack<int> s;
    s.push(10);
    s.push(20);
    s.display();
    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.display();
    return 0;
}
