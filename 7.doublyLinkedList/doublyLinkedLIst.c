# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;

node* head = NULL;

node* createNode (int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Couldn't allocate memory\n");
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void deleteNode(int pos) {
    if (head == NULL) {
        printf("List is empty nothing to delete!\n");
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head -> next;
        if(head) head -> prev = NULL;
        free(temp);
        printf("Deleted the first node.\n");
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp -> next == NULL) {
            printf("Invalid location.\n");
            return;
        }
        temp = temp -> next;
    }

    node* delNode = temp -> next;
    temp -> next = delNode -> next;
    if (delNode -> next != NULL){
        delNode -> next -> prev = temp;
    }

    free(delNode);
    printf("Deleted node at position %d.\n", pos);
}

void insertAtBeginning(int val) {
    node* newNode = createNode(val);
    if (newNode == NULL) return;
    if(head == NULL){
        head = newNode;
    }else{
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    printf("%d inserted successfully at the beginning.\n", val);
}

void insertAtEnd(int val) {
    node* newNode = createNode(val);
    if (newNode == NULL) return;
    if (head == NULL) {
        head = newNode;
    }else {
        node* temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
    }
    printf("%d inserted at the end.\n", val);
}

void insertAtRandom (int val, int pos) {
    if (pos <= 0){
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }

    node* newNode = createNode(val);
    if(!newNode) return;

    if (head == NULL) {
        printf("Invalid position. List is empty.\n");
        free(newNode);
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos -1; i++) {
        if (temp -> next == NULL) {
            printf("Invalid location.\n");
            free(newNode);
            return;
        }
        temp = temp -> next;
    }

    newNode -> prev = temp;
    newNode -> next = temp -> next;
    if(temp -> next != NULL){
        temp -> next -> prev = newNode;
    }
    temp -> next = newNode;
    printf("Inserted %d at position %d successfully.\n", val, pos);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty nothing to delete!\n");
        return;
    }
    node* temp = head;
    if(temp -> next == NULL) {
        free(temp);
        head = NULL;
        printf("Deleted the only node.\n");
        return;
    }

    while(temp -> next != NULL) {
        temp = temp -> next;
    }


    temp->prev->next = NULL;
    free(temp);
    printf("Deleted node from end.\n");
}

void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* temp = head;
    printf("List Items: ");
    while (temp != NULL) {
        printf("%d -> ",temp -> data);
        temp = temp -> next;
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
                deleteNode(1);
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteNode(pos);
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
