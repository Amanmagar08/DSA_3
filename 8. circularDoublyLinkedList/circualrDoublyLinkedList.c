# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Couldn't allocate memory.\n");
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = newNode;
    newNode -> prev = newNode;
    return newNode;
}

void insertAtBeginning(int val) {
    Node* newNode = createNode(val);
    if(!newNode) return;
    
    if (head == NULL)
        head = newNode;
    else {
        newNode -> next = head;
        newNode -> prev = head -> prev;
        head -> prev -> next = newNode;
        head -> prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int val) {
    Node* newNode = createNode(val);
    if(!newNode) return;

    if(head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while(temp -> next != head)
            temp = temp -> next;
        temp -> next = newNode;
        newNode -> prev = temp;
        newNode -> next = head;
        head -> prev = newNode;
    }
}

void insertAtRandom(int val, int pos) {
    Node* newNode = createNode(val);
    if(!newNode) return;

    if(pos <= 0) {
        printf("Invalid position. position cannot be less than 0.\n");
        free(newNode);
        return;
    }

    if(pos == 1) {
        insertAtBeginning(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp -> next == head) {
            printf("Position out of bound.\n");
            free(newNode);
            return;
        }
        temp = temp -> next;
    }
    
    newNode -> next = temp -> next;
    newNode -> prev = temp;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
}

void delete(int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        Node* delNode = head;
        if(delNode -> next == head) {
            head = NULL;
        }
        else {
            head -> prev -> next = head -> next;
            head -> next -> prev = head -> prev;
            head = head -> next;
        }
        free(delNode);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if(temp -> next == head) {
            printf("Position out of bound.\n");
            return;
        }
        temp = temp -> next;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
}

int length() {
    if(head == NULL) {
        return 0;
    }
    Node* temp = head;
    int i = 0;
    do {
        temp = temp->next;
        i++;
    } while (temp != head);
    return i;
}

void display() {
    Node* temp = head;
    if(head == NULL){
        printf("List is empty.\n");
    }else {
        printf("List items: ");
        do {
            printf("%d -> ", temp -> data);
            temp = temp -> next;
        } while (temp != head);
        printf("HEAD.\n");
    }
}

int main() {
    printf("Aman\n");
    int ch, val, pos, i;

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
                if (head == NULL){
                    printf("Already empty.\n");
                    break;
                }
                delete(1);
                break;
            case 5:
                i = length();
                if(i == 0) {
                    printf("list is already empty.\n");
                }
                else{
                    delete(i);
                }
                break;
            case 6:
                if (head == NULL){
                    printf("Already empty.\n");
                    break;
                }
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete(pos);
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