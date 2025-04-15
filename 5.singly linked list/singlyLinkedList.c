#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* head = NULL;

node* createNode(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Couldn't allocate memory!\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node at position %d.\n", pos);
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
             return;
        }
        temp = temp->next;
    }
    node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf("Deleted node at position %d.\n", pos);
}

void insertAtBeginning(int val) {
    node* newNode = createNode(val);
    if (newNode == NULL) return;
    newNode->next = head;
    head = newNode;
    printf("%d inserted successfully.\n", val);
}

void insertAtEnd(int val) {
    node* newNode = createNode(val);
    if (newNode == NULL) return;
    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d successfully.\n", val);
}

void insertAtRandom(int val, int pos) {
    node* newNode = createNode(val);
    if (newNode == NULL) return;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d.\n", val, pos);
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", val, pos);
}

void deleteAtBeginning() {
    deleteNode(1);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int pos = 1;
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        pos++;
    }
    deleteNode(pos);
}

void deleteAtRandom(int pos) {
    deleteNode(pos);
}

void display() {
    node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Aman\n");
    int ch, val, pos;

    while (1) {
        printf("\nEnter a choice:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Random Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Random Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtRandom(val, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtRandom(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
