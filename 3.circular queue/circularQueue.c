#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;

void initQueue() {
    front = -1; 
    rear = -1;  
}

void enqueue(int item) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = item;
    printf("Inserted %d successfully.\n", item);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Removed %d from the Queue.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("The items in the queue are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("Aman\n");
    int ch, val;

    initQueue();

    do {
        printf("\nEnter the corresponding number of the function you want to use:\n");
        printf("1. Enqueue (Add item)\n2. Dequeue (Remove item)\n3. Display (See all items)\n4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value you'd like to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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
