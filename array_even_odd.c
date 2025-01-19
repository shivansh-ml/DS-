#include <stdio.h>
#include <stdlib.h>

void rearrangeEvenOdd(int* arr, int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        // Increment left pointer if it's even
        if (arr[left] % 2 == 0) {
            left++;
        }
        // Decrement right pointer if it's odd
        else if (arr[right] % 2 != 0) {
            right--;
        }
        // If left is odd and right is even, swap them
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int size;

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

    // Rearranging even and odd numbers
    rearrangeEvenOdd(arr, size);

    // Displaying the rearranged array
    printf("Rearranged array (even numbers followed by odd numbers):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
