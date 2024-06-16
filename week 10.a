#include <stdio.h>

// Function to perform linear search
void linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Key %d found at index %d\n", key, i);
            return;
        }
    }
    printf("Key %d not found in the array\n", key);
}

int main() {
    int arr[] = {2, 4, 0, 1, 9, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    linearSearch(arr, size, key);

    return 0;
}

