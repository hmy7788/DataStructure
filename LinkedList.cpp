#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next = NULL) {
        this->value = value;
        this->next = next;
    }
};

class Linked_List {
public:
    int size;
    Node* head;

    Linked_List(Node* head = NULL) {
        this->head = head;
        this->size = 0;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        if (this->size == 0) {
            this->head = new_node;
        }
        else {
            Node* current_node = this->head;
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
        this->size++;
    }

    void pop() {
        if (this->size == 0) {
            return;
        }
        else if (this->size == 1) {
            delete(this->head);
            this->head = NULL;
        }
        else {
            Node* remove_node = this->head;
            Node* prev_node = this->head;
            while (remove_node->next != NULL) {
                remove_node = remove_node->next;   // remove_node->next == *remove_node.next
                if (remove_node->next == NULL) {
                    break;
                }
                prev_node = prev_node->next;
            }
            prev_node->next = NULL;
            delete(remove_node);
        }
        this->size--;
    }

    void display() {
        if (this->size == 0) {
            cout << "size is 0" << "\n";
            return;
        }
        else {
            Node* current_node = this->head;
            while (current_node != NULL) {
                cout << current_node->value << " -> ";
                current_node = current_node->next;
            }
            cout << "NULL\n\n";
        }
    }

    void insert(int i, int value) {
        if (i == this->size) {
            this->append(value);
            return;
        }
        else if (i < 0 || i > this->size) {
            cout << "index error" << "\n";
            return;
        }
        else if (i == 0) {
            Node* new_node = new Node(value);
            Node* next_node = this->head;
            this->head = new_node;
            new_node->next = next_node;
        }
        else {
            Node* new_node = new Node(value);
            Node* prev_node = this->head;
            Node* next_node = prev_node->next;
            while (--i > 0) {
                prev_node = next_node;
                next_node = next_node->next;
            }
            prev_node->next = new_node;
            new_node->next = next_node;
        }
        this->size++;
    }

    void remove(int i) {
        if (i == this->size - 1) {
            this->pop();
            return;
        }
        else if (i < 0 || i >= this->size) {
            cout << "index error" << "\n";
            return;
        }
        else {
            Node* remove_node = this->head;
            Node* prev_node = this->head;
            Node* next_node = this->head;

            int x = i; int y = i; int z = i;
            while (--x > 0) {
                prev_node = prev_node->next;
            }
            while (y-- > 0) {
                remove_node = remove_node->next;
            }
            while (z-- > -1) {
                next_node = next_node->next;
            }

            if (i == 0) {
                this->head = next_node;
            }
            else {
                prev_node->next = next_node;
            }
            delete(remove_node);
        }
        this->size--;
    }

    void clear() {
        if (this->size == 0) {
            return;
        }
        else {
            while (this->head != NULL) {
                Node* next_node = this->head->next;
                delete(this->head);
                this->head = next_node;
            }
            this->size = 0;
        }
    }
};

int main() {
    Linked_List LL;

    LL.insert(0, 0);
    LL.insert(1, 1);
    LL.insert(2, 2);
    LL.insert(3, 3);
    LL.insert(0, 4);
    cout << "연결 리스트 사이즈: " << LL.size << "\n";
    LL.display();

    LL.remove(2);
    cout << "연결 리스트 사이즈: " << LL.size << "\n";
    LL.display();

    LL.remove(0);
    cout << "연결 리스트 사이즈: " << LL.size << "\n";
    LL.display();

    LL.remove(2);
    cout << "연결 리스트 사이즈: " << LL.size << "\n";
    LL.display();

    LL.clear();
    cout << "연결 리스트 사이즈: " << LL.size << "\n";
    LL.display();

    LL.display();
    LL.display();
    LL.display();
    LL.display();
    LL.display();
    LL.display(); LL.display(); LL.display();
    LL.display();
    LL.display();
    LL.display();
    LL.display();
    LL.display();

    return 0;
}