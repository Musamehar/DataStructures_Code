#include <iostream>
using namespace std;

template<typename T>
class DNode {
private:
    T value;
    DNode<T>* next_node;
    DNode<T>* prev_node;

public:
    DNode(T val = T(), DNode<T>* next = nullptr, DNode<T>* prev = nullptr)
        : value(val), next_node(next), prev_node(prev) {}

    T retrieve() const { return value; }
    DNode<T>* next() const { return next_node; }
    DNode<T>* prev() const { return prev_node; }
    void set_next(DNode<T>* next) { next_node = next; }
    void set_prev(DNode<T>* prev) { prev_node = prev; }

    template<typename> friend class D_List;
};

template<typename T>
class D_List {
private:
    DNode<T>* list_head;
    DNode<T>* list_tail;

public:
    D_List() : list_head(nullptr), list_tail(nullptr) {}

    ~D_List() { while (!empty()) pop_front(); }

    bool empty() const { return (list_head == nullptr); }

    int size() const {
        int count = 0;
        for (DNode<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) ++count;
        return count;
    }

    T front() const {
        if (empty()) { cerr << "List is empty! Cannot access front element.\n"; return T(); }
        return list_head->retrieve();
    }

    T end() const {
        if (empty()) { cerr << "List is empty! Cannot access end element.\n"; return T(); }
        return list_tail->retrieve();
    }

    DNode<T>* head() const { return list_head; }
    DNode<T>* tail() const { return list_tail; }

    int count(const T& n) const {
        int node_count = 0;
        for (DNode<T>* ptr = head(); ptr != nullptr; ptr = ptr->next()) if (ptr->retrieve() == n) ++node_count;
        return node_count;
    }

    void push_front(const T& n) {
        DNode<T>* new_node = new DNode<T>(n, list_head, nullptr);
        if (empty()) list_head = list_tail = new_node;
        else { list_head->set_prev(new_node); list_head = new_node; }
    }

    void push_end(const T& n) {
        DNode<T>* new_node = new DNode<T>(n, nullptr, list_tail);
        if (empty()) list_head = list_tail = new_node;
        else { list_tail->set_next(new_node); list_tail = new_node; }
    }

    void push_between(int index, const T& n) {
        int size_val = size();
        if (index < 0 || index > size_val) { cerr << "Invalid index! Must be between 0 and " << size_val << ".\n"; return; }
        if (index == 0) { push_front(n); return; }
        if (index == size_val) { push_end(n); return; }
        DNode<T>* ptr = list_head;
        for (int i = 0; i < index - 1; ++i) ptr = ptr->next();
        DNode<T>* new_node = new DNode<T>(n, ptr->next(), ptr);
        ptr->next()->set_prev(new_node);
        ptr->set_next(new_node);
    }

    T pop_front() {
        if (empty()) { cerr << "List is empty! Cannot pop front.\n"; return T(); }
        T value = list_head->retrieve();
        DNode<T>* temp = list_head;
        if (list_head == list_tail) list_head = list_tail = nullptr;
        else { list_head = list_head->next(); list_head->set_prev(nullptr); }
        delete temp; return value;
    }

    T pop_end() {
        if (empty()) { cerr << "List is empty! Cannot pop end.\n"; return T(); }
        T value = list_tail->retrieve();
        DNode<T>* temp = list_tail;
        if (list_head == list_tail) list_head = list_tail = nullptr;
        else { list_tail = list_tail->prev(); list_tail->set_next(nullptr); }
        delete temp; return value;
    }

    int erase(const T& n) {
        int count_removed = 0;
        DNode<T>* ptr = list_head;
        while (ptr != nullptr) {
            DNode<T>* next_node = ptr->next();
            if (ptr->retrieve() == n) {
                if (ptr == list_head) pop_front();
                else if (ptr == list_tail) pop_end();
                else { ptr->prev()->set_next(ptr->next()); ptr->next()->set_prev(ptr->prev()); delete ptr; }
                ++count_removed;
            }
            ptr = next_node;
        }
        return count_removed;
    }

    void display() const {
        if (empty()) { cout << "List is empty.\n"; return; }
        cout << "nullptr <- ";
        for (DNode<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
            cout << ptr->retrieve();
            if (ptr->next() != nullptr) cout << " <-> ";
        }
        cout << " -> nullptr\n";
    }

    void display_reverse() const {
        if (empty()) { cout << "List is empty.\n"; return; }
        cout << "nullptr <- ";
        for (DNode<T>* ptr = list_tail; ptr != nullptr; ptr = ptr->prev()) {
            cout << ptr->retrieve();
            if (ptr->prev() != nullptr) cout << " <-> ";
        }
        cout << " -> nullptr\n";
    }
};

int main() {
    D_List<int> lst;

    cout << "Pushing front 10, 20, 30:\n";
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.display();

    cout << "\nPushing end 40, 50:\n";
    lst.push_end(40);
    lst.push_end(50);
    lst.display();

    cout << "\nDisplay in reverse:\n";
    lst.display_reverse();

    cout << "\nFront element: " << lst.front() << endl;
    cout << "End element: " << lst.end() << endl;
    cout << "Size of list: " << lst.size() << endl;

    cout << "\nCounting how many times 20 appears: " << lst.count(20) << endl;

    cout << "\nErasing all nodes with value 20:\n";
    lst.erase(20);
    lst.display();

    cout << "\nPopping front: " << lst.pop_front() << endl;
    lst.display();

    cout << "\nPopping end: " << lst.pop_end() << endl;
    lst.display();

    cout << "\nErasing 10 and 40...\n";
    lst.erase(10);
    lst.erase(40);
    lst.display();

    cout << "\nAttempting to pop from empty list:\n";
    lst.pop_front();

    cout << "\nProgram finished successfully.\n";
    return 0;
}
