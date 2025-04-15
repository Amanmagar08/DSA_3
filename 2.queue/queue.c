#include <stdio.h>
#define SIZE 5

typedef struct linearQueue{
    int queue[SIZE];
    int front, rear;
}lq;

// typedef struct linearQueue lq;

void initQueue(lq *q) {
    q->front = -1; 
    q->rear = -1;  
}

void enqueue(lq *q, int item) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full!!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->queue[++q->rear] = item;
    printf("Inserted %d successfully.\n", item);
}

void dequeue(lq *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed %d from the Queue.\n", q->queue[q->front++]);
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void display(lq *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("The items in the queue are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Aman\n\n");
    lq lq;
    int ch, val;

    initQueue(&lq);

    do {
        printf("\nEnter the corresponding number of the function you want to use:\n");
        printf("1. Enqueue (Add item)\n2. Dequeue (Remove item)\n3. Display (See all items)\n4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value you'd like to enqueue: ");
                scanf("%d", &val);
                enqueue(&lq, val);
                break;
            case 2:
                dequeue(&lq);
                break;
            case 3:
                display(&lq);
                break;
            case 4:
                printf("Program exited...\n");
                break;
            default:
                printf("Invalid input. Try again\n");
        }
    } while (ch != 4);

    return 0;
}
