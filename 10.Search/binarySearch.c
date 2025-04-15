#include <stdio.h>

// Function to perform Binary Search (Iterative)
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow

        if (arr[mid] == target) return mid; // Target found

        if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    // Using ternary operator for output
    result != -1 ? printf("Element found at index %d\n", result) 
                 : printf("Element not found\n");

    return 0;
}
