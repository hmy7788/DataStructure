#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value, Node* next) {
        this->value = value;
        this->next = NULL;
    }
};

class CirCular_Linked_List {
public:
    int size;
    Node* head;
    Node* tail;

    CirCular_Linked_List() {
        Node* dummy_node = new Node(NULL, NULL);

        this->size = 0;
        this->head = dummy_node;
        this->tail = dummy_node;
        dummy_node->next = dummy_node;
    }

    void append(int value) {
        Node* new_node = new Node(value, this->head);
        Node* current_node = this->tail;
        current_node->next = new_node;
        this->tail = new_node;
        this->size++;
    }

    void display() {
        if (this->size == 0) {
            cout << "size is 0" << "\n";
            return;
        }
        else {
            Node* current_node = this->head->next;
            Node* tail_node = this->tail;
            while (current_node != tail_node) {
                cout << current_node->value << " -> ";
                current_node = current_node->next;
            }
            cout << tail_node->value << " -> ";
            cout << "NULL\n\n";
        }
    }
};

int main() {
    CirCular_Linked_List CLL;

    CLL.append(1);
    CLL.append(2);
    CLL.append(2);
    CLL.append(2);
    CLL.append(2);
    cout << "연결 리스트 길이: " << CLL.size << "\n";
    CLL.display();

    return 0;
}
