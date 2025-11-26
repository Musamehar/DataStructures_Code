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
    template<typename> friend class List;
};

template<typename T>
class List {
private:
    Node<T>* list_head;

public:
    List() : list_head(nullptr) {}
    ~List() { while (!empty()) pop_front(); }

    bool empty() const { return (list_head == nullptr); }

    int size() const { int count = 0; for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) ++count; return count; }

    T front() const { if (empty()) { cerr << "List is empty! Cannot access front element.\n"; return T(); } return list_head->retrieve(); }

    T end() const {
        if (empty()) { cerr << "List is empty! Cannot access end element.\n"; return T(); }
        Node<T>* ptr = list_head;
        while (ptr->next() != nullptr) ptr = ptr->next();
        return ptr->retrieve();
    }

    Node<T>* head() const { return list_head; }

    int count(const T& n) const { int node_count = 0; for (Node<T>* ptr = head(); ptr != nullptr; ptr = ptr->next()) if (ptr->retrieve() == n) ++node_count; return node_count; }

    void push_front(const T& n) { Node<T>* new_node = new Node<T>(n, list_head); list_head = new_node; }

    void push_end(const T& n) {
        Node<T>* new_node = new Node<T>(n, nullptr);
        if (empty()) { list_head = new_node; return; }
        Node<T>* ptr = list_head; while (ptr->next() != nullptr) ptr = ptr->next(); ptr->set_next(new_node);
    }

    void push_between(int index, const T& n) {
        int size_val = size();
        if (index < 0 || index > size_val) { cerr << "Invalid index! Must be between 0 and " << size_val << ".\n"; return; }
        if (index == 0) { push_front(n); return; }
        if (index == size_val) { push_end(n); return; }
        Node<T>* ptr = list_head; for (int i = 0; i < index - 1; ++i) ptr = ptr->next(); Node<T>* new_node = new Node<T>(n, ptr->next()); ptr->set_next(new_node);
    }

    T pop_front() { if (empty()) { cerr << "List is empty! Cannot pop front.\n"; return T(); } T value = list_head->retrieve(); Node<T>* temp = list_head; list_head = list_head->next(); delete temp; return value; }

    T pop_end() {
        if (empty()) { cerr << "List is empty! Cannot pop end.\n"; return T(); }
        if (list_head->next() == nullptr) { T value = list_head->retrieve(); delete list_head; list_head = nullptr; return value; }
        Node<T>* ptr = list_head; while (ptr->next()->next() != nullptr) ptr = ptr->next(); T value = ptr->next()->retrieve(); delete ptr->next(); ptr->set_next(nullptr); return value;
    }

    int erase(const T& n) {
        int count_removed = 0;
        while (list_head != nullptr && list_head->retrieve() == n) { Node<T>* temp = list_head; list_head = list_head->next(); delete temp; ++count_removed; }
        Node<T>* ptr = list_head;
        while (ptr != nullptr && ptr->next() != nullptr) {
            if (ptr->next()->retrieve() == n) {
                Node<T>* temp = ptr->next();
                ptr->set_next(ptr->next()->next());
                delete temp;
                ++count_removed;
            } else { ptr = ptr->next(); }
        }
        return count_removed;
    }

    void display() const { if (empty()) { cout << "List is empty.\n"; return; } for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) cout << ptr->retrieve() << " -> "; cout << "nullptr\n"; }
};

int main() {
    List<int> lst;
    cout << "Pushing front 10, 20, 30 (30 will become the head):\n";
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.display();

    cout << "\nPushing end 40, 50 (these will be appended at tail):\n";
    lst.push_end(40);
    lst.push_end(50);
    lst.display();

    cout << "\nFront element: " << lst.front() << endl;
    cout << "End element: " << lst.end() << endl;
    cout << "Size of list: " << lst.size() << endl;

    cout << "\nCounting how many times 20 appears: " << lst.count(20) << endl;

    cout << "\nErasing all nodes with value 20:\n";
    lst.erase(20);
    lst.display();

    cout << "\nPopping front (removes head node): " << lst.pop_front() << endl;
    lst.display();

    cout << "\nPopping end (removes last node): " << lst.pop_end() << endl;
    lst.display();

    cout << "\nIs list empty? " << (lst.empty() ? "Yes" : "No") << endl;
    cout << "Final size of list: " << lst.size() << endl;

    cout << "\nProgram finished successfully.\n";
    return 0;
}
