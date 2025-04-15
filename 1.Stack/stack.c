// To implement an operation in stack as ADT

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack {
    int arr[SIZE];
    int top;
};

typedef struct stack st;

void iniStack(st *s) {
    s->top = -1;
}

int isEmpty(st *s) {
    return (s->top == -1);
}

int isFull(st *s) {
    return (s->top == SIZE - 1);
}

void push(st *s, int val) {
    if (isFull(s)) {
        printf("Stack is full. No more items can be added.\n");
    } else {
        s->top++;
        s->arr[s->top] = val;
        printf("%d has been added to the stack successfully.\n", val);
    }
}

void display(st *s) {
    if (isEmpty(s)) {
        printf("The stack is currently empty.\n");
    } else {
        printf("The contents in the stack currently are: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

void pop(st *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to remove.\n");
    } else {
        int delitem = s->arr[s->top];
        s->top--;
        printf("%d has been removed from the stack successfully.\n", delitem);
    }
}

int peek(st *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; 
    } else {
        return s->arr[s->top];
    }
}

int main() {
    printf("Aman Thapa Magar");
    st *s = (st *)malloc(sizeof(st));
    iniStack(s);

    int ch, val;
    do {
        printf("\nEnter the corresponding number of the function you want to use?\n");
        printf("1. Push (Add item)\n2. Pop (Remove item)\n3. Peek (View top item)\n4. Display (See all items)\n5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the value you'd like to push: ");
                scanf("%d", &val);
                push(s, val);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                val = peek(s);
                if (val != -1) {
                    printf("The top item in the stack is %d.\n", val);
                }
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Program exited successfully!!\n");
                free(s);
                break;
            default:
                printf("Invalid input. Try again\n");
        }
    } while (ch != 5);

    return 0;
}
