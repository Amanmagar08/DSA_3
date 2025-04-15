#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Stack* stack = NULL;

void initStack()
{
    // Dynamically allocate memory for the stack
    stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
}

int isEmpty()
{
    return stack->top == NULL;
}

void push(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;  // Return -1 to indicate underflow
    }
    Node *temp = stack->top;
    int popValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popValue;
}

void display()
{
    if (isEmpty())
    {
        printf("Stack empty\n");
        return;
    }
    Node *temp = stack->top;
    printf("Stack: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    initStack();
    int ch, val;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("Popped value: %d\n", val);
            break;
        case 3:
            display();
            break;
        case 4:
            free(stack);  // Free the allocated memory for the stack before exiting
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

