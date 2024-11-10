#include <iostream>

using namespace std;

class Node {
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

class Stack {
public:
	int size;
	Node* next;
	Node* tail;

	Stack() {
		this->size = 0;

		Node* dummy_node = new Node(NULL);
		dummy_node->next = dummy_node;

		this->next = dummy_node;
		this->tail = dummy_node;
	}

	void push(int value) {
		Node* tail_node = this->tail;
		Node* new_node = new Node(value, NULL, tail_node);

		tail_node->next = new_node;
		this->tail = new_node;
		this->size++;
	}

	void pop() {
		if (this->size == 0) {
			cout << "Stack is Empty" << "\n";
			return;
		}
		else {
			Node* tail_node = this->tail;
			Node* prev_node = tail_node->prev;

			prev_node->next = NULL;
			this->tail = prev_node;
			delete(tail_node);
			this->size--;
		}
	}

	int peek() {
		if (this->size > 0) {
			return this->tail->value;
		}
		else {
			cout << "Stack is Empty" << "\n";
			return -1;
		}
	}

	int get_size() {
		return this->size;
	}

	void display() {
		Node* current_node = this->next->next;
		while (current_node != nullptr) {
			cout << current_node->value << " -> ";
			current_node = current_node->next;
		}
	}
};

int main() {
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.display();

	
	return 0;
}