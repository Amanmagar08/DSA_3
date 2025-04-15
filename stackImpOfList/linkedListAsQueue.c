#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *queue = NULL;

void initQueue()
{
    // Dynamically allocate memory for the queue
    queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    queue->front = queue->rear = NULL;
}

int isEmpty()
{
    return queue->front == NULL;
}

void enqueue(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear)
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL)
    {
        queue->front = queue->rear;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
        return -1; // Return -1 to indicate underflow
    }
    Node *temp = queue->front;
    int dequeueValue = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return dequeueValue;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue empty\n");
        return;
    }
    Node *temp = queue->front;
    printf("Queue: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    initQueue();

    int ch, val;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1)
        {
            printf("Invalid input\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (ch)
        {
        case 1:
            printf("Enter value to enqueue: ");
            if (scanf("%d", &val) != 1)
            {
                printf("Invalid input\n");
                while (getchar() != '\n'); // Clear the input buffer
                continue;
            }
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if (val != -1)
            {
                printf("Dequeued value: %d\n", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("Front element: %d\n", val);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            // Clean up allocated memory for queue before exiting
            while (!isEmpty())
            {
                dequeue();
            }
            free(queue);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
