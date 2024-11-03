#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    int size;
    struct Node* head;
} LinkedList;

void LL_init(LinkedList* LL) {
    LL->size = 0;
    LL->head = NULL;
}

struct Node* create_node(int value) {
    struct Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void append(int value, LinkedList* LL) {
    struct Node* new_node = create_node(value);

    if (LL->size == 0) {
        LL->head = new_node;
    }
    else {
        Node* current_node = LL->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    LL->size++;
}

void pop(LinkedList* LL) {
    if (LL->size == 0) {
        return;
    }
    else if (LL->size == 1) {
        free(LL->head);
        LL->head = NULL;
    }
    else {
        struct Node* remove_node = LL->head;
        struct Node* prev_node = LL->head;
        while (remove_node->next != NULL) {
            remove_node = remove_node->next;
            if (remove_node->next == NULL) {
                break;
            }
            prev_node = prev_node->next;
        }
        prev_node->next = NULL;
        free(remove_node);
    }
    LL->size--;
}

void display(LinkedList* LL) {
    if (LL->size == 0) {
        printf("size is 0");
        return;
    }
    else {
        Node* current_node = LL->head;
        while (current_node != NULL) {
            printf("%d -> ", current_node->value);
            current_node = current_node->next;
        }
        printf("NULL\n\n");
    }
}

void insert(int i, int value, LinkedList* LL) {
    if (i == LL->size) {
        append(value, LL);
        return;
    }
    else if (i < 0 || i > LL->size) {
        printf("index error\n");
    }
    else if (i == 0) {
        struct Node* new_node = create_node(value);
        struct Node* next_node = LL->head;
        LL->head = new_node;
        new_node->next = next_node;
    }
    else {
        struct Node* new_node = create_node(value);
        struct Node* prev_node = LL->head;
        struct Node* next_node = prev_node->next;
        while (--i > 0) {
            prev_node = next_node;
            next_node = next_node->next;
        }
        prev_node->next = new_node;
        new_node->next = next_node;
    }
    LL->size++;
}

void node_delete(int i, LinkedList* LL) {
    if (i == LL->size - 1) {
        pop(LL);
        return;
    }
    else if (i < 0 || i >= LL->size) {
        printf("index error\n");
        return;
    }
    else {
        struct Node* remove_node = LL->head;
        struct Node* prev_node = LL->head;
        struct Node* next_node = LL->head;

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
            LL->head = next_node;
        }
        else {
            prev_node->next = next_node;
        }
        free(remove_node);
    }
    LL->size--;
}

void clear(LinkedList* LL) {
    if (LL->size == 0) {
        return;
    }
    else {
        while (LL->head != NULL) {
            struct Node* next_node = LL->head->next;
            free(LL->head);
            LL->head = next_node;
        }
        LL->size = 0;
    }
}

int main() {
    LinkedList LL;
    LL_init(&LL);

    insert(0, 0, &LL);
    insert(1, 1, &LL);
    insert(2, 2, &LL);
    insert(3, 3, &LL);
    insert(0, 4, &LL);
    printf("연결 리스트 사이즈: %d\n", LL.size);
    display(&LL);

    node_delete(2, &LL);
    printf("연결 리스트 사이즈: %d\n", LL.size);
    display(&LL);

    node_delete(0, &LL);
    printf("연결 리스트 사이즈: %d\n", LL.size);
    display(&LL);

    node_delete(2, &LL);
    printf("연결 리스트 사이즈: %d\n", LL.size);
    display(&LL);

    clear(&LL);
    printf("연결 리스트 사이즈: %d\n", LL.size);
    display(&LL);

    printf("1");

    return 0;
}
