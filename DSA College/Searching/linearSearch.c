#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        // Check if current element is the target
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

int main() {
    int arr[] = {3, 5, 7, 9, 11, 13, 15};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of elements in the array
    int target;

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Call the linear search function
    int result = linearSearch(arr, n, target);

    // Check and print the result
    if (result == -1) {
        printf("Target not found in the array.\n");
    } else {
        printf("Target found at index %d.\n", result);
    }

    return 0;
}
