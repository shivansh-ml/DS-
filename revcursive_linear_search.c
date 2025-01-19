#include <stdio.h>
#include <stdlib.h>

// Recursive function to perform linear search
int recursiveLinearSearch(int* arr, int size, int key, int index) {
    // Base case: if index is out of bounds (element not found)
    if (index >= size) {
        return -1;
    }

    // If element is found at the current index
    if (arr[index] == key) {
        return index;
    }

    // Recursive call to search in the next index
    return recursiveLinearSearch(arr, size, key, index + 1);
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

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the search key as input
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    // Calling the recursive linear search function
    int result = recursiveLinearSearch(arr, size, key, 0);

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
