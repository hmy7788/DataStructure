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

    void back_push(int value) {
        Node* new_node = new Node(value, this->head);
        Node* current_node = this->tail;

        current_node->next = new_node;
        this->tail = new_node;
        this->size++;
    }

    void front_push(int value) {
        Node* new_node = new Node(value, NULL);
        Node* current_node = this->head;
        Node* next_node = current_node->next;

        current_node->next = new_node;
        new_node->next = next_node;
        this->size++;
    }

    void back_pop() {
        if (this->size == 0) {
            cout << "size is 0" << "\n";
            return;
        }
        else {
            int last_idx = this->size - 1;
            Node* current_node = this->head;
            while (last_idx-- > 0) {
                current_node = current_node->next;
            }
            Node* remove_node = current_node->next;

            delete(remove_node);
            current_node->next = NULL;
            this->tail = current_node;
            this->size--;
        }

    }

    void front_pop() {
        if (this->size == 0) {
            cout << "size is 0" << "\n";
            return;
        }
        else {
            Node* remove_node = this->head->next;
            Node* next_node = remove_node->next;
            this->head->next = next_node;
            this->size--;
        }
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
            cout << "Dummy Node\n\n";
        }
    }

    void insert(int i, int value) {
        if (i == 0 || i == this->size) {
            if (i == 0) {
                this->front_push(value);
                return;
            }
            else {
                this->back_push(value);
                return;
            }
        }
        else if (i < 0 || i > this->size) {
            cout << "index error\n";
            return;
        }
        else {
            Node* new_node = new Node(value, NULL);
            Node* current_node = this->head;
            
            while (i-- > 0) {
                current_node = current_node->next;
            }
            Node* next_node = current_node->next;

            current_node->next = new_node;
            new_node->next = next_node;
            this->size++;
        }
    }

    void remove(int i) {
        if (i == 0 || i == this->size - 1) {
            if (i == 0) {
                this->front_pop();
                return;
            }
            else {
                this->back_pop();
                return;
            }
        }
        else if (i < 0 || i >= this->size) {
            cout << "index error" << "\n";
            return;
        }
        else {
            Node* prev_node = this->head->next;
            Node* remove_node = this->head->next;
            int x = i; int y = i;
            while (--x > 0) {
                prev_node = prev_node->next;
            }
            while (y-- > 0) {
                remove_node = remove_node->next;
            }
            Node* next_node = remove_node->next;

            prev_node->next = next_node;
            delete(remove_node);
            this->size--;
        }
    }
};

int main() {
    CirCular_Linked_List CLL;

    CLL.back_push(1);
    CLL.back_push(2);
    CLL.back_push(3);
    CLL.insert(3,4);
    cout << "연결 리스트 길이: " << CLL.size << "\n";
    CLL.display();

    CLL.back_pop();
    CLL.display();

    CLL.front_pop();
    CLL.display();

    CLL.insert(0, 1);
    CLL.insert(3, 4);
    CLL.display();

    CLL.remove(1);
    CLL.display();

    return 0;
}
