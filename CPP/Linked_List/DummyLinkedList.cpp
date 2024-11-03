#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next = NULL) {
        this->value = value;
        this->next = NULL;
    }
};

class Dummy_Linked_List {
public:
    int size;
    Node* head;

    Dummy_Linked_List() {
        this->head = new Node(NULL, NULL);
        this->size = 0;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        Node* current_node = this->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        this->size++;
    }

    void pop() {
        if (this->size == 0) {
            return;
        }
        else {
            Node* remove_node = this->head->next;
            Node* prev_node = this->head;
            while (remove_node->next != NULL) {
                remove_node = remove_node->next;
                prev_node = prev_node->next;
            }
            prev_node->next = NULL;
            delete(remove_node);
            this->size--;
        }
    }

    void display() {
        Node* current_node = this->head->next;
        if (this->size == 0) {
            cout << "size is 0" << "\n";
            return;
        }
        else {
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
        else if (i <= 0 || i > this->size) {
            cout << "index error" << "\n";
            return;
        }
        else {
            Node* prev_node = this->head;
            Node* current_node = this->head->next;
            Node* new_node = new Node(value);

        }
    }

    void remove(int i) {

    }
};

int main() {
    Dummy_Linked_List DLL;

    DLL.append(1);
    DLL.append(2);
    DLL.append(3);
    DLL.append(4);
    cout << "연결 리스트 사이즈: " << DLL.size << "\n";
    DLL.display();

    DLL.pop();
    cout << "연결 리스트 사이즈: " << DLL.size << "\n";
    DLL.display();

    return 0;
}
