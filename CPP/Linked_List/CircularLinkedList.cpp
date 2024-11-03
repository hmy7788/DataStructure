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
        this->size = 0;
        this->head = new Node(NULL, NULL);
        this->tail = this->head;
        this->head->next = this->head;
    }

    void append(int value) {
        Node* new_node = new Node(value, this->head);
        Node* current_node = this->head;

        while (current_node->next != this->head) {
            current_node = current_node->next;
        }

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
            cout << "NULL\n\n";
        }
    }
};

int main() {
    CirCular_Linked_List CLL;

    CLL.append(1);
    CLL.append(2);
    CLL.append(3);
    CLL.append(4);
    CLL.append(5);
    cout << "¿¬°á ¸®½ºÆ® »çÀÌÁî: " << CLL.size << "\n";
    CLL.display();
    CLL.display();

    return 0;
}
