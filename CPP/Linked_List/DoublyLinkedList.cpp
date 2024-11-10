#include <iostream>

using namespace std;

class Node{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value, Node* next = NULL, Node* prev = NULL) {
		this->value = value;
		this->next = next;
		this->prev = prev;
	}
};

class DoublyLinkedList {
public:
	int size;
	Node* head;

	DoublyLinkedList() {
		Node* dummy_node = new Node(NULL);
		this->size = 0;
		this->head = dummy_node;
		dummy_node->next = dummy_node;
		dummy_node->prev = dummy_node;
	}

	void back_push(int value) {
		Node* new_node = new Node(value);
		Node* tail_node = this->head->prev;

		tail_node->next = new_node;
		new_node->prev = tail_node;
		new_node->next = this->head;
		this->head->prev = new_node;

		this->size++;
	}

	void front_push(int value) {
		if (this->size == 0) {
			back_push(value);
			return;
		}
		else {
			Node* new_node = new Node(value);
			Node* dummy_node = this->head;
			Node* next_node = dummy_node->next;

			dummy_node->next = new_node;
			next_node->prev = new_node;
			new_node->prev = dummy_node;
			new_node->next = next_node;

			this->size++;
		}
	}

	void back_pop() {
		if (this->size == 0) {
			return;
		}
		else {
			Node* tail_node = this->head->prev;
			Node* prev_node = tail_node->prev;
			
			prev_node->next = this->head;
			this->head->prev = prev_node;
			delete(tail_node);
			this->size--;
		}
	}

	void front_pop() {
		if (this->size == 0) {
			return;
		}
		else if (this->size == 1) {
			this->back_pop();
			return;
		}
		else {
			Node* remove_node = this->head->next;
			Node* next_node = remove_node->next;

			this->head->next = next_node;
			next_node->prev = this->head;
			delete(remove_node);
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
			Node* tail_node = this->head->prev;
			cout << "Dummy Node -> ";
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
			cout << "index error" << "\n";
			return;
		}
		else {
			Node* new_node = new Node(value);
			Node* current_node = this->head;
			while (i-- > 0) {
				current_node = current_node->next;
			}
			Node* next_node = current_node->next;

			current_node->next = new_node;
			new_node->next = next_node;
			new_node->prev = current_node;
			next_node->prev = new_node;

			this->size++;
		}
	}

	void remove(int i) {
		if (this->size == 0) {
			return;
		}
		else if (i == 0 || i == this->size - 1) {
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
			Node* current_node = this->head;
			while (i-- > 0) {
				current_node = current_node->next;
			}
			Node* remove_node = current_node->next;
			Node* next_node = remove_node->next;

			current_node->next = next_node;
			next_node->prev = current_node;
			delete(remove_node);
			this->size--;
		}
	}
};

int main() {
	DoublyLinkedList DLL;

	DLL.back_push(1);
	DLL.front_push(2);
	DLL.back_push(3);
	DLL.back_push(4);
	DLL.display();

	DLL.back_pop();
	DLL.display();

	DLL.front_pop();
	DLL.display();

	DLL.insert(1, 2);
	DLL.insert(0, 0);
	DLL.display();

	DLL.insert(4, 4);
	DLL.remove(0);
	DLL.remove(3);
	DLL.display();

	DLL.remove(1);
	DLL.display();

	return 0;
}