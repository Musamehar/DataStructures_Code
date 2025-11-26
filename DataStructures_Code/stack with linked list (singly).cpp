#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
    T value;
    Node<T>* next_node;

public:
    Node(T val = T(), Node<T>* next = nullptr) : value(val), next_node(next) {}
    T retrieve() const { return value; }
    Node<T>* next() const { return next_node; }
    void set_next(Node<T>* next) { next_node = next; }
    template<typename> friend class Stack;
};

template<typename T>
class Stack {
private:
    Node<T>* list_head;
    int stack_size;

public:
    Stack() : list_head(nullptr), stack_size(0) {}
    ~Stack() { while (!empty()) pop(); }
    bool empty() const { return (list_head == nullptr); }
    int size() const { return stack_size; }

    void push(const T& n) { Node<T>* new_node = new Node<T>(n, list_head); list_head = new_node; ++stack_size; }

    T pop() {
        if (empty()) { cerr << "Stack is empty! Cannot pop.\n"; return T(); }
        T value = list_head->retrieve(); Node<T>* temp = list_head; list_head = list_head->next(); delete temp; --stack_size; return value;
    }

    T top() const { if (empty()) { cerr << "Stack is empty! Cannot access top element.\n"; return T(); } return list_head->retrieve(); }

    void display() const {
        if (empty()) { cout << "Stack is empty.\n"; return; }
        cout << "TOP -> ";
        for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            cout << ptr->retrieve(); if (ptr->next() != nullptr) cout << " -> ";
        }
        cout << " -> BOTTOM\n";
    }
};

int main() {
    Stack<int> s;
    cout << "Pushing 10, 20, 30 onto the stack:\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "\nTop element: " << s.top() << endl;
    cout << "Size of stack: " << s.size() << endl;

    cout << "\nPopping: " << s.pop() << endl;
    s.display();

    cout << "\nPushing 40:\n";
    s.push(40);
    s.display();

    cout << "\nPopping: " << s.pop() << endl;
    cout << "Popping: " << s.pop() << endl;
    cout << "Popping: " << s.pop() << endl;
    s.display();

    cout << "\nIs stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    cout << "\nProgram finished successfully.\n";
    return 0;
}
