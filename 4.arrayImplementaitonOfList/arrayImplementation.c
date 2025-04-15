#include <stdio.h>

#define SIZE 3

int addElement(int arr[], int initialSize, int element) {
    if (initialSize >= SIZE) {
        printf("The list is full. Cannot add more elements.\n");
        return initialSize;
    }
    arr[initialSize] = element;
    return initialSize + 1;
}

int removeElement(int arr[], int initialSize, int element) {
    int found = 0;
    for (int i = 0; i < initialSize; i++) {
        if (arr[i] == element) {
            found = 1;
            for (int j = i; j < initialSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            initialSize--;
            break;
        }
    }
    if (!found) {
        printf("Element not found in the list.\n");
    }
    return initialSize;
}

void displayList(int arr[], int initialSize) {
    if (initialSize == 0) {
        printf("The list is empty.\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < initialSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    int initialSize = 0;
    int ch, element;

    while (1) {
        printf("\nChoices:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                initialSize = addElement(arr, initialSize, element);
                break;
            case 2:
                printf("Enter element to remove: ");
                scanf("%d", &element);
                initialSize = removeElement(arr, initialSize, element);
                break;
            case 3:
                displayList(arr, initialSize);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
