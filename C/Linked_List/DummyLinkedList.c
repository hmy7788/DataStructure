#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

typedef struct Dummy_Node {
	const char* value;
	struct Node* next;
} Dummy_Node;

typedef struct DummyLinkedList {
	int size;
	struct Dummy_Node* head;
} DummyLinkedList;

void DLL_init(DummyLinkedList* DLL) {
	Dummy_Node* dummy_node = (Dummy_Node*)malloc(sizeof(Dummy_Node));

	dummy_node->value = "DUMMY";
	dummy_node->next = NULL;
	DLL->head = dummy_node;
	DLL->size = 0;
}

void new_node_init(Node* new_node, int value) {
	new_node->value = value;
	new_node->next = NULL;
}

void back_push(DummyLinkedList* DLL, int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node_init(new_node, value);

	Node* current_node = DLL->head;
	while (current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = new_node;
	DLL->size++;
}

void front_push(DummyLinkedList* DLL, int value) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node_init(new_node, value);

	Node* current_node = DLL->head;
	Node* next_node = current_node->next;

	current_node->next = new_node;
	new_node->next = next_node;
	DLL->size++;
}

void display(DummyLinkedList* DLL) {
	Node* current_node = DLL->head->next;

	printf("Dummy -> ");
	while (current_node != NULL) {
		printf("%d -> ", current_node->value);
		current_node = current_node->next;
	}
	printf("NULL\n\n");
}

void back_pop(DummyLinkedList* DLL) {
	if (DLL->size == 0) {
		return;
	}
	else {
		Node* current_node = DLL->head;
		int i = DLL->size;

		while (--i > 0) {
			current_node = current_node->next;
		}
		Node* remove_node = current_node->next;
		
		current_node->next = NULL;
		free(remove_node);
		DLL->size--;
	}
}

void front_pop(DummyLinkedList* DLL) {
	if (DLL->size == 0) {
		return;
	}
	else {
		Node* dummy_node = DLL->head;
		Node* remove_node = dummy_node->next;
		Node* next_node = remove_node->next;

		dummy_node->next = next_node;
		free(remove_node);
		DLL->size--;
	}
}

void insert(DummyLinkedList* DLL, int i, int value) {
	if (i == 0 || i == DLL->size) {
		if (i == 0) {
			front_push(DLL, value);
		}
		else {
			back_push(DLL, value);
		}
		return;
	}
	else if (i < 0 || i > DLL->size) {
		printf("index error\n");
		return;
	}
	else {
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node_init(new_node, value);
		Node* current_node = DLL->head;
		while (i-- > 0) {
			current_node = current_node->next;
		}
		Node* next_node = current_node->next;

		current_node->next = new_node;
		new_node->next = next_node;
		DLL->size++;
	}
}

void delete(DummyLinkedList* DLL, int i) {
	if (i == 0 || i == DLL->size - 1) {
		if (i == 0) {
			front_pop(DLL);
		}
		else {
			back_pop(DLL);
		}
		return;
	}
	else if (i < 0 || i >= DLL->size) {
		printf("index error\n");
		return;
	}
	else {
		Node* current_node = DLL->head;
		while (i-- > 0) {
			current_node = current_node->next;
		}
		Node* remove_node = current_node->next;
		Node* next_node = remove_node->next;

		current_node->next = next_node;
		free(remove_node);
		DLL->size--;
	}

}

int main() {
	DummyLinkedList DLL;
	DLL_init(&DLL);

	back_push(&DLL, 1);
	back_push(&DLL, 2);
	display(&DLL);

	front_push(&DLL, 0);
	front_push(&DLL, -1);
	display(&DLL);

	front_pop(&DLL);
	display(&DLL);

	back_pop(&DLL);
	display(&DLL);

	insert(&DLL, 2, 2);
	insert(&DLL, 1, 4);
	insert(&DLL, 0, 5);
	display(&DLL);

	delete(&DLL, 0);
	delete(&DLL, 3);
	display(&DLL);

	delete(&DLL, 1);
	display(&DLL);

	return 0;
}