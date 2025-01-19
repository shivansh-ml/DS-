#include <stdio.h>
#include <stdlib.h>

// Recursive function to perform binary search
int recursiveBinarySearch(int* arr, int left, int right, int key) {
    // Base case: if the search range is invalid (element not found)
    if (left > right) {
        return -1;
    }

    // Find the middle index
    int mid = left + (right - left) / 2;

    // If the element is found at the middle
    if (arr[mid] == key) {
        return mid;
    }

    // If the element is smaller than mid, search in the left subarray
    if (arr[mid] > key) {
        return recursiveBinarySearch(arr, left, mid - 1, key);
    }
    
    // If the element is greater than mid, search in the right subarray
    return recursiveBinarySearch(arr, mid + 1, right, key);
}

int main() {
    int size, key;

    // Taking dynamic array input
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocating memory for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    printf("Enter the elements of the array (must be sorted):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the search key as input
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Calling the recursive binary search function
    int result = recursiveBinarySearch(arr, 0, size - 1, key);

    // Output result
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
