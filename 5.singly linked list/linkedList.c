#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node n;

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

void insertAtBeginning (struct Node** head, int val){
    struct Node* newNode = createNode(val);
    newNode -> next =  *head;
    *head = newNode;
}

void insertAtEnd (struct Node** head, int val){
    struct Node* newNode = crateNode(val);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(){
    struct Node* temp = head;
    if (head != NULL)


}
