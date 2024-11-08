#include <iostream>

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

	}

	void front_pop() {

	}
};

int main() {
	return 0;
}