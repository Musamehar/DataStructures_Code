#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
    T value;
    Node<T>* next_node;

public:
    Node(T val = T(), Node<T>* next = nullptr)
        : value(val), next_node(next) {}

    T retrieve() const { return value; }
    Node<T>* next() const { return next_node; }
    void set_next(Node<T>* next) { next_node = next; }

    template<typename> friend class C_List;
};

template<typename T>
class C_List {
private:
    Node<T>* list_tail;

public:
    C_List() : list_tail(nullptr) {}

    ~C_List() {
        while (!empty())
            pop_front();
    }

    bool empty() const { return (list_tail == nullptr); }

    Node<T>* head() const { return empty() ? nullptr : list_tail->next(); }
    Node<T>* tail() const { return list_tail; }

    T front() const {
        if (empty()) {
            cerr << "List is empty! Cannot access front element.\n";
            return T();
        }
        return head()->retrieve();
    }

    T end() const {
        if (empty()) {
            cerr << "List is empty! Cannot access end element.\n";
            return T();
        }
        return tail()->retrieve();
    }

    void push_front(const T& n) {
        if (empty()) {
            Node<T>* new_node = new Node<T>(n);
            new_node->set_next(new_node);
            list_tail = new_node;
        } else {
            Node<T>* old_head = list_tail->next();
            Node<T>* new_node = new Node<T>(n, old_head);
            list_tail->set_next(new_node);
        }
    }

    void push_end(const T& n) {
        if (empty()) {
            push_front(n);
        } else {
            Node<T>* old_head = list_tail->next();
            Node<T>* new_node = new Node<T>(n, old_head);
            list_tail->set_next(new_node);
            list_tail = new_node;
        }
    }

    void push_between(int index, const T& n) {
        if (empty()) {
            cerr << "Cannot insert in empty list! Use push_front first.\n";
            return;
        }

        int size_val = size();
        if (index < 0 || index >= size_val) {
            cerr << "Invalid index! Must be between 0 and " << (size_val - 1) << ".\n";
            return;
        }

        if (index == 0) { push_front(n); return; }

        Node<T>* ptr = head();
        for (int i = 0; i < index - 1; ++i) ptr = ptr->next();

        Node<T>* new_node = new Node<T>(n, ptr->next());
        ptr->set_next(new_node);
    }

    T pop_front() {
        if (empty()) {
            cerr << "List is empty! Cannot pop front.\n";
            return T();
        }

        Node<T>* old_head = list_tail->next();
        T value = old_head->retrieve();

        if (old_head == list_tail) {
            delete old_head;
            list_tail = nullptr;
        } else {
            list_tail->set_next(old_head->next());
            delete old_head;
        }
        return value;
    }

    T pop_end() {
        if (empty()) {
            cerr << "List is empty! Cannot pop end.\n";
            return T();
        }

        Node<T>* old_tail = list_tail;
        T value = old_tail->retrieve();

        if (list_tail->next() == list_tail) {
            delete old_tail;
            list_tail = nullptr;
        } else {
            Node<T>* ptr = list_tail->next();
            while (ptr->next() != list_tail) ptr = ptr->next();
            ptr->set_next(list_tail->next());
            list_tail = ptr;
            delete old_tail;
        }
        return value;
    }

    T erase(int index) {
        if (empty()) {
            cerr << "List is empty! Cannot erase.\n";
            return T();
        }

        int size_val = size();
        if (index < 0 || index >= size_val) {
            cerr << "Invalid index! Must be between 0 and " << (size_val - 1) << ".\n";
            return T();
        }

        if (index == 0) return pop_front();
        if (index == size_val - 1) return pop_end();

        Node<T>* ptr = head();
        for (int i = 0; i < index - 1; ++i) ptr = ptr->next();

        Node<T>* to_delete = ptr->next();
        T value = to_delete->retrieve();
        ptr->set_next(to_delete->next());
        delete to_delete;
        return value;
    }

    void display() const {
        if (empty()) { cout << "List is empty.\n"; return; }
        Node<T>* ptr = head();
        cout << "Head -> ";
        do {
            cout << ptr->retrieve() << " -> ";
            ptr = ptr->next();
        } while (ptr != head());
        cout << "(Back to Head)\n";
        cout << "(Tail is: " << list_tail->retrieve() << ")\n";
    }

    int size() const {
        if (empty()) return 0;
        int count = 0;
        Node<T>* ptr = head();
        do { ++count; ptr = ptr->next(); } while (ptr != head());
        return count;
    }
};

int main() {
    C_List<int> lst;

    cout << "Pushing front 10, 20, 30:\n";
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    lst.display();

    cout << "\nPushing end 40, 50:\n";
    lst.push_end(40);
    lst.push_end(50);
    lst.display();

    cout << "\nFront element: " << lst.front() << endl;
    cout << "End element: " << lst.end() << endl;
    cout << "Size: " << lst.size() << endl;

    cout << "\nPopping front: " << lst.pop_front() << endl;
    lst.display();

    cout << "\nPopping end: " << lst.pop_end() << endl;
    lst.display();

    cout << "\nPopping end: " << lst.pop_end() << endl;
    lst.display();

    cout << "\nPopping front: " << lst.pop_front() << endl;
    lst.display();

    cout << "\nPopping end: " << lst.pop_end() << endl;
    lst.display();

    cout << "\nProgram finished successfully.\n";
    return 0;
}
